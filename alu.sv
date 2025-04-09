module ALU (
    input  [63:0] ex_operand1_in,
    input  [63:0] ex_operand2_in,
    input  [3:0]  ex_alu_op_in,
    output [63:0] ex_alu_result_out
);
    logic [63:0] result;
    logic [63:0] ex_operand_temp;
    logic [63:0] result_add_word;
    always_comb begin
        ex_operand_temp  = ex_operand1_in + ex_operand2_in;
        result_add_word = {{32{ex_operand_temp[31]}}, ex_operand_temp[31:0]};
        case (ex_alu_op_in)
            4'b0000: result = ex_operand1_in + ex_operand2_in;  // ADD NOT WORD
            4'b1110: result = result_add_word;
            4'b1111: result = ex_operand2_in;
            4'b0001: result = ex_operand1_in - ex_operand2_in;  // SUB
            4'b0010: result = ex_operand1_in & ex_operand2_in;  // AND
            4'b0011: result = ex_operand1_in | ex_operand2_in;  // OR
            4'b0100: result = ex_operand1_in ^ ex_operand2_in;  // XOR
            4'b0101: result = ex_operand1_in << ex_operand2_in[5:0]; //SLL
            4'b0110: result = ex_operand1_in >> ex_operand2_in[5:0]; // SRL
            4'b0111: result = $signed(ex_operand1_in) >>> ex_operand2_in[5:0]; // SRAI
            //4'b1000: result = (ex_operand1_in < ex_operand2_in) ? 64'b1 : 64'b0;  // SLT Set Less Than (signed)
            //4'b1001: result = (ex_operand1_in < ex_operand1_in) ? 64'b1 : 64'b0;  // Set Less Than Unsigned
            4'b1010: result = ex_operand1_in * ex_operand2_in;      // Multiplication
            4'b1011: result = (ex_operand1_in * ex_operand2_in) >> 64; // Multiply High (64-bit result)
            4'b1100: result = ex_operand1_in / ex_operand2_in;      // Division
            4'b1101: result = ex_operand1_in % ex_operand2_in;      // Remainder
        endcase
        //add less or qeual
    end
    assign ex_alu_result_out = result;
endmodule