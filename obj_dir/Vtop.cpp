// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL (__PVT____024unit, Vtop___024unit);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vtop::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_initial__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at top.sv:394
    VL_WRITEF("Initializing top, entry point = 0x%x\n",
	      64,vlTOPp->entry);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__m_axi_arvalid,0,0);
    VL_SIG8(__Vdly__m_axi_rready,0,0);
    VL_SIG8(__Vdlyvset__top__DOT__fetch_inst__DOT__instruction_array__v0,0,0);
    VL_SIG8(__Vdlyvset__top__DOT__fetch_inst__DOT__instruction_array__v1,0,0);
    VL_SIG16(__Vdly__top__DOT__fetch_inst__DOT__index,9,0);
    VL_SIG16(__Vdlyvdim0__top__DOT__fetch_inst__DOT__instruction_array__v0,9,0);
    VL_SIG16(__Vdlyvdim0__top__DOT__fetch_inst__DOT__instruction_array__v1,9,0);
    VL_SIG16(__Vdly__top__DOT__fetch_inst__DOT__pc_fetch,9,0);
    VL_SIG(__Vdlyvval__top__DOT__fetch_inst__DOT__instruction_array__v0,31,0);
    VL_SIG(__Vdlyvval__top__DOT__fetch_inst__DOT__instruction_array__v1,31,0);
    //char	__VpadToAlign44[4];
    VL_SIG64(__Vdly__top__DOT__fetch_inst__DOT__next_display_addr,63,0);
    // Body
    __Vdly__top__DOT__fetch_inst__DOT__pc_fetch = vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch;
    __Vdly__top__DOT__fetch_inst__DOT__next_display_addr 
	= vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr;
    __Vdly__m_axi_arvalid = vlTOPp->m_axi_arvalid;
    __Vdly__m_axi_rready = vlTOPp->m_axi_rready;
    __Vdly__top__DOT__fetch_inst__DOT__index = vlTOPp->top__DOT__fetch_inst__DOT__index;
    __Vdlyvset__top__DOT__fetch_inst__DOT__instruction_array__v0 = 0U;
    __Vdlyvset__top__DOT__fetch_inst__DOT__instruction_array__v1 = 0U;
    // ALWAYS at fetch.sv:123
    if (vlTOPp->reset) {
	__Vdly__top__DOT__fetch_inst__DOT__pc_fetch = 0U;
    } else {
	if (vlTOPp->m_axi_rlast) {
	    __Vdly__top__DOT__fetch_inst__DOT__pc_fetch 
		= (0x3ffU & ((IData)(4U) + (IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch)));
	}
    }
    // ALWAYS at fetch.sv:73
    vlTOPp->m_axi_araddr = vlTOPp->top__DOT__fetch_inst__DOT__pc;
    vlTOPp->m_axi_arlen = 7U;
    vlTOPp->m_axi_arsize = 0U;
    vlTOPp->m_axi_arburst = 2U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	__Vdly__m_axi_arvalid = (0U == (IData)(vlTOPp->top__DOT__fetch_inst__DOT__state));
	if (((IData)(vlTOPp->m_axi_arvalid) & (IData)(vlTOPp->m_axi_arready))) {
	    __Vdly__m_axi_arvalid = 0U;
	}
	if (((1U == (IData)(vlTOPp->top__DOT__fetch_inst__DOT__state)) 
	     & (IData)(vlTOPp->m_axi_rvalid))) {
	    __Vdly__m_axi_rready = 1U;
	}
	if (((IData)(vlTOPp->m_axi_rvalid) & (IData)(vlTOPp->m_axi_rready))) {
	    __Vdly__m_axi_rready = 0U;
	    __Vdly__top__DOT__fetch_inst__DOT__next_display_addr 
		= (VL_ULL(8) + vlTOPp->top__DOT__fetch_inst__DOT__display_addr);
	    vlTOPp->top__DOT__fetch_inst__DOT__fetched_instr 
		= vlTOPp->m_axi_rdata;
	}
    }
    // ALWAYS at fetch.sv:113
    if (vlTOPp->reset) {
	__Vdly__top__DOT__fetch_inst__DOT__index = 0U;
    } else {
	if ((((IData)(vlTOPp->m_axi_rvalid) & (IData)(vlTOPp->m_axi_rready)) 
	     & (0x3e8U > (IData)(vlTOPp->top__DOT__fetch_inst__DOT__index)))) {
	    vlTOPp->top__DOT__fetch_inst__DOT____Vlvbound1 
		= (IData)(vlTOPp->m_axi_rdata);
	    if ((0x3e7U >= (IData)(vlTOPp->top__DOT__fetch_inst__DOT__index))) {
		__Vdlyvval__top__DOT__fetch_inst__DOT__instruction_array__v0 
		    = vlTOPp->top__DOT__fetch_inst__DOT____Vlvbound1;
		__Vdlyvset__top__DOT__fetch_inst__DOT__instruction_array__v0 = 1U;
		__Vdlyvdim0__top__DOT__fetch_inst__DOT__instruction_array__v0 
		    = vlTOPp->top__DOT__fetch_inst__DOT__index;
	    }
	    vlTOPp->top__DOT__fetch_inst__DOT____Vlvbound2 
		= (IData)((vlTOPp->m_axi_rdata >> 0x20U));
	    if ((0x3e7U >= (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__fetch_inst__DOT__index))))) {
		__Vdlyvval__top__DOT__fetch_inst__DOT__instruction_array__v1 
		    = vlTOPp->top__DOT__fetch_inst__DOT____Vlvbound2;
		__Vdlyvset__top__DOT__fetch_inst__DOT__instruction_array__v1 = 1U;
		__Vdlyvdim0__top__DOT__fetch_inst__DOT__instruction_array__v1 
		    = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__fetch_inst__DOT__index)));
	    }
	    __Vdly__top__DOT__fetch_inst__DOT__index 
		= (0x3ffU & ((IData)(2U) + (IData)(vlTOPp->top__DOT__fetch_inst__DOT__index)));
	}
    }
    vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch = __Vdly__top__DOT__fetch_inst__DOT__pc_fetch;
    vlTOPp->m_axi_arvalid = __Vdly__m_axi_arvalid;
    vlTOPp->top__DOT__fetch_inst__DOT__index = __Vdly__top__DOT__fetch_inst__DOT__index;
    vlTOPp->m_axi_rready = __Vdly__m_axi_rready;
    // ALWAYSPOST at fetch.sv:117
    if (__Vdlyvset__top__DOT__fetch_inst__DOT__instruction_array__v0) {
	vlTOPp->top__DOT__fetch_inst__DOT__instruction_array[__Vdlyvdim0__top__DOT__fetch_inst__DOT__instruction_array__v0] 
	    = __Vdlyvval__top__DOT__fetch_inst__DOT__instruction_array__v0;
    }
    if (__Vdlyvset__top__DOT__fetch_inst__DOT__instruction_array__v1) {
	vlTOPp->top__DOT__fetch_inst__DOT__instruction_array[__Vdlyvdim0__top__DOT__fetch_inst__DOT__instruction_array__v1] 
	    = __Vdlyvval__top__DOT__fetch_inst__DOT__instruction_array__v1;
    }
    // ALWAYS at fetch.sv:103
    if (vlTOPp->reset) {
	vlTOPp->top__DOT__fetch_inst__DOT__pc = vlTOPp->entry;
	vlTOPp->top__DOT__fetch_inst__DOT__state = 0U;
    } else {
	vlTOPp->top__DOT__fetch_inst__DOT__pc = vlTOPp->top__DOT__fetch_inst__DOT__next_pc;
	vlTOPp->top__DOT__fetch_inst__DOT__state = vlTOPp->top__DOT__fetch_inst__DOT__next_state;
	vlTOPp->top__DOT__fetch_inst__DOT__display_addr 
	    = vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr;
    }
    vlTOPp->top__DOT__if_instr = ((0x3e7U >= (0xffU 
					      & ((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
						 >> 2U)))
				   ? vlTOPp->top__DOT__fetch_inst__DOT__instruction_array
				  [(0xffU & ((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
					     >> 2U))]
				   : 0U);
    vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr 
	= __Vdly__top__DOT__fetch_inst__DOT__next_display_addr;
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__if_instr = ((0x3e7U >= (0xffU 
					      & ((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
						 >> 2U)))
				   ? vlTOPp->top__DOT__fetch_inst__DOT__instruction_array
				  [(0xffU & ((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
					     >> 2U))]
				   : 0U);
    // ALWAYS at fetch.sv:43
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if ((0U == (IData)(vlTOPp->top__DOT__fetch_inst__DOT__state))) {
	    if (((IData)(vlTOPp->m_axi_arready) & (IData)(vlTOPp->m_axi_arvalid))) {
		vlTOPp->top__DOT__fetch_inst__DOT__next_state = 1U;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->top__DOT__fetch_inst__DOT__state))) {
		if (((IData)(vlTOPp->m_axi_rvalid) 
		     & (IData)(vlTOPp->m_axi_rready))) {
		    if (VL_UNLIKELY((VL_ULL(0) == vlTOPp->m_axi_rdata))) {
			vl_finish("fetch.sv",53,"");
		    }
		    vlTOPp->top__DOT__fetch_inst__DOT__next_state = 4U;
		}
	    } else {
		if ((4U == (IData)(vlTOPp->top__DOT__fetch_inst__DOT__state))) {
		    if (vlTOPp->m_axi_rlast) {
			if ((1U & (~ (IData)(vlTOPp->m_axi_rvalid)))) {
			    vlTOPp->top__DOT__fetch_inst__DOT__next_pc 
				= (VL_ULL(0x40) + vlTOPp->top__DOT__fetch_inst__DOT__pc);
			    vlTOPp->top__DOT__fetch_inst__DOT__next_state = 0U;
			}
		    } else {
			vlTOPp->top__DOT__fetch_inst__DOT__next_state = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at decode.sv:23
    vlTOPp->top__DOT__Decoder__DOT__opcode = (0x7fU 
					      & vlTOPp->top__DOT__if_instr);
    vlTOPp->top__DOT__Decoder__DOT__rd = (0x1fU & (vlTOPp->top__DOT__if_instr 
						   >> 7U));
    vlTOPp->top__DOT__Decoder__DOT__funct3 = (7U & 
					      (vlTOPp->top__DOT__if_instr 
					       >> 0xcU));
    vlTOPp->top__DOT__Decoder__DOT__rs1 = (0x1fU & 
					   (vlTOPp->top__DOT__if_instr 
					    >> 0xfU));
    vlTOPp->top__DOT__Decoder__DOT__rs2 = (0x1fU & 
					   (vlTOPp->top__DOT__if_instr 
					    >> 0x14U));
    vlTOPp->top__DOT__Decoder__DOT__funct7 = (0x7fU 
					      & (vlTOPp->top__DOT__if_instr 
						 >> 0x19U));
    if (((((((((0x33U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)) 
	       | (0x13U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	      | (0x1bU == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	     | (0x67U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	    | (3U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	   | (0x23U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	  | (0x63U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	 | (0x37U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
	if (VL_UNLIKELY((0x33U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
	    vlTOPp->top__DOT__Decoder__DOT__imm_signed = 0U;
	    if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
		if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
		    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x414444);
		    vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
		} else {
		    if ((0x20U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x535542);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 6U;
		    }
		}
	    } else {
		if ((7U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
		    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x414e44);
		    vlTOPp->top__DOT__Decoder__DOT__alu_op = 5U;
		} else {
		    if ((6U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4f52);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 3U;
		    } else {
			if ((4U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x584f52);
			    vlTOPp->top__DOT__Decoder__DOT__alu_op = 1U;
			} else {
			    if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x534c4c);
				vlTOPp->top__DOT__Decoder__DOT__alu_op = 4U;
			    } else {
				if ((5U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				    if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x53524c);
					vlTOPp->top__DOT__Decoder__DOT__alu_op = 5U;
				    } else {
					if ((0x20U 
					     == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
					    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x535241);
					    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xbU;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	    VL_WRITEF("R-type %x :%x %s x%2#, x%2#, x%2#\n",
		      32,vlTOPp->top__DOT__Decoder__DOT__address,
		      32,vlTOPp->top__DOT__if_instr,
		      64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
		      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
		      5,vlTOPp->top__DOT__Decoder__DOT__rs1,
		      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs2));
	} else {
	    if (VL_UNLIKELY((0x13U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
		vlTOPp->top__DOT__Decoder__DOT__imm_signed 
		    = ((0xfffff000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->top__DOT__if_instr 
							       >> 0x1fU)))) 
				       << 0xcU)) | 
		       (0xfffU & (vlTOPp->top__DOT__if_instr 
				  >> 0x14U)));
		vlTOPp->top__DOT__Decoder__DOT__rs2 = 0U;
		if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
		    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x41444449);
		    vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
		} else {
		    if ((7U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x414e4449);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 0U;
		    } else {
			if ((6U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4f5249);
			    vlTOPp->top__DOT__Decoder__DOT__alu_op = 1U;
			} else {
			    if ((4U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x584f5249);
				vlTOPp->top__DOT__Decoder__DOT__alu_op = 3U;
			    } else {
				if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x534c4c49);
				    vlTOPp->top__DOT__Decoder__DOT__alu_op = 4U;
				} else {
				    if ((3U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x534c544955);
					vlTOPp->top__DOT__Decoder__DOT__alu_op = 6U;
				    } else {
					if ((5U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					    if ((0U 
						 == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
						vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x53524c49);
						vlTOPp->top__DOT__Decoder__DOT__alu_op = 5U;
					    } else {
						if (
						    (0x20U 
						     == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
						    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x53524149);
						    vlTOPp->top__DOT__Decoder__DOT__alu_op = 7U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
		VL_WRITEF("I-type %x :%x %s x%2#, x%2#, %11d\n",
			  32,vlTOPp->top__DOT__Decoder__DOT__address,
			  32,vlTOPp->top__DOT__if_instr,
			  64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
			  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
			  5,vlTOPp->top__DOT__Decoder__DOT__rs1,
			  32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
	    } else {
		if (VL_UNLIKELY((0x1bU == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
		    vlTOPp->top__DOT__Decoder__DOT__imm_signed 
			= ((0xfffff000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__if_instr 
								   >> 0x1fU)))) 
					   << 0xcU)) 
			   | (0xfffU & (vlTOPp->top__DOT__if_instr 
					>> 0x14U)));
		    if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4144444957);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
		    } else {
			if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x534c4c4957);
			    vlTOPp->top__DOT__Decoder__DOT__alu_op = 4U;
			} else {
			    if ((5U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x53524c4957);
				    vlTOPp->top__DOT__Decoder__DOT__alu_op = 5U;
				} else {
				    if ((0x20U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5352414957);
					vlTOPp->top__DOT__Decoder__DOT__alu_op = 7U;
				    }
				}
			    }
			}
		    }
		    VL_WRITEF("I-Type %x :%x %s x%2#, x%2#, %11d\n",
			      32,vlTOPp->top__DOT__Decoder__DOT__address,
			      32,vlTOPp->top__DOT__if_instr,
			      64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
			      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
			      5,vlTOPp->top__DOT__Decoder__DOT__rs1,
			      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
		} else {
		    if (VL_UNLIKELY((0x67U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
			VL_WRITEF("I-Type %x :%x     JALR x%2#, x%2#, %11d\n",
				  32,vlTOPp->top__DOT__Decoder__DOT__address,
				  32,vlTOPp->top__DOT__if_instr,
				  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
				  5,vlTOPp->top__DOT__Decoder__DOT__rs1,
				  32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4a414c52);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
		    } else {
			if (VL_UNLIKELY((3U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
			    if ((3U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4c44);
			    } else {
				if ((2U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4c57);
				} else {
				    if ((4U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4c4255);
				    }
				}
			    }
			    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0U;
			    VL_WRITEF("I-Type %x :%x %s x%2#, %11d(x%2#)\n",
				      32,vlTOPp->top__DOT__Decoder__DOT__address,
				      32,vlTOPp->top__DOT__if_instr,
				      64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
				      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
				      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed,
				      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs1));
			} else {
			    if (VL_UNLIKELY((0x23U 
					     == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
				vlTOPp->top__DOT__Decoder__DOT__imm_signed 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__if_instr 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | ((0xfe0U & 
					   (vlTOPp->top__DOT__if_instr 
					    >> 0x14U)) 
					  | (0x1fU 
					     & (vlTOPp->top__DOT__if_instr 
						>> 7U))));
				vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
				if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5342);
				} else {
				    if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5348);
				    } else {
					if ((2U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5357);
					} else {
					    if ((3U 
						 == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
						vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5344);
					    }
					}
				    }
				}
				VL_WRITEF("S-Type %x :%x %s x%2#, %11d(x%2#)\n",
					  32,vlTOPp->top__DOT__Decoder__DOT__address,
					  32,vlTOPp->top__DOT__if_instr,
					  64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
					  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs2),
					  32,vlTOPp->top__DOT__Decoder__DOT__imm_signed,
					  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs1));
			    } else {
				if ((0x63U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) {
				    vlTOPp->top__DOT__Decoder__DOT__imm_signed 
					= ((0xffffe000U 
					    & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlTOPp->top__DOT__if_instr 
								       >> 0x1fU)))) 
					       << 0xdU)) 
					   | ((0x1000U 
					       & (vlTOPp->top__DOT__if_instr 
						  >> 0x13U)) 
					      | ((0x800U 
						  & (vlTOPp->top__DOT__if_instr 
						     << 4U)) 
						 | ((0x7e0U 
						     & (vlTOPp->top__DOT__if_instr 
							>> 0x14U)) 
						    | (0x1eU 
						       & (vlTOPp->top__DOT__if_instr 
							  >> 7U))))));
				    vlTOPp->top__DOT__Decoder__DOT__imm_unsigned 
					= ((0x800U 
					    & (vlTOPp->top__DOT__if_instr 
					       << 4U)) 
					   | ((0x7e0U 
					       & (vlTOPp->top__DOT__if_instr 
						  >> 0x14U)) 
					      | (0x1eU 
						 & (vlTOPp->top__DOT__if_instr 
						    >> 7U))));
				    if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424551);
					vlTOPp->top__DOT__Decoder__DOT__alu_op = 8U;
				    } else {
					if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424e45);
					    vlTOPp->top__DOT__Decoder__DOT__alu_op = 9U;
					} else {
					    if ((4U 
						 == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
						vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424c54);
						vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xaU;
					    } else {
						if (
						    (5U 
						     == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
						    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424745);
						    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xbU;
						} else {
						    if (
							(6U 
							 == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
							vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424c5455);
							vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xcU;
						    } else {
							if (
							    (7U 
							     == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
							    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x42474555);
							    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xdU;
							}
						    }
						}
					    }
					}
				    }
				    VL_WRITEF("B-Type %x :%x %s x%2#, x%2#, %11d\n",
					      32,vlTOPp->top__DOT__Decoder__DOT__address,
					      32,vlTOPp->top__DOT__if_instr,
					      64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
					      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs1),
					      5,vlTOPp->top__DOT__Decoder__DOT__rs2,
					      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
				} else {
				    vlTOPp->top__DOT__Decoder__DOT__imm_signed 
					= (0xfffff000U 
					   & vlTOPp->top__DOT__if_instr);
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4c5549);
				    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0U;
				    VL_WRITEF("%x :%x      LUI x%2#, %11d\n",
					      32,vlTOPp->top__DOT__Decoder__DOT__address,
					      32,vlTOPp->top__DOT__if_instr,
					      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
					      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if (VL_UNLIKELY((0x17U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
	    vlTOPp->top__DOT__Decoder__DOT__imm_signed 
		= (0xfffff000U & vlTOPp->top__DOT__if_instr);
	    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4155495043);
	    vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
	    VL_WRITEF("U-Type %x :%x    AUIPC x%2#, %11d\n",
		      32,vlTOPp->top__DOT__Decoder__DOT__address,
		      32,vlTOPp->top__DOT__if_instr,
		      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
		      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
	} else {
	    if (VL_UNLIKELY((0x6fU == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
		vlTOPp->top__DOT__Decoder__DOT__imm_signed 
		    = ((0xffe00000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->top__DOT__if_instr 
							       >> 0x1fU)))) 
				       << 0x15U)) | 
		       ((0x100000U & (vlTOPp->top__DOT__if_instr 
				      >> 0xbU)) | (
						   (0xff000U 
						    & vlTOPp->top__DOT__if_instr) 
						   | ((0x800U 
						       & (vlTOPp->top__DOT__if_instr 
							  >> 9U)) 
						      | (0x7feU 
							 & (vlTOPp->top__DOT__if_instr 
							    >> 0x14U))))));
		vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4a414c);
		vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xeU;
		VL_WRITEF("J-Type %x :%x      JAL x%2#, %11d\n",
			  32,vlTOPp->top__DOT__Decoder__DOT__address,
			  32,vlTOPp->top__DOT__if_instr,
			  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
			  32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
	    }
	}
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_combo__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at fetch.sv:43
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if ((0U == (IData)(vlTOPp->top__DOT__fetch_inst__DOT__state))) {
	    if (((IData)(vlTOPp->m_axi_arready) & (IData)(vlTOPp->m_axi_arvalid))) {
		vlTOPp->top__DOT__fetch_inst__DOT__next_state = 1U;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->top__DOT__fetch_inst__DOT__state))) {
		if (((IData)(vlTOPp->m_axi_rvalid) 
		     & (IData)(vlTOPp->m_axi_rready))) {
		    if (VL_UNLIKELY((VL_ULL(0) == vlTOPp->m_axi_rdata))) {
			vl_finish("fetch.sv",53,"");
		    }
		    vlTOPp->top__DOT__fetch_inst__DOT__next_state = 4U;
		}
	    } else {
		if ((4U == (IData)(vlTOPp->top__DOT__fetch_inst__DOT__state))) {
		    if (vlTOPp->m_axi_rlast) {
			if ((1U & (~ (IData)(vlTOPp->m_axi_rvalid)))) {
			    vlTOPp->top__DOT__fetch_inst__DOT__next_pc 
				= (VL_ULL(0x40) + vlTOPp->top__DOT__fetch_inst__DOT__pc);
			    vlTOPp->top__DOT__fetch_inst__DOT__next_state = 0U;
			}
		    } else {
			vlTOPp->top__DOT__fetch_inst__DOT__next_state = 1U;
		    }
		}
	    }
	}
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at decode.sv:23
    vlTOPp->top__DOT__Decoder__DOT__opcode = (0x7fU 
					      & vlTOPp->top__DOT__if_instr);
    vlTOPp->top__DOT__Decoder__DOT__rd = (0x1fU & (vlTOPp->top__DOT__if_instr 
						   >> 7U));
    vlTOPp->top__DOT__Decoder__DOT__funct3 = (7U & 
					      (vlTOPp->top__DOT__if_instr 
					       >> 0xcU));
    vlTOPp->top__DOT__Decoder__DOT__rs1 = (0x1fU & 
					   (vlTOPp->top__DOT__if_instr 
					    >> 0xfU));
    vlTOPp->top__DOT__Decoder__DOT__rs2 = (0x1fU & 
					   (vlTOPp->top__DOT__if_instr 
					    >> 0x14U));
    vlTOPp->top__DOT__Decoder__DOT__funct7 = (0x7fU 
					      & (vlTOPp->top__DOT__if_instr 
						 >> 0x19U));
    if (((((((((0x33U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)) 
	       | (0x13U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	      | (0x1bU == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	     | (0x67U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	    | (3U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	   | (0x23U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	  | (0x63U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) 
	 | (0x37U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
	if (VL_UNLIKELY((0x33U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
	    vlTOPp->top__DOT__Decoder__DOT__imm_signed = 0U;
	    if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
		if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
		    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x414444);
		    vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
		} else {
		    if ((0x20U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x535542);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 6U;
		    }
		}
	    } else {
		if ((7U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
		    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x414e44);
		    vlTOPp->top__DOT__Decoder__DOT__alu_op = 5U;
		} else {
		    if ((6U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4f52);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 3U;
		    } else {
			if ((4U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x584f52);
			    vlTOPp->top__DOT__Decoder__DOT__alu_op = 1U;
			} else {
			    if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x534c4c);
				vlTOPp->top__DOT__Decoder__DOT__alu_op = 4U;
			    } else {
				if ((5U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				    if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x53524c);
					vlTOPp->top__DOT__Decoder__DOT__alu_op = 5U;
				    } else {
					if ((0x20U 
					     == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
					    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x535241);
					    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xbU;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	    VL_WRITEF("R-type %x :%x %s x%2#, x%2#, x%2#\n",
		      32,vlTOPp->top__DOT__Decoder__DOT__address,
		      32,vlTOPp->top__DOT__if_instr,
		      64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
		      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
		      5,vlTOPp->top__DOT__Decoder__DOT__rs1,
		      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs2));
	} else {
	    if (VL_UNLIKELY((0x13U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
		vlTOPp->top__DOT__Decoder__DOT__imm_signed 
		    = ((0xfffff000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->top__DOT__if_instr 
							       >> 0x1fU)))) 
				       << 0xcU)) | 
		       (0xfffU & (vlTOPp->top__DOT__if_instr 
				  >> 0x14U)));
		vlTOPp->top__DOT__Decoder__DOT__rs2 = 0U;
		if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
		    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x41444449);
		    vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
		} else {
		    if ((7U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x414e4449);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 0U;
		    } else {
			if ((6U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4f5249);
			    vlTOPp->top__DOT__Decoder__DOT__alu_op = 1U;
			} else {
			    if ((4U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x584f5249);
				vlTOPp->top__DOT__Decoder__DOT__alu_op = 3U;
			    } else {
				if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x534c4c49);
				    vlTOPp->top__DOT__Decoder__DOT__alu_op = 4U;
				} else {
				    if ((3U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x534c544955);
					vlTOPp->top__DOT__Decoder__DOT__alu_op = 6U;
				    } else {
					if ((5U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					    if ((0U 
						 == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
						vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x53524c49);
						vlTOPp->top__DOT__Decoder__DOT__alu_op = 5U;
					    } else {
						if (
						    (0x20U 
						     == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
						    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x53524149);
						    vlTOPp->top__DOT__Decoder__DOT__alu_op = 7U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
		VL_WRITEF("I-type %x :%x %s x%2#, x%2#, %11d\n",
			  32,vlTOPp->top__DOT__Decoder__DOT__address,
			  32,vlTOPp->top__DOT__if_instr,
			  64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
			  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
			  5,vlTOPp->top__DOT__Decoder__DOT__rs1,
			  32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
	    } else {
		if (VL_UNLIKELY((0x1bU == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
		    vlTOPp->top__DOT__Decoder__DOT__imm_signed 
			= ((0xfffff000U & (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__if_instr 
								   >> 0x1fU)))) 
					   << 0xcU)) 
			   | (0xfffU & (vlTOPp->top__DOT__if_instr 
					>> 0x14U)));
		    if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4144444957);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
		    } else {
			if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
			    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x534c4c4957);
			    vlTOPp->top__DOT__Decoder__DOT__alu_op = 4U;
			} else {
			    if ((5U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x53524c4957);
				    vlTOPp->top__DOT__Decoder__DOT__alu_op = 5U;
				} else {
				    if ((0x20U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct7))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5352414957);
					vlTOPp->top__DOT__Decoder__DOT__alu_op = 7U;
				    }
				}
			    }
			}
		    }
		    VL_WRITEF("I-Type %x :%x %s x%2#, x%2#, %11d\n",
			      32,vlTOPp->top__DOT__Decoder__DOT__address,
			      32,vlTOPp->top__DOT__if_instr,
			      64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
			      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
			      5,vlTOPp->top__DOT__Decoder__DOT__rs1,
			      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
		} else {
		    if (VL_UNLIKELY((0x67U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
			VL_WRITEF("I-Type %x :%x     JALR x%2#, x%2#, %11d\n",
				  32,vlTOPp->top__DOT__Decoder__DOT__address,
				  32,vlTOPp->top__DOT__if_instr,
				  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
				  5,vlTOPp->top__DOT__Decoder__DOT__rs1,
				  32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
			vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4a414c52);
			vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
		    } else {
			if (VL_UNLIKELY((3U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
			    if ((3U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4c44);
			    } else {
				if ((2U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4c57);
				} else {
				    if ((4U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4c4255);
				    }
				}
			    }
			    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0U;
			    VL_WRITEF("I-Type %x :%x %s x%2#, %11d(x%2#)\n",
				      32,vlTOPp->top__DOT__Decoder__DOT__address,
				      32,vlTOPp->top__DOT__if_instr,
				      64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
				      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
				      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed,
				      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs1));
			} else {
			    if (VL_UNLIKELY((0x23U 
					     == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
				vlTOPp->top__DOT__Decoder__DOT__imm_signed 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__if_instr 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | ((0xfe0U & 
					   (vlTOPp->top__DOT__if_instr 
					    >> 0x14U)) 
					  | (0x1fU 
					     & (vlTOPp->top__DOT__if_instr 
						>> 7U))));
				vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
				if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5342);
				} else {
				    if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5348);
				    } else {
					if ((2U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5357);
					} else {
					    if ((3U 
						 == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
						vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x5344);
					    }
					}
				    }
				}
				VL_WRITEF("S-Type %x :%x %s x%2#, %11d(x%2#)\n",
					  32,vlTOPp->top__DOT__Decoder__DOT__address,
					  32,vlTOPp->top__DOT__if_instr,
					  64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
					  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs2),
					  32,vlTOPp->top__DOT__Decoder__DOT__imm_signed,
					  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs1));
			    } else {
				if ((0x63U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode))) {
				    vlTOPp->top__DOT__Decoder__DOT__imm_signed 
					= ((0xffffe000U 
					    & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlTOPp->top__DOT__if_instr 
								       >> 0x1fU)))) 
					       << 0xdU)) 
					   | ((0x1000U 
					       & (vlTOPp->top__DOT__if_instr 
						  >> 0x13U)) 
					      | ((0x800U 
						  & (vlTOPp->top__DOT__if_instr 
						     << 4U)) 
						 | ((0x7e0U 
						     & (vlTOPp->top__DOT__if_instr 
							>> 0x14U)) 
						    | (0x1eU 
						       & (vlTOPp->top__DOT__if_instr 
							  >> 7U))))));
				    vlTOPp->top__DOT__Decoder__DOT__imm_unsigned 
					= ((0x800U 
					    & (vlTOPp->top__DOT__if_instr 
					       << 4U)) 
					   | ((0x7e0U 
					       & (vlTOPp->top__DOT__if_instr 
						  >> 0x14U)) 
					      | (0x1eU 
						 & (vlTOPp->top__DOT__if_instr 
						    >> 7U))));
				    if ((0U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424551);
					vlTOPp->top__DOT__Decoder__DOT__alu_op = 8U;
				    } else {
					if ((1U == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
					    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424e45);
					    vlTOPp->top__DOT__Decoder__DOT__alu_op = 9U;
					} else {
					    if ((4U 
						 == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
						vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424c54);
						vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xaU;
					    } else {
						if (
						    (5U 
						     == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
						    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424745);
						    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xbU;
						} else {
						    if (
							(6U 
							 == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
							vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x424c5455);
							vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xcU;
						    } else {
							if (
							    (7U 
							     == (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))) {
							    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x42474555);
							    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xdU;
							}
						    }
						}
					    }
					}
				    }
				    VL_WRITEF("B-Type %x :%x %s x%2#, x%2#, %11d\n",
					      32,vlTOPp->top__DOT__Decoder__DOT__address,
					      32,vlTOPp->top__DOT__if_instr,
					      64,vlTOPp->top__DOT__Decoder__DOT__decoded_instruction,
					      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rs1),
					      5,vlTOPp->top__DOT__Decoder__DOT__rs2,
					      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
				} else {
				    vlTOPp->top__DOT__Decoder__DOT__imm_signed 
					= (0xfffff000U 
					   & vlTOPp->top__DOT__if_instr);
				    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4c5549);
				    vlTOPp->top__DOT__Decoder__DOT__alu_op = 0U;
				    VL_WRITEF("%x :%x      LUI x%2#, %11d\n",
					      32,vlTOPp->top__DOT__Decoder__DOT__address,
					      32,vlTOPp->top__DOT__if_instr,
					      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
					      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if (VL_UNLIKELY((0x17U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
	    vlTOPp->top__DOT__Decoder__DOT__imm_signed 
		= (0xfffff000U & vlTOPp->top__DOT__if_instr);
	    vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4155495043);
	    vlTOPp->top__DOT__Decoder__DOT__alu_op = 2U;
	    VL_WRITEF("U-Type %x :%x    AUIPC x%2#, %11d\n",
		      32,vlTOPp->top__DOT__Decoder__DOT__address,
		      32,vlTOPp->top__DOT__if_instr,
		      5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
		      32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
	} else {
	    if (VL_UNLIKELY((0x6fU == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)))) {
		vlTOPp->top__DOT__Decoder__DOT__imm_signed 
		    = ((0xffe00000U & (VL_NEGATE_I((IData)(
							   (1U 
							    & (vlTOPp->top__DOT__if_instr 
							       >> 0x1fU)))) 
				       << 0x15U)) | 
		       ((0x100000U & (vlTOPp->top__DOT__if_instr 
				      >> 0xbU)) | (
						   (0xff000U 
						    & vlTOPp->top__DOT__if_instr) 
						   | ((0x800U 
						       & (vlTOPp->top__DOT__if_instr 
							  >> 9U)) 
						      | (0x7feU 
							 & (vlTOPp->top__DOT__if_instr 
							    >> 0x14U))))));
		vlTOPp->top__DOT__Decoder__DOT__decoded_instruction = VL_ULL(0x4a414c);
		vlTOPp->top__DOT__Decoder__DOT__alu_op = 0xeU;
		VL_WRITEF("J-Type %x :%x      JAL x%2#, %11d\n",
			  32,vlTOPp->top__DOT__Decoder__DOT__address,
			  32,vlTOPp->top__DOT__if_instr,
			  5,(IData)(vlTOPp->top__DOT__Decoder__DOT__rd),
			  32,vlTOPp->top__DOT__Decoder__DOT__imm_signed);
	    }
	}
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
	vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    hz32768timer = VL_RAND_RESET_I(1);
    entry = VL_RAND_RESET_Q(64);
    stackptr = VL_RAND_RESET_Q(64);
    satp = VL_RAND_RESET_Q(64);
    m_axi_awid = VL_RAND_RESET_I(13);
    m_axi_awaddr = VL_RAND_RESET_Q(64);
    m_axi_awlen = VL_RAND_RESET_I(8);
    m_axi_awsize = VL_RAND_RESET_I(3);
    m_axi_awburst = VL_RAND_RESET_I(2);
    m_axi_awlock = VL_RAND_RESET_I(1);
    m_axi_awcache = VL_RAND_RESET_I(4);
    m_axi_awprot = VL_RAND_RESET_I(3);
    m_axi_awvalid = VL_RAND_RESET_I(1);
    m_axi_awready = VL_RAND_RESET_I(1);
    m_axi_wdata = VL_RAND_RESET_Q(64);
    m_axi_wstrb = VL_RAND_RESET_I(8);
    m_axi_wlast = VL_RAND_RESET_I(1);
    m_axi_wvalid = VL_RAND_RESET_I(1);
    m_axi_wready = VL_RAND_RESET_I(1);
    m_axi_bid = VL_RAND_RESET_I(13);
    m_axi_bresp = VL_RAND_RESET_I(2);
    m_axi_bvalid = VL_RAND_RESET_I(1);
    m_axi_bready = VL_RAND_RESET_I(1);
    m_axi_arid = VL_RAND_RESET_I(13);
    m_axi_araddr = VL_RAND_RESET_Q(64);
    m_axi_arlen = VL_RAND_RESET_I(8);
    m_axi_arsize = VL_RAND_RESET_I(3);
    m_axi_arburst = VL_RAND_RESET_I(2);
    m_axi_arlock = VL_RAND_RESET_I(1);
    m_axi_arcache = VL_RAND_RESET_I(4);
    m_axi_arprot = VL_RAND_RESET_I(3);
    m_axi_arvalid = VL_RAND_RESET_I(1);
    m_axi_arready = VL_RAND_RESET_I(1);
    m_axi_rid = VL_RAND_RESET_I(13);
    m_axi_rdata = VL_RAND_RESET_Q(64);
    m_axi_rresp = VL_RAND_RESET_I(2);
    m_axi_rlast = VL_RAND_RESET_I(1);
    m_axi_rvalid = VL_RAND_RESET_I(1);
    m_axi_rready = VL_RAND_RESET_I(1);
    m_axi_acvalid = VL_RAND_RESET_I(1);
    m_axi_acready = VL_RAND_RESET_I(1);
    m_axi_acaddr = VL_RAND_RESET_Q(64);
    m_axi_acsnoop = VL_RAND_RESET_I(4);
    top__DOT__pc = VL_RAND_RESET_Q(64);
    top__DOT__instruction = VL_RAND_RESET_Q(64);
    top__DOT__state = VL_RAND_RESET_I(3);
    top__DOT__next_state = VL_RAND_RESET_I(3);
    top__DOT__next_pc = VL_RAND_RESET_Q(64);
    top__DOT__fetched_instr = VL_RAND_RESET_Q(64);
    top__DOT__display_addr = VL_RAND_RESET_Q(64);
    top__DOT__next_display_addr = VL_RAND_RESET_Q(64);
    top__DOT__if_instr = VL_RAND_RESET_I(32);
    top__DOT__fetch_inst__DOT__state = VL_RAND_RESET_I(3);
    top__DOT__fetch_inst__DOT__next_state = VL_RAND_RESET_I(3);
    top__DOT__fetch_inst__DOT__pc = VL_RAND_RESET_Q(64);
    top__DOT__fetch_inst__DOT__next_pc = VL_RAND_RESET_Q(64);
    top__DOT__fetch_inst__DOT__fetched_instr = VL_RAND_RESET_Q(64);
    top__DOT__fetch_inst__DOT__display_addr = VL_RAND_RESET_Q(64);
    top__DOT__fetch_inst__DOT__next_display_addr = VL_RAND_RESET_Q(64);
    { int __Vi0=0; for (; __Vi0<1000; ++__Vi0) {
	    top__DOT__fetch_inst__DOT__instruction_array[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__fetch_inst__DOT__index = VL_RAND_RESET_I(10);
    top__DOT__fetch_inst__DOT__pc_fetch = VL_RAND_RESET_I(10);
    top__DOT__fetch_inst__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    top__DOT__fetch_inst__DOT____Vlvbound2 = VL_RAND_RESET_I(32);
    top__DOT__Decoder__DOT__address = VL_RAND_RESET_I(32);
    top__DOT__Decoder__DOT__rs1 = VL_RAND_RESET_I(5);
    top__DOT__Decoder__DOT__rs2 = VL_RAND_RESET_I(5);
    top__DOT__Decoder__DOT__rd = VL_RAND_RESET_I(5);
    top__DOT__Decoder__DOT__opcode = VL_RAND_RESET_I(7);
    top__DOT__Decoder__DOT__funct7 = VL_RAND_RESET_I(7);
    top__DOT__Decoder__DOT__funct3 = VL_RAND_RESET_I(3);
    top__DOT__Decoder__DOT__imm_signed = VL_RAND_RESET_I(32);
    top__DOT__Decoder__DOT__imm_unsigned = VL_RAND_RESET_I(32);
    top__DOT__Decoder__DOT__decoded_instruction = VL_RAND_RESET_Q(64);
    top__DOT__Decoder__DOT__alu_op = VL_RAND_RESET_I(4);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void Vtop::_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_configure_coverage\n"); );
}
