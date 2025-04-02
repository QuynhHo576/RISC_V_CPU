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
    // INITIAL at top.sv:344
    VL_WRITEF("Initializing top, entry point = 0x%x\n",
	      64,vlTOPp->entry);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vtask_top__DOT__decoding__0__rd,11,7);
    VL_SIG8(__Vtask_top__DOT__decoding__0__rs1,4,0);
    VL_SIG8(__Vtask_top__DOT__decoding__0__rs2,4,0);
    VL_SIG8(__Vtask_top__DOT__decoding__0__opcode,6,0);
    VL_SIG8(__Vtask_top__DOT__decoding__0__funct3,2,0);
    VL_SIG8(__Vtask_top__DOT__decoding__0__funct7,6,0);
    VL_SIG8(__Vtask_top__DOT__decoding__1__rd,11,7);
    VL_SIG8(__Vtask_top__DOT__decoding__1__rs1,4,0);
    VL_SIG8(__Vtask_top__DOT__decoding__1__rs2,4,0);
    VL_SIG8(__Vtask_top__DOT__decoding__1__opcode,6,0);
    VL_SIG8(__Vtask_top__DOT__decoding__1__funct3,2,0);
    VL_SIG8(__Vtask_top__DOT__decoding__1__funct7,6,0);
    VL_SIG8(__Vdly__m_axi_arvalid,0,0);
    VL_SIG8(__Vdly__m_axi_rready,0,0);
    //char	__VpadToAlign38[2];
    VL_SIG(__Vtask_top__DOT__decoding__0__address,31,0);
    VL_SIG(__Vtask_top__DOT__decoding__0__input_bin,31,0);
    VL_SIG(__Vtask_top__DOT__decoding__0__imm,31,0);
    VL_SIG(__Vtask_top__DOT__decoding__1__address,31,0);
    VL_SIG(__Vtask_top__DOT__decoding__1__input_bin,31,0);
    VL_SIG(__Vtask_top__DOT__decoding__1__imm,31,0);
    VL_SIG64(__Vtask_top__DOT__decoding__0__decoded_instruction,63,0);
    VL_SIG64(__Vtask_top__DOT__decoding__1__decoded_instruction,63,0);
    VL_SIG64(__Vdly__top__DOT__fetched_instr,63,0);
    VL_SIG64(__Vdly__top__DOT__next_display_addr,63,0);
    // Body
    __Vdly__top__DOT__fetched_instr = vlTOPp->top__DOT__fetched_instr;
    __Vdly__top__DOT__next_display_addr = vlTOPp->top__DOT__next_display_addr;
    __Vdly__m_axi_arvalid = vlTOPp->m_axi_arvalid;
    __Vdly__m_axi_rready = vlTOPp->m_axi_rready;
    // ALWAYS at top.sv:135
    vlTOPp->m_axi_araddr = vlTOPp->top__DOT__pc;
    vlTOPp->m_axi_arlen = 7U;
    vlTOPp->m_axi_arsize = 0U;
    vlTOPp->m_axi_arburst = 2U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	__Vdly__m_axi_arvalid = (0U == (IData)(vlTOPp->top__DOT__state));
	if (((IData)(vlTOPp->m_axi_arvalid) & (IData)(vlTOPp->m_axi_arready))) {
	    __Vdly__m_axi_arvalid = 0U;
	}
	if (((1U == (IData)(vlTOPp->top__DOT__state)) 
	     & (IData)(vlTOPp->m_axi_rvalid))) {
	    __Vdly__m_axi_rready = 1U;
	}
	if (((IData)(vlTOPp->m_axi_rvalid) & (IData)(vlTOPp->m_axi_rready))) {
	    __Vdly__m_axi_rready = 0U;
	    __Vdly__top__DOT__fetched_instr = vlTOPp->m_axi_rdata;
	}
	if ((4U == (IData)(vlTOPp->top__DOT__state))) {
	    // Function: decoding at top.sv:159
	    // Function: decoding at top.sv:160
	    __Vtask_top__DOT__decoding__0__input_bin 
		= (IData)(vlTOPp->top__DOT__fetched_instr);
	    __Vtask_top__DOT__decoding__0__address 
		= (IData)(vlTOPp->top__DOT__display_addr);
	    __Vdly__top__DOT__next_display_addr = (VL_ULL(8) 
						   + vlTOPp->top__DOT__display_addr);
	    __Vtask_top__DOT__decoding__0__opcode = 
		(0x7fU & __Vtask_top__DOT__decoding__0__input_bin);
	    __Vtask_top__DOT__decoding__0__rd = (0x1fU 
						 & (__Vtask_top__DOT__decoding__0__input_bin 
						    >> 7U));
	    __Vtask_top__DOT__decoding__0__funct3 = 
		(7U & (__Vtask_top__DOT__decoding__0__input_bin 
		       >> 0xcU));
	    __Vtask_top__DOT__decoding__0__funct7 = 
		(0x7fU & (__Vtask_top__DOT__decoding__0__input_bin 
			  >> 0x19U));
	    __Vtask_top__DOT__decoding__0__rs1 = (0x1fU 
						  & (__Vtask_top__DOT__decoding__0__input_bin 
						     >> 0xfU));
	    __Vtask_top__DOT__decoding__0__rs2 = (0x1fU 
						  & (__Vtask_top__DOT__decoding__0__input_bin 
						     >> 0x14U));
	    __Vtask_top__DOT__decoding__0__imm = (0xfffU 
						  & (__Vtask_top__DOT__decoding__0__input_bin 
						     >> 0x14U));
	    if (((((((((0x33U == (IData)(__Vtask_top__DOT__decoding__0__opcode)) 
		       | (0x13U == (IData)(__Vtask_top__DOT__decoding__0__opcode))) 
		      | (0x1bU == (IData)(__Vtask_top__DOT__decoding__0__opcode))) 
		     | (0x23U == (IData)(__Vtask_top__DOT__decoding__0__opcode))) 
		    | (0x63U == (IData)(__Vtask_top__DOT__decoding__0__opcode))) 
		   | (0x37U == (IData)(__Vtask_top__DOT__decoding__0__opcode))) 
		  | (0x17U == (IData)(__Vtask_top__DOT__decoding__0__opcode))) 
		 | (0x6fU == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
		if (VL_UNLIKELY((0x33U == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
		    if ((0U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
			if ((0U == (IData)(__Vtask_top__DOT__decoding__0__funct7))) {
			    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x414444);
			} else {
			    if ((0x20U == (IData)(__Vtask_top__DOT__decoding__0__funct7))) {
				__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x535542);
			    }
			}
		    } else {
			if ((7U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
			    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x414e44);
			} else {
			    if ((6U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4f52);
			    } else {
				if ((4U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x584f52);
				} else {
				    if ((1U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x534c4c);
				    } else {
					if ((5U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					    if ((0U 
						 == (IData)(__Vtask_top__DOT__decoding__0__funct7))) {
						__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x53524c);
					    } else {
						if (
						    (0x20U 
						     == (IData)(__Vtask_top__DOT__decoding__0__funct7))) {
						    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x535241);
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		    VL_WRITEF("%x :%x %s x%2#, x%2#, x%2#\n",
			      32,__Vtask_top__DOT__decoding__0__address,
			      32,__Vtask_top__DOT__decoding__0__input_bin,
			      64,__Vtask_top__DOT__decoding__0__decoded_instruction,
			      5,(IData)(__Vtask_top__DOT__decoding__0__rd),
			      5,__Vtask_top__DOT__decoding__0__rs1,
			      5,(IData)(__Vtask_top__DOT__decoding__0__rs2));
		} else {
		    if (VL_UNLIKELY((0x13U == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
			__Vtask_top__DOT__decoding__0__imm 
			    = ((0xfffff000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (__Vtask_top__DOT__decoding__0__input_bin 
								       >> 0x1fU)))) 
					       << 0xcU)) 
			       | (0xfffU & (__Vtask_top__DOT__decoding__0__input_bin 
					    >> 0x14U)));
			if ((0U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
			    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x41444449);
			} else {
			    if ((7U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x414e4449);
			    } else {
				if ((6U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4f5249);
				} else {
				    if ((4U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x584f5249);
				    } else {
					if ((1U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x534c4c49);
					} else {
					    if ((3U 
						 == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
						__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x534c544955);
					    } else {
						if (
						    (5U 
						     == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
						    if (
							(0U 
							 == (IData)(__Vtask_top__DOT__decoding__0__funct7))) {
							__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x53524c49);
						    } else {
							if (
							    (0x20U 
							     == (IData)(__Vtask_top__DOT__decoding__0__funct7))) {
							    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x53524149);
							}
						    }
						}
					    }
					}
				    }
				}
			    }
			}
			VL_WRITEF("%x :%x %s x%2#, x%2#, %11d\n",
				  32,__Vtask_top__DOT__decoding__0__address,
				  32,__Vtask_top__DOT__decoding__0__input_bin,
				  64,__Vtask_top__DOT__decoding__0__decoded_instruction,
				  5,(IData)(__Vtask_top__DOT__decoding__0__rd),
				  5,__Vtask_top__DOT__decoding__0__rs1,
				  32,__Vtask_top__DOT__decoding__0__imm);
		    } else {
			if (VL_UNLIKELY((0x1bU == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
			    if ((0U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4144444957);
			    } else {
				if ((1U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x534c4c4957);
				} else {
				    if ((5U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					if ((0U == (IData)(__Vtask_top__DOT__decoding__0__funct7))) {
					    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x53524c4957);
					} else {
					    if ((0x20U 
						 == (IData)(__Vtask_top__DOT__decoding__0__funct7))) {
						__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x5352414957);
					    }
					}
				    }
				}
			    }
			    VL_WRITEF("%x :%x %s x%2#, x%2#, %11d\n",
				      32,__Vtask_top__DOT__decoding__0__address,
				      32,__Vtask_top__DOT__decoding__0__input_bin,
				      64,__Vtask_top__DOT__decoding__0__decoded_instruction,
				      5,(IData)(__Vtask_top__DOT__decoding__0__rd),
				      5,__Vtask_top__DOT__decoding__0__rs1,
				      32,__Vtask_top__DOT__decoding__0__imm);
			} else {
			    if (VL_UNLIKELY((0x23U 
					     == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
				__Vtask_top__DOT__decoding__0__imm 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (__Vtask_top__DOT__decoding__0__input_bin 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | ((0xfe0U & 
					   (__Vtask_top__DOT__decoding__0__input_bin 
					    >> 0x14U)) 
					  | (0x1fU 
					     & (__Vtask_top__DOT__decoding__0__input_bin 
						>> 7U))));
				if ((0U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x5342);
				} else {
				    if ((1U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x5348);
				    } else {
					if ((2U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x5357);
					} else {
					    if ((3U 
						 == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
						__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x5344);
					    }
					}
				    }
				}
				VL_WRITEF("%x :%x %s x%2#, %11d(x%2#)\n",
					  32,__Vtask_top__DOT__decoding__0__address,
					  32,__Vtask_top__DOT__decoding__0__input_bin,
					  64,__Vtask_top__DOT__decoding__0__decoded_instruction,
					  5,(IData)(__Vtask_top__DOT__decoding__0__rs2),
					  32,__Vtask_top__DOT__decoding__0__imm,
					  5,(IData)(__Vtask_top__DOT__decoding__0__rs1));
			    } else {
				if (VL_UNLIKELY((0x63U 
						 == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
				    __Vtask_top__DOT__decoding__0__imm 
					= ((0xffffe000U 
					    & (VL_NEGATE_I((IData)(
								   (1U 
								    & (__Vtask_top__DOT__decoding__0__input_bin 
								       >> 0x1fU)))) 
					       << 0xdU)) 
					   | ((0x1000U 
					       & (__Vtask_top__DOT__decoding__0__input_bin 
						  >> 0x13U)) 
					      | ((0x800U 
						  & (__Vtask_top__DOT__decoding__0__input_bin 
						     << 4U)) 
						 | ((0x7e0U 
						     & (__Vtask_top__DOT__decoding__0__input_bin 
							>> 0x14U)) 
						    | (0x1eU 
						       & (__Vtask_top__DOT__decoding__0__input_bin 
							  >> 7U))))));
				    if ((0U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x424551);
				    } else {
					if ((1U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
					    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x424e45);
					} else {
					    if ((4U 
						 == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
						__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x424c54);
					    } else {
						if (
						    (5U 
						     == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
						    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x424745);
						}
					    }
					}
				    }
				    VL_WRITEF("%x :%x %s x%2#, x%2#, %11d\n",
					      32,__Vtask_top__DOT__decoding__0__address,
					      32,__Vtask_top__DOT__decoding__0__input_bin,
					      64,__Vtask_top__DOT__decoding__0__decoded_instruction,
					      5,(IData)(__Vtask_top__DOT__decoding__0__rs1),
					      5,__Vtask_top__DOT__decoding__0__rs2,
					      32,__Vtask_top__DOT__decoding__0__imm);
				} else {
				    if (VL_UNLIKELY(
						    (0x37U 
						     == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
					__Vtask_top__DOT__decoding__0__imm 
					    = (0xfffff000U 
					       & __Vtask_top__DOT__decoding__0__input_bin);
					__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4c5549);
					VL_WRITEF("%x :%x      LUI x%2#, %11d\n",
						  32,
						  __Vtask_top__DOT__decoding__0__address,
						  32,
						  __Vtask_top__DOT__decoding__0__input_bin,
						  5,
						  (IData)(__Vtask_top__DOT__decoding__0__rd),
						  32,
						  __Vtask_top__DOT__decoding__0__imm);
				    } else {
					if ((0x17U 
					     == (IData)(__Vtask_top__DOT__decoding__0__opcode))) {
					    __Vtask_top__DOT__decoding__0__imm 
						= (0xfffff000U 
						   & __Vtask_top__DOT__decoding__0__input_bin);
					    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4155495043);
					    VL_WRITEF("%x :%x    AUIPC x%2#, %11d\n",
						      32,
						      __Vtask_top__DOT__decoding__0__address,
						      32,
						      __Vtask_top__DOT__decoding__0__input_bin,
						      5,
						      (IData)(__Vtask_top__DOT__decoding__0__rd),
						      32,
						      __Vtask_top__DOT__decoding__0__imm);
					} else {
					    __Vtask_top__DOT__decoding__0__imm 
						= (
						   (0xffe00000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (__Vtask_top__DOT__decoding__0__input_bin 
									       >> 0x1fU)))) 
						       << 0x15U)) 
						   | ((0x100000U 
						       & (__Vtask_top__DOT__decoding__0__input_bin 
							  >> 0xbU)) 
						      | ((0xff000U 
							  & __Vtask_top__DOT__decoding__0__input_bin) 
							 | ((0x800U 
							     & (__Vtask_top__DOT__decoding__0__input_bin 
								>> 9U)) 
							    | (0x7feU 
							       & (__Vtask_top__DOT__decoding__0__input_bin 
								  >> 0x14U))))));
					    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4a414c);
					    VL_WRITEF("%x :%x      JAL x%2#, %11d\n",
						      32,
						      __Vtask_top__DOT__decoding__0__address,
						      32,
						      __Vtask_top__DOT__decoding__0__input_bin,
						      5,
						      (IData)(__Vtask_top__DOT__decoding__0__rd),
						      32,
						      __Vtask_top__DOT__decoding__0__imm);
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if (VL_UNLIKELY((0x67U == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
		    VL_WRITEF("%x :%x     JALR x%2#, x%2#, %11d\n",
			      32,__Vtask_top__DOT__decoding__0__address,
			      32,__Vtask_top__DOT__decoding__0__input_bin,
			      5,(IData)(__Vtask_top__DOT__decoding__0__rd),
			      5,__Vtask_top__DOT__decoding__0__rs1,
			      32,__Vtask_top__DOT__decoding__0__imm);
		    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4a414c52);
		} else {
		    if (VL_UNLIKELY((3U == (IData)(__Vtask_top__DOT__decoding__0__opcode)))) {
			if ((3U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
			    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4c44);
			} else {
			    if ((2U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				__Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4c57);
			    } else {
				if ((4U == (IData)(__Vtask_top__DOT__decoding__0__funct3))) {
				    __Vtask_top__DOT__decoding__0__decoded_instruction = VL_ULL(0x4c4255);
				}
			    }
			}
			VL_WRITEF("%x :%x %s x%2#, %11d(x%2#)\n",
				  32,__Vtask_top__DOT__decoding__0__address,
				  32,__Vtask_top__DOT__decoding__0__input_bin,
				  64,__Vtask_top__DOT__decoding__0__decoded_instruction,
				  5,(IData)(__Vtask_top__DOT__decoding__0__rd),
				  32,__Vtask_top__DOT__decoding__0__imm,
				  5,(IData)(__Vtask_top__DOT__decoding__0__rs1));
		    }
		}
	    }
	    __Vtask_top__DOT__decoding__1__input_bin 
		= (IData)((vlTOPp->top__DOT__fetched_instr 
			   >> 0x20U));
	    __Vtask_top__DOT__decoding__1__address 
		= ((IData)(4U) + (IData)(vlTOPp->top__DOT__display_addr));
	    __Vtask_top__DOT__decoding__1__opcode = 
		(0x7fU & __Vtask_top__DOT__decoding__1__input_bin);
	    __Vtask_top__DOT__decoding__1__rd = (0x1fU 
						 & (__Vtask_top__DOT__decoding__1__input_bin 
						    >> 7U));
	    __Vtask_top__DOT__decoding__1__funct3 = 
		(7U & (__Vtask_top__DOT__decoding__1__input_bin 
		       >> 0xcU));
	    __Vtask_top__DOT__decoding__1__funct7 = 
		(0x7fU & (__Vtask_top__DOT__decoding__1__input_bin 
			  >> 0x19U));
	    __Vtask_top__DOT__decoding__1__rs1 = (0x1fU 
						  & (__Vtask_top__DOT__decoding__1__input_bin 
						     >> 0xfU));
	    __Vtask_top__DOT__decoding__1__rs2 = (0x1fU 
						  & (__Vtask_top__DOT__decoding__1__input_bin 
						     >> 0x14U));
	    __Vtask_top__DOT__decoding__1__imm = (0xfffU 
						  & (__Vtask_top__DOT__decoding__1__input_bin 
						     >> 0x14U));
	    if (((((((((0x33U == (IData)(__Vtask_top__DOT__decoding__1__opcode)) 
		       | (0x13U == (IData)(__Vtask_top__DOT__decoding__1__opcode))) 
		      | (0x1bU == (IData)(__Vtask_top__DOT__decoding__1__opcode))) 
		     | (0x23U == (IData)(__Vtask_top__DOT__decoding__1__opcode))) 
		    | (0x63U == (IData)(__Vtask_top__DOT__decoding__1__opcode))) 
		   | (0x37U == (IData)(__Vtask_top__DOT__decoding__1__opcode))) 
		  | (0x17U == (IData)(__Vtask_top__DOT__decoding__1__opcode))) 
		 | (0x6fU == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
		if (VL_UNLIKELY((0x33U == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
		    if ((0U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
			if ((0U == (IData)(__Vtask_top__DOT__decoding__1__funct7))) {
			    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x414444);
			} else {
			    if ((0x20U == (IData)(__Vtask_top__DOT__decoding__1__funct7))) {
				__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x535542);
			    }
			}
		    } else {
			if ((7U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
			    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x414e44);
			} else {
			    if ((6U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4f52);
			    } else {
				if ((4U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x584f52);
				} else {
				    if ((1U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x534c4c);
				    } else {
					if ((5U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					    if ((0U 
						 == (IData)(__Vtask_top__DOT__decoding__1__funct7))) {
						__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x53524c);
					    } else {
						if (
						    (0x20U 
						     == (IData)(__Vtask_top__DOT__decoding__1__funct7))) {
						    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x535241);
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		    VL_WRITEF("%x :%x %s x%2#, x%2#, x%2#\n",
			      32,__Vtask_top__DOT__decoding__1__address,
			      32,__Vtask_top__DOT__decoding__1__input_bin,
			      64,__Vtask_top__DOT__decoding__1__decoded_instruction,
			      5,(IData)(__Vtask_top__DOT__decoding__1__rd),
			      5,__Vtask_top__DOT__decoding__1__rs1,
			      5,(IData)(__Vtask_top__DOT__decoding__1__rs2));
		} else {
		    if (VL_UNLIKELY((0x13U == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
			__Vtask_top__DOT__decoding__1__imm 
			    = ((0xfffff000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (__Vtask_top__DOT__decoding__1__input_bin 
								       >> 0x1fU)))) 
					       << 0xcU)) 
			       | (0xfffU & (__Vtask_top__DOT__decoding__1__input_bin 
					    >> 0x14U)));
			if ((0U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
			    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x41444449);
			} else {
			    if ((7U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x414e4449);
			    } else {
				if ((6U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4f5249);
				} else {
				    if ((4U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x584f5249);
				    } else {
					if ((1U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x534c4c49);
					} else {
					    if ((3U 
						 == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
						__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x534c544955);
					    } else {
						if (
						    (5U 
						     == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
						    if (
							(0U 
							 == (IData)(__Vtask_top__DOT__decoding__1__funct7))) {
							__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x53524c49);
						    } else {
							if (
							    (0x20U 
							     == (IData)(__Vtask_top__DOT__decoding__1__funct7))) {
							    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x53524149);
							}
						    }
						}
					    }
					}
				    }
				}
			    }
			}
			VL_WRITEF("%x :%x %s x%2#, x%2#, %11d\n",
				  32,__Vtask_top__DOT__decoding__1__address,
				  32,__Vtask_top__DOT__decoding__1__input_bin,
				  64,__Vtask_top__DOT__decoding__1__decoded_instruction,
				  5,(IData)(__Vtask_top__DOT__decoding__1__rd),
				  5,__Vtask_top__DOT__decoding__1__rs1,
				  32,__Vtask_top__DOT__decoding__1__imm);
		    } else {
			if (VL_UNLIKELY((0x1bU == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
			    if ((0U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4144444957);
			    } else {
				if ((1U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x534c4c4957);
				} else {
				    if ((5U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					if ((0U == (IData)(__Vtask_top__DOT__decoding__1__funct7))) {
					    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x53524c4957);
					} else {
					    if ((0x20U 
						 == (IData)(__Vtask_top__DOT__decoding__1__funct7))) {
						__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x5352414957);
					    }
					}
				    }
				}
			    }
			    VL_WRITEF("%x :%x %s x%2#, x%2#, %11d\n",
				      32,__Vtask_top__DOT__decoding__1__address,
				      32,__Vtask_top__DOT__decoding__1__input_bin,
				      64,__Vtask_top__DOT__decoding__1__decoded_instruction,
				      5,(IData)(__Vtask_top__DOT__decoding__1__rd),
				      5,__Vtask_top__DOT__decoding__1__rs1,
				      32,__Vtask_top__DOT__decoding__1__imm);
			} else {
			    if (VL_UNLIKELY((0x23U 
					     == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
				__Vtask_top__DOT__decoding__1__imm 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (__Vtask_top__DOT__decoding__1__input_bin 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | ((0xfe0U & 
					   (__Vtask_top__DOT__decoding__1__input_bin 
					    >> 0x14U)) 
					  | (0x1fU 
					     & (__Vtask_top__DOT__decoding__1__input_bin 
						>> 7U))));
				if ((0U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x5342);
				} else {
				    if ((1U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x5348);
				    } else {
					if ((2U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x5357);
					} else {
					    if ((3U 
						 == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
						__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x5344);
					    }
					}
				    }
				}
				VL_WRITEF("%x :%x %s x%2#, %11d(x%2#)\n",
					  32,__Vtask_top__DOT__decoding__1__address,
					  32,__Vtask_top__DOT__decoding__1__input_bin,
					  64,__Vtask_top__DOT__decoding__1__decoded_instruction,
					  5,(IData)(__Vtask_top__DOT__decoding__1__rs2),
					  32,__Vtask_top__DOT__decoding__1__imm,
					  5,(IData)(__Vtask_top__DOT__decoding__1__rs1));
			    } else {
				if (VL_UNLIKELY((0x63U 
						 == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
				    __Vtask_top__DOT__decoding__1__imm 
					= ((0xffffe000U 
					    & (VL_NEGATE_I((IData)(
								   (1U 
								    & (__Vtask_top__DOT__decoding__1__input_bin 
								       >> 0x1fU)))) 
					       << 0xdU)) 
					   | ((0x1000U 
					       & (__Vtask_top__DOT__decoding__1__input_bin 
						  >> 0x13U)) 
					      | ((0x800U 
						  & (__Vtask_top__DOT__decoding__1__input_bin 
						     << 4U)) 
						 | ((0x7e0U 
						     & (__Vtask_top__DOT__decoding__1__input_bin 
							>> 0x14U)) 
						    | (0x1eU 
						       & (__Vtask_top__DOT__decoding__1__input_bin 
							  >> 7U))))));
				    if ((0U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x424551);
				    } else {
					if ((1U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
					    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x424e45);
					} else {
					    if ((4U 
						 == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
						__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x424c54);
					    } else {
						if (
						    (5U 
						     == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
						    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x424745);
						}
					    }
					}
				    }
				    VL_WRITEF("%x :%x %s x%2#, x%2#, %11d\n",
					      32,__Vtask_top__DOT__decoding__1__address,
					      32,__Vtask_top__DOT__decoding__1__input_bin,
					      64,__Vtask_top__DOT__decoding__1__decoded_instruction,
					      5,(IData)(__Vtask_top__DOT__decoding__1__rs1),
					      5,__Vtask_top__DOT__decoding__1__rs2,
					      32,__Vtask_top__DOT__decoding__1__imm);
				} else {
				    if (VL_UNLIKELY(
						    (0x37U 
						     == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
					__Vtask_top__DOT__decoding__1__imm 
					    = (0xfffff000U 
					       & __Vtask_top__DOT__decoding__1__input_bin);
					__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4c5549);
					VL_WRITEF("%x :%x      LUI x%2#, %11d\n",
						  32,
						  __Vtask_top__DOT__decoding__1__address,
						  32,
						  __Vtask_top__DOT__decoding__1__input_bin,
						  5,
						  (IData)(__Vtask_top__DOT__decoding__1__rd),
						  32,
						  __Vtask_top__DOT__decoding__1__imm);
				    } else {
					if ((0x17U 
					     == (IData)(__Vtask_top__DOT__decoding__1__opcode))) {
					    __Vtask_top__DOT__decoding__1__imm 
						= (0xfffff000U 
						   & __Vtask_top__DOT__decoding__1__input_bin);
					    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4155495043);
					    VL_WRITEF("%x :%x    AUIPC x%2#, %11d\n",
						      32,
						      __Vtask_top__DOT__decoding__1__address,
						      32,
						      __Vtask_top__DOT__decoding__1__input_bin,
						      5,
						      (IData)(__Vtask_top__DOT__decoding__1__rd),
						      32,
						      __Vtask_top__DOT__decoding__1__imm);
					} else {
					    __Vtask_top__DOT__decoding__1__imm 
						= (
						   (0xffe00000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (__Vtask_top__DOT__decoding__1__input_bin 
									       >> 0x1fU)))) 
						       << 0x15U)) 
						   | ((0x100000U 
						       & (__Vtask_top__DOT__decoding__1__input_bin 
							  >> 0xbU)) 
						      | ((0xff000U 
							  & __Vtask_top__DOT__decoding__1__input_bin) 
							 | ((0x800U 
							     & (__Vtask_top__DOT__decoding__1__input_bin 
								>> 9U)) 
							    | (0x7feU 
							       & (__Vtask_top__DOT__decoding__1__input_bin 
								  >> 0x14U))))));
					    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4a414c);
					    VL_WRITEF("%x :%x      JAL x%2#, %11d\n",
						      32,
						      __Vtask_top__DOT__decoding__1__address,
						      32,
						      __Vtask_top__DOT__decoding__1__input_bin,
						      5,
						      (IData)(__Vtask_top__DOT__decoding__1__rd),
						      32,
						      __Vtask_top__DOT__decoding__1__imm);
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if (VL_UNLIKELY((0x67U == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
		    VL_WRITEF("%x :%x     JALR x%2#, x%2#, %11d\n",
			      32,__Vtask_top__DOT__decoding__1__address,
			      32,__Vtask_top__DOT__decoding__1__input_bin,
			      5,(IData)(__Vtask_top__DOT__decoding__1__rd),
			      5,__Vtask_top__DOT__decoding__1__rs1,
			      32,__Vtask_top__DOT__decoding__1__imm);
		    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4a414c52);
		} else {
		    if (VL_UNLIKELY((3U == (IData)(__Vtask_top__DOT__decoding__1__opcode)))) {
			if ((3U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
			    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4c44);
			} else {
			    if ((2U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				__Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4c57);
			    } else {
				if ((4U == (IData)(__Vtask_top__DOT__decoding__1__funct3))) {
				    __Vtask_top__DOT__decoding__1__decoded_instruction = VL_ULL(0x4c4255);
				}
			    }
			}
			VL_WRITEF("%x :%x %s x%2#, %11d(x%2#)\n",
				  32,__Vtask_top__DOT__decoding__1__address,
				  32,__Vtask_top__DOT__decoding__1__input_bin,
				  64,__Vtask_top__DOT__decoding__1__decoded_instruction,
				  5,(IData)(__Vtask_top__DOT__decoding__1__rd),
				  32,__Vtask_top__DOT__decoding__1__imm,
				  5,(IData)(__Vtask_top__DOT__decoding__1__rs1));
		    }
		}
	    }
	}
    }
    vlTOPp->top__DOT__fetched_instr = __Vdly__top__DOT__fetched_instr;
    vlTOPp->m_axi_arvalid = __Vdly__m_axi_arvalid;
    vlTOPp->m_axi_rready = __Vdly__m_axi_rready;
    // ALWAYS at top.sv:175
    vlTOPp->top__DOT__display_addr = vlTOPp->top__DOT__next_display_addr;
    // ALWAYS at top.sv:169
    if (vlTOPp->reset) {
	vlTOPp->top__DOT__pc = vlTOPp->entry;
	vlTOPp->top__DOT__state = 0U;
    } else {
	vlTOPp->top__DOT__state = vlTOPp->top__DOT__next_state;
    }
    vlTOPp->top__DOT__pc = vlTOPp->top__DOT__next_pc;
    vlTOPp->top__DOT__next_display_addr = __Vdly__top__DOT__next_display_addr;
}

VL_INLINE_OPT void Vtop::_combo__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_combo__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top.sv:107
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
	if ((0U == (IData)(vlTOPp->top__DOT__state))) {
	    if (((IData)(vlTOPp->m_axi_arready) & (IData)(vlTOPp->m_axi_arvalid))) {
		vlTOPp->top__DOT__next_state = 1U;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->top__DOT__state))) {
		if (((IData)(vlTOPp->m_axi_rvalid) 
		     & (IData)(vlTOPp->m_axi_rready))) {
		    if (VL_UNLIKELY((VL_ULL(0) == vlTOPp->m_axi_rdata))) {
			vl_finish("top.sv",116,"");
		    }
		    vlTOPp->top__DOT__next_state = 4U;
		}
	    } else {
		if ((4U == (IData)(vlTOPp->top__DOT__state))) {
		    if (vlTOPp->m_axi_rlast) {
			if ((1U & (~ (IData)(vlTOPp->m_axi_rvalid)))) {
			    vlTOPp->top__DOT__next_pc 
				= (VL_ULL(0x40) + vlTOPp->top__DOT__pc);
			    vlTOPp->top__DOT__next_state = 0U;
			}
		    } else {
			vlTOPp->top__DOT__next_state = 1U;
		    }
		}
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
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
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
    vlTOPp->_combo__TOP__3(vlSymsp);
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
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}

void Vtop::_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_configure_coverage\n"); );
}
