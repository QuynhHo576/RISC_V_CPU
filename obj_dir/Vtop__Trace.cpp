// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp; // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlTOPp->top__DOT__if_instr),32);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+2,(vlTOPp->top__DOT__fetch_inst__DOT__next_state),3);
	vcdp->chgQuad (c+3,(vlTOPp->top__DOT__fetch_inst__DOT__next_pc),64);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+5,(vlTOPp->top__DOT__Decoder__DOT__rs1),5);
	vcdp->chgBus  (c+6,(vlTOPp->top__DOT__Decoder__DOT__rs2),5);
	vcdp->chgBus  (c+7,(vlTOPp->top__DOT__Decoder__DOT__rd),5);
	vcdp->chgBus  (c+8,(vlTOPp->top__DOT__Decoder__DOT__imm),32);
	vcdp->chgBus  (c+9,(vlTOPp->top__DOT__Decoder__DOT__opcode),7);
	vcdp->chgBus  (c+10,(vlTOPp->top__DOT__id_reg_funct7_out),7);
	vcdp->chgBus  (c+11,(vlTOPp->top__DOT__Decoder__DOT__alu_op),4);
	vcdp->chgQuad (c+12,(vlTOPp->top__DOT__regA_data),64);
	vcdp->chgQuad (c+14,(vlTOPp->top__DOT__regB_data),64);
	vcdp->chgBus  (c+16,(vlTOPp->top__DOT__Decoder__DOT__funct3),3);
	vcdp->chgBus  (c+17,(vlTOPp->top__DOT__Decoder__DOT__funct7),7);
	vcdp->chgBus  (c+18,(vlTOPp->top__DOT__Decoder__DOT__imm_signed),32);
	vcdp->chgBus  (c+19,(vlTOPp->top__DOT__Decoder__DOT__imm_unsigned),32);
	vcdp->chgQuad (c+20,(vlTOPp->top__DOT__Decoder__DOT__decoded_instruction),64);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+22,(vlTOPp->top__DOT__fetch_inst__DOT__state),3);
	vcdp->chgQuad (c+23,(vlTOPp->top__DOT__fetch_inst__DOT__pc),64);
	vcdp->chgQuad (c+25,(vlTOPp->top__DOT__fetch_inst__DOT__fetched_instr),64);
	vcdp->chgQuad (c+27,(vlTOPp->top__DOT__fetch_inst__DOT__display_addr),64);
	vcdp->chgQuad (c+29,(vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr),64);
	vcdp->chgBus  (c+31,(vlTOPp->top__DOT__fetch_inst__DOT__index),10);
	vcdp->chgBus  (c+32,(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch),10);
	vcdp->chgQuad (c+33,(vlTOPp->top__DOT__RegisterFile__DOT__registers[0]),64);
	vcdp->chgQuad (c+35,(vlTOPp->top__DOT__RegisterFile__DOT__registers[1]),64);
	vcdp->chgQuad (c+37,(vlTOPp->top__DOT__RegisterFile__DOT__registers[2]),64);
	vcdp->chgQuad (c+39,(vlTOPp->top__DOT__RegisterFile__DOT__registers[3]),64);
	vcdp->chgQuad (c+41,(vlTOPp->top__DOT__RegisterFile__DOT__registers[4]),64);
	vcdp->chgQuad (c+43,(vlTOPp->top__DOT__RegisterFile__DOT__registers[5]),64);
	vcdp->chgQuad (c+45,(vlTOPp->top__DOT__RegisterFile__DOT__registers[6]),64);
	vcdp->chgQuad (c+47,(vlTOPp->top__DOT__RegisterFile__DOT__registers[7]),64);
	vcdp->chgQuad (c+49,(vlTOPp->top__DOT__RegisterFile__DOT__registers[8]),64);
	vcdp->chgQuad (c+51,(vlTOPp->top__DOT__RegisterFile__DOT__registers[9]),64);
	vcdp->chgQuad (c+53,(vlTOPp->top__DOT__RegisterFile__DOT__registers[10]),64);
	vcdp->chgQuad (c+55,(vlTOPp->top__DOT__RegisterFile__DOT__registers[11]),64);
	vcdp->chgQuad (c+57,(vlTOPp->top__DOT__RegisterFile__DOT__registers[12]),64);
	vcdp->chgQuad (c+59,(vlTOPp->top__DOT__RegisterFile__DOT__registers[13]),64);
	vcdp->chgQuad (c+61,(vlTOPp->top__DOT__RegisterFile__DOT__registers[14]),64);
	vcdp->chgQuad (c+63,(vlTOPp->top__DOT__RegisterFile__DOT__registers[15]),64);
	vcdp->chgQuad (c+65,(vlTOPp->top__DOT__RegisterFile__DOT__registers[16]),64);
	vcdp->chgQuad (c+67,(vlTOPp->top__DOT__RegisterFile__DOT__registers[17]),64);
	vcdp->chgQuad (c+69,(vlTOPp->top__DOT__RegisterFile__DOT__registers[18]),64);
	vcdp->chgQuad (c+71,(vlTOPp->top__DOT__RegisterFile__DOT__registers[19]),64);
	vcdp->chgQuad (c+73,(vlTOPp->top__DOT__RegisterFile__DOT__registers[20]),64);
	vcdp->chgQuad (c+75,(vlTOPp->top__DOT__RegisterFile__DOT__registers[21]),64);
	vcdp->chgQuad (c+77,(vlTOPp->top__DOT__RegisterFile__DOT__registers[22]),64);
	vcdp->chgQuad (c+79,(vlTOPp->top__DOT__RegisterFile__DOT__registers[23]),64);
	vcdp->chgQuad (c+81,(vlTOPp->top__DOT__RegisterFile__DOT__registers[24]),64);
	vcdp->chgQuad (c+83,(vlTOPp->top__DOT__RegisterFile__DOT__registers[25]),64);
	vcdp->chgQuad (c+85,(vlTOPp->top__DOT__RegisterFile__DOT__registers[26]),64);
	vcdp->chgQuad (c+87,(vlTOPp->top__DOT__RegisterFile__DOT__registers[27]),64);
	vcdp->chgQuad (c+89,(vlTOPp->top__DOT__RegisterFile__DOT__registers[28]),64);
	vcdp->chgQuad (c+91,(vlTOPp->top__DOT__RegisterFile__DOT__registers[29]),64);
	vcdp->chgQuad (c+93,(vlTOPp->top__DOT__RegisterFile__DOT__registers[30]),64);
	vcdp->chgQuad (c+95,(vlTOPp->top__DOT__RegisterFile__DOT__registers[31]),64);
	vcdp->chgBus  (c+97,(vlTOPp->top__DOT__RegisterFile__DOT__i),32);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+98,(vlTOPp->clk));
	vcdp->chgBit  (c+99,(vlTOPp->reset));
	vcdp->chgBit  (c+100,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+101,(vlTOPp->entry),64);
	vcdp->chgQuad (c+103,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+105,(vlTOPp->satp),64);
	vcdp->chgBus  (c+107,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+108,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+110,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+111,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+112,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+113,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+114,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+115,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+116,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+117,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+118,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+120,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+121,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+122,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+123,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+124,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+125,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+126,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+127,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+128,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+129,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+131,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+132,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+133,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+134,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+135,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+136,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+137,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+138,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+139,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+140,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+142,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+143,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+144,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+145,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+146,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+147,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+148,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+150,(vlTOPp->m_axi_acsnoop),4);
    }
}
