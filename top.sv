`include "Sysbus.defs"
`include "fetch.sv"
//`include "pipeline_reg.sv"
`include "decode.sv"

module top
#(
 ID_WIDTH = 13,
 ADDR_WIDTH = 64,
 DATA_WIDTH = 64,
 STRB_WIDTH = DATA_WIDTH/8
)
(
 input  clk,
        reset,
        hz32768timer,


 // 64-bit addresses of the program entry point and initial stack pointer
 input  [63:0] entry,
 input  [63:0] stackptr,
 input  [63:0] satp,


 // interface to connect to the bus
 // Write Address Channel (Send Address Data to slave)
 output  wire [ID_WIDTH-1:0]    m_axi_awid,
 output  wire [ADDR_WIDTH-1:0]  m_axi_awaddr,  //Starting address for the write
 output  wire [7:0]             m_axi_awlen,   //Number of transfers in the burst
 output  wire [2:0]             m_axi_awsize,  //Size of each data transfer
 output  wire [1:0]             m_axi_awburst, //Type of burst: Fixed, Incrementing, Wrapping
 output  wire                   m_axi_awlock,
 output  wire [3:0]             m_axi_awcache, //Cache control signals (e.g., bufferable or cacheable access)
 output  wire [2:0]             m_axi_awprot,
 output  wire                   m_axi_awvalid, //Valid signal; high when the address/control data is valid
 input   wire                   m_axi_awready, //Ready signal from the slave, indicating it can accept address data
  //Write Data Channel (Send Write Data to slave)
 output  wire [DATA_WIDTH-1:0]  m_axi_wdata,   //Data to be written to the slave
 output  wire [STRB_WIDTH-1:0]  m_axi_wstrb,
 output  wire                   m_axi_wlast,   //High when the last data transfer in the burst occurs
 output  wire                   m_axi_wvalid,  //Valid signal; high when the write data is valid
 input   wire                   m_axi_wready,  //Ready signal from the slave, indicating it can accept the data
  //Write Response Channel (B)
 input   wire [ID_WIDTH-1:0]    m_axi_bid,
 input   wire [1:0]             m_axi_bresp,
 input   wire                   m_axi_bvalid,  //Valid signal; high when the response is valid
 output  wire                   m_axi_bready,  //Ready signal from the master, indicating it accepts the response.
  //Read Address Channel (AR) (Retrieve address data from slave)
 output  wire [ID_WIDTH-1:0]    m_axi_arid,
 output  wire [ADDR_WIDTH-1:0]  m_axi_araddr,  //Starting address for the read transaction
 output  wire [7:0]             m_axi_arlen,   //Number of transfers in the read burst
 output  wire [2:0]             m_axi_arsize,  //Size of each data transfer
 output  wire [1:0]             m_axi_arburst, //Type of burst (fixed, incrementing, wrapping)
 output  wire                   m_axi_arlock,
 output  wire [3:0]             m_axi_arcache, //Cache control signals
 output  wire [2:0]             m_axi_arprot,
 output  wire                   m_axi_arvalid, //Valid signal; high when the address/control data is valid
 input   wire                   m_axi_arready, //Ready signal from the slave, indicating it can accept the data
  //Read Data Channel (R) (Retrieve read data from slave)
 input   wire [ID_WIDTH-1:0]    m_axi_rid,
 input   wire [DATA_WIDTH-1:0]  m_axi_rdata,  //Data read from the slave (size: DATA_WIDTH)
 input   wire [1:0]             m_axi_rresp,
 input   wire                   m_axi_rlast,  //High when the last transfer in the read burst occurs
 input   wire                   m_axi_rvalid, //Valid signal; high when the read data is valid.
 output  wire                   m_axi_rready, //Ready signal from the master, indicating it accepts the data.
  //Cache Related
 input   wire                   m_axi_acvalid,
 output  wire                   m_axi_acready,
 input   wire [ADDR_WIDTH-1:0]  m_axi_acaddr, //Address for cache coherence operations
 input   wire [3:0]             m_axi_acsnoop //Specifies the type of snoop operation (e.g., invalidate, clean, etc.).
);




 // set some set values with burst
 // 1. get instruction data
 // 2. get address data
 logic [63:0] pc;
 logic [63:0] instruction;


 // Define state machine states using a named enumeration
typedef enum logic [2:0] {
   SEND_READ_ADDRESS = 3'b000,
   SEND_READ_DATA    = 3'b001,
   DECODE_INSTRUCTION = 3'b100
} state_t;


state_t state, next_state;
logic [63:0] next_pc;
logic [DATA_WIDTH-1:0] fetched_instr;
logic [ADDR_WIDTH-1:0] display_addr;
logic [ADDR_WIDTH-1:0] next_display_addr;
//Fetch fetching the instruction from memory.
//The CPU relies on a special register called the program counter (PC) to keep track of the address of the next instruction to be executed.


//The PC points to the memory address of the instruction.
//The CPU sends a signal to the memory to retrieve the instruction at that address.
//The retrieved instruction is then stored in the instruction register (IR).
//ALU: op1 op2, tin hieu chon phep toan, function add, and, xor, shift
//load and store

//============FETCH============================
logic [31:0] if_instr;
//logic [63:0] if_address; 

Fetch fetch_inst (
        .clk            (clk),
        .reset          (reset),
        .entry          (entry),

        // AXI Read Address Channel
        .m_axi_araddr   (m_axi_araddr),
        .m_axi_arvalid  (m_axi_arvalid),
        .m_axi_arready  (m_axi_arready),
        .m_axi_arlen    (m_axi_arlen),
        .m_axi_arsize   (m_axi_arsize),
        .m_axi_arburst  (m_axi_arburst),

        // AXI Read Data Channel
        .m_axi_rdata    (m_axi_rdata),
        .m_axi_rvalid   (m_axi_rvalid),
        .m_axi_rready   (m_axi_rready),
        .m_axi_rlast    (m_axi_rlast),

        .if_instr       (if_instr)
        //.if_address     (if_address)
    );

// //=============IF_ID_REG====================
// logic [63:0] if_id_instr_out;
// logic [63:0] if_if_address_out; 

// IF_ID_register IF_ID_register(
//         .clk            (clk),
//         .reset          (reset),

//         .if_id_address_in    (if_address),
//         .if_id_instruction_in(if_instr),

//         .if_id_address_out    (if_if_address_out),
//         .if_id_instruction_out(if_id_instr_out)
// );
//===============DECODE====================
Decoder Decoder(
        .input_bin(if_instr),
        //.address(if_if_address_out)

        // .rs1, 
        // .rs2, 
        // .rd,
        // .imm_signed,
        // .imm_unsigned,
        // .opcode
        // .funct7,
        // .funct3
);

//===============

//Combinational logic to handle read transaction of current state
// always_comb begin
//    if (!reset) begin
//        case(state)
//            SEND_READ_ADDRESS: begin   
//                if (m_axi_arready && m_axi_arvalid)   
//                    next_state = SEND_READ_DATA;
//            end
//            SEND_READ_DATA: begin
//                if (m_axi_rvalid && m_axi_rready) begin
//                    if (m_axi_rdata == 64'b0) $finish;
//                        next_state = DECODE_INSTRUCTION;
//                end
//            end
//            DECODE_INSTRUCTION:    
//                 if (m_axi_rlast) begin
//                     if (!m_axi_rvalid) begin
                        
//                         next_pc = pc + 64;
//                         next_state = SEND_READ_ADDRESS;
//                     end
//                 end else begin
//                     next_state = SEND_READ_DATA;
//                 end
//        endcase
//    end
// end

// //Sequential logic to keep track of combinational logic output
// always_ff @(posedge clk) begin 
//     //reset
//     m_axi_araddr <= pc;
//     m_axi_arlen <= 7;
//     m_axi_arsize <= 8;
//     m_axi_arburst <= 2;
    
//     if(!reset) begin
//     //READ ADDRESS CHANNEL
//         if (state == SEND_READ_ADDRESS) 
//             m_axi_arvalid <= 1; 
//         else m_axi_arvalid <= 0; 
//         if (m_axi_arvalid == 1 && m_axi_arready == 1)
//             m_axi_arvalid <= 0;

//         //READ DATA CHANNEL
//         if (state == SEND_READ_DATA && m_axi_rvalid == 1)
//             m_axi_rready <= 1;
//         if (m_axi_rvalid == 1 && m_axi_rready == 1) begin
//             m_axi_rready <= 0;
//             fetched_instr <= m_axi_rdata;
//         end
//         //DECODE
//         if (state == DECODE_INSTRUCTION) begin
//             decoding(display_addr, fetched_instr[31:0]);
//             decoding(display_addr + 4, fetched_instr[63:32]);
//             next_display_addr <= display_addr + 8;
//         end
//     end
// end


// //sequential logic to toggle between the states
// always_ff @(posedge clk) begin
//    if (reset) begin
//        pc                         <= entry;
//        state                      <= SEND_READ_ADDRESS;
//    end else
//        state <= next_state;
//        pc    <= next_pc;
//        display_addr <= next_display_addr;
// end

//====================DECODE====================================

function decoding([31:0] address, [31:0] input_bin);
   reg [7:11] rd;        // Destination register
   reg [4:0] rs1, rs2; 
   logic signed [31:0] imm;
   reg [6:0] opcode;    // Opcode
   reg [2:0] funct3;    // Function field
   reg [6:0] funct7;    // Function field (for R-type)
   reg [63:0] decoded_instruction; // Human-readable decoded instruction

   // Internal registers
   reg [4:0] shamt; // Shift amount for certain instructions
   reg [31:0] signed_imm; // Sign-extended immediate for human-readable form


   begin
       // Extract the 32-bit instruction from the lower half of the 64-bit input
       opcode = input_bin[6:0];      // Opcode is always bits [6:0]
       rd = input_bin[11:7];         // Destination register is bits [11:7]
       funct3 = input_bin[14:12];    // Function3 is bits [14:12]
       funct7 = input_bin[31:25];    // Function7 is bits [31:25] (only for R-type)
       rs1 = input_bin[19:15]; // Source Register 1
       rs2 = input_bin[24:20]; // Source Register 2
       imm = input_bin[31:20]; // Immediate Value (for I-type)
       

       case (opcode)
           // R-Type Instructions (opcode: 0110011)
           7'b0110011: begin
               case (funct3)
                   3'b000: begin // ADD, SUB
                       if (funct7 == 7'b0000000)
                           decoded_instruction = "ADD";
                       else if (funct7 == 7'b0100000)
                           decoded_instruction = "SUB";
                   end
                   3'b111: decoded_instruction = "AND";
                   3'b110: decoded_instruction = "OR";
                   3'b100: decoded_instruction = "XOR";
                   3'b001: decoded_instruction = "SLL";
                   3'b101: begin
                       if (funct7 == 7'b0000000)
                           decoded_instruction = "SRL";
                       else if (funct7 == 7'b0100000)
                           decoded_instruction = "SRA";
                   end
               endcase
               $display("%x :%h %s x%d, x%d, x%d", address, input_bin, decoded_instruction, rd, rs1, rs2);
           end


           // I-Type Instructions (opcode: 0010011 for arithmetic, 0000011 for loads)
           7'b0010011: begin
               imm = {{20{input_bin[31]}}, input_bin[31:20]};
               case (funct3)
                   3'b000: decoded_instruction = "ADDI"; // ADDI
                   3'b111: decoded_instruction = "ANDI"; // ANDI
                   3'b110: decoded_instruction = "ORI";  // ORI
                   3'b100: decoded_instruction = "XORI"; // XORI
                   3'b001: decoded_instruction = "SLLI"; // SLLI
                   3'b011: decoded_instruction = "SLTIU"; // SLTIU
                   3'b101: begin
                       if (funct7 == 7'b0000000)
                           decoded_instruction = "SRLI"; // SRLI
                       else if (funct7 == 7'b0100000)
                           decoded_instruction = "SRAI"; // SRAI
                   end
               endcase
               $display("%x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm);
           end


           // I-Type (64-bit specific immediate arithmetic) (opcode: 0011011)
           7'b0011011: begin
               case (funct3)
                   3'b000: decoded_instruction = "ADDIW"; // ADDIW
                   3'b001: decoded_instruction = "SLLIW"; // SLLIW
                   3'b101: begin
                       if (funct7 == 7'b0000000)
                           decoded_instruction = "SRLIW"; // SRLIW
                       else if (funct7 == 7'b0100000)
                           decoded_instruction = "SRAIW"; // SRAIW
                   end
               endcase
               $display("%x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm);
           end


           // S-Type Instructions (opcode: 0100011) // NO RD
           7'b0100011: begin
               imm = {{20{input_bin[31]}}, input_bin[31:25], input_bin[11:7]};
               case (funct3)
                   3'b000: decoded_instruction = "SB";  // Store byte
                   3'b001: decoded_instruction = "SH";  // Store halfword
                   3'b010: decoded_instruction = "SW";  // Store word
                   3'b011: decoded_instruction = "SD";  // Store doubleword (64-bit store)
               endcase
               $display("%x :%h %s x%d, %d(x%d)", address, input_bin, decoded_instruction, rs2, imm, rs1);
           end


           // B-Type Instructions (opcode: 1100011) // NO RD
           7'b1100011: begin
               imm = {{19{input_bin[31]}}, input_bin[31], input_bin[7], input_bin[30:25], input_bin[11:8], 1'b0}; 
               case (funct3)
                   3'b000: decoded_instruction = "BEQ";  // Branch if equal
                   3'b001: decoded_instruction = "BNE";  // Branch if not equal
                   3'b100: decoded_instruction = "BLT";  // Branch if less than
                   3'b101: decoded_instruction = "BGE";  // Branch if greater or equal
               endcase
               $display("%x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rs1, rs2, imm);
           end


           // U-Type Instructions (opcode: 0110111 for LUI, 0010111 for AUIPC)
           7'b0110111: begin
               imm = {input_bin[31:12], 12'b0}; 
               decoded_instruction = "LUI";  // Load upper immediate
               $display("%x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm);
           end
           7'b0010111: begin
               imm = {input_bin[31:12], 12'b0}; 
               decoded_instruction = "AUIPC";  // Add upper immediate to PC
               $display("%x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm);
           end


           // J-Type Instructions (opcode: 1101111)
           7'b1101111: begin
               imm = {{11{input_bin[31]}}, input_bin[31], input_bin[19:12], input_bin[20], input_bin[30:21], 1'b0};
               decoded_instruction = "JAL";  // Jump and link
               $display("%x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm);
           end


           // JALR (I-Type for jumps, opcode: 1100111)
           7'b1100111: begin
               decoded_instruction = "JALR";  // Jump and link register
               $display("%x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm);
           end


           // Load double word (opcode: 0000011, funct3: 011 for LD)
           7'b0000011: begin
               case (funct3)
                   3'b011: decoded_instruction = "LD";  // Load doubleword (64-bit load)
                   3'b010: decoded_instruction = "LW";  // Load word
                   3'b100: decoded_instruction = "LBU"; // LBU
               endcase
               $display("%x :%h %s x%d, %d(x%d)", address, input_bin, decoded_instruction, rd, imm, rs1);
           end
       endcase
   end
 endfunction


// Initialization
initial begin
   $display("Initializing top, entry point = 0x%x", entry);
end

//======================INPUT INTO REGISTER FILE=============================



endmodule
