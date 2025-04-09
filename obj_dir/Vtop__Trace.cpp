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
	vcdp->chgQuad (c+8,((QData)((IData)(vlTOPp->top__DOT__Decoder__DOT__imm))),64);
	vcdp->chgQuad (c+10,(vlTOPp->top__DOT__Decoder__DOT__imm_signed),64);
	vcdp->chgQuad (c+12,(vlTOPp->top__DOT__Decoder__DOT__imm_unsigned),64);
	vcdp->chgBus  (c+14,(vlTOPp->top__DOT__Decoder__DOT__opcode),7);
	vcdp->chgBus  (c+15,(vlTOPp->top__DOT__id_reg_funct7_out),7);
	vcdp->chgBus  (c+16,(vlTOPp->top__DOT__Decoder__DOT__alu_op),4);
	vcdp->chgBit  (c+17,(vlTOPp->top__DOT__ControlUnit__DOT__reg_write));
	vcdp->chgBit  (c+18,(vlTOPp->top__DOT__ControlUnit__DOT__alu_src));
	vcdp->chgQuad (c+19,(vlTOPp->top__DOT__regA_data_out),64);
	vcdp->chgQuad (c+21,(vlTOPp->top__DOT__regB_data_out),64);
	vcdp->chgQuad (c+23,(vlTOPp->top__DOT__ALU__DOT__result),64);
	vcdp->chgQuad (c+25,(vlTOPp->top__DOT__ex_operand_2_in),64);
	vcdp->chgBus  (c+27,(vlTOPp->top__DOT__Decoder__DOT__imm),32);
	vcdp->chgBus  (c+28,(vlTOPp->top__DOT__Decoder__DOT__funct3),3);
	vcdp->chgBus  (c+29,(vlTOPp->top__DOT__Decoder__DOT__funct7),7);
	vcdp->chgQuad (c+30,(vlTOPp->top__DOT__Decoder__DOT__decoded_instruction),64);
	vcdp->chgBit  (c+32,(vlTOPp->top__DOT__ControlUnit__DOT__mem_read));
	vcdp->chgBit  (c+33,(vlTOPp->top__DOT__ControlUnit__DOT__mem_write));
	vcdp->chgBit  (c+34,(vlTOPp->top__DOT__ControlUnit__DOT__mem_to_reg));
	vcdp->chgBus  (c+35,(vlTOPp->top__DOT__ControlUnit__DOT__opcode),7);
	vcdp->chgQuad (c+36,(vlTOPp->top__DOT__ALU__DOT__ex_operand_temp),64);
	vcdp->chgQuad (c+38,(vlTOPp->top__DOT__ALU__DOT__result_add_word),64);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgQuad (c+40,((QData)((IData)(((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
					      - (IData)(4U))))),64);
	vcdp->chgBus  (c+42,(((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
			      - (IData)(4U))),32);
	vcdp->chgBus  (c+43,(vlTOPp->top__DOT__fetch_inst__DOT__state),3);
	vcdp->chgQuad (c+44,(vlTOPp->top__DOT__fetch_inst__DOT__pc),64);
	vcdp->chgQuad (c+46,(vlTOPp->top__DOT__fetch_inst__DOT__fetched_instr),64);
	vcdp->chgQuad (c+48,(vlTOPp->top__DOT__fetch_inst__DOT__display_addr),64);
	vcdp->chgQuad (c+50,(vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr),64);
	vcdp->chgBus  (c+52,(vlTOPp->top__DOT__fetch_inst__DOT__index),10);
	vcdp->chgBus  (c+53,(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch),10);
	vcdp->chgQuad (c+54,(vlTOPp->top__DOT__RegisterFile__DOT__registers[0]),64);
	vcdp->chgQuad (c+56,(vlTOPp->top__DOT__RegisterFile__DOT__registers[1]),64);
	vcdp->chgQuad (c+58,(vlTOPp->top__DOT__RegisterFile__DOT__registers[2]),64);
	vcdp->chgQuad (c+60,(vlTOPp->top__DOT__RegisterFile__DOT__registers[3]),64);
	vcdp->chgQuad (c+62,(vlTOPp->top__DOT__RegisterFile__DOT__registers[4]),64);
	vcdp->chgQuad (c+64,(vlTOPp->top__DOT__RegisterFile__DOT__registers[5]),64);
	vcdp->chgQuad (c+66,(vlTOPp->top__DOT__RegisterFile__DOT__registers[6]),64);
	vcdp->chgQuad (c+68,(vlTOPp->top__DOT__RegisterFile__DOT__registers[7]),64);
	vcdp->chgQuad (c+70,(vlTOPp->top__DOT__RegisterFile__DOT__registers[8]),64);
	vcdp->chgQuad (c+72,(vlTOPp->top__DOT__RegisterFile__DOT__registers[9]),64);
	vcdp->chgQuad (c+74,(vlTOPp->top__DOT__RegisterFile__DOT__registers[10]),64);
	vcdp->chgQuad (c+76,(vlTOPp->top__DOT__RegisterFile__DOT__registers[11]),64);
	vcdp->chgQuad (c+78,(vlTOPp->top__DOT__RegisterFile__DOT__registers[12]),64);
	vcdp->chgQuad (c+80,(vlTOPp->top__DOT__RegisterFile__DOT__registers[13]),64);
	vcdp->chgQuad (c+82,(vlTOPp->top__DOT__RegisterFile__DOT__registers[14]),64);
	vcdp->chgQuad (c+84,(vlTOPp->top__DOT__RegisterFile__DOT__registers[15]),64);
	vcdp->chgQuad (c+86,(vlTOPp->top__DOT__RegisterFile__DOT__registers[16]),64);
	vcdp->chgQuad (c+88,(vlTOPp->top__DOT__RegisterFile__DOT__registers[17]),64);
	vcdp->chgQuad (c+90,(vlTOPp->top__DOT__RegisterFile__DOT__registers[18]),64);
	vcdp->chgQuad (c+92,(vlTOPp->top__DOT__RegisterFile__DOT__registers[19]),64);
	vcdp->chgQuad (c+94,(vlTOPp->top__DOT__RegisterFile__DOT__registers[20]),64);
	vcdp->chgQuad (c+96,(vlTOPp->top__DOT__RegisterFile__DOT__registers[21]),64);
	vcdp->chgQuad (c+98,(vlTOPp->top__DOT__RegisterFile__DOT__registers[22]),64);
	vcdp->chgQuad (c+100,(vlTOPp->top__DOT__RegisterFile__DOT__registers[23]),64);
	vcdp->chgQuad (c+102,(vlTOPp->top__DOT__RegisterFile__DOT__registers[24]),64);
	vcdp->chgQuad (c+104,(vlTOPp->top__DOT__RegisterFile__DOT__registers[25]),64);
	vcdp->chgQuad (c+106,(vlTOPp->top__DOT__RegisterFile__DOT__registers[26]),64);
	vcdp->chgQuad (c+108,(vlTOPp->top__DOT__RegisterFile__DOT__registers[27]),64);
	vcdp->chgQuad (c+110,(vlTOPp->top__DOT__RegisterFile__DOT__registers[28]),64);
	vcdp->chgQuad (c+112,(vlTOPp->top__DOT__RegisterFile__DOT__registers[29]),64);
	vcdp->chgQuad (c+114,(vlTOPp->top__DOT__RegisterFile__DOT__registers[30]),64);
	vcdp->chgQuad (c+116,(vlTOPp->top__DOT__RegisterFile__DOT__registers[31]),64);
	vcdp->chgBus  (c+118,(vlTOPp->top__DOT__RegisterFile__DOT__i),32);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+119,(vlTOPp->clk));
	vcdp->chgBit  (c+120,(vlTOPp->reset));
	vcdp->chgBit  (c+121,(vlTOPp->hz32768timer));
	vcdp->chgQuad (c+122,(vlTOPp->entry),64);
	vcdp->chgQuad (c+124,(vlTOPp->stackptr),64);
	vcdp->chgQuad (c+126,(vlTOPp->satp),64);
	vcdp->chgBus  (c+128,(vlTOPp->m_axi_awid),13);
	vcdp->chgQuad (c+129,(vlTOPp->m_axi_awaddr),64);
	vcdp->chgBus  (c+131,(vlTOPp->m_axi_awlen),8);
	vcdp->chgBus  (c+132,(vlTOPp->m_axi_awsize),3);
	vcdp->chgBus  (c+133,(vlTOPp->m_axi_awburst),2);
	vcdp->chgBit  (c+134,(vlTOPp->m_axi_awlock));
	vcdp->chgBus  (c+135,(vlTOPp->m_axi_awcache),4);
	vcdp->chgBus  (c+136,(vlTOPp->m_axi_awprot),3);
	vcdp->chgBit  (c+137,(vlTOPp->m_axi_awvalid));
	vcdp->chgBit  (c+138,(vlTOPp->m_axi_awready));
	vcdp->chgQuad (c+139,(vlTOPp->m_axi_wdata),64);
	vcdp->chgBus  (c+141,(vlTOPp->m_axi_wstrb),8);
	vcdp->chgBit  (c+142,(vlTOPp->m_axi_wlast));
	vcdp->chgBit  (c+143,(vlTOPp->m_axi_wvalid));
	vcdp->chgBit  (c+144,(vlTOPp->m_axi_wready));
	vcdp->chgBus  (c+145,(vlTOPp->m_axi_bid),13);
	vcdp->chgBus  (c+146,(vlTOPp->m_axi_bresp),2);
	vcdp->chgBit  (c+147,(vlTOPp->m_axi_bvalid));
	vcdp->chgBit  (c+148,(vlTOPp->m_axi_bready));
	vcdp->chgBus  (c+149,(vlTOPp->m_axi_arid),13);
	vcdp->chgQuad (c+150,(vlTOPp->m_axi_araddr),64);
	vcdp->chgBus  (c+152,(vlTOPp->m_axi_arlen),8);
	vcdp->chgBus  (c+153,(vlTOPp->m_axi_arsize),3);
	vcdp->chgBus  (c+154,(vlTOPp->m_axi_arburst),2);
	vcdp->chgBit  (c+155,(vlTOPp->m_axi_arlock));
	vcdp->chgBus  (c+156,(vlTOPp->m_axi_arcache),4);
	vcdp->chgBus  (c+157,(vlTOPp->m_axi_arprot),3);
	vcdp->chgBit  (c+158,(vlTOPp->m_axi_arvalid));
	vcdp->chgBit  (c+159,(vlTOPp->m_axi_arready));
	vcdp->chgBus  (c+160,(vlTOPp->m_axi_rid),13);
	vcdp->chgQuad (c+161,(vlTOPp->m_axi_rdata),64);
	vcdp->chgBus  (c+163,(vlTOPp->m_axi_rresp),2);
	vcdp->chgBit  (c+164,(vlTOPp->m_axi_rlast));
	vcdp->chgBit  (c+165,(vlTOPp->m_axi_rvalid));
	vcdp->chgBit  (c+166,(vlTOPp->m_axi_rready));
	vcdp->chgBit  (c+167,(vlTOPp->m_axi_acvalid));
	vcdp->chgBit  (c+168,(vlTOPp->m_axi_acready));
	vcdp->chgQuad (c+169,(vlTOPp->m_axi_acaddr),64);
	vcdp->chgBus  (c+171,(vlTOPp->m_axi_acsnoop),4);
    }
}
