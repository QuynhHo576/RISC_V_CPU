module RegisterFile (
    input clk,
    input reset,
    input [4:0] regA_addr_in,
    input [4:0] regB_addr_in,
    input [4:0] rd_addr_in, //reg destination
    input [63:0] reg_write_data_in,
    input reg_write_enable, //enable
    output [63:0] regA_data_out,
    output [63:0] regB_data_out
);
//output decoder match input reg_file
//reg 0 =0
//register dual output
//list all 32 register
    logic [63:0] registers [32]; //data from instruction
    integer i;
    //assign reg_write_enable = 1;
    //assign rd_addr = 1s
    always_ff @(posedge clk) begin
        if (reset) begin
             for (i = 0; i < 32; i = i + 1) 
                 registers[i] <= 0;
        end else if (reg_write_enable && rd_addr_in!= 0) begin //register not register 0
            registers[rd_addr_in] <= reg_write_data_in;
        //if opcode == , imm
        end
    end
    //x0,x1,x2
    //rs1 = x7
    //register[00111] =  
    //design reg_write_enable (for instruction that has imm)
    assign regA_data_out = registers[regA_addr_in];
    assign regB_data_out = registers[regB_addr_in];
    
endmodule

