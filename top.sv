`include "Sysbus.defs"
`include "fetch.sv"
//`include "pipeline_reg.sv"
`include "decode.sv"
`include "reg_file.sv"
`include "control_logic.sv"
`include "alu.sv"
`include "dmem.sv"
`include "branch_compare.sv"
//`include "pc_control.sv"

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


//============PC CONTROL (FETCH STAGE (output) + EX STAGE(input))============================
// logic [63:0]    pc_control_pc_fetch;

// PCControl       PCControl(
//         .clk(clk),
//         .entry(entry),
//         .reset(reset),
//         .pc_from_alu_result(ex_alu_result_out),
//         .pcsel(pc_sel_out),

//         .pc_fetch(pc_control_pc_fetch),
//         //.next_pc_fetch,
// );
//============FETCH (FETCH STAGE)============================================================
logic [31:0] if_instr;
logic [63:0] if_address_out; 
// always_comb begin
//     case (pcSel)
//         PC_4:     pc_next = pc + 4;
//         PC_BR:    pc_next = pc_branch_target; // e.g., PC + imm (B-type)
//         PC_JAL:   pc_next = pc_jal_target;    // e.g., PC + imm (J-type)
//         PC_JALR:  pc_next = pc_jalr_target;   // e.g., rs1 + imm
//     endcase
// end


Fetch fetch_inst (
        .clk            (clk),
        .reset          (reset),
        .entry          (entry),
        .pc_from_alu_result(ex_alu_result_out),
        .pcsel          (pc_sel_out),

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
        .id_reg_funct3_out(id_reg_funct3_out),
        .id_alu_op_out(id_alu_op_out)
);

//===============CONTROL LOGIC=======================
logic reg_write_control;          // control signal to write to register
logic mem_read_control;           // control signal for memory read
logic mem_write_control;          // control signal for memory write
logic alu_operand1_control;
logic alu_operand2_control;            // ALU source control signal - use for when ALU need imm or rs2
logic mem_to_reg_control;
logic pc_sel_out;

ControlUnit ControlUnit(
        .if_opcode(id_reg_opcode_out),
        .branch_compare_result(id_branch_compare_result), //for B-type instruction

        .reg_write_control(reg_write_control),
        .mem_read_control(mem_read_control),
        .mem_write_control(mem_write_control),
        .alu_operand1_control_out(alu_operand1_control),
        .alu_operand2_control_out(alu_operand2_control),
        .mem_to_reg_control(mem_to_reg_control),
        .pc_sel_out(pc_sel_out)
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
        .reg_write_data_in(write_back_data), //output from ALU OR data_read of MEM stage OR  => mux can be checked at MEM stage
        .reg_write_enable(reg_write_control), //enable from control logic

        .regA_data_out(regA_data_out),
        .regB_data_out(regB_data_out)
);

//===============BRANCH COMPARE FOR B-TYPE INSTRUCTION  (DECODE STAGE)==========
logic   id_branch_compare_result;

BranchCompare BranchCompare(
        .branch_compare_regA_data(regA_data_out),
        .branch_compare_regB_data(regB_data_out),
        .branch_compare_opcode(id_reg_opcode_out),
        .branch_compare_funct3(id_reg_funct3_out),

        .branch_compare_result(id_branch_compare_result)
);

//if id_branch_compare_result = 1 then pcsel = pc + imm, else pc = pc + 4
//===============ALU (EXECUTE STAGE)============================================
logic [63:0]    ex_operand_1_in;
logic [63:0]    ex_operand_2_in;

//first mux to choose either pc (B-type) or regA_data (I/S-type)
assign ex_operand_1_in = alu_operand1_control? if_address_out: regA_data_out; ///for B-type re-route datapath with alu_result to pccontrol before fetching

//second mux to choose either imm (I-type) or regB_data (R-type)
assign ex_operand_2_in = alu_operand2_control? id_reg_imm_out : regB_data_out; //select imm or rs2 depends on the instruction - Bsel

ALU     ALU(
        .ex_operand1_in(ex_operand_1_in), // R[rs1]
        .ex_operand2_in(ex_operand_2_in),
        .ex_alu_op_in(id_alu_op_out),
        .ex_alu_result_out(ex_alu_result_out)
);

//===============MEMORY (MEMORY STAGE)============================
logic [63:0] ex_mem_read_data_out;


Dmem    D_MEMORY(
        .clk(clk),
        .reset(reset),
        .ex_mem_address(ex_alu_result_out),
        .ex_mem_write_data(regB_data_out),
        .ex_mem_memory_write(mem_write_control), //from control logic
        .ex_mem_memory_read(mem_read_control), //from control logic

        .ex_mem_read_data_out(ex_mem_read_data_out)
);
//===============WRITE BACK STAGE============================
//at this point, to input back to rd in reg_file, we need to choose either ex_mem_read_data_out or ex_alu_result_out
// logic [63:0] write_back_data;
// assign write_back_data = mem_to_reg_control ? ex_mem_read_data_out : ex_alu_result_out;
//                              //(from control logic)
logic [63:0] write_back_data;
assign write_back_data = 
    (mem_to_reg_control == 2'b00) ? ex_alu_result_out :
    (mem_to_reg_control == 2'b01) ? ex_mem_read_data_out :
    (mem_to_reg_control == 2'b10) ? if_address_out + 4 :
    (mem_to_reg_control == 2'b11) ? 64'b0:
    64'b0;
/////////////////////////////////////////////////////////////////////////


// Initialization
initial begin
   $display("Initializing top, entry point = 0x%x", entry);
end



endmodule
