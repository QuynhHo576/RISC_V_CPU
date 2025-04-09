`include "Sysbus.defs"
`include "fetch.sv"
//`include "pipeline_reg.sv"
`include "decode.sv"
`include "reg_file.sv"
`include "control_logic.sv"
`include "alu.sv"

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

//Fetch fetching the instruction from memory.
//The CPU relies on a special register called the program counter (PC) to keep track of the address of the next instruction to be executed.


//The PC points to the memory address of the instruction.
//The CPU sends a signal to the memory to retrieve the instruction at that address.
//The retrieved instruction is then stored in the instruction register (IR).
//ALU: op1 op2, tin hieu chon phep toan, function add, and, xor, shift
//load and store

//============FETCH (FETCH STAGE)============================
logic [31:0] if_instr;
logic [63:0] if_address_out; 

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

        .if_instr       (if_instr),
        .if_address_out (if_address_out)
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


/* AFTER INSTRUCTION FETCHED, INFO OF INSTRUCTION GO INTO 2 PATHS RUNNING AT THE SAME TIME
* PATH 1: DECODE 
* PATH 2: CONTROL LOGIC
*/
//===============DECODE (DECODE STAGE)====================
logic [4:0]             id_reg_rs1_out, id_reg_rs2_out, id_reg_rd_out;
logic [63:0]            id_reg_imm_out;
logic [63:0]            id_reg_imm_signed_out;
logic [63:0]            id_reg_imm_unsigned_out;
logic [6:0]             id_reg_opcode_out, id_reg_funct7_out;
logic [2:0]             id_reg_funct3_out;
logic [3:0]             id_alu_op_out;

Decoder Decoder(
        .input_bin(if_instr),
        .address(if_address_out),

        .id_reg_rs1_out(id_reg_rs1_out), 
        .id_reg_rs2_out(id_reg_rs2_out), 
        .id_reg_rd_out(id_reg_rd_out),
        .id_reg_imm_out(id_reg_imm_out),
        .id_reg_imm_signed_out(id_reg_imm_signed_out),
        .id_reg_imm_unsigned_out(id_reg_imm_unsigned_out),
        .id_reg_opcode_out(id_reg_opcode_out),
        .id_reg_funct7_out(id_reg_funct7_out),
        .id_reg_funct3_out(id_reg_funct7_out),
        .id_alu_op_out(id_alu_op_out)
);

//===============CONTROL LOGIC=======================
logic reg_write_control;          // control signal to write to register
logic mem_read_control;           // control signal for memory read
logic mem_write_control;          // control signal for memory write
logic alu_src_control;            // ALU source control signal - use for when ALU need imm or rs2
logic mem_to_reg_control;

ControlUnit ControlUnit(
        .if_instr(if_instr),

        .reg_write_control(reg_write_control),
        //.mem_read_control(mem_read_control),
        //.mem_write_control(mem_write_control),
        .alu_src_control(alu_src_control),
        //.mem_to_reg_control(mem_to_reg_control)
);

//===============REG_FILE  (DECODE STAGE)============================
logic [63:0] regA_data_out;
logic [63:0] regB_data_out;

RegisterFile RegisterFile(
        .clk(clk),
        .reset(reset),
        .regA_addr_in(id_reg_rs1_out),
        .regB_addr_in(id_reg_rs2_out),
        .rd_addr_in(id_reg_rd_out), //reg destination
        .reg_write_data_in(ex_alu_result_out), //output from ALU
        .reg_write_enable(reg_write_control), //enable from control logic

        .regA_data_out(regA_data_out),
        .regB_data_out(regB_data_out)
);

//===============ALU (EXECUTE STAGE)============================
logic [63:0]    ex_alu_result_out;
logic [63:0]    ex_operand_2_in;

assign ex_operand_2_in = alu_src_control ? id_reg_imm_out : regB_data_out; //select imm or rs2 depends on the instruction - Bsel

ALU     ALU(
        .ex_operand1_in(regA_data_out), // R[rs1]
        .ex_operand2_in(ex_operand_2_in),
        .ex_alu_op_in(id_alu_op_out),
        .ex_alu_result_out(ex_alu_result_out)
);

//===============MEMORY============================
// Initialization
initial begin
   $display("Initializing top, entry point = 0x%x", entry);
end



endmodule
