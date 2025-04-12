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
	vcdp->declBit  (c+141,"clk",-1);
	vcdp->declBit  (c+142,"reset",-1);
	vcdp->declBit  (c+143,"hz32768timer",-1);
	vcdp->declQuad (c+144,"entry",-1,63,0);
	vcdp->declQuad (c+146,"stackptr",-1,63,0);
	vcdp->declQuad (c+148,"satp",-1,63,0);
	vcdp->declBus  (c+150,"m_axi_awid",-1,12,0);
	vcdp->declQuad (c+151,"m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+153,"m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+154,"m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+155,"m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+156,"m_axi_awlock",-1);
	vcdp->declBus  (c+157,"m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+158,"m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+159,"m_axi_awvalid",-1);
	vcdp->declBit  (c+160,"m_axi_awready",-1);
	vcdp->declQuad (c+161,"m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+163,"m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+164,"m_axi_wlast",-1);
	vcdp->declBit  (c+165,"m_axi_wvalid",-1);
	vcdp->declBit  (c+166,"m_axi_wready",-1);
	vcdp->declBus  (c+167,"m_axi_bid",-1,12,0);
	vcdp->declBus  (c+168,"m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+169,"m_axi_bvalid",-1);
	vcdp->declBit  (c+170,"m_axi_bready",-1);
	vcdp->declBus  (c+171,"m_axi_arid",-1,12,0);
	vcdp->declQuad (c+172,"m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+174,"m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+175,"m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+176,"m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+177,"m_axi_arlock",-1);
	vcdp->declBus  (c+178,"m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+179,"m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+180,"m_axi_arvalid",-1);
	vcdp->declBit  (c+181,"m_axi_arready",-1);
	vcdp->declBus  (c+182,"m_axi_rid",-1,12,0);
	vcdp->declQuad (c+183,"m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+185,"m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+186,"m_axi_rlast",-1);
	vcdp->declBit  (c+187,"m_axi_rvalid",-1);
	vcdp->declBit  (c+188,"m_axi_rready",-1);
	vcdp->declBit  (c+189,"m_axi_acvalid",-1);
	vcdp->declBit  (c+190,"m_axi_acready",-1);
	vcdp->declQuad (c+191,"m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+193,"m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+194,"top ID_WIDTH",-1,31,0);
	vcdp->declBus  (c+195,"top ADDR_WIDTH",-1,31,0);
	vcdp->declBus  (c+195,"top DATA_WIDTH",-1,31,0);
	vcdp->declBus  (c+196,"top STRB_WIDTH",-1,31,0);
	vcdp->declBit  (c+141,"top clk",-1);
	vcdp->declBit  (c+142,"top reset",-1);
	vcdp->declBit  (c+143,"top hz32768timer",-1);
	vcdp->declQuad (c+144,"top entry",-1,63,0);
	vcdp->declQuad (c+146,"top stackptr",-1,63,0);
	vcdp->declQuad (c+148,"top satp",-1,63,0);
	vcdp->declBus  (c+150,"top m_axi_awid",-1,12,0);
	vcdp->declQuad (c+151,"top m_axi_awaddr",-1,63,0);
	vcdp->declBus  (c+153,"top m_axi_awlen",-1,7,0);
	vcdp->declBus  (c+154,"top m_axi_awsize",-1,2,0);
	vcdp->declBus  (c+155,"top m_axi_awburst",-1,1,0);
	vcdp->declBit  (c+156,"top m_axi_awlock",-1);
	vcdp->declBus  (c+157,"top m_axi_awcache",-1,3,0);
	vcdp->declBus  (c+158,"top m_axi_awprot",-1,2,0);
	vcdp->declBit  (c+159,"top m_axi_awvalid",-1);
	vcdp->declBit  (c+160,"top m_axi_awready",-1);
	vcdp->declQuad (c+161,"top m_axi_wdata",-1,63,0);
	vcdp->declBus  (c+163,"top m_axi_wstrb",-1,7,0);
	vcdp->declBit  (c+164,"top m_axi_wlast",-1);
	vcdp->declBit  (c+165,"top m_axi_wvalid",-1);
	vcdp->declBit  (c+166,"top m_axi_wready",-1);
	vcdp->declBus  (c+167,"top m_axi_bid",-1,12,0);
	vcdp->declBus  (c+168,"top m_axi_bresp",-1,1,0);
	vcdp->declBit  (c+169,"top m_axi_bvalid",-1);
	vcdp->declBit  (c+170,"top m_axi_bready",-1);
	vcdp->declBus  (c+171,"top m_axi_arid",-1,12,0);
	vcdp->declQuad (c+172,"top m_axi_araddr",-1,63,0);
	vcdp->declBus  (c+174,"top m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+175,"top m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+176,"top m_axi_arburst",-1,1,0);
	vcdp->declBit  (c+177,"top m_axi_arlock",-1);
	vcdp->declBus  (c+178,"top m_axi_arcache",-1,3,0);
	vcdp->declBus  (c+179,"top m_axi_arprot",-1,2,0);
	vcdp->declBit  (c+180,"top m_axi_arvalid",-1);
	vcdp->declBit  (c+181,"top m_axi_arready",-1);
	vcdp->declBus  (c+182,"top m_axi_rid",-1,12,0);
	vcdp->declQuad (c+183,"top m_axi_rdata",-1,63,0);
	vcdp->declBus  (c+185,"top m_axi_rresp",-1,1,0);
	vcdp->declBit  (c+186,"top m_axi_rlast",-1);
	vcdp->declBit  (c+187,"top m_axi_rvalid",-1);
	vcdp->declBit  (c+188,"top m_axi_rready",-1);
	vcdp->declBit  (c+189,"top m_axi_acvalid",-1);
	vcdp->declBit  (c+190,"top m_axi_acready",-1);
	vcdp->declQuad (c+191,"top m_axi_acaddr",-1,63,0);
	vcdp->declBus  (c+193,"top m_axi_acsnoop",-1,3,0);
	vcdp->declBus  (c+1,"top if_instr",-1,31,0);
	vcdp->declQuad (c+62,"top if_address_out",-1,63,0);
	vcdp->declBus  (c+7,"top id_reg_rs1_out",-1,4,0);
	vcdp->declBus  (c+8,"top id_reg_rs2_out",-1,4,0);
	vcdp->declBus  (c+9,"top id_reg_rd_out",-1,4,0);
	vcdp->declQuad (c+10,"top id_reg_imm_out",-1,63,0);
	vcdp->declQuad (c+12,"top id_reg_imm_signed_out",-1,63,0);
	vcdp->declQuad (c+14,"top id_reg_imm_unsigned_out",-1,63,0);
	vcdp->declBus  (c+16,"top id_reg_opcode_out",-1,6,0);
	vcdp->declBus  (c+17,"top id_reg_funct7_out",-1,6,0);
	vcdp->declBus  (c+18,"top id_reg_funct3_out",-1,2,0);
	vcdp->declBus  (c+19,"top id_alu_op_out",-1,3,0);
	vcdp->declBit  (c+20,"top reg_write_control",-1);
	vcdp->declBit  (c+21,"top mem_read_control",-1);
	vcdp->declBit  (c+22,"top mem_write_control",-1);
	vcdp->declBit  (c+23,"top alu_operand1_control",-1);
	vcdp->declBit  (c+24,"top alu_operand2_control",-1);
	vcdp->declBit  (c+25,"top mem_to_reg_control",-1);
	vcdp->declBit  (c+197,"top pc_sel_out",-1);
	vcdp->declQuad (c+26,"top regA_data_out",-1,63,0);
	vcdp->declQuad (c+28,"top regB_data_out",-1,63,0);
	vcdp->declBit  (c+30,"top id_branch_compare_result",-1);
	vcdp->declQuad (c+31,"top ex_operand_1_in",-1,63,0);
	vcdp->declQuad (c+33,"top ex_operand_2_in",-1,63,0);
	vcdp->declQuad (c+35,"top ex_mem_read_data_out",-1,63,0);
	vcdp->declQuad (c+2,"top write_back_data",-1,63,0);
	vcdp->declBit  (c+37,"top ex_alu_result_out",-1);
	vcdp->declBit  (c+141,"top fetch_inst clk",-1);
	vcdp->declBit  (c+142,"top fetch_inst reset",-1);
	vcdp->declQuad (c+144,"top fetch_inst entry",-1,63,0);
	vcdp->declQuad (c+38,"top fetch_inst pc_from_alu_result",-1,63,0);
	vcdp->declBit  (c+197,"top fetch_inst pcsel",-1);
	vcdp->declQuad (c+172,"top fetch_inst m_axi_araddr",-1,63,0);
	vcdp->declBit  (c+180,"top fetch_inst m_axi_arvalid",-1);
	vcdp->declBit  (c+181,"top fetch_inst m_axi_arready",-1);
	vcdp->declBus  (c+174,"top fetch_inst m_axi_arlen",-1,7,0);
	vcdp->declBus  (c+175,"top fetch_inst m_axi_arsize",-1,2,0);
	vcdp->declBus  (c+176,"top fetch_inst m_axi_arburst",-1,1,0);
	vcdp->declQuad (c+183,"top fetch_inst m_axi_rdata",-1,63,0);
	vcdp->declBit  (c+187,"top fetch_inst m_axi_rvalid",-1);
	vcdp->declBit  (c+188,"top fetch_inst m_axi_rready",-1);
	vcdp->declBit  (c+186,"top fetch_inst m_axi_rlast",-1);
	vcdp->declBus  (c+1,"top fetch_inst if_instr",-1,31,0);
	vcdp->declBus  (c+64,"top fetch_inst if_address_out",-1,31,0);
	vcdp->declBus  (c+65,"top fetch_inst state",-1,2,0);
	vcdp->declBus  (c+4,"top fetch_inst next_state",-1,2,0);
	vcdp->declQuad (c+66,"top fetch_inst pc",-1,63,0);
	vcdp->declQuad (c+5,"top fetch_inst next_pc",-1,63,0);
	vcdp->declQuad (c+68,"top fetch_inst fetched_instr",-1,63,0);
	vcdp->declQuad (c+70,"top fetch_inst display_addr",-1,63,0);
	vcdp->declQuad (c+72,"top fetch_inst next_display_addr",-1,63,0);
	// Tracing: top fetch_inst instruction_array // Ignored: Wide memory > --trace-max-array ents at fetch.sv:40
	vcdp->declBus  (c+74,"top fetch_inst index",-1,9,0);
	vcdp->declBus  (c+75,"top fetch_inst pc_fetch",-1,9,0);
	vcdp->declBus  (c+198,"top fetch_inst pcSel",-1,1,0);
	vcdp->declBus  (c+1,"top Decoder input_bin",-1,31,0);
	vcdp->declBus  (c+64,"top Decoder address",-1,31,0);
	vcdp->declBus  (c+7,"top Decoder id_reg_rs1_out",-1,4,0);
	vcdp->declBus  (c+8,"top Decoder id_reg_rs2_out",-1,4,0);
	vcdp->declBus  (c+9,"top Decoder id_reg_rd_out",-1,4,0);
	vcdp->declBus  (c+40,"top Decoder id_reg_imm_out",-1,31,0);
	vcdp->declQuad (c+12,"top Decoder id_reg_imm_signed_out",-1,63,0);
	vcdp->declQuad (c+14,"top Decoder id_reg_imm_unsigned_out",-1,63,0);
	vcdp->declBus  (c+16,"top Decoder id_reg_opcode_out",-1,6,0);
	vcdp->declBus  (c+17,"top Decoder id_reg_funct7_out",-1,6,0);
	vcdp->declBus  (c+18,"top Decoder id_reg_funct3_out",-1,2,0);
	vcdp->declBus  (c+19,"top Decoder id_alu_op_out",-1,3,0);
	vcdp->declBus  (c+7,"top Decoder rs1",-1,4,0);
	vcdp->declBus  (c+8,"top Decoder rs2",-1,4,0);
	vcdp->declBus  (c+9,"top Decoder rd",-1,4,0);
	vcdp->declBus  (c+16,"top Decoder opcode",-1,6,0);
	vcdp->declBus  (c+17,"top Decoder funct7",-1,6,0);
	vcdp->declBus  (c+18,"top Decoder funct3",-1,2,0);
	vcdp->declBus  (c+40,"top Decoder imm",-1,31,0);
	vcdp->declQuad (c+12,"top Decoder imm_signed",-1,63,0);
	vcdp->declQuad (c+14,"top Decoder imm_unsigned",-1,63,0);
	vcdp->declQuad (c+41,"top Decoder decoded_instruction",-1,63,0);
	vcdp->declBus  (c+19,"top Decoder alu_op",-1,3,0);
	vcdp->declBus  (c+43,"top ControlUnit if_opcode",-1,31,0);
	vcdp->declBit  (c+30,"top ControlUnit branch_compare_result",-1);
	vcdp->declBit  (c+20,"top ControlUnit reg_write_control",-1);
	vcdp->declBit  (c+21,"top ControlUnit mem_read_control",-1);
	vcdp->declBit  (c+22,"top ControlUnit mem_write_control",-1);
	vcdp->declBit  (c+23,"top ControlUnit alu_operand1_control_out",-1);
	vcdp->declBit  (c+24,"top ControlUnit alu_operand2_control_out",-1);
	vcdp->declBit  (c+25,"top ControlUnit mem_to_reg_control",-1);
	vcdp->declBit  (c+197,"top ControlUnit pc_sel_out",-1);
	vcdp->declBit  (c+20,"top ControlUnit reg_write",-1);
	vcdp->declBit  (c+21,"top ControlUnit mem_read",-1);
	vcdp->declBit  (c+22,"top ControlUnit mem_write",-1);
	vcdp->declBit  (c+23,"top ControlUnit alu_operand1_control",-1);
	vcdp->declBit  (c+24,"top ControlUnit alu_operand2_control",-1);
	vcdp->declBus  (c+44,"top ControlUnit pcSel",-1,1,0);
	vcdp->declBus  (c+45,"top ControlUnit mem_to_reg",-1,1,0);
	vcdp->declBit  (c+46,"top ControlUnit pc_contrl_out",-1);
	vcdp->declBit  (c+141,"top RegisterFile clk",-1);
	vcdp->declBit  (c+142,"top RegisterFile reset",-1);
	vcdp->declBus  (c+7,"top RegisterFile regA_addr_in",-1,4,0);
	vcdp->declBus  (c+8,"top RegisterFile regB_addr_in",-1,4,0);
	vcdp->declBus  (c+9,"top RegisterFile rd_addr_in",-1,4,0);
	vcdp->declQuad (c+2,"top RegisterFile reg_write_data_in",-1,63,0);
	vcdp->declBit  (c+20,"top RegisterFile reg_write_enable",-1);
	vcdp->declQuad (c+26,"top RegisterFile regA_data_out",-1,63,0);
	vcdp->declQuad (c+28,"top RegisterFile regB_data_out",-1,63,0);
	{int i; for (i=0; i<32; i++) {
		vcdp->declQuad (c+76+i*2,"top RegisterFile registers",(i+0),63,0);}}
	vcdp->declBus  (c+140,"top RegisterFile i",-1,31,0);
	vcdp->declQuad (c+26,"top BranchCompare branch_compare_regA_data",-1,63,0);
	vcdp->declQuad (c+28,"top BranchCompare branch_compare_regB_data",-1,63,0);
	vcdp->declBus  (c+16,"top BranchCompare branch_compare_opcode",-1,6,0);
	vcdp->declBus  (c+18,"top BranchCompare branch_compare_funct3",-1,2,0);
	vcdp->declBit  (c+30,"top BranchCompare branch_compare_result",-1);
	vcdp->declBit  (c+47,"top BranchCompare branch_compare_regA_data_signed",-1);
	vcdp->declBit  (c+48,"top BranchCompare branch_compare_regB_data_signed",-1);
	vcdp->declBit  (c+49,"top BranchCompare branch_compare_regA_data_unsigned",-1);
	vcdp->declBit  (c+199,"top BranchCompare branch_compare_regB_data_unsigned",-1);
	vcdp->declBit  (c+50,"top BranchCompare equal_result",-1);
	vcdp->declBit  (c+51,"top BranchCompare not_equal_result",-1);
	vcdp->declBit  (c+52,"top BranchCompare less_than_result",-1);
	vcdp->declBit  (c+53,"top BranchCompare greater_equal_result",-1);
	vcdp->declBit  (c+54,"top BranchCompare less_than_result_unsigned",-1);
	vcdp->declBit  (c+55,"top BranchCompare greater_equal_result_unsigned",-1);
	vcdp->declQuad (c+31,"top ALU ex_operand1_in",-1,63,0);
	vcdp->declQuad (c+33,"top ALU ex_operand2_in",-1,63,0);
	vcdp->declBus  (c+19,"top ALU ex_alu_op_in",-1,3,0);
	vcdp->declQuad (c+56,"top ALU ex_alu_result_out",-1,63,0);
	vcdp->declQuad (c+56,"top ALU result",-1,63,0);
	vcdp->declQuad (c+58,"top ALU ex_operand_temp",-1,63,0);
	vcdp->declQuad (c+60,"top ALU result_add_word",-1,63,0);
	vcdp->declBit  (c+141,"top D_MEMORY clk",-1);
	vcdp->declBit  (c+142,"top D_MEMORY reset",-1);
	vcdp->declQuad (c+38,"top D_MEMORY ex_mem_address",-1,63,0);
	vcdp->declQuad (c+28,"top D_MEMORY ex_mem_write_data",-1,63,0);
	vcdp->declBit  (c+22,"top D_MEMORY ex_mem_memory_write",-1);
	vcdp->declBit  (c+21,"top D_MEMORY ex_mem_memory_read",-1);
	vcdp->declQuad (c+35,"top D_MEMORY ex_mem_read_data_out",-1,63,0);
	// Tracing: top D_MEMORY d_memory // Ignored: Wide memory > --trace-max-array ents at dmem.sv:12
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlTOPp->top__DOT__if_instr),32);
	vcdp->fullQuad (c+2,(((1U & (IData)(vlTOPp->top__DOT__ControlUnit__DOT__mem_to_reg))
			       ? ((1U & (IData)(vlTOPp->top__DOT__ControlUnit__DOT__mem_to_reg))
				   ? vlTOPp->top__DOT__ex_mem_read_data_out
				   : ((2U == (1U & (IData)(vlTOPp->top__DOT__ControlUnit__DOT__mem_to_reg)))
				       ? (VL_ULL(4) 
					  + (QData)((IData)(
							    ((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
							     - (IData)(4U)))))
				       : VL_ULL(0)))
			       : (QData)((IData)((1U 
						  & (IData)(vlTOPp->top__DOT__ALU__DOT__result)))))),64);
	vcdp->fullBus  (c+4,(vlTOPp->top__DOT__fetch_inst__DOT__next_state),3);
	vcdp->fullQuad (c+5,(vlTOPp->top__DOT__fetch_inst__DOT__next_pc),64);
	vcdp->fullBus  (c+7,(vlTOPp->top__DOT__Decoder__DOT__rs1),5);
	vcdp->fullBus  (c+8,(vlTOPp->top__DOT__Decoder__DOT__rs2),5);
	vcdp->fullBus  (c+9,(vlTOPp->top__DOT__Decoder__DOT__rd),5);
	vcdp->fullQuad (c+10,((QData)((IData)(vlTOPp->top__DOT__Decoder__DOT__imm))),64);
	vcdp->fullQuad (c+12,(vlTOPp->top__DOT__Decoder__DOT__imm_signed),64);
	vcdp->fullQuad (c+14,(vlTOPp->top__DOT__Decoder__DOT__imm_unsigned),64);
	vcdp->fullBus  (c+16,(vlTOPp->top__DOT__Decoder__DOT__opcode),7);
	vcdp->fullBus  (c+17,(vlTOPp->top__DOT__Decoder__DOT__funct7),7);
	vcdp->fullBus  (c+18,(vlTOPp->top__DOT__Decoder__DOT__funct3),3);
	vcdp->fullBus  (c+19,(vlTOPp->top__DOT__Decoder__DOT__alu_op),4);
	vcdp->fullBit  (c+20,(vlTOPp->top__DOT__ControlUnit__DOT__reg_write));
	vcdp->fullBit  (c+21,(vlTOPp->top__DOT__ControlUnit__DOT__mem_read));
	vcdp->fullBit  (c+22,(vlTOPp->top__DOT__ControlUnit__DOT__mem_write));
	vcdp->fullBit  (c+23,(vlTOPp->top__DOT__ControlUnit__DOT__alu_operand1_control));
	vcdp->fullBit  (c+24,(vlTOPp->top__DOT__ControlUnit__DOT__alu_operand2_control));
	vcdp->fullBit  (c+25,((1U & (IData)(vlTOPp->top__DOT__ControlUnit__DOT__mem_to_reg))));
	vcdp->fullQuad (c+26,(vlTOPp->top__DOT__regA_data_out),64);
	vcdp->fullQuad (c+28,(vlTOPp->top__DOT__regB_data_out),64);
	vcdp->fullBit  (c+30,(((0x63U == (IData)(vlTOPp->top__DOT__Decoder__DOT__opcode)) 
			       & ((4U & (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))
				   ? ((2U & (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))
				       ? ((1U & (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))
					   ? (((IData)(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regA_data_unsigned) 
					       >= (IData)(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regB_data_unsigned))
					       ? 1U
					       : 0U)
					   : (((IData)(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regA_data_unsigned) 
					       < (IData)(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regB_data_unsigned))
					       ? 1U
					       : 0U))
				       : ((1U & (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))
					   ? (VL_GTES_III(1,1,1, 
							  (1U 
							   & (IData)(vlTOPp->top__DOT__regA_data_out)), 
							  (1U 
							   & (IData)(vlTOPp->top__DOT__regB_data_out)))
					       ? 1U
					       : 0U)
					   : (VL_LTS_III(1,1,1, 
							 (1U 
							  & (IData)(vlTOPp->top__DOT__regA_data_out)), 
							 (1U 
							  & (IData)(vlTOPp->top__DOT__regB_data_out)))
					       ? 1U
					       : 0U)))
				   : ((~ ((IData)(vlTOPp->top__DOT__Decoder__DOT__funct3) 
					  >> 1U)) & 
				      ((1U & (IData)(vlTOPp->top__DOT__Decoder__DOT__funct3))
				        ? (((1U & (IData)(vlTOPp->top__DOT__regA_data_out)) 
					    != (1U 
						& (IData)(vlTOPp->top__DOT__regB_data_out)))
					    ? 1U : 0U)
				        : (((1U & (IData)(vlTOPp->top__DOT__regA_data_out)) 
					    == (1U 
						& (IData)(vlTOPp->top__DOT__regB_data_out)))
					    ? 1U : 0U)))))));
	vcdp->fullQuad (c+31,(vlTOPp->top__DOT__ex_operand_1_in),64);
	vcdp->fullQuad (c+33,(vlTOPp->top__DOT__ex_operand_2_in),64);
	vcdp->fullQuad (c+35,(vlTOPp->top__DOT__ex_mem_read_data_out),64);
	vcdp->fullBit  (c+37,((1U & (IData)(vlTOPp->top__DOT__ALU__DOT__result))));
	vcdp->fullQuad (c+38,((QData)((IData)((1U & (IData)(vlTOPp->top__DOT__ALU__DOT__result))))),64);
	vcdp->fullBus  (c+40,(vlTOPp->top__DOT__Decoder__DOT__imm),32);
	vcdp->fullQuad (c+41,(vlTOPp->top__DOT__Decoder__DOT__decoded_instruction),64);
	vcdp->fullBus  (c+43,(vlTOPp->top__DOT__Decoder__DOT__opcode),32);
	vcdp->fullBus  (c+44,(vlTOPp->top__DOT__ControlUnit__DOT__pcSel),2);
	vcdp->fullBus  (c+45,(vlTOPp->top__DOT__ControlUnit__DOT__mem_to_reg),2);
	vcdp->fullBit  (c+46,((1U & (IData)(vlTOPp->top__DOT__ControlUnit__DOT__pcSel))));
	vcdp->fullBit  (c+47,((1U & (IData)(vlTOPp->top__DOT__regA_data_out))));
	vcdp->fullBit  (c+48,((1U & (IData)(vlTOPp->top__DOT__regB_data_out))));
	vcdp->fullBit  (c+49,(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regA_data_unsigned));
	vcdp->fullBit  (c+50,((1U & (((1U & (IData)(vlTOPp->top__DOT__regA_data_out)) 
				      == (1U & (IData)(vlTOPp->top__DOT__regB_data_out)))
				      ? 1U : 0U))));
	vcdp->fullBit  (c+51,((1U & (((1U & (IData)(vlTOPp->top__DOT__regA_data_out)) 
				      != (1U & (IData)(vlTOPp->top__DOT__regB_data_out)))
				      ? 1U : 0U))));
	vcdp->fullBit  (c+52,((1U & (VL_LTS_III(1,1,1, 
						(1U 
						 & (IData)(vlTOPp->top__DOT__regA_data_out)), 
						(1U 
						 & (IData)(vlTOPp->top__DOT__regB_data_out)))
				      ? 1U : 0U))));
	vcdp->fullBit  (c+53,((1U & (VL_GTES_III(1,1,1, 
						 (1U 
						  & (IData)(vlTOPp->top__DOT__regA_data_out)), 
						 (1U 
						  & (IData)(vlTOPp->top__DOT__regB_data_out)))
				      ? 1U : 0U))));
	vcdp->fullBit  (c+54,((1U & (((IData)(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regA_data_unsigned) 
				      < (IData)(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regB_data_unsigned))
				      ? 1U : 0U))));
	vcdp->fullBit  (c+55,((1U & (((IData)(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regA_data_unsigned) 
				      >= (IData)(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regB_data_unsigned))
				      ? 1U : 0U))));
	vcdp->fullQuad (c+56,(vlTOPp->top__DOT__ALU__DOT__result),64);
	vcdp->fullQuad (c+58,(vlTOPp->top__DOT__ALU__DOT__ex_operand_temp),64);
	vcdp->fullQuad (c+60,(vlTOPp->top__DOT__ALU__DOT__result_add_word),64);
	vcdp->fullQuad (c+62,((QData)((IData)(((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
					       - (IData)(4U))))),64);
	vcdp->fullBus  (c+64,(((IData)(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch) 
			       - (IData)(4U))),32);
	vcdp->fullBus  (c+65,(vlTOPp->top__DOT__fetch_inst__DOT__state),3);
	vcdp->fullQuad (c+66,(vlTOPp->top__DOT__fetch_inst__DOT__pc),64);
	vcdp->fullQuad (c+68,(vlTOPp->top__DOT__fetch_inst__DOT__fetched_instr),64);
	vcdp->fullQuad (c+70,(vlTOPp->top__DOT__fetch_inst__DOT__display_addr),64);
	vcdp->fullQuad (c+72,(vlTOPp->top__DOT__fetch_inst__DOT__next_display_addr),64);
	vcdp->fullBus  (c+74,(vlTOPp->top__DOT__fetch_inst__DOT__index),10);
	vcdp->fullBus  (c+75,(vlTOPp->top__DOT__fetch_inst__DOT__pc_fetch),10);
	vcdp->fullQuad (c+76,(vlTOPp->top__DOT__RegisterFile__DOT__registers[0]),64);
	vcdp->fullQuad (c+78,(vlTOPp->top__DOT__RegisterFile__DOT__registers[1]),64);
	vcdp->fullQuad (c+80,(vlTOPp->top__DOT__RegisterFile__DOT__registers[2]),64);
	vcdp->fullQuad (c+82,(vlTOPp->top__DOT__RegisterFile__DOT__registers[3]),64);
	vcdp->fullQuad (c+84,(vlTOPp->top__DOT__RegisterFile__DOT__registers[4]),64);
	vcdp->fullQuad (c+86,(vlTOPp->top__DOT__RegisterFile__DOT__registers[5]),64);
	vcdp->fullQuad (c+88,(vlTOPp->top__DOT__RegisterFile__DOT__registers[6]),64);
	vcdp->fullQuad (c+90,(vlTOPp->top__DOT__RegisterFile__DOT__registers[7]),64);
	vcdp->fullQuad (c+92,(vlTOPp->top__DOT__RegisterFile__DOT__registers[8]),64);
	vcdp->fullQuad (c+94,(vlTOPp->top__DOT__RegisterFile__DOT__registers[9]),64);
	vcdp->fullQuad (c+96,(vlTOPp->top__DOT__RegisterFile__DOT__registers[10]),64);
	vcdp->fullQuad (c+98,(vlTOPp->top__DOT__RegisterFile__DOT__registers[11]),64);
	vcdp->fullQuad (c+100,(vlTOPp->top__DOT__RegisterFile__DOT__registers[12]),64);
	vcdp->fullQuad (c+102,(vlTOPp->top__DOT__RegisterFile__DOT__registers[13]),64);
	vcdp->fullQuad (c+104,(vlTOPp->top__DOT__RegisterFile__DOT__registers[14]),64);
	vcdp->fullQuad (c+106,(vlTOPp->top__DOT__RegisterFile__DOT__registers[15]),64);
	vcdp->fullQuad (c+108,(vlTOPp->top__DOT__RegisterFile__DOT__registers[16]),64);
	vcdp->fullQuad (c+110,(vlTOPp->top__DOT__RegisterFile__DOT__registers[17]),64);
	vcdp->fullQuad (c+112,(vlTOPp->top__DOT__RegisterFile__DOT__registers[18]),64);
	vcdp->fullQuad (c+114,(vlTOPp->top__DOT__RegisterFile__DOT__registers[19]),64);
	vcdp->fullQuad (c+116,(vlTOPp->top__DOT__RegisterFile__DOT__registers[20]),64);
	vcdp->fullQuad (c+118,(vlTOPp->top__DOT__RegisterFile__DOT__registers[21]),64);
	vcdp->fullQuad (c+120,(vlTOPp->top__DOT__RegisterFile__DOT__registers[22]),64);
	vcdp->fullQuad (c+122,(vlTOPp->top__DOT__RegisterFile__DOT__registers[23]),64);
	vcdp->fullQuad (c+124,(vlTOPp->top__DOT__RegisterFile__DOT__registers[24]),64);
	vcdp->fullQuad (c+126,(vlTOPp->top__DOT__RegisterFile__DOT__registers[25]),64);
	vcdp->fullQuad (c+128,(vlTOPp->top__DOT__RegisterFile__DOT__registers[26]),64);
	vcdp->fullQuad (c+130,(vlTOPp->top__DOT__RegisterFile__DOT__registers[27]),64);
	vcdp->fullQuad (c+132,(vlTOPp->top__DOT__RegisterFile__DOT__registers[28]),64);
	vcdp->fullQuad (c+134,(vlTOPp->top__DOT__RegisterFile__DOT__registers[29]),64);
	vcdp->fullQuad (c+136,(vlTOPp->top__DOT__RegisterFile__DOT__registers[30]),64);
	vcdp->fullQuad (c+138,(vlTOPp->top__DOT__RegisterFile__DOT__registers[31]),64);
	vcdp->fullBus  (c+140,(vlTOPp->top__DOT__RegisterFile__DOT__i),32);
	vcdp->fullBit  (c+141,(vlTOPp->clk));
	vcdp->fullBit  (c+142,(vlTOPp->reset));
	vcdp->fullBit  (c+143,(vlTOPp->hz32768timer));
	vcdp->fullQuad (c+144,(vlTOPp->entry),64);
	vcdp->fullQuad (c+146,(vlTOPp->stackptr),64);
	vcdp->fullQuad (c+148,(vlTOPp->satp),64);
	vcdp->fullBus  (c+150,(vlTOPp->m_axi_awid),13);
	vcdp->fullQuad (c+151,(vlTOPp->m_axi_awaddr),64);
	vcdp->fullBus  (c+153,(vlTOPp->m_axi_awlen),8);
	vcdp->fullBus  (c+154,(vlTOPp->m_axi_awsize),3);
	vcdp->fullBus  (c+155,(vlTOPp->m_axi_awburst),2);
	vcdp->fullBit  (c+156,(vlTOPp->m_axi_awlock));
	vcdp->fullBus  (c+157,(vlTOPp->m_axi_awcache),4);
	vcdp->fullBus  (c+158,(vlTOPp->m_axi_awprot),3);
	vcdp->fullBit  (c+159,(vlTOPp->m_axi_awvalid));
	vcdp->fullBit  (c+160,(vlTOPp->m_axi_awready));
	vcdp->fullQuad (c+161,(vlTOPp->m_axi_wdata),64);
	vcdp->fullBus  (c+163,(vlTOPp->m_axi_wstrb),8);
	vcdp->fullBit  (c+164,(vlTOPp->m_axi_wlast));
	vcdp->fullBit  (c+165,(vlTOPp->m_axi_wvalid));
	vcdp->fullBit  (c+166,(vlTOPp->m_axi_wready));
	vcdp->fullBus  (c+167,(vlTOPp->m_axi_bid),13);
	vcdp->fullBus  (c+168,(vlTOPp->m_axi_bresp),2);
	vcdp->fullBit  (c+169,(vlTOPp->m_axi_bvalid));
	vcdp->fullBit  (c+170,(vlTOPp->m_axi_bready));
	vcdp->fullBus  (c+171,(vlTOPp->m_axi_arid),13);
	vcdp->fullQuad (c+172,(vlTOPp->m_axi_araddr),64);
	vcdp->fullBus  (c+174,(vlTOPp->m_axi_arlen),8);
	vcdp->fullBus  (c+175,(vlTOPp->m_axi_arsize),3);
	vcdp->fullBus  (c+176,(vlTOPp->m_axi_arburst),2);
	vcdp->fullBit  (c+177,(vlTOPp->m_axi_arlock));
	vcdp->fullBus  (c+178,(vlTOPp->m_axi_arcache),4);
	vcdp->fullBus  (c+179,(vlTOPp->m_axi_arprot),3);
	vcdp->fullBit  (c+180,(vlTOPp->m_axi_arvalid));
	vcdp->fullBit  (c+181,(vlTOPp->m_axi_arready));
	vcdp->fullBus  (c+182,(vlTOPp->m_axi_rid),13);
	vcdp->fullQuad (c+183,(vlTOPp->m_axi_rdata),64);
	vcdp->fullBus  (c+185,(vlTOPp->m_axi_rresp),2);
	vcdp->fullBit  (c+186,(vlTOPp->m_axi_rlast));
	vcdp->fullBit  (c+187,(vlTOPp->m_axi_rvalid));
	vcdp->fullBit  (c+188,(vlTOPp->m_axi_rready));
	vcdp->fullBit  (c+189,(vlTOPp->m_axi_acvalid));
	vcdp->fullBit  (c+190,(vlTOPp->m_axi_acready));
	vcdp->fullQuad (c+191,(vlTOPp->m_axi_acaddr),64);
	vcdp->fullBus  (c+193,(vlTOPp->m_axi_acsnoop),4);
	vcdp->fullBus  (c+194,(0xdU),32);
	vcdp->fullBus  (c+195,(0x40U),32);
	vcdp->fullBus  (c+196,(8U),32);
	vcdp->fullBit  (c+197,(vlTOPp->top__DOT__pc_sel_out));
	vcdp->fullBus  (c+198,(vlTOPp->top__DOT__fetch_inst__DOT__pcSel),2);
	vcdp->fullBit  (c+199,(vlTOPp->top__DOT__BranchCompare__DOT__branch_compare_regB_data_unsigned));
    }
}
