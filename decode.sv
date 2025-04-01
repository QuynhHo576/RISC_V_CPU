module InstructionDecoder (
    input logic [31:0] address,
    input logic [31:0] input_bin,
    output logic [63:0] decoded_instruction,
    output logic [4:0] rd
);
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;

    always_comb begin
        opcode = input_bin[6:0];
        rd = input_bin[11:7];
        funct3 = input_bin[14:12];
        funct7 = input_bin[31:25];

        case (opcode)
            7'b0110011: begin // R-Type Instructions
                case (funct3)
                    3'b000: decoded_instruction = (funct7 == 7'b0000000) ? "ADD" : "SUB";
                    3'b111: decoded_instruction = "AND";
                    3'b110: decoded_instruction = "OR";
                    3'b100: decoded_instruction = "XOR";
                    3'b001: decoded_instruction = "SLL";
                    3'b101: decoded_instruction = (funct7 == 7'b0000000) ? "SRL" : "SRA";
                endcase
            end
            7'b0010011: begin // I-Type Instructions
                case (funct3)
                    3'b000: decoded_instruction = "ADDI";
                    3'b111: decoded_instruction = "ANDI";
                    3'b110: decoded_instruction = "ORI";
                    3'b100: decoded_instruction = "XORI";
                    3'b001: decoded_instruction = "SLLI";
                    3'b011: decoded_instruction = "SLTIU";
                    3'b101: decoded_instruction = (funct7 == 7'b0000000) ? "SRLI" : "SRAI";
                endcase
            end
        endcase
    end
endmodule
