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
	vcdp->declBit  (c+28,"clk",-1);
	vcdp->declBit  (c+29,"reset",-1);
	vcdp->declBit  (c+30,"hz32768timer",-1);
	vcdp->declQuad (c+31,"entry",-1,63,0);
	vcdp->declQuad (c+33,"stackptr",-1,63,0);
	vcdp->declQuad (c+35,"satp",-1,63,0);
	vcdp->declBus  (c+37,"m_axi_awid",-1,12,0);
	vcdp->declQuad (c+38,"m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+40,"m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+41,"m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+42,"m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+43,"m_axi_awlock",-1);
	vcdp->declBus  (c+44,"m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+45,"m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+46,"m_axi_awvalid",-1);
	vcdp->declBit  (c+47,"m_axi_awready",-1);
	vcdp->declQuad (c+48,"m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+50,"m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+51,"m_axi_wlast",-1);
	vcdp->declBit  (c+52,"m_axi_wvalid",-1);
	vcdp->declBit  (c+53,"m_axi_wready",-1);
	vcdp->declBus  (c+54,"m_axi_bid",-1,12,0);
	vcdp->declBus  (c+55,"m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+56,"m_axi_bvalid",-1);
	vcdp->declBit  (c+57,"m_axi_bready",-1);
	vcdp->declBus  (c+58,"m_axi_arid",-1,12,0);
	vcdp->declQuad (c+59,"m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+61,"m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+62,"m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+63,"m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+64,"m_axi_arlock",-1);
	vcdp->declBus  (c+65,"m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+66,"m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+67,"m_axi_arvalid",-1);
	vcdp->declBit  (c+68,"m_axi_arready",-1);
	vcdp->declBus  (c+69,"m_axi_rid",-1,12,0);
	vcdp->declQuad (c+70,"m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+72,"m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+73,"m_axi_rlast",-1);
	vcdp->declBit  (c+74,"m_axi_rvalid",-1);
	vcdp->declBit  (c+75,"m_axi_rready",-1);
	vcdp->declBit  (c+76,"m_axi_acvalid",-1);
	vcdp->declBit  (c+77,"m_axi_acready",-1);
	vcdp->declQuad (c+78,"m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+80,"m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+81,"top ID_WIDTH",-1,31,0);
	vcdp->declBus  (c+82,"top ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+82,"top DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+83,"top STRB_WIDTH",-1,31,0);
	vcdp->declBit  (c+28,"top clk",-1);
	vcdp->declBit  (c+29,"top reset",-1);
	vcdp->declBit  (c+30,"top hz32768timer",-1);
	vcdp->declQuad (c+31,"top entry",-1,63,0);
	vcdp->declQuad (c+33,"top stackptr",-1,63,0);
	vcdp->declQuad (c+35,"top satp",-1,63,0);
	vcdp->declBus  (c+37,"top m_axi_awid",-1,12,0);
	vcdp->declQuad (c+38,"top m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+40,"top m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+41,"top m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+42,"top m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+43,"top m_axi_awlock",-1);
	vcdp->declBus  (c+44,"top m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+45,"top m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+46,"top m_axi_awvalid",-1);
	vcdp->declBit  (c+47,"top m_axi_awready",-1);
	vcdp->declQuad (c+48,"top m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+50,"top m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+51,"top m_axi_wlast",-1);
	vcdp->declBit  (c+52,"top m_axi_wvalid",-1);
	vcdp->declBit  (c+53,"top m_axi_wready",-1);
	vcdp->declBus  (c+54,"top m_axi_bid",-1,12,0);
	vcdp->declBus  (c+55,"top m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+56,"top m_axi_bvalid",-1);
	vcdp->declBit  (c+57,"top m_axi_bready",-1);
	vcdp->declBus  (c+58,"top m_axi_arid",-1,12,0);
	vcdp->declQuad (c+59,"top m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+61,"top m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+62,"top m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+63,"top m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+64,"top m_axi_arlock",-1);
	vcdp->declBus  (c+65,"top m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+66,"top m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+67,"top m_axi_arvalid",-1);
	vcdp->declBit  (c+68,"top m_axi_arready",-1);
	vcdp->declBus  (c+69,"top m_axi_rid",-1,12,0);
	vcdp->declQuad (c+70,"top m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+72,"top m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+73,"top m_axi_rlast",-1);
	vcdp->declBit  (c+74,"top m_axi_rvalid",-1);
	vcdp->declBit  (c+75,"top m_axi_rready",-1);
	vcdp->declBit  (c+76,"top m_axi_acvalid",-1);
	vcdp->declBit  (c+77,"top m_axi_acready",-1);
	vcdp->declQuad (c+78,"top m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+80,"top m_axi_acsnoop",-1,3,0);
	vcdp->declQuad (c+84,"top pc",-1,63,0);
	vcdp->declQuad (c+86,"top instruction",-1,63,0);
	vcdp->declBus  (c+88,"top state",-1,2,0);
	vcdp->declBus  (c+89,"top next_state",-1,2,0);
	vcdp->declQuad (c+90,"top next_pc",-1,63,0);
	vcdp->declQuad (c+92,"top fetched_instr",-1,63,0);
	vcdp->declQuad (c+94,"top display_addr",-1,63,0);
	vcdp->declQuad (c+96,"top next_display_addr",-1,63,0);
	vcdp->declBus  (c+1,"top if_instr",-1,31,0);
	vcdp->declBit  (c+28,"top fetch_inst clk",-1);
	vcdp->declBit  (c+29,"top fetch_inst reset",-1);
	vcdp->declQuad (c+31,"top fetch_inst entry",-1,63,0);
	vcdp->declQuad (c+59,"top fetch_inst m_axi_araddr",-1,63,0);
	vcdp->declBit  (c+67,"top fetch_inst m_axi_arvalid",-1);
	vcdp->declBit  (c+68,"top fetch_inst m_axi_arready",-1);
	vcdp->declBus  (c+61,"top fetch_inst m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+62,"top fetch_inst m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+63,"top fetch_inst m_axi_arburst",-1,1,0);
	vcdp->declQuad (c+70,"top fetch_inst m_axi_rdata",-1,63,0);
	vcdp->declBit  (c+74,"top fetch_inst m_axi_rvalid",-1);
	vcdp->declBit  (c+75,"top fetch_inst m_axi_rready",-1);
	vcdp->declBit  (c+73,"top fetch_inst m_axi_rlast",-1);
	vcdp->declBus  (c+1,"top fetch_inst if_instr",-1,31,0);
	vcdp->declBus  (c+17,"top fetch_inst state",-1,2,0);
	vcdp->declBus  (c+2,"top fetch_inst next_state",-1,2,0);
	vcdp->declQuad (c+18,"top fetch_inst pc",-1,63,0);
	vcdp->declQuad (c+3,"top fetch_inst next_pc",-1,63,0);
	vcdp->declQuad (c+20,"top fetch_inst fetched_instr",-1,63,0);
	vcdp->declQuad (c+22,"top fetch_inst display_addr",-1,63,0);
	vcdp->declQuad (c+24,"top fetch_inst next_display_addr",-1,63,0);
	// Tracing: top fetch_inst instruction_array // Ignored: Wide memory > --trace-max-array ents at fetch.sv:37
	vcdp->declBus  (c+26,"top fetch_inst index",-1,9,0);
	vcdp->declBus  (c+27,"top fetch_inst pc_fetch",-1,9,0);
	vcdp->declBus  (c+1,"top Decoder input_bin",-1,31,0);
	vcdp->declBus  (c+98,"top Decoder address",-1,31,0);
	vcdp->declBus  (c+5,"top Decoder id_reg_rs1_out",-1,4,0);
	vcdp->declBus  (c+6,"top Decoder id_reg_rs2_out",-1,4,0);
	vcdp->declBus  (c+7,"top Decoder id_reg_rd_out",-1,4,0);
	vcdp->declBus  (c+8,"top Decoder id_reg_imm",-1,31,0);
	vcdp->declBus  (c+9,"top Decoder id_reg_opcode_out",-1,6,0);
	vcdp->declBus  (c+10,"top Decoder id_reg_funct7_out",-1,6,0);
	vcdp->declBus  (c+11,"top Decoder id_reg_funct3_out",-1,2,0);
	vcdp->declBus  (c+12,"top Decoder id_alu_op_out",-1,3,0);
	vcdp->declBus  (c+5,"top Decoder rs1",-1,4,0);
	vcdp->declBus  (c+6,"top Decoder rs2",-1,4,0);
	vcdp->declBus  (c+7,"top Decoder rd",-1,4,0);
	vcdp->declBus  (c+9,"top Decoder opcode",-1,6,0);
	vcdp->declBus  (c+10,"top Decoder funct7",-1,6,0);
	vcdp->declBus  (c+11,"top Decoder funct3",-1,2,0);
	vcdp->declBus  (c+8,"top Decoder imm",-1,31,0);
	vcdp->declBus  (c+13,"top Decoder imm_signed",-1,31,0);
	vcdp->declBus  (c+14,"top Decoder imm_unsigned",-1,31,0);
	vcdp->declQuad (c+15,"top Decoder decoded_instruction",-1,63,0);
	vcdp->declBus  (c+12,"top Decoder alu_op",-1,3,0);
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
	vcdp->fullBus  (c+8,(vlTOPp->top__DOT__Decoder__DOT__imm),32);
	vcdp->fullBus  (c+9,(vlTOPp->top__DOT__Decoder__DOT__opcode),7);
	vcdp->fullBus  (c+10,(vlTOPp->top__DOT__Decoder__DOT__funct7),7);
	vcdp->fullBus  (c+11,(vlTOPp->top__DOT__Decoder__DOT__funct3),3);
	vcdp->fullBus  (c+12,(vlTOPp->top__DOT__Decoder__DOT__alu_op),4);
	vcdp->fullBus  (c+13,(vlTOPp->top__DOT__Decoder__DOT__imm_signed),32);
	vcdp->fullBus  (c+14,(vlTOPp->top__DOT__Decoder__DOT__imm_unsigned),32);
	vcdp->fullQuad (c+15,(vlTOPp->top__DOT__Decoder__DOT__decoded_instruction),64);
	vcdp->fullBus  (c+17,(vlTOPp->top__DOT__fetch_inst__DOT__state),3);
	vcdp->fullQuad (c+18,(vlTOPp->top__DOT__fetch_inst__DOT__pc),64);
	vcdp->fullQuad (c+20,(vlTOPp->top__DOT__fetch_inst__DOT__fetched_instr),64);
	vcdp->fullQuad (c+22,(vlTOPp->top__DOT__fetch_inst__DOT__display_addr),64);
	vcdp->fullQuad (c+24,(vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr),64);
	vcdp->fullBus  (c+26,(vlTOPp->top__DOT__fetch_inst__DOT__index),10);
	vcdp->fullBus  (c+27,(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch),10);
	vcdp->fullBit  (c+28,(vlTOPp->clk));
	vcdp->fullBit  (c+29,(vlTOPp->reset));
	vcdp->fullBit  (c+30,(vlTOPp->hz32768timer));
	vcdp->fullQuad (c+31,(vlTOPp->entry),64);
	vcdp->fullQuad (c+33,(vlTOPp->stackptr),64);
	vcdp->fullQuad (c+35,(vlTOPp->satp),64);
	vcdp->fullBus  (c+37,(vlTOPp->m_axi_awid),13);
	vcdp->fullQuad (c+38,(vlTOPp->m_axi_awaddr),64);
	vcdp->fullBus  (c+40,(vlTOPp->m_axi_awlen),8);
	vcdp->fullBus  (c+41,(vlTOPp->m_axi_awsize),3);
	vcdp->fullBus  (c+42,(vlTOPp->m_axi_awburst),2);
	vcdp->fullBit  (c+43,(vlTOPp->m_axi_awlock));
	vcdp->fullBus  (c+44,(vlTOPp->m_axi_awcache),4);
	vcdp->fullBus  (c+45,(vlTOPp->m_axi_awprot),3);
	vcdp->fullBit  (c+46,(vlTOPp->m_axi_awvalid));
	vcdp->fullBit  (c+47,(vlTOPp->m_axi_awready));
	vcdp->fullQuad (c+48,(vlTOPp->m_axi_wdata),64);
	vcdp->fullBus  (c+50,(vlTOPp->m_axi_wstrb),8);
	vcdp->fullBit  (c+51,(vlTOPp->m_axi_wlast));
	vcdp->fullBit  (c+52,(vlTOPp->m_axi_wvalid));
	vcdp->fullBit  (c+53,(vlTOPp->m_axi_wready));
	vcdp->fullBus  (c+54,(vlTOPp->m_axi_bid),13);
	vcdp->fullBus  (c+55,(vlTOPp->m_axi_bresp),2);
	vcdp->fullBit  (c+56,(vlTOPp->m_axi_bvalid));
	vcdp->fullBit  (c+57,(vlTOPp->m_axi_bready));
	vcdp->fullBus  (c+58,(vlTOPp->m_axi_arid),13);
	vcdp->fullQuad (c+59,(vlTOPp->m_axi_araddr),64);
	vcdp->fullBus  (c+61,(vlTOPp->m_axi_arlen),8);
	vcdp->fullBus  (c+62,(vlTOPp->m_axi_arsize),3);
	vcdp->fullBus  (c+63,(vlTOPp->m_axi_arburst),2);
	vcdp->fullBit  (c+64,(vlTOPp->m_axi_arlock));
	vcdp->fullBus  (c+65,(vlTOPp->m_axi_arcache),4);
	vcdp->fullBus  (c+66,(vlTOPp->m_axi_arprot),3);
	vcdp->fullBit  (c+67,(vlTOPp->m_axi_arvalid));
	vcdp->fullBit  (c+68,(vlTOPp->m_axi_arready));
	vcdp->fullBus  (c+69,(vlTOPp->m_axi_rid),13);
	vcdp->fullQuad (c+70,(vlTOPp->m_axi_rdata),64);
	vcdp->fullBus  (c+72,(vlTOPp->m_axi_rresp),2);
	vcdp->fullBit  (c+73,(vlTOPp->m_axi_rlast));
	vcdp->fullBit  (c+74,(vlTOPp->m_axi_rvalid));
	vcdp->fullBit  (c+75,(vlTOPp->m_axi_rready));
	vcdp->fullBit  (c+76,(vlTOPp->m_axi_acvalid));
	vcdp->fullBit  (c+77,(vlTOPp->m_axi_acready));
	vcdp->fullQuad (c+78,(vlTOPp->m_axi_acaddr),64);
	vcdp->fullBus  (c+80,(vlTOPp->m_axi_acsnoop),4);
	vcdp->fullBus  (c+81,(0xdU),32);
	vcdp->fullBus  (c+82,(0x40U),32);
	vcdp->fullBus  (c+83,(8U),32);
	vcdp->fullQuad (c+84,(vlTOPp->top__DOT__pc),64);
	vcdp->fullQuad (c+86,(vlTOPp->top__DOT__instruction),64);
	vcdp->fullBus  (c+88,(vlTOPp->top__DOT__state),3);
	vcdp->fullBus  (c+89,(vlTOPp->top__DOT__next_state),3);
	vcdp->fullQuad (c+90,(vlTOPp->top__DOT__next_pc),64);
	vcdp->fullQuad (c+92,(vlTOPp->top__DOT__fetched_instr),64);
	vcdp->fullQuad (c+94,(vlTOPp->top__DOT__display_addr),64);
	vcdp->fullQuad (c+96,(vlTOPp->top__DOT__next_display_addr),64);
	vcdp->fullBus  (c+98,(vlTOPp->top__DOT__Decoder__DOT__address),32);
    }
}
