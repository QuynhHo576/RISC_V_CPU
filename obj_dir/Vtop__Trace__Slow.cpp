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
	vcdp->declBit  (c+103,"clk",-1);
	vcdp->declBit  (c+104,"reset",-1);
	vcdp->declBit  (c+105,"hz32768timer",-1);
	vcdp->declQuad (c+106,"entry",-1,63,0);
	vcdp->declQuad (c+108,"stackptr",-1,63,0);
	vcdp->declQuad (c+110,"satp",-1,63,0);
	vcdp->declBus  (c+112,"m_axi_awid",-1,12,0);
	vcdp->declQuad (c+113,"m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+115,"m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+116,"m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+117,"m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+118,"m_axi_awlock",-1);
	vcdp->declBus  (c+119,"m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+120,"m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+121,"m_axi_awvalid",-1);
	vcdp->declBit  (c+122,"m_axi_awready",-1);
	vcdp->declQuad (c+123,"m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+125,"m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+126,"m_axi_wlast",-1);
	vcdp->declBit  (c+127,"m_axi_wvalid",-1);
	vcdp->declBit  (c+128,"m_axi_wready",-1);
	vcdp->declBus  (c+129,"m_axi_bid",-1,12,0);
	vcdp->declBus  (c+130,"m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+131,"m_axi_bvalid",-1);
	vcdp->declBit  (c+132,"m_axi_bready",-1);
	vcdp->declBus  (c+133,"m_axi_arid",-1,12,0);
	vcdp->declQuad (c+134,"m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+136,"m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+137,"m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+138,"m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+139,"m_axi_arlock",-1);
	vcdp->declBus  (c+140,"m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+141,"m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+142,"m_axi_arvalid",-1);
	vcdp->declBit  (c+143,"m_axi_arready",-1);
	vcdp->declBus  (c+144,"m_axi_rid",-1,12,0);
	vcdp->declQuad (c+145,"m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+147,"m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+148,"m_axi_rlast",-1);
	vcdp->declBit  (c+149,"m_axi_rvalid",-1);
	vcdp->declBit  (c+150,"m_axi_rready",-1);
	vcdp->declBit  (c+151,"m_axi_acvalid",-1);
	vcdp->declBit  (c+152,"m_axi_acready",-1);
	vcdp->declQuad (c+153,"m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+155,"m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+156,"top ID_WIDTH",-1,31,0);
	vcdp->declBus  (c+157,"top ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+157,"top DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+158,"top STRB_WIDTH",-1,31,0);
	vcdp->declBit  (c+103,"top clk",-1);
	vcdp->declBit  (c+104,"top reset",-1);
	vcdp->declBit  (c+105,"top hz32768timer",-1);
	vcdp->declQuad (c+106,"top entry",-1,63,0);
	vcdp->declQuad (c+108,"top stackptr",-1,63,0);
	vcdp->declQuad (c+110,"top satp",-1,63,0);
	vcdp->declBus  (c+112,"top m_axi_awid",-1,12,0);
	vcdp->declQuad (c+113,"top m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+115,"top m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+116,"top m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+117,"top m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+118,"top m_axi_awlock",-1);
	vcdp->declBus  (c+119,"top m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+120,"top m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+121,"top m_axi_awvalid",-1);
	vcdp->declBit  (c+122,"top m_axi_awready",-1);
	vcdp->declQuad (c+123,"top m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+125,"top m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+126,"top m_axi_wlast",-1);
	vcdp->declBit  (c+127,"top m_axi_wvalid",-1);
	vcdp->declBit  (c+128,"top m_axi_wready",-1);
	vcdp->declBus  (c+129,"top m_axi_bid",-1,12,0);
	vcdp->declBus  (c+130,"top m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+131,"top m_axi_bvalid",-1);
	vcdp->declBit  (c+132,"top m_axi_bready",-1);
	vcdp->declBus  (c+133,"top m_axi_arid",-1,12,0);
	vcdp->declQuad (c+134,"top m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+136,"top m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+137,"top m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+138,"top m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+139,"top m_axi_arlock",-1);
	vcdp->declBus  (c+140,"top m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+141,"top m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+142,"top m_axi_arvalid",-1);
	vcdp->declBit  (c+143,"top m_axi_arready",-1);
	vcdp->declBus  (c+144,"top m_axi_rid",-1,12,0);
	vcdp->declQuad (c+145,"top m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+147,"top m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+148,"top m_axi_rlast",-1);
	vcdp->declBit  (c+149,"top m_axi_rvalid",-1);
	vcdp->declBit  (c+150,"top m_axi_rready",-1);
	vcdp->declBit  (c+151,"top m_axi_acvalid",-1);
	vcdp->declBit  (c+152,"top m_axi_acready",-1);
	vcdp->declQuad (c+153,"top m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+155,"top m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+1,"top if_instr",-1,31,0);
	vcdp->declBus  (c+5,"top id_reg_rs1_out",-1,4,0);
	vcdp->declBus  (c+6,"top id_reg_rs2_out",-1,4,0);
	vcdp->declBus  (c+7,"top id_reg_rd_out",-1,4,0);
	vcdp->declBus  (c+8,"top id_reg_imm_signed",-1,31,0);
	vcdp->declBus  (c+9,"top id_reg_imm_unsigned",-1,31,0);
	vcdp->declBus  (c+10,"top id_reg_opcode_out",-1,6,0);
	vcdp->declBus  (c+11,"top id_reg_funct7_out",-1,6,0);
	vcdp->declBus  (c+159,"top id_reg_funct3_out",-1,2,0);
	vcdp->declBus  (c+12,"top id_alu_op_out",-1,3,0);
	vcdp->declBit  (c+13,"top reg_write_control",-1);
	vcdp->declBit  (c+160,"top mem_read_control",-1);
	vcdp->declBit  (c+161,"top mem_write_control",-1);
	vcdp->declBit  (c+14,"top alu_src_control",-1);
	vcdp->declBit  (c+15,"top mem_to_reg_control",-1);
	vcdp->declQuad (c+16,"top regA_data",-1,63,0);
	vcdp->declQuad (c+18,"top regB_data",-1,63,0);
	vcdp->declBit  (c+103,"top fetch_inst clk",-1);
	vcdp->declBit  (c+104,"top fetch_inst reset",-1);
	vcdp->declQuad (c+106,"top fetch_inst entry",-1,63,0);
	vcdp->declQuad (c+134,"top fetch_inst m_axi_araddr",-1,63,0);
	vcdp->declBit  (c+142,"top fetch_inst m_axi_arvalid",-1);
	vcdp->declBit  (c+143,"top fetch_inst m_axi_arready",-1);
	vcdp->declBus  (c+136,"top fetch_inst m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+137,"top fetch_inst m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+138,"top fetch_inst m_axi_arburst",-1,1,0);
	vcdp->declQuad (c+145,"top fetch_inst m_axi_rdata",-1,63,0);
	vcdp->declBit  (c+149,"top fetch_inst m_axi_rvalid",-1);
	vcdp->declBit  (c+150,"top fetch_inst m_axi_rready",-1);
	vcdp->declBit  (c+148,"top fetch_inst m_axi_rlast",-1);
	vcdp->declBus  (c+1,"top fetch_inst if_instr",-1,31,0);
	vcdp->declBus  (c+27,"top fetch_inst state",-1,2,0);
	vcdp->declBus  (c+2,"top fetch_inst next_state",-1,2,0);
	vcdp->declQuad (c+28,"top fetch_inst pc",-1,63,0);
	vcdp->declQuad (c+3,"top fetch_inst next_pc",-1,63,0);
	vcdp->declQuad (c+30,"top fetch_inst fetched_instr",-1,63,0);
	vcdp->declQuad (c+32,"top fetch_inst display_addr",-1,63,0);
	vcdp->declQuad (c+34,"top fetch_inst next_display_addr",-1,63,0);
	// Tracing: top fetch_inst instruction_array // Ignored: Wide memory > --trace-max-array ents at fetch.sv:37
	vcdp->declBus  (c+36,"top fetch_inst index",-1,9,0);
	vcdp->declBus  (c+37,"top fetch_inst pc_fetch",-1,9,0);
	vcdp->declBus  (c+1,"top Decoder input_bin",-1,31,0);
	vcdp->declBus  (c+162,"top Decoder address",-1,31,0);
	vcdp->declBus  (c+5,"top Decoder id_reg_rs1_out",-1,4,0);
	vcdp->declBus  (c+6,"top Decoder id_reg_rs2_out",-1,4,0);
	vcdp->declBus  (c+7,"top Decoder id_reg_rd_out",-1,4,0);
	vcdp->declBus  (c+8,"top Decoder id_reg_imm_signed",-1,31,0);
	vcdp->declBus  (c+9,"top Decoder id_reg_imm_unsigned",-1,31,0);
	vcdp->declBus  (c+10,"top Decoder id_reg_opcode_out",-1,6,0);
	vcdp->declBus  (c+11,"top Decoder id_reg_funct7_out",-1,6,0);
	vcdp->declBus  (c+20,"top Decoder id_reg_funct3_out",-1,2,0);
	vcdp->declBus  (c+12,"top Decoder id_alu_op_out",-1,3,0);
	vcdp->declBus  (c+5,"top Decoder rs1",-1,4,0);
	vcdp->declBus  (c+6,"top Decoder rs2",-1,4,0);
	vcdp->declBus  (c+7,"top Decoder rd",-1,4,0);
	vcdp->declBus  (c+10,"top Decoder opcode",-1,6,0);
	vcdp->declBus  (c+21,"top Decoder funct7",-1,6,0);
	vcdp->declBus  (c+20,"top Decoder funct3",-1,2,0);
	vcdp->declBus  (c+8,"top Decoder imm_signed",-1,31,0);
	vcdp->declBus  (c+9,"top Decoder imm_unsigned",-1,31,0);
	vcdp->declQuad (c+22,"top Decoder decoded_instruction",-1,63,0);
	vcdp->declBus  (c+12,"top Decoder alu_op",-1,3,0);
	vcdp->declBus  (c+1,"top ControlUnit if_instr",-1,31,0);
	vcdp->declBit  (c+13,"top ControlUnit reg_write_control",-1);
	vcdp->declBit  (c+24,"top ControlUnit mem_read_control",-1);
	vcdp->declBit  (c+25,"top ControlUnit mem_write_control",-1);
	vcdp->declBit  (c+14,"top ControlUnit alu_src_control",-1);
	vcdp->declBit  (c+15,"top ControlUnit mem_to_reg_control",-1);
	vcdp->declBus  (c+26,"top ControlUnit opcode",-1,6,0);
	vcdp->declBus  (c+163,"top ControlUnit funct7",-1,6,0);
	vcdp->declBus  (c+164,"top ControlUnit funct3",-1,2,0);
	vcdp->declBit  (c+13,"top ControlUnit reg_write",-1);
	vcdp->declBit  (c+24,"top ControlUnit mem_read",-1);
	vcdp->declBit  (c+25,"top ControlUnit mem_write",-1);
	vcdp->declBit  (c+14,"top ControlUnit alu_src",-1);
	vcdp->declBit  (c+15,"top ControlUnit mem_to_reg",-1);
	vcdp->declBit  (c+103,"top RegisterFile clk",-1);
	vcdp->declBit  (c+104,"top RegisterFile reset",-1);
	vcdp->declBus  (c+5,"top RegisterFile regA_addr",-1,4,0);
	vcdp->declBus  (c+6,"top RegisterFile regB_addr",-1,4,0);
	vcdp->declBus  (c+7,"top RegisterFile rd_addr",-1,4,0);
	vcdp->declQuad (c+165,"top RegisterFile write_data",-1,63,0);
	vcdp->declBit  (c+167,"top RegisterFile reg_write_enable",-1);
	vcdp->declQuad (c+16,"top RegisterFile regA_data",-1,63,0);
	vcdp->declQuad (c+18,"top RegisterFile regB_data",-1,63,0);
	{int i; for (i=0; i<32; i++) {
		vcdp->declQuad (c+38+i*2,"top RegisterFile registers",(i+0),63,0);}}
	vcdp->declBus  (c+102,"top RegisterFile i",-1,31,0);
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
	vcdp->fullQuad (c+16,(vlTOPp->top__DOT__regA_data),64);
	vcdp->fullQuad (c+18,(vlTOPp->top__DOT__regB_data),64);
	vcdp->fullBus  (c+20,(vlTOPp->top__DOT__Decoder__DOT__funct3),3);
	vcdp->fullBus  (c+21,(vlTOPp->top__DOT__Decoder__DOT__funct7),7);
	vcdp->fullQuad (c+22,(vlTOPp->top__DOT__Decoder__DOT__decoded_instruction),64);
	vcdp->fullBit  (c+24,(vlTOPp->top__DOT__ControlUnit__DOT__mem_read));
	vcdp->fullBit  (c+25,(vlTOPp->top__DOT__ControlUnit__DOT__mem_write));
	vcdp->fullBus  (c+26,(vlTOPp->top__DOT__ControlUnit__DOT__opcode),7);
	vcdp->fullBus  (c+27,(vlTOPp->top__DOT__fetch_inst__DOT__state),3);
	vcdp->fullQuad (c+28,(vlTOPp->top__DOT__fetch_inst__DOT__pc),64);
	vcdp->fullQuad (c+30,(vlTOPp->top__DOT__fetch_inst__DOT__fetched_instr),64);
	vcdp->fullQuad (c+32,(vlTOPp->top__DOT__fetch_inst__DOT__display_addr),64);
	vcdp->fullQuad (c+34,(vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr),64);
	vcdp->fullBus  (c+36,(vlTOPp->top__DOT__fetch_inst__DOT__index),10);
	vcdp->fullBus  (c+37,(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch),10);
	vcdp->fullQuad (c+38,(vlTOPp->top__DOT__RegisterFile__DOT__registers[0]),64);
	vcdp->fullQuad (c+40,(vlTOPp->top__DOT__RegisterFile__DOT__registers[1]),64);
	vcdp->fullQuad (c+42,(vlTOPp->top__DOT__RegisterFile__DOT__registers[2]),64);
	vcdp->fullQuad (c+44,(vlTOPp->top__DOT__RegisterFile__DOT__registers[3]),64);
	vcdp->fullQuad (c+46,(vlTOPp->top__DOT__RegisterFile__DOT__registers[4]),64);
	vcdp->fullQuad (c+48,(vlTOPp->top__DOT__RegisterFile__DOT__registers[5]),64);
	vcdp->fullQuad (c+50,(vlTOPp->top__DOT__RegisterFile__DOT__registers[6]),64);
	vcdp->fullQuad (c+52,(vlTOPp->top__DOT__RegisterFile__DOT__registers[7]),64);
	vcdp->fullQuad (c+54,(vlTOPp->top__DOT__RegisterFile__DOT__registers[8]),64);
	vcdp->fullQuad (c+56,(vlTOPp->top__DOT__RegisterFile__DOT__registers[9]),64);
	vcdp->fullQuad (c+58,(vlTOPp->top__DOT__RegisterFile__DOT__registers[10]),64);
	vcdp->fullQuad (c+60,(vlTOPp->top__DOT__RegisterFile__DOT__registers[11]),64);
	vcdp->fullQuad (c+62,(vlTOPp->top__DOT__RegisterFile__DOT__registers[12]),64);
	vcdp->fullQuad (c+64,(vlTOPp->top__DOT__RegisterFile__DOT__registers[13]),64);
	vcdp->fullQuad (c+66,(vlTOPp->top__DOT__RegisterFile__DOT__registers[14]),64);
	vcdp->fullQuad (c+68,(vlTOPp->top__DOT__RegisterFile__DOT__registers[15]),64);
	vcdp->fullQuad (c+70,(vlTOPp->top__DOT__RegisterFile__DOT__registers[16]),64);
	vcdp->fullQuad (c+72,(vlTOPp->top__DOT__RegisterFile__DOT__registers[17]),64);
	vcdp->fullQuad (c+74,(vlTOPp->top__DOT__RegisterFile__DOT__registers[18]),64);
	vcdp->fullQuad (c+76,(vlTOPp->top__DOT__RegisterFile__DOT__registers[19]),64);
	vcdp->fullQuad (c+78,(vlTOPp->top__DOT__RegisterFile__DOT__registers[20]),64);
	vcdp->fullQuad (c+80,(vlTOPp->top__DOT__RegisterFile__DOT__registers[21]),64);
	vcdp->fullQuad (c+82,(vlTOPp->top__DOT__RegisterFile__DOT__registers[22]),64);
	vcdp->fullQuad (c+84,(vlTOPp->top__DOT__RegisterFile__DOT__registers[23]),64);
	vcdp->fullQuad (c+86,(vlTOPp->top__DOT__RegisterFile__DOT__registers[24]),64);
	vcdp->fullQuad (c+88,(vlTOPp->top__DOT__RegisterFile__DOT__registers[25]),64);
	vcdp->fullQuad (c+90,(vlTOPp->top__DOT__RegisterFile__DOT__registers[26]),64);
	vcdp->fullQuad (c+92,(vlTOPp->top__DOT__RegisterFile__DOT__registers[27]),64);
	vcdp->fullQuad (c+94,(vlTOPp->top__DOT__RegisterFile__DOT__registers[28]),64);
	vcdp->fullQuad (c+96,(vlTOPp->top__DOT__RegisterFile__DOT__registers[29]),64);
	vcdp->fullQuad (c+98,(vlTOPp->top__DOT__RegisterFile__DOT__registers[30]),64);
	vcdp->fullQuad (c+100,(vlTOPp->top__DOT__RegisterFile__DOT__registers[31]),64);
	vcdp->fullBus  (c+102,(vlTOPp->top__DOT__RegisterFile__DOT__i),32);
	vcdp->fullBit  (c+103,(vlTOPp->clk));
	vcdp->fullBit  (c+104,(vlTOPp->reset));
	vcdp->fullBit  (c+105,(vlTOPp->hz32768timer));
	vcdp->fullQuad (c+106,(vlTOPp->entry),64);
	vcdp->fullQuad (c+108,(vlTOPp->stackptr),64);
	vcdp->fullQuad (c+110,(vlTOPp->satp),64);
	vcdp->fullBus  (c+112,(vlTOPp->m_axi_awid),13);
	vcdp->fullQuad (c+113,(vlTOPp->m_axi_awaddr),64);
	vcdp->fullBus  (c+115,(vlTOPp->m_axi_awlen),8);
	vcdp->fullBus  (c+116,(vlTOPp->m_axi_awsize),3);
	vcdp->fullBus  (c+117,(vlTOPp->m_axi_awburst),2);
	vcdp->fullBit  (c+118,(vlTOPp->m_axi_awlock));
	vcdp->fullBus  (c+119,(vlTOPp->m_axi_awcache),4);
	vcdp->fullBus  (c+120,(vlTOPp->m_axi_awprot),3);
	vcdp->fullBit  (c+121,(vlTOPp->m_axi_awvalid));
	vcdp->fullBit  (c+122,(vlTOPp->m_axi_awready));
	vcdp->fullQuad (c+123,(vlTOPp->m_axi_wdata),64);
	vcdp->fullBus  (c+125,(vlTOPp->m_axi_wstrb),8);
	vcdp->fullBit  (c+126,(vlTOPp->m_axi_wlast));
	vcdp->fullBit  (c+127,(vlTOPp->m_axi_wvalid));
	vcdp->fullBit  (c+128,(vlTOPp->m_axi_wready));
	vcdp->fullBus  (c+129,(vlTOPp->m_axi_bid),13);
	vcdp->fullBus  (c+130,(vlTOPp->m_axi_bresp),2);
	vcdp->fullBit  (c+131,(vlTOPp->m_axi_bvalid));
	vcdp->fullBit  (c+132,(vlTOPp->m_axi_bready));
	vcdp->fullBus  (c+133,(vlTOPp->m_axi_arid),13);
	vcdp->fullQuad (c+134,(vlTOPp->m_axi_araddr),64);
	vcdp->fullBus  (c+136,(vlTOPp->m_axi_arlen),8);
	vcdp->fullBus  (c+137,(vlTOPp->m_axi_arsize),3);
	vcdp->fullBus  (c+138,(vlTOPp->m_axi_arburst),2);
	vcdp->fullBit  (c+139,(vlTOPp->m_axi_arlock));
	vcdp->fullBus  (c+140,(vlTOPp->m_axi_arcache),4);
	vcdp->fullBus  (c+141,(vlTOPp->m_axi_arprot),3);
	vcdp->fullBit  (c+142,(vlTOPp->m_axi_arvalid));
	vcdp->fullBit  (c+143,(vlTOPp->m_axi_arready));
	vcdp->fullBus  (c+144,(vlTOPp->m_axi_rid),13);
	vcdp->fullQuad (c+145,(vlTOPp->m_axi_rdata),64);
	vcdp->fullBus  (c+147,(vlTOPp->m_axi_rresp),2);
	vcdp->fullBit  (c+148,(vlTOPp->m_axi_rlast));
	vcdp->fullBit  (c+149,(vlTOPp->m_axi_rvalid));
	vcdp->fullBit  (c+150,(vlTOPp->m_axi_rready));
	vcdp->fullBit  (c+151,(vlTOPp->m_axi_acvalid));
	vcdp->fullBit  (c+152,(vlTOPp->m_axi_acready));
	vcdp->fullQuad (c+153,(vlTOPp->m_axi_acaddr),64);
	vcdp->fullBus  (c+155,(vlTOPp->m_axi_acsnoop),4);
	vcdp->fullBus  (c+156,(0xdU),32);
	vcdp->fullBus  (c+157,(0x40U),32);
	vcdp->fullBus  (c+158,(8U),32);
	vcdp->fullBus  (c+159,(vlTOPp->top__DOT__id_reg_funct3_out),3);
	vcdp->fullBit  (c+160,(vlTOPp->top__DOT__mem_read_control));
	vcdp->fullBit  (c+161,(vlTOPp->top__DOT__mem_write_control));
	vcdp->fullBus  (c+162,(vlTOPp->top__DOT__Decoder__DOT__address),32);
	vcdp->fullBus  (c+163,(vlTOPp->top__DOT__ControlUnit__DOT__funct7),7);
	vcdp->fullBus  (c+164,(vlTOPp->top__DOT__ControlUnit__DOT__funct3),3);
	vcdp->fullQuad (c+165,(vlTOPp->top__DOT__RegisterFile__DOT__write_data),64);
	vcdp->fullBit  (c+167,(vlTOPp->top__DOT__RegisterFile__DOT__reg_write_enable));
    }
}
