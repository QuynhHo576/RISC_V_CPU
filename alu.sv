module ALU (
    input  [63:0] operand1,
    input  [63:0] operand2,
    input  [3:0]  alu_op,
    output reg [63:0] result
);
    always @(*) begin
        //logic [63:0] alu_operand_b;

        //assign alu_operand_b = bsel ? imm : regB_data;

        case (alu_op)
            4'b0000: result = operand1 + operand2;  // ADD
            4'b0001: result = operand1 - operand2;  // SUB
            4'b0010: result = operand1 & operand2;  // AND
            4'b0011: result = operand1 | operand2;  // OR
            4'b0100: result = operand1 ^ operand2;  // XOR
            4'b0101: result = operand1 << operand2[5:0]; // SLL
            4'b0110: result = operand1 >> operand2[5:0]; // SRL
            4'b0111: result = $signed(operand1) >>> operand2[5:0]; // SRA
            default: result = 0;
        endcase
    end
endmodule