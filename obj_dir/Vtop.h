// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

class Vtop__Syms;
class Vtop___024unit;
class VerilatedVcd;

//----------

VL_MODULE(Vtop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop___024unit*    	__PVT____024unit;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(hz32768timer,0,0);
    VL_OUT8(m_axi_awlen,7,0);
    VL_OUT8(m_axi_awsize,2,0);
    VL_OUT8(m_axi_awburst,1,0);
    VL_OUT8(m_axi_awlock,0,0);
    VL_OUT8(m_axi_awcache,3,0);
    VL_OUT8(m_axi_awprot,2,0);
    VL_OUT8(m_axi_awvalid,0,0);
    VL_IN8(m_axi_awready,0,0);
    VL_OUT8(m_axi_wstrb,7,0);
    VL_OUT8(m_axi_wlast,0,0);
    VL_OUT8(m_axi_wvalid,0,0);
    VL_IN8(m_axi_wready,0,0);
    VL_IN8(m_axi_bresp,1,0);
    VL_IN8(m_axi_bvalid,0,0);
    VL_OUT8(m_axi_bready,0,0);
    VL_OUT8(m_axi_arlen,7,0);
    VL_OUT8(m_axi_arsize,2,0);
    VL_OUT8(m_axi_arburst,1,0);
    VL_OUT8(m_axi_arlock,0,0);
    VL_OUT8(m_axi_arcache,3,0);
    VL_OUT8(m_axi_arprot,2,0);
    VL_OUT8(m_axi_arvalid,0,0);
    VL_IN8(m_axi_arready,0,0);
    VL_IN8(m_axi_rresp,1,0);
    VL_IN8(m_axi_rlast,0,0);
    VL_IN8(m_axi_rvalid,0,0);
    VL_OUT8(m_axi_rready,0,0);
    VL_IN8(m_axi_acvalid,0,0);
    VL_OUT8(m_axi_acready,0,0);
    VL_IN8(m_axi_acsnoop,3,0);
    //char	__VpadToAlign33[1];
    VL_OUT16(m_axi_awid,12,0);
    VL_IN16(m_axi_bid,12,0);
    VL_OUT16(m_axi_arid,12,0);
    VL_IN16(m_axi_rid,12,0);
    //char	__VpadToAlign42[6];
    VL_IN64(entry,63,0);
    VL_IN64(stackptr,63,0);
    VL_IN64(satp,63,0);
    VL_OUT64(m_axi_awaddr,63,0);
    VL_OUT64(m_axi_wdata,63,0);
    VL_OUT64(m_axi_araddr,63,0);
    VL_IN64(m_axi_rdata,63,0);
    VL_IN64(m_axi_acaddr,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(top__DOT__id_reg_funct7_out,6,0);
    VL_SIG8(top__DOT__id_reg_funct3_out,2,0);
    VL_SIG8(top__DOT__mem_read_control,0,0);
    VL_SIG8(top__DOT__mem_write_control,0,0);
    VL_SIG8(top__DOT__mem_to_reg_control,0,0);
    VL_SIG8(top__DOT__fetch_inst__DOT__state,2,0);
    VL_SIG8(top__DOT__fetch_inst__DOT__next_state,2,0);
    VL_SIG8(top__DOT__Decoder__DOT__rs1,4,0);
    VL_SIG8(top__DOT__Decoder__DOT__rs2,4,0);
    VL_SIG8(top__DOT__Decoder__DOT__rd,4,0);
    VL_SIG8(top__DOT__Decoder__DOT__opcode,6,0);
    VL_SIG8(top__DOT__Decoder__DOT__funct7,6,0);
    VL_SIG8(top__DOT__Decoder__DOT__funct3,2,0);
    VL_SIG8(top__DOT__Decoder__DOT__alu_op,3,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__pc_contrl,0,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__opcode,6,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__funct7,6,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__funct3,2,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__reg_write,0,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__mem_read,0,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__mem_write,0,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__alu_src,0,0);
    VL_SIG8(top__DOT__ControlUnit__DOT__mem_to_reg,0,0);
    //char	__VpadToAlign139[1];
    VL_SIG16(top__DOT__fetch_inst__DOT__index,9,0);
    VL_SIG16(top__DOT__fetch_inst__DOT__pc_fetch,9,0);
    VL_SIG(top__DOT__if_instr,31,0);
    VL_SIG(top__DOT__Decoder__DOT__imm,31,0);
    VL_SIG(top__DOT__RegisterFile__DOT__i,31,0);
    //char	__VpadToAlign156[4];
    VL_SIG64(top__DOT__regA_data_out,63,0);
    VL_SIG64(top__DOT__regB_data_out,63,0);
    VL_SIG64(top__DOT__ex_operand_2_in,63,0);
    VL_SIG64(top__DOT__fetch_inst__DOT__pc,63,0);
    VL_SIG64(top__DOT__fetch_inst__DOT__next_pc,63,0);
    VL_SIG64(top__DOT__fetch_inst__DOT__fetched_instr,63,0);
    VL_SIG64(top__DOT__fetch_inst__DOT__display_addr,63,0);
    VL_SIG64(top__DOT__fetch_inst__DOT__next_display_addr,63,0);
    VL_SIG64(top__DOT__Decoder__DOT__imm_signed,63,0);
    VL_SIG64(top__DOT__Decoder__DOT__imm_unsigned,63,0);
    VL_SIG64(top__DOT__Decoder__DOT__decoded_instruction,63,0);
    VL_SIG64(top__DOT__ALU__DOT__result,63,0);
    VL_SIG64(top__DOT__ALU__DOT__ex_operand_temp,63,0);
    VL_SIG64(top__DOT__ALU__DOT__result_add_word,63,0);
    VL_SIG(top__DOT__fetch_inst__DOT__instruction_array[1000],31,0);
    VL_SIG64(top__DOT__RegisterFile__DOT__registers[32],63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign4533[3];
    VL_SIG(top__DOT__fetch_inst__DOT____Vlvbound1,31,0);
    VL_SIG(top__DOT__fetch_inst__DOT____Vlvbound2,31,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vtop& operator= (const Vtop&);	///< Copying not allowed
    Vtop(const Vtop&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__4(Vtop__Syms* __restrict vlSymsp);
  private:
    void	_configure_coverage(Vtop__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vtop__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void	_initial__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void	_settle__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void	traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void	traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
