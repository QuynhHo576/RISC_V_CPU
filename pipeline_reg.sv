module IF_ID_register(
    input  logic         clk,
    input  logic         reset,

    input  logic [63:0]  if_id_pc_in,
    input  logic [63:0]  if_id_instruction_in,

    output logic [63:0]  if_id_pc_out,
    output logic [63:0]  if_id_instruction_out
);

    // Internal pipeline registers
    logic [63:0] pc_reg;
    logic [31:0] instruction_reg;

    always_ff @(posedge clk or posedge reset) begin
            pc_reg          <= if_id_pc_in;
            instruction_reg <= if_id_instruction_in;
    end

    // Assign output values
    assign if_id_pc_out         = pc_reg;
    assign if_id_instruction_out = instruction_reg;

endmodule
