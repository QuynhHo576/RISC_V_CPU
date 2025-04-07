module Decoder (
    input  logic [31:0] input_bin,
    input  logic [31:0] address,

    output logic [4:0] id_reg_rs1_out, id_reg_rs2_out, id_reg_rd_out,
    output logic signed [31:0]id_reg_imm_signed,
    output logic unsigned [31:0] id_reg_imm_unsigned,
    output logic [6:0]  id_reg_opcode_out, id_reg_funct7_out,
    output logic [2:0]  id_reg_funct3_out

);

    // Internal signals for decoded fields
    logic [4:0]  rs1, rs2, rd;
    logic [6:0]  opcode, funct7;
    logic [2:0]  funct3;
    logic signed [31:0] imm_signed;
    logic [63:0] decoded_instruction;

    always_comb begin
            opcode = input_bin[6:0];
            rd     = input_bin[11:7];
            funct3 = input_bin[14:12];
            rs1    = input_bin[19:15];
            rs2    = input_bin[24:20];
            funct7 = input_bin[31:25];
            imm_signed    = input_bin[31:20];

            case (opcode)
            /* R-type
            ID Stage: Decode instruction (opcode, rs1, rs2, funct3, funct7)
                Control Unit generates: alu_op, reg_write
                Output: rs1, rs2, rd, funct3, funct7, alu_op
            Register File: 
                Inputs: rs1, rs2 (from ID stage)
                Outputs: reg_data1, reg_data2
            ALU Control:
                Inputs: alu_op, funct3, funct7
                Output: alu_ctrl (ALU operation)
            ALU:
                Inputs: reg_data1, reg_data2, alu_ctrl
                Output: alu_result
            EX/MEM Register: 
                Inputs: alu_result, rd, reg_write
                Outputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
            Memory: 
                Inputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                Output: None (R-type doesn't access memory)
            MEM/WB Register:
                Inputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                Outputs: MEM_WB_alu_result, MEM_WB_rd, MEM_WB_reg_write
            Write Back: 
                Inputs: MEM_WB_alu_result, MEM_WB_rd, MEM_WB_reg_write
                Output: register_file[MEM_WB_rd] (write back ALU result)
            */
                7'b0110011: begin // R-type
                    case (funct3)
                        3'b000: begin // ADD, SUB
                            if (funct7 == 7'b0000000)
                                decoded_instruction = "ADD";
                            else if (funct7 == 7'b0100000)
                                decoded_instruction = "SUB";
                        end
                        3'b111: decoded_instruction = "AND";
                        3'b110: decoded_instruction = "OR";
                        3'b100: decoded_instruction = "XOR";
                        3'b001: decoded_instruction = "SLL";
                        3'b101: begin
                            if (funct7 == 7'b0000000)
                                decoded_instruction = "SRL";
                            else if (funct7 == 7'b0100000)
                                decoded_instruction = "SRA";
                        end
                    endcase
                    $display("%x :%h %s x%d, x%d, x%d", address, input_bin, decoded_instruction, rd, rs1, rs2);
                end

                7'b0010011: begin // I-type (ALU)
                    imm_signed = {{20{input_bin[31]}}, input_bin[31:20]};
                    case (funct3)
                        3'b000: decoded_instruction = "ADDI"; // ADDI
                        3'b111: decoded_instruction = "ANDI"; // ANDI
                        3'b110: decoded_instruction = "ORI";  // ORI
                        3'b100: decoded_instruction = "XORI"; // XORI
                        3'b001: decoded_instruction = "SLLI"; // SLLI
                        3'b011: decoded_instruction = "SLTIU"; // SLTIU
                        3'b101: begin
                            if (funct7 == 7'b0000000)
                                decoded_instruction = "SRLI"; // SRLI
                            else if (funct7 == 7'b0100000)
                                decoded_instruction = "SRAI"; // SRAI
                        end
                    endcase
                    $display("%x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm_signed);
                end

                // I-Type (64-bit specific immediate arithmetic) (opcode: 0011011)
                7'b0011011: begin
                    case (funct3)
                        3'b000: decoded_instruction = "ADDIW"; // ADDIW
                        3'b001: decoded_instruction = "SLLIW"; // SLLIW
                        3'b101: begin
                            if (funct7 == 7'b0000000)
                                decoded_instruction = "SRLIW"; // SRLIW
                            else if (funct7 == 7'b0100000)
                                decoded_instruction = "SRAIW"; // SRAIW
                        end
                    endcase
                    $display("%x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm_signed);
                end


                // S-Type Instructions (opcode: 0100011) // NO RD
                7'b0100011: begin
                    imm_signed = {{20{input_bin[31]}}, input_bin[31:25], input_bin[11:7]};
                    case (funct3)
                        3'b000: decoded_instruction = "SB";  // Store byte
                        3'b001: decoded_instruction = "SH";  // Store halfword
                        3'b010: decoded_instruction = "SW";  // Store word
                        3'b011: decoded_instruction = "SD";  // Store doubleword (64-bit store)
                    endcase
                    $display("%x :%h %s x%d, %d(x%d)", address, input_bin, decoded_instruction, rs2, imm_signed, rs1);
                end


                // B-Type Instructions (opcode: 1100011) // NO RD
                7'b1100011: begin
                    imm_signed = {{19{input_bin[31]}}, input_bin[31], input_bin[7], input_bin[30:25], input_bin[11:8], 1'b0}; 
                    case (funct3)
                        3'b000: decoded_instruction = "BEQ";  // Branch if equal
                        3'b001: decoded_instruction = "BNE";  // Branch if not equal
                        3'b100: decoded_instruction = "BLT";  // Branch if less than
                        3'b101: decoded_instruction = "BGE";  // Branch if greater or equal
                    endcase
                    $display("%x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rs1, rs2, imm_signed);
                end


                // U-Type Instructions (opcode: 0110111 for LUI, 0010111 for AUIPC)
                7'b0110111: begin
                    imm_signed = {input_bin[31:12], 12'b0}; 
                    decoded_instruction = "LUI";  // Load upper immediate
                    $display("%x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm_signed);
                end
                7'b0010111: begin
                    imm_signed = {input_bin[31:12], 12'b0}; 
                    decoded_instruction = "AUIPC";  // Add upper immediate to PC
                    $display("%x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm_signed);
                end


                // J-Type Instructions (opcode: 1101111)
                7'b1101111: begin
                    imm_signed = {{11{input_bin[31]}}, input_bin[31], input_bin[19:12], input_bin[20], input_bin[30:21], 1'b0};
                    decoded_instruction = "JAL";  // Jump and link
                    $display("%x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm_signed);
                end


                // JALR (I-Type for jumps, opcode: 1100111)
                7'b1100111: begin
                    decoded_instruction = "JALR";  // Jump and link register
                    $display("%x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm_signed);
                end


                // Load double word (opcode: 0000011, funct3: 011 for LD)
                7'b0000011: begin
                    case (funct3)
                        3'b011: decoded_instruction = "LD";  // Load doubleword (64-bit load)
                        3'b010: decoded_instruction = "LW";  // Load word
                        3'b100: decoded_instruction = "LBU"; // LBU
                    endcase
                    $display("%x :%h %s x%d, %d(x%d)", address, input_bin, decoded_instruction, rd, imm_signed, rs1);
                end
            endcase
    end

    assign id_reg_rs1_out = rs1;
    assign id_reg_rs2_out = rs2;
    assign id_reg_rd_out = rd;
    assign id_reg_imm_signed = imm_signed;
    assign id_reg_imm_unsigned = imm_signed;
    assign id_reg_opcode_out = opcode;
    assign id_reg_funct7_out = funct7;
    assign id_reg_funct3_out = funct3;
endmodule
