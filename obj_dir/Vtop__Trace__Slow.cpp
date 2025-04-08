// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) vl_fatal(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name()); // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+108,"clk",-1);
	vcdp->declBit  (c+109,"reset",-1);
	vcdp->declBit  (c+110,"hz32768timer",-1);
	vcdp->declQuad (c+111,"entry",-1,63,0);
	vcdp->declQuad (c+113,"stackptr",-1,63,0);
	vcdp->declQuad (c+115,"satp",-1,63,0);
	vcdp->declBus  (c+117,"m_axi_awid",-1,12,0);
	vcdp->declQuad (c+118,"m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+120,"m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+121,"m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+122,"m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+123,"m_axi_awlock",-1);
	vcdp->declBus  (c+124,"m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+125,"m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+126,"m_axi_awvalid",-1);
	vcdp->declBit  (c+127,"m_axi_awready",-1);
	vcdp->declQuad (c+128,"m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+130,"m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+131,"m_axi_wlast",-1);
	vcdp->declBit  (c+132,"m_axi_wvalid",-1);
	vcdp->declBit  (c+133,"m_axi_wready",-1);
	vcdp->declBus  (c+134,"m_axi_bid",-1,12,0);
	vcdp->declBus  (c+135,"m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+136,"m_axi_bvalid",-1);
	vcdp->declBit  (c+137,"m_axi_bready",-1);
	vcdp->declBus  (c+138,"m_axi_arid",-1,12,0);
	vcdp->declQuad (c+139,"m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+141,"m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+142,"m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+143,"m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+144,"m_axi_arlock",-1);
	vcdp->declBus  (c+145,"m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+146,"m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+147,"m_axi_arvalid",-1);
	vcdp->declBit  (c+148,"m_axi_arready",-1);
	vcdp->declBus  (c+149,"m_axi_rid",-1,12,0);
	vcdp->declQuad (c+150,"m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+152,"m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+153,"m_axi_rlast",-1);
	vcdp->declBit  (c+154,"m_axi_rvalid",-1);
	vcdp->declBit  (c+155,"m_axi_rready",-1);
	vcdp->declBit  (c+156,"m_axi_acvalid",-1);
	vcdp->declBit  (c+157,"m_axi_acready",-1);
	vcdp->declQuad (c+158,"m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+160,"m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+161,"top ID_WIDTH",-1,31,0);
	vcdp->declBus  (c+162,"top ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+162,"top DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+163,"top STRB_WIDTH",-1,31,0);
	vcdp->declBit  (c+108,"top clk",-1);
	vcdp->declBit  (c+109,"top reset",-1);
	vcdp->declBit  (c+110,"top hz32768timer",-1);
	vcdp->declQuad (c+111,"top entry",-1,63,0);
	vcdp->declQuad (c+113,"top stackptr",-1,63,0);
	vcdp->declQuad (c+115,"top satp",-1,63,0);
	vcdp->declBus  (c+117,"top m_axi_awid",-1,12,0);
	vcdp->declQuad (c+118,"top m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+120,"top m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+121,"top m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+122,"top m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+123,"top m_axi_awlock",-1);
	vcdp->declBus  (c+124,"top m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+125,"top m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+126,"top m_axi_awvalid",-1);
	vcdp->declBit  (c+127,"top m_axi_awready",-1);
	vcdp->declQuad (c+128,"top m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+130,"top m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+131,"top m_axi_wlast",-1);
	vcdp->declBit  (c+132,"top m_axi_wvalid",-1);
	vcdp->declBit  (c+133,"top m_axi_wready",-1);
	vcdp->declBus  (c+134,"top m_axi_bid",-1,12,0);
	vcdp->declBus  (c+135,"top m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+136,"top m_axi_bvalid",-1);
	vcdp->declBit  (c+137,"top m_axi_bready",-1);
	vcdp->declBus  (c+138,"top m_axi_arid",-1,12,0);
	vcdp->declQuad (c+139,"top m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+141,"top m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+142,"top m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+143,"top m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+144,"top m_axi_arlock",-1);
	vcdp->declBus  (c+145,"top m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+146,"top m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+147,"top m_axi_arvalid",-1);
	vcdp->declBit  (c+148,"top m_axi_arready",-1);
	vcdp->declBus  (c+149,"top m_axi_rid",-1,12,0);
	vcdp->declQuad (c+150,"top m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+152,"top m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+153,"top m_axi_rlast",-1);
	vcdp->declBit  (c+154,"top m_axi_rvalid",-1);
	vcdp->declBit  (c+155,"top m_axi_rready",-1);
	vcdp->declBit  (c+156,"top m_axi_acvalid",-1);
	vcdp->declBit  (c+157,"top m_axi_acready",-1);
	vcdp->declQuad (c+158,"top m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+160,"top m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+1,"top if_instr",-1,31,0);
	vcdp->declBus  (c+5,"top id_reg_rs1_out",-1,4,0);
	vcdp->declBus  (c+6,"top id_reg_rs2_out",-1,4,0);
	vcdp->declBus  (c+7,"top id_reg_rd_out",-1,4,0);
	vcdp->declBus  (c+8,"top id_reg_imm_signed_out",-1,31,0);
	vcdp->declBus  (c+9,"top id_reg_imm_unsigned_out",-1,31,0);
	vcdp->declBus  (c+10,"top id_reg_opcode_out",-1,6,0);
	vcdp->declBus  (c+11,"top id_reg_funct7_out",-1,6,0);
	vcdp->declBus  (c+164,"top id_reg_funct3_out",-1,2,0);
	vcdp->declBus  (c+12,"top id_alu_op_out",-1,3,0);
	vcdp->declBit  (c+13,"top reg_write_control",-1);
	vcdp->declBit  (c+165,"top mem_read_control",-1);
	vcdp->declBit  (c+166,"top mem_write_control",-1);
	vcdp->declBit  (c+14,"top alu_src_control",-1);
	vcdp->declBit  (c+15,"top mem_to_reg_control",-1);
	vcdp->declQuad (c+16,"top regA_data_out",-1,63,0);
	vcdp->declQuad (c+18,"top regB_data_out",-1,63,0);
	vcdp->declQuad (c+167,"top ex_alu_result_out",-1,63,0);
	vcdp->declQuad (c+20,"top ex_operand_2_in",-1,63,0);
	vcdp->declBit  (c+22,"top ex_alu_result",-1);
	vcdp->declBit  (c+108,"top fetch_inst clk",-1);
	vcdp->declBit  (c+109,"top fetch_inst reset",-1);
	vcdp->declQuad (c+111,"top fetch_inst entry",-1,63,0);
	vcdp->declQuad (c+139,"top fetch_inst m_axi_araddr",-1,63,0);
	vcdp->declBit  (c+147,"top fetch_inst m_axi_arvalid",-1);
	vcdp->declBit  (c+148,"top fetch_inst m_axi_arready",-1);
	vcdp->declBus  (c+141,"top fetch_inst m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+142,"top fetch_inst m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+143,"top fetch_inst m_axi_arburst",-1,1,0);
	vcdp->declQuad (c+150,"top fetch_inst m_axi_rdata",-1,63,0);
	vcdp->declBit  (c+154,"top fetch_inst m_axi_rvalid",-1);
	vcdp->declBit  (c+155,"top fetch_inst m_axi_rready",-1);
	vcdp->declBit  (c+153,"top fetch_inst m_axi_rlast",-1);
	vcdp->declBus  (c+1,"top fetch_inst if_instr",-1,31,0);
	vcdp->declBus  (c+32,"top fetch_inst state",-1,2,0);
	vcdp->declBus  (c+2,"top fetch_inst next_state",-1,2,0);
	vcdp->declQuad (c+33,"top fetch_inst pc",-1,63,0);
	vcdp->declQuad (c+3,"top fetch_inst next_pc",-1,63,0);
	vcdp->declQuad (c+35,"top fetch_inst fetched_instr",-1,63,0);
	vcdp->declQuad (c+37,"top fetch_inst display_addr",-1,63,0);
	vcdp->declQuad (c+39,"top fetch_inst next_display_addr",-1,63,0);
	// Tracing: top fetch_inst instruction_array // Ignored: Wide memory > --trace-max-array ents at fetch.sv:37
	vcdp->declBus  (c+41,"top fetch_inst index",-1,9,0);
	vcdp->declBus  (c+42,"top fetch_inst pc_fetch",-1,9,0);
	vcdp->declBus  (c+1,"top Decoder input_bin",-1,31,0);
	vcdp->declBus  (c+169,"top Decoder address",-1,31,0);
	vcdp->declBus  (c+5,"top Decoder id_reg_rs1_out",-1,4,0);
	vcdp->declBus  (c+6,"top Decoder id_reg_rs2_out",-1,4,0);
	vcdp->declBus  (c+7,"top Decoder id_reg_rd_out",-1,4,0);
	vcdp->declBus  (c+8,"top Decoder id_reg_imm_signed_out",-1,31,0);
	vcdp->declBus  (c+9,"top Decoder id_reg_imm_unsigned_out",-1,31,0);
	vcdp->declBus  (c+10,"top Decoder id_reg_opcode_out",-1,6,0);
	vcdp->declBus  (c+11,"top Decoder id_reg_funct7_out",-1,6,0);
	vcdp->declBus  (c+23,"top Decoder id_reg_funct3_out",-1,2,0);
	vcdp->declBus  (c+12,"top Decoder id_alu_op_out",-1,3,0);
	vcdp->declBus  (c+5,"top Decoder rs1",-1,4,0);
	vcdp->declBus  (c+6,"top Decoder rs2",-1,4,0);
	vcdp->declBus  (c+7,"top Decoder rd",-1,4,0);
	vcdp->declBus  (c+10,"top Decoder opcode",-1,6,0);
	vcdp->declBus  (c+24,"top Decoder funct7",-1,6,0);
	vcdp->declBus  (c+23,"top Decoder funct3",-1,2,0);
	vcdp->declBus  (c+8,"top Decoder imm_signed",-1,31,0);
	vcdp->declBus  (c+9,"top Decoder imm_unsigned",-1,31,0);
	vcdp->declQuad (c+25,"top Decoder decoded_instruction",-1,63,0);
	vcdp->declBus  (c+12,"top Decoder alu_op",-1,3,0);
	vcdp->declBus  (c+1,"top ControlUnit if_instr",-1,31,0);
	vcdp->declBit  (c+13,"top ControlUnit reg_write_control",-1);
	vcdp->declBit  (c+27,"top ControlUnit mem_read_control",-1);
	vcdp->declBit  (c+28,"top ControlUnit mem_write_control",-1);
	vcdp->declBit  (c+14,"top ControlUnit alu_src_control",-1);
	vcdp->declBit  (c+15,"top ControlUnit mem_to_reg_control",-1);
	vcdp->declBus  (c+29,"top ControlUnit opcode",-1,6,0);
	vcdp->declBus  (c+170,"top ControlUnit funct7",-1,6,0);
	vcdp->declBus  (c+171,"top ControlUnit funct3",-1,2,0);
	vcdp->declBit  (c+13,"top ControlUnit reg_write",-1);
	vcdp->declBit  (c+27,"top ControlUnit mem_read",-1);
	vcdp->declBit  (c+28,"top ControlUnit mem_write",-1);
	vcdp->declBit  (c+14,"top ControlUnit alu_src",-1);
	vcdp->declBit  (c+15,"top ControlUnit mem_to_reg",-1);
	vcdp->declBit  (c+108,"top RegisterFile clk",-1);
	vcdp->declBit  (c+109,"top RegisterFile reset",-1);
	vcdp->declBus  (c+5,"top RegisterFile regA_addr_in",-1,4,0);
	vcdp->declBus  (c+6,"top RegisterFile regB_addr_in",-1,4,0);
	vcdp->declBus  (c+7,"top RegisterFile rd_addr_in",-1,4,0);
	vcdp->declQuad (c+172,"top RegisterFile reg_write_data_in",-1,63,0);
	vcdp->declBit  (c+174,"top RegisterFile reg_write_enable",-1);
	vcdp->declQuad (c+16,"top RegisterFile regA_data_out",-1,63,0);
	vcdp->declQuad (c+18,"top RegisterFile regB_data_out",-1,63,0);
	{int i; for (i=0; i<32; i++) {
		vcdp->declQuad (c+43+i*2,"top RegisterFile registers",(i+0),63,0);}}
	vcdp->declBus  (c+107,"top RegisterFile i",-1,31,0);
	vcdp->declQuad (c+16,"top ALU ex_operand1_in",-1,63,0);
	vcdp->declQuad (c+20,"top ALU ex_operand2_in",-1,63,0);
	vcdp->declBus  (c+12,"top ALU ex_alu_op_in",-1,3,0);
	vcdp->declQuad (c+30,"top ALU ex_alu_result_out",-1,63,0);
	vcdp->declQuad (c+30,"top ALU result",-1,63,0);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->top__DOT__if_instr),32);
	vcdp->fullBus  (c+2,(vlTOPp->top__DOT__fetch_inst__DOT__next_state),3);
	vcdp->fullQuad (c+3,(vlTOPp->top__DOT__fetch_inst__DOT__next_pc),64);
	vcdp->fullBus  (c+5,(vlTOPp->top__DOT__Decoder__DOT__rs1),5);
	vcdp->fullBus  (c+6,(vlTOPp->top__DOT__Decoder__DOT__rs2),5);
	vcdp->fullBus  (c+7,(vlTOPp->top__DOT__Decoder__DOT__rd),5);
	vcdp->fullBus  (c+8,(vlTOPp->top__DOT__Decoder__DOT__imm_signed),32);
	vcdp->fullBus  (c+9,(vlTOPp->top__DOT__Decoder__DOT__imm_unsigned),32);
	vcdp->fullBus  (c+10,(vlTOPp->top__DOT__Decoder__DOT__opcode),7);
	vcdp->fullBus  (c+11,(vlTOPp->top__DOT__id_reg_funct7_out),7);
	vcdp->fullBus  (c+12,(vlTOPp->top__DOT__Decoder__DOT__alu_op),4);
	vcdp->fullBit  (c+13,(vlTOPp->top__DOT__ControlUnit__DOT__reg_write));
	vcdp->fullBit  (c+14,(vlTOPp->top__DOT__ControlUnit__DOT__alu_src));
	vcdp->fullBit  (c+15,(vlTOPp->top__DOT__ControlUnit__DOT__mem_to_reg));
	vcdp->fullQuad (c+16,(vlTOPp->top__DOT__regA_data_out),64);
	vcdp->fullQuad (c+18,(vlTOPp->top__DOT__regB_data_out),64);
	vcdp->fullQuad (c+20,(vlTOPp->top__DOT__ex_operand_2_in),64);
	vcdp->fullBit  (c+22,((1U & (IData)(vlTOPp->top__DOT__ALU__DOT__result))));
	vcdp->fullBus  (c+23,(vlTOPp->top__DOT__Decoder__DOT__funct3),3);
	vcdp->fullBus  (c+24,(vlTOPp->top__DOT__Decoder__DOT__funct7),7);
	vcdp->fullQuad (c+25,(vlTOPp->top__DOT__Decoder__DOT__decoded_instruction),64);
	vcdp->fullBit  (c+27,(vlTOPp->top__DOT__ControlUnit__DOT__mem_read));
	vcdp->fullBit  (c+28,(vlTOPp->top__DOT__ControlUnit__DOT__mem_write));
	vcdp->fullBus  (c+29,(vlTOPp->top__DOT__ControlUnit__DOT__opcode),7);
	vcdp->fullQuad (c+30,(vlTOPp->top__DOT__ALU__DOT__result),64);
	vcdp->fullBus  (c+32,(vlTOPp->top__DOT__fetch_inst__DOT__state),3);
	vcdp->fullQuad (c+33,(vlTOPp->top__DOT__fetch_inst__DOT__pc),64);
	vcdp->fullQuad (c+35,(vlTOPp->top__DOT__fetch_inst__DOT__fetched_instr),64);
	vcdp->fullQuad (c+37,(vlTOPp->top__DOT__fetch_inst__DOT__display_addr),64);
	vcdp->fullQuad (c+39,(vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr),64);
	vcdp->fullBus  (c+41,(vlTOPp->top__DOT__fetch_inst__DOT__index),10);
	vcdp->fullBus  (c+42,(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch),10);
	vcdp->fullQuad (c+43,(vlTOPp->top__DOT__RegisterFile__DOT__registers[0]),64);
	vcdp->fullQuad (c+45,(vlTOPp->top__DOT__RegisterFile__DOT__registers[1]),64);
	vcdp->fullQuad (c+47,(vlTOPp->top__DOT__RegisterFile__DOT__registers[2]),64);
	vcdp->fullQuad (c+49,(vlTOPp->top__DOT__RegisterFile__DOT__registers[3]),64);
	vcdp->fullQuad (c+51,(vlTOPp->top__DOT__RegisterFile__DOT__registers[4]),64);
	vcdp->fullQuad (c+53,(vlTOPp->top__DOT__RegisterFile__DOT__registers[5]),64);
	vcdp->fullQuad (c+55,(vlTOPp->top__DOT__RegisterFile__DOT__registers[6]),64);
	vcdp->fullQuad (c+57,(vlTOPp->top__DOT__RegisterFile__DOT__registers[7]),64);
	vcdp->fullQuad (c+59,(vlTOPp->top__DOT__RegisterFile__DOT__registers[8]),64);
	vcdp->fullQuad (c+61,(vlTOPp->top__DOT__RegisterFile__DOT__registers[9]),64);
	vcdp->fullQuad (c+63,(vlTOPp->top__DOT__RegisterFile__DOT__registers[10]),64);
	vcdp->fullQuad (c+65,(vlTOPp->top__DOT__RegisterFile__DOT__registers[11]),64);
	vcdp->fullQuad (c+67,(vlTOPp->top__DOT__RegisterFile__DOT__registers[12]),64);
	vcdp->fullQuad (c+69,(vlTOPp->top__DOT__RegisterFile__DOT__registers[13]),64);
	vcdp->fullQuad (c+71,(vlTOPp->top__DOT__RegisterFile__DOT__registers[14]),64);
	vcdp->fullQuad (c+73,(vlTOPp->top__DOT__RegisterFile__DOT__registers[15]),64);
	vcdp->fullQuad (c+75,(vlTOPp->top__DOT__RegisterFile__DOT__registers[16]),64);
	vcdp->fullQuad (c+77,(vlTOPp->top__DOT__RegisterFile__DOT__registers[17]),64);
	vcdp->fullQuad (c+79,(vlTOPp->top__DOT__RegisterFile__DOT__registers[18]),64);
	vcdp->fullQuad (c+81,(vlTOPp->top__DOT__RegisterFile__DOT__registers[19]),64);
	vcdp->fullQuad (c+83,(vlTOPp->top__DOT__RegisterFile__DOT__registers[20]),64);
	vcdp->fullQuad (c+85,(vlTOPp->top__DOT__RegisterFile__DOT__registers[21]),64);
	vcdp->fullQuad (c+87,(vlTOPp->top__DOT__RegisterFile__DOT__registers[22]),64);
	vcdp->fullQuad (c+89,(vlTOPp->top__DOT__RegisterFile__DOT__registers[23]),64);
	vcdp->fullQuad (c+91,(vlTOPp->top__DOT__RegisterFile__DOT__registers[24]),64);
	vcdp->fullQuad (c+93,(vlTOPp->top__DOT__RegisterFile__DOT__registers[25]),64);
	vcdp->fullQuad (c+95,(vlTOPp->top__DOT__RegisterFile__DOT__registers[26]),64);
	vcdp->fullQuad (c+97,(vlTOPp->top__DOT__RegisterFile__DOT__registers[27]),64);
	vcdp->fullQuad (c+99,(vlTOPp->top__DOT__RegisterFile__DOT__registers[28]),64);
	vcdp->fullQuad (c+101,(vlTOPp->top__DOT__RegisterFile__DOT__registers[29]),64);
	vcdp->fullQuad (c+103,(vlTOPp->top__DOT__RegisterFile__DOT__registers[30]),64);
	vcdp->fullQuad (c+105,(vlTOPp->top__DOT__RegisterFile__DOT__registers[31]),64);
	vcdp->fullBus  (c+107,(vlTOPp->top__DOT__RegisterFile__DOT__i),32);
	vcdp->fullBit  (c+108,(vlTOPp->clk));
	vcdp->fullBit  (c+109,(vlTOPp->reset));
	vcdp->fullBit  (c+110,(vlTOPp->hz32768timer));
	vcdp->fullQuad (c+111,(vlTOPp->entry),64);
	vcdp->fullQuad (c+113,(vlTOPp->stackptr),64);
	vcdp->fullQuad (c+115,(vlTOPp->satp),64);
	vcdp->fullBus  (c+117,(vlTOPp->m_axi_awid),13);
	vcdp->fullQuad (c+118,(vlTOPp->m_axi_awaddr),64);
	vcdp->fullBus  (c+120,(vlTOPp->m_axi_awlen),8);
	vcdp->fullBus  (c+121,(vlTOPp->m_axi_awsize),3);
	vcdp->fullBus  (c+122,(vlTOPp->m_axi_awburst),2);
	vcdp->fullBit  (c+123,(vlTOPp->m_axi_awlock));
	vcdp->fullBus  (c+124,(vlTOPp->m_axi_awcache),4);
	vcdp->fullBus  (c+125,(vlTOPp->m_axi_awprot),3);
	vcdp->fullBit  (c+126,(vlTOPp->m_axi_awvalid));
	vcdp->fullBit  (c+127,(vlTOPp->m_axi_awready));
	vcdp->fullQuad (c+128,(vlTOPp->m_axi_wdata),64);
	vcdp->fullBus  (c+130,(vlTOPp->m_axi_wstrb),8);
	vcdp->fullBit  (c+131,(vlTOPp->m_axi_wlast));
	vcdp->fullBit  (c+132,(vlTOPp->m_axi_wvalid));
	vcdp->fullBit  (c+133,(vlTOPp->m_axi_wready));
	vcdp->fullBus  (c+134,(vlTOPp->m_axi_bid),13);
	vcdp->fullBus  (c+135,(vlTOPp->m_axi_bresp),2);
	vcdp->fullBit  (c+136,(vlTOPp->m_axi_bvalid));
	vcdp->fullBit  (c+137,(vlTOPp->m_axi_bready));
	vcdp->fullBus  (c+138,(vlTOPp->m_axi_arid),13);
	vcdp->fullQuad (c+139,(vlTOPp->m_axi_araddr),64);
	vcdp->fullBus  (c+141,(vlTOPp->m_axi_arlen),8);
	vcdp->fullBus  (c+142,(vlTOPp->m_axi_arsize),3);
	vcdp->fullBus  (c+143,(vlTOPp->m_axi_arburst),2);
	vcdp->fullBit  (c+144,(vlTOPp->m_axi_arlock));
	vcdp->fullBus  (c+145,(vlTOPp->m_axi_arcache),4);
	vcdp->fullBus  (c+146,(vlTOPp->m_axi_arprot),3);
	vcdp->fullBit  (c+147,(vlTOPp->m_axi_arvalid));
	vcdp->fullBit  (c+148,(vlTOPp->m_axi_arready));
	vcdp->fullBus  (c+149,(vlTOPp->m_axi_rid),13);
	vcdp->fullQuad (c+150,(vlTOPp->m_axi_rdata),64);
	vcdp->fullBus  (c+152,(vlTOPp->m_axi_rresp),2);
	vcdp->fullBit  (c+153,(vlTOPp->m_axi_rlast));
	vcdp->fullBit  (c+154,(vlTOPp->m_axi_rvalid));
	vcdp->fullBit  (c+155,(vlTOPp->m_axi_rready));
	vcdp->fullBit  (c+156,(vlTOPp->m_axi_acvalid));
	vcdp->fullBit  (c+157,(vlTOPp->m_axi_acready));
	vcdp->fullQuad (c+158,(vlTOPp->m_axi_acaddr),64);
	vcdp->fullBus  (c+160,(vlTOPp->m_axi_acsnoop),4);
	vcdp->fullBus  (c+161,(0xdU),32);
	vcdp->fullBus  (c+162,(0x40U),32);
	vcdp->fullBus  (c+163,(8U),32);
	vcdp->fullBus  (c+164,(vlTOPp->top__DOT__id_reg_funct3_out),3);
	vcdp->fullBit  (c+165,(vlTOPp->top__DOT__mem_read_control));
	vcdp->fullBit  (c+166,(vlTOPp->top__DOT__mem_write_control));
	vcdp->fullQuad (c+167,(vlTOPp->top__DOT__ex_alu_result_out),64);
	vcdp->fullBus  (c+169,(vlTOPp->top__DOT__Decoder__DOT__address),32);
	vcdp->fullBus  (c+170,(vlTOPp->top__DOT__ControlUnit__DOT__funct7),7);
	vcdp->fullBus  (c+171,(vlTOPp->top__DOT__ControlUnit__DOT__funct3),3);
	vcdp->fullQuad (c+172,(vlTOPp->top__DOT__RegisterFile__DOT__reg_write_data_in),64);
	vcdp->fullBit  (c+174,(vlTOPp->top__DOT__RegisterFile__DOT__reg_write_enable));
    }
}
