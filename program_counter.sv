module ProgramCounter (
    input logic clk,
    input logic reset,
    input logic pc_write_enable,        // for stalling
    input logic [63:0] pc_next,         // from PC mux
    output logic [63:0] pc              // current PC
);

    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            pc <= 64'd0;                // start address
        else if (pc_write_enable)
            pc <= pc_next;              // update PC
        // else: hold value (stall)
    end

endmodule
