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
	vcdp->declBit  (c+27,"clk",-1);
	vcdp->declBit  (c+28,"reset",-1);
	vcdp->declBit  (c+29,"hz32768timer",-1);
	vcdp->declQuad (c+30,"entry",-1,63,0);
	vcdp->declQuad (c+32,"stackptr",-1,63,0);
	vcdp->declQuad (c+34,"satp",-1,63,0);
	vcdp->declBus  (c+36,"m_axi_awid",-1,12,0);
	vcdp->declQuad (c+37,"m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+39,"m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+40,"m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+41,"m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+42,"m_axi_awlock",-1);
	vcdp->declBus  (c+43,"m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+44,"m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+45,"m_axi_awvalid",-1);
	vcdp->declBit  (c+46,"m_axi_awready",-1);
	vcdp->declQuad (c+47,"m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+49,"m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+50,"m_axi_wlast",-1);
	vcdp->declBit  (c+51,"m_axi_wvalid",-1);
	vcdp->declBit  (c+52,"m_axi_wready",-1);
	vcdp->declBus  (c+53,"m_axi_bid",-1,12,0);
	vcdp->declBus  (c+54,"m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+55,"m_axi_bvalid",-1);
	vcdp->declBit  (c+56,"m_axi_bready",-1);
	vcdp->declBus  (c+57,"m_axi_arid",-1,12,0);
	vcdp->declQuad (c+58,"m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+60,"m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+61,"m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+62,"m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+63,"m_axi_arlock",-1);
	vcdp->declBus  (c+64,"m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+65,"m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+66,"m_axi_arvalid",-1);
	vcdp->declBit  (c+67,"m_axi_arready",-1);
	vcdp->declBus  (c+68,"m_axi_rid",-1,12,0);
	vcdp->declQuad (c+69,"m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+71,"m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+72,"m_axi_rlast",-1);
	vcdp->declBit  (c+73,"m_axi_rvalid",-1);
	vcdp->declBit  (c+74,"m_axi_rready",-1);
	vcdp->declBit  (c+75,"m_axi_acvalid",-1);
	vcdp->declBit  (c+76,"m_axi_acready",-1);
	vcdp->declQuad (c+77,"m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+79,"m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+80,"top ID_WIDTH",-1,31,0);
	vcdp->declBus  (c+81,"top ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+81,"top DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+82,"top STRB_WIDTH",-1,31,0);
	vcdp->declBit  (c+27,"top clk",-1);
	vcdp->declBit  (c+28,"top reset",-1);
	vcdp->declBit  (c+29,"top hz32768timer",-1);
	vcdp->declQuad (c+30,"top entry",-1,63,0);
	vcdp->declQuad (c+32,"top stackptr",-1,63,0);
	vcdp->declQuad (c+34,"top satp",-1,63,0);
	vcdp->declBus  (c+36,"top m_axi_awid",-1,12,0);
	vcdp->declQuad (c+37,"top m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+39,"top m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+40,"top m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+41,"top m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+42,"top m_axi_awlock",-1);
	vcdp->declBus  (c+43,"top m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+44,"top m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+45,"top m_axi_awvalid",-1);
	vcdp->declBit  (c+46,"top m_axi_awready",-1);
	vcdp->declQuad (c+47,"top m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+49,"top m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+50,"top m_axi_wlast",-1);
	vcdp->declBit  (c+51,"top m_axi_wvalid",-1);
	vcdp->declBit  (c+52,"top m_axi_wready",-1);
	vcdp->declBus  (c+53,"top m_axi_bid",-1,12,0);
	vcdp->declBus  (c+54,"top m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+55,"top m_axi_bvalid",-1);
	vcdp->declBit  (c+56,"top m_axi_bready",-1);
	vcdp->declBus  (c+57,"top m_axi_arid",-1,12,0);
	vcdp->declQuad (c+58,"top m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+60,"top m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+61,"top m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+62,"top m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+63,"top m_axi_arlock",-1);
	vcdp->declBus  (c+64,"top m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+65,"top m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+66,"top m_axi_arvalid",-1);
	vcdp->declBit  (c+67,"top m_axi_arready",-1);
	vcdp->declBus  (c+68,"top m_axi_rid",-1,12,0);
	vcdp->declQuad (c+69,"top m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+71,"top m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+72,"top m_axi_rlast",-1);
	vcdp->declBit  (c+73,"top m_axi_rvalid",-1);
	vcdp->declBit  (c+74,"top m_axi_rready",-1);
	vcdp->declBit  (c+75,"top m_axi_acvalid",-1);
	vcdp->declBit  (c+76,"top m_axi_acready",-1);
	vcdp->declQuad (c+77,"top m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+79,"top m_axi_acsnoop",-1,3,0);
	vcdp->declQuad (c+83,"top pc",-1,63,0);
	vcdp->declQuad (c+85,"top instruction",-1,63,0);
	vcdp->declBus  (c+87,"top state",-1,2,0);
	vcdp->declBus  (c+88,"top next_state",-1,2,0);
	vcdp->declQuad (c+89,"top next_pc",-1,63,0);
	vcdp->declQuad (c+91,"top fetched_instr",-1,63,0);
	vcdp->declQuad (c+93,"top display_addr",-1,63,0);
	vcdp->declQuad (c+95,"top next_display_addr",-1,63,0);
	vcdp->declBus  (c+1,"top if_instr",-1,31,0);
	vcdp->declBit  (c+27,"top fetch_inst clk",-1);
	vcdp->declBit  (c+28,"top fetch_inst reset",-1);
	vcdp->declQuad (c+30,"top fetch_inst entry",-1,63,0);
	vcdp->declQuad (c+58,"top fetch_inst m_axi_araddr",-1,63,0);
	vcdp->declBit  (c+66,"top fetch_inst m_axi_arvalid",-1);
	vcdp->declBit  (c+67,"top fetch_inst m_axi_arready",-1);
	vcdp->declBus  (c+60,"top fetch_inst m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+61,"top fetch_inst m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+62,"top fetch_inst m_axi_arburst",-1,1,0);
	vcdp->declQuad (c+69,"top fetch_inst m_axi_rdata",-1,63,0);
	vcdp->declBit  (c+73,"top fetch_inst m_axi_rvalid",-1);
	vcdp->declBit  (c+74,"top fetch_inst m_axi_rready",-1);
	vcdp->declBit  (c+72,"top fetch_inst m_axi_rlast",-1);
	vcdp->declBus  (c+1,"top fetch_inst if_instr",-1,31,0);
	vcdp->declBus  (c+16,"top fetch_inst state",-1,2,0);
	vcdp->declBus  (c+2,"top fetch_inst next_state",-1,2,0);
	vcdp->declQuad (c+17,"top fetch_inst pc",-1,63,0);
	vcdp->declQuad (c+3,"top fetch_inst next_pc",-1,63,0);
	vcdp->declQuad (c+19,"top fetch_inst fetched_instr",-1,63,0);
	vcdp->declQuad (c+21,"top fetch_inst display_addr",-1,63,0);
	vcdp->declQuad (c+23,"top fetch_inst next_display_addr",-1,63,0);
	// Tracing: top fetch_inst instruction_array // Ignored: Wide memory > --trace-max-array ents at fetch.sv:37
	vcdp->declBus  (c+25,"top fetch_inst index",-1,9,0);
	vcdp->declBus  (c+26,"top fetch_inst pc_fetch",-1,9,0);
	vcdp->declBus  (c+1,"top Decoder input_bin",-1,31,0);
	vcdp->declBus  (c+97,"top Decoder address",-1,31,0);
	vcdp->declBus  (c+5,"top Decoder id_reg_rs1_out",-1,4,0);
	vcdp->declBus  (c+6,"top Decoder id_reg_rs2_out",-1,4,0);
	vcdp->declBus  (c+7,"top Decoder id_reg_rd_out",-1,4,0);
	vcdp->declBus  (c+8,"top Decoder id_reg_imm_signed",-1,31,0);
	vcdp->declBus  (c+8,"top Decoder id_reg_imm_unsigned",-1,31,0);
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
	vcdp->declBus  (c+8,"top Decoder imm_signed",-1,31,0);
	vcdp->declBus  (c+13,"top Decoder imm_unsigned",-1,31,0);
	vcdp->declQuad (c+14,"top Decoder decoded_instruction",-1,63,0);
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
	vcdp->fullBus  (c+8,(vlTOPp->top__DOT__Decoder__DOT__imm_signed),32);
	vcdp->fullBus  (c+9,(vlTOPp->top__DOT__Decoder__DOT__opcode),7);
	vcdp->fullBus  (c+10,(vlTOPp->top__DOT__Decoder__DOT__funct7),7);
	vcdp->fullBus  (c+11,(vlTOPp->top__DOT__Decoder__DOT__funct3),3);
	vcdp->fullBus  (c+12,(vlTOPp->top__DOT__Decoder__DOT__alu_op),4);
	vcdp->fullBus  (c+13,(vlTOPp->top__DOT__Decoder__DOT__imm_unsigned),32);
	vcdp->fullQuad (c+14,(vlTOPp->top__DOT__Decoder__DOT__decoded_instruction),64);
	vcdp->fullBus  (c+16,(vlTOPp->top__DOT__fetch_inst__DOT__state),3);
	vcdp->fullQuad (c+17,(vlTOPp->top__DOT__fetch_inst__DOT__pc),64);
	vcdp->fullQuad (c+19,(vlTOPp->top__DOT__fetch_inst__DOT__fetched_instr),64);
	vcdp->fullQuad (c+21,(vlTOPp->top__DOT__fetch_inst__DOT__display_addr),64);
	vcdp->fullQuad (c+23,(vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr),64);
	vcdp->fullBus  (c+25,(vlTOPp->top__DOT__fetch_inst__DOT__index),10);
	vcdp->fullBus  (c+26,(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch),10);
	vcdp->fullBit  (c+27,(vlTOPp->clk));
	vcdp->fullBit  (c+28,(vlTOPp->reset));
	vcdp->fullBit  (c+29,(vlTOPp->hz32768timer));
	vcdp->fullQuad (c+30,(vlTOPp->entry),64);
	vcdp->fullQuad (c+32,(vlTOPp->stackptr),64);
	vcdp->fullQuad (c+34,(vlTOPp->satp),64);
	vcdp->fullBus  (c+36,(vlTOPp->m_axi_awid),13);
	vcdp->fullQuad (c+37,(vlTOPp->m_axi_awaddr),64);
	vcdp->fullBus  (c+39,(vlTOPp->m_axi_awlen),8);
	vcdp->fullBus  (c+40,(vlTOPp->m_axi_awsize),3);
	vcdp->fullBus  (c+41,(vlTOPp->m_axi_awburst),2);
	vcdp->fullBit  (c+42,(vlTOPp->m_axi_awlock));
	vcdp->fullBus  (c+43,(vlTOPp->m_axi_awcache),4);
	vcdp->fullBus  (c+44,(vlTOPp->m_axi_awprot),3);
	vcdp->fullBit  (c+45,(vlTOPp->m_axi_awvalid));
	vcdp->fullBit  (c+46,(vlTOPp->m_axi_awready));
	vcdp->fullQuad (c+47,(vlTOPp->m_axi_wdata),64);
	vcdp->fullBus  (c+49,(vlTOPp->m_axi_wstrb),8);
	vcdp->fullBit  (c+50,(vlTOPp->m_axi_wlast));
	vcdp->fullBit  (c+51,(vlTOPp->m_axi_wvalid));
	vcdp->fullBit  (c+52,(vlTOPp->m_axi_wready));
	vcdp->fullBus  (c+53,(vlTOPp->m_axi_bid),13);
	vcdp->fullBus  (c+54,(vlTOPp->m_axi_bresp),2);
	vcdp->fullBit  (c+55,(vlTOPp->m_axi_bvalid));
	vcdp->fullBit  (c+56,(vlTOPp->m_axi_bready));
	vcdp->fullBus  (c+57,(vlTOPp->m_axi_arid),13);
	vcdp->fullQuad (c+58,(vlTOPp->m_axi_araddr),64);
	vcdp->fullBus  (c+60,(vlTOPp->m_axi_arlen),8);
	vcdp->fullBus  (c+61,(vlTOPp->m_axi_arsize),3);
	vcdp->fullBus  (c+62,(vlTOPp->m_axi_arburst),2);
	vcdp->fullBit  (c+63,(vlTOPp->m_axi_arlock));
	vcdp->fullBus  (c+64,(vlTOPp->m_axi_arcache),4);
	vcdp->fullBus  (c+65,(vlTOPp->m_axi_arprot),3);
	vcdp->fullBit  (c+66,(vlTOPp->m_axi_arvalid));
	vcdp->fullBit  (c+67,(vlTOPp->m_axi_arready));
	vcdp->fullBus  (c+68,(vlTOPp->m_axi_rid),13);
	vcdp->fullQuad (c+69,(vlTOPp->m_axi_rdata),64);
	vcdp->fullBus  (c+71,(vlTOPp->m_axi_rresp),2);
	vcdp->fullBit  (c+72,(vlTOPp->m_axi_rlast));
	vcdp->fullBit  (c+73,(vlTOPp->m_axi_rvalid));
	vcdp->fullBit  (c+74,(vlTOPp->m_axi_rready));
	vcdp->fullBit  (c+75,(vlTOPp->m_axi_acvalid));
	vcdp->fullBit  (c+76,(vlTOPp->m_axi_acready));
	vcdp->fullQuad (c+77,(vlTOPp->m_axi_acaddr),64);
	vcdp->fullBus  (c+79,(vlTOPp->m_axi_acsnoop),4);
	vcdp->fullBus  (c+80,(0xdU),32);
	vcdp->fullBus  (c+81,(0x40U),32);
	vcdp->fullBus  (c+82,(8U),32);
	vcdp->fullQuad (c+83,(vlTOPp->top__DOT__pc),64);
	vcdp->fullQuad (c+85,(vlTOPp->top__DOT__instruction),64);
	vcdp->fullBus  (c+87,(vlTOPp->top__DOT__state),3);
	vcdp->fullBus  (c+88,(vlTOPp->top__DOT__next_state),3);
	vcdp->fullQuad (c+89,(vlTOPp->top__DOT__next_pc),64);
	vcdp->fullQuad (c+91,(vlTOPp->top__DOT__fetched_instr),64);
	vcdp->fullQuad (c+93,(vlTOPp->top__DOT__display_addr),64);
	vcdp->fullQuad (c+95,(vlTOPp->top__DOT__next_display_addr),64);
	vcdp->fullBus  (c+97,(vlTOPp->top__DOT__Decoder__DOT__address),32);
    }
}
