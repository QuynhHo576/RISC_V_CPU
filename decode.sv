// Decoding module extracted from the function
module Decoder (
    input  logic        clk,
    input  logic        reset,
    input  logic [31:0] instr_address,
    input  logic [31:0] instr_data
);

    // Internal signals for decoded fields
    logic [4:0]  rs1, rs2, rd;
    logic [6:0]  opcode, funct7;
    logic [2:0]  funct3;
    logic signed [31:0] imm;
    string decoded_instruction;

    always_ff @(posedge clk) begin
        if (!reset) begin
            opcode = instr_data[6:0];
            rd     = instr_data[11:7];
            funct3 = instr_data[14:12];
            rs1    = instr_data[19:15];
            rs2    = instr_data[24:20];
            funct7 = instr_data[31:25];
            imm    = instr_data[31:20];

            case (opcode)
                7'b0110011: begin // R-type
                    case (funct3)
                        3'b000: decoded_instruction = (funct7 == 7'b0000000) ? "ADD" : "SUB";
                        3'b111: decoded_instruction = "AND";
                        3'b110: decoded_instruction = "OR";
                        3'b100: decoded_instruction = "XOR";
                        3'b001: decoded_instruction = "SLL";
                        3'b101: decoded_instruction = (funct7 == 7'b0000000) ? "SRL" : "SRA";
                        default: decoded_instruction = "UNKNOWN";
                    endcase
                    $display("%x :%h %s x%d, x%d, x%d", instr_address, instr_data, decoded_instruction, rd, rs1, rs2);
                end

                7'b0010011: begin // I-type (ALU)
                    imm = {{20{instr_data[31]}}, instr_data[31:20]};
                    case (funct3)
                        3'b000: decoded_instruction = "ADDI";
                        3'b111: decoded_instruction = "ANDI";
                        3'b110: decoded_instruction = "ORI";
                        3'b100: decoded_instruction = "XORI";
                        3'b001: decoded_instruction = "SLLI";
                        3'b011: decoded_instruction = "SLTIU";
                        3'b101: decoded_instruction = (funct7 == 7'b0000000) ? "SRLI" : "SRAI";
                        default: decoded_instruction = "UNKNOWN";
                    endcase
                    $display("%x :%h %s x%d, x%d, %d", instr_address, instr_data, decoded_instruction, rd, rs1, imm);
                end

                7'b0100011: begin // S-type
                    imm = {{20{instr_data[31]}}, instr_data[31:25], instr_data[11:7]};
                    case (funct3)
                        3'b000: decoded_instruction = "SB";
                        3'b001: decoded_instruction = "SH";
                        3'b010: decoded_instruction = "SW";
                        3'b011: decoded_instruction = "SD";
                        default: decoded_instruction = "UNKNOWN";
                    endcase
                    $display("%x :%h %s x%d, %d(x%d)", instr_address, instr_data, decoded_instruction, rs2, imm, rs1);
                end

                7'b1100011: begin // B-type
                    imm = {{19{instr_data[31]}}, instr_data[31], instr_data[7], instr_data[30:25], instr_data[11:8], 1'b0};
                    case (funct3)
                        3'b000: decoded_instruction = "BEQ";
                        3'b001: decoded_instruction = "BNE";
                        3'b100: decoded_instruction = "BLT";
                        3'b101: decoded_instruction = "BGE";
                        default: decoded_instruction = "UNKNOWN";
                    endcase
                    $display("%x :%h %s x%d, x%d, %d", instr_address, instr_data, decoded_instruction, rs1, rs2, imm);
                end

                7'b0110111: begin // LUI
                    imm = {instr_data[31:12], 12'b0};
                    decoded_instruction = "LUI";
                    $display("%x :%h %s x%d, %d", instr_address, instr_data, decoded_instruction, rd, imm);
                end
                7'b0010111: begin // AUIPC
                    imm = {instr_data[31:12], 12'b0};
                    decoded_instruction = "AUIPC";
                    $display("%x :%h %s x%d, %d", instr_address, instr_data, decoded_instruction, rd, imm);
                end

                7'b1101111: begin // J-type (JAL)
                    imm = {{11{instr_data[31]}}, instr_data[31], instr_data[19:12], instr_data[20], instr_data[30:21], 1'b0};
                    decoded_instruction = "JAL";
                    $display("%x :%h %s x%d, %d", instr_address, instr_data, decoded_instruction, rd, imm);
                end

                7'b1100111: begin // JALR (I-type jump)
                    decoded_instruction = "JALR";
                    $display("%x :%h %s x%d, x%d, %d", instr_address, instr_data, decoded_instruction, rd, rs1, imm);
                end

                7'b0000011: begin // Loads
                    case (funct3)
                        3'b011: decoded_instruction = "LD";
                        3'b010: decoded_instruction = "LW";
                        3'b100: decoded_instruction = "LBU";
                        default: decoded_instruction = "UNKNOWN";
                    endcase
                    $display("%x :%h %s x%d, %d(x%d)", instr_address, instr_data, decoded_instruction, rd, imm, rs1);
                end

                default: begin
                    decoded_instruction = "UNKNOWN";
                    $display("%x :%h UNKNOWN INSTRUCTION", instr_address, instr_data);
                end
            endcase
        end
    end

endmodule
