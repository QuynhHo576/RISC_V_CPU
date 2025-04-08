module ALU (
    input  [63:0] ex_operand1_in,
    input  [63:0] ex_operand2_in,
    input  [3:0]  ex_alu_op_in,
    output [63:0] ex_alu_result_out
);
    logic [63:0] result;
    always_comb begin
        case (ex_alu_op_in)
            4'b0000: result = ex_operand1_in + ex_operand2_in;  // ADD
            4'b0001: result = ex_operand1_in - ex_operand2_in;  // SUB
            4'b0010: result = ex_operand1_in & ex_operand2_in;  // AND
            4'b0011: result = ex_operand1_in | ex_operand2_in;  // OR
            4'b0100: result = ex_operand1_in ^ ex_operand2_in;  // XOR
            4'b0101: result = ex_operand1_in << ex_operand2_in[5:0]; // SLL
            4'b0110: result = ex_operand1_in >> ex_operand2_in[5:0]; // SRL
            4'b0111: result = $signed(ex_operand1_in) >>> ex_operand2_in[5:0]; // SRA
        endcase
    end
    assign ex_alu_result_out = result;
endmodule