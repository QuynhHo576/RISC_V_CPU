module PCControl(
    input clk;
    input [63:0] entry;
    input logic [63:0] pc_contl_alu_result;
    input logic pcsel;

    output [63:0] pc_fetch;
    output [63:0] next_pc_fetch;
);
    assign next_pc_fetch = pc_fetch + 4;
    always_ff(posedge clk)
    if (reset) begin
        pc_fetch <= entry;
    end else if (pcsel == 1)begin
        pc_fetch <= pc_contl_alu_result;
        else begin
        pc_fetch <= next_pc_fetch;
        end 
    end 
endmodule