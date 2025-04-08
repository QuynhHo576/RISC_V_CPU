module Decoder (
    input  logic [31:0] input_bin,
    input  logic [31:0] address,

    output logic [4:0] id_reg_rs1_out, id_reg_rs2_out, id_reg_rd_out,
    //output logic [31:0]id_reg_imm_out,
    output logic signed [31:0]id_reg_imm_signed_out,
    output logic unsigned [31:0] id_reg_imm_unsigned_out,
    output logic [6:0]  id_reg_opcode_out, id_reg_funct7_out,
    output logic [2:0]  id_reg_funct3_out,
    output logic [3:0]  id_alu_op_out

);

    // Internal signals for decoded fields
    logic [4:0]  rs1, rs2, rd;
    logic [6:0]  opcode, funct7;
    logic [2:0]  funct3;
    //logic signed [31:0] imm;
    logic signed [31:0] imm_signed;
    logic unsigned [31:0] imm_unsigned;
    logic [63:0] decoded_instruction;
    logic [3:0]  alu_op;

    always_comb begin
            //bit range for all these variables are the same across instruction types, except imm -> need seperate imm
            opcode = input_bin[6:0];
            rd     = input_bin[11:7];
            funct3 = input_bin[14:12];
            rs1    = input_bin[19:15];
            rs2    = input_bin[24:20];
            funct7 = input_bin[31:25];
            //imm_signed    = input_bin[31:20];

            case (opcode)
                /* R-type Datapath
                ID Stage: Decode instruction (opcode, rs1, rs2, funct3, funct7, rd)
                    Output: rs1, rs2, rd, funct3, funct7, opcode, alu_op 
                Register File: 
                    Inputs: rs1, rs2 (from ID stage)
                    Outputs: reg_data1, reg_data2
                ALU Control:
                    Inputs: opcode, funct3, funct7
                    Output: reg_write, alu_op (ALU operation)
                ALU:
                    Inputs: reg_data1, reg_data2, alu_op
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
                //R-type does not need imm so set any imm to zero
                    imm_signed      = 0;
                    imm_unsigned    = 0;
                    //imm             = 0;
                    case (funct3)
                        3'b000: begin // ADD, SUB
                            if (funct7 == 7'b0000000) begin
                                decoded_instruction = "ADD";
                                alu_op = 4'b0010;  // ADD
                            end else if (funct7 == 7'b0100000) begin
                                decoded_instruction = "SUB";
                                alu_op = 4'b0110;  // SUB
                            end
                        end
                        3'b111: begin // AND
                            decoded_instruction = "AND";
                            alu_op = 4'b0101;  // AND
                        end
                        3'b110: begin // OR
                            decoded_instruction = "OR";
                            alu_op = 4'b0011;  // OR
                        end
                        3'b100: begin // XOR
                            decoded_instruction = "XOR";
                            alu_op = 4'b0001;  // XOR
                        end
                        3'b001: begin // SLL (Shift Left Logical)
                            decoded_instruction = "SLL";
                            alu_op = 4'b0100;  // SLL
                        end
                        3'b101: begin // SRL, SRA (Shift Right Logical/Arithmetic)
                            if (funct7 == 7'b0000000) begin
                                decoded_instruction = "SRL";
                                alu_op = 4'b0101;  // SRL
                            end else if (funct7 == 7'b0100000) begin
                                decoded_instruction = "SRA";
                                alu_op = 4'b1011;  // SRA
                            end
                        end
                    endcase
                    $display("R-type %x :%h %s x%d, x%d, x%d", address, input_bin, decoded_instruction, rd, rs1, rs2);
                end

                /* I-type Datapath
                ID Stage: Decode instruction (opcode, rs1, imm, funct3, rd)
                    Output: rs1, rd, imm, funct3, opcode, alu_op 
                Register File: 
                    Inputs: rs1 (from ID stage)
                    Outputs: reg_data1
                ALU Control:
                    Inputs: opcode, funct3
                    Output: alu_op (ALU operation)
                ALU:
                    Inputs: reg_data1, imm, alu_op
                    Output: alu_result 
                EX/MEM Register: 
                    Inputs: alu_result, rd, reg_write
                    Outputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                Memory: 
                    Inputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                    Output: None (I-type doesn't access memory)
                MEM/WB Register:
                    Inputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                    Outputs: MEM_WB_alu_result, MEM_WB_rd, MEM_WB_reg_write
                Write Back: 
                    Inputs: MEM_WB_alu_result, MEM_WB_rd, MEM_WB_reg_write
                    Output: register_file[MEM_WB_rd] (write back ALU result)
                */
                7'b0010011: begin // I-type (ALU arithmetic)
                //I-type arithmetic does not need imm so set any imm to zero
                    rs2 = 0;
                    imm_signed = {{20{input_bin[31]}}, input_bin[31:20]};
                    //imm = imm_signed;
                    funct7 = 0;
                    case (funct3)
                        3'b000: begin
                            decoded_instruction = "ADDI";  // ADDI
                            alu_op = 4'b0010;  // ALU operation for ADDI
                        end
                        3'b111: begin
                            decoded_instruction = "ANDI";  // ANDI
                            alu_op = 4'b0000;  // ALU operation for ANDI
                        end
                        3'b110: begin
                            decoded_instruction = "ORI";   // ORI
                            alu_op = 4'b0001;  // ALU operation for ORI
                        end
                        3'b100: begin
                            decoded_instruction = "XORI";  // XORI
                            alu_op = 4'b0011;  // ALU operation for XORI
                        end
                        3'b001: begin
                            decoded_instruction = "SLLI";  // SLLI
                            alu_op = 4'b0100;  // ALU operation for SLLI
                        end
                        3'b011: begin
                            decoded_instruction = "SLTIU"; // SLTIU
                            alu_op = 4'b0110;  // ALU operation for SLTIU
                        end
                        3'b101: begin
                            if (funct7 == 7'b0000000) begin
                                decoded_instruction = "SRLI";  // SRLI
                                alu_op = 4'b0101;  // ALU operation for SRLI
                            end else if (funct7 == 7'b0100000) begin
                                decoded_instruction = "SRAI";  // SRAI
                                alu_op = 4'b0111;  // ALU operation for SRAI
                            end
                        end
                    endcase
                    $display("I-type %x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm_signed);
                end

                // I-Type (64-bit specific immediate arithmetic) (opcode: 0011011)
                7'b0011011: begin
                    rs2 = 0;
                    imm_signed = {{20{input_bin[31]}}, input_bin[31:20]};
                    //imm = imm_signed;
                    funct7 = 0;
                    case (funct3)
                        3'b000: begin
                            decoded_instruction = "ADDIW";  // ADDIW
                            alu_op = 4'b0010;  // ALU operation for ADDIW
                        end
                        3'b001: begin
                            decoded_instruction = "SLLIW";  // SLLIW
                            alu_op = 4'b0100;  // ALU operation for SLLIW
                        end
                        3'b101: begin
                            if (funct7 == 7'b0000000) begin
                                decoded_instruction = "SRLIW";  // SRLIW
                                alu_op = 4'b0101;  // ALU operation for SRLIW
                            end else if (funct7 == 7'b0100000) begin
                                decoded_instruction = "SRAIW";  // SRAIW
                                alu_op = 4'b0111;  // ALU operation for SRAIW
                            end
                        end
                    endcase
                    $display("I-Type %x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm_signed);
                end

                /* I-type JALR Datapath
                    ID Stage: Decode instruction (opcode, rs1, imm, funct3, rd)
                        Output: rs1, rd, imm, funct3, opcode, alu_op 
                    Register File: 
                        Inputs: rs1 (from ID stage)
                        Outputs: reg_data1
                    ALU Control:
                        Inputs: opcode, funct3
                        Output: alu_op (ALU operation for JALR)
                    ALU:
                        Inputs: reg_data1, imm, alu_op
                        Output: alu_result (This will calculate the target address for the jump)
                    EX/MEM Register: 
                        Inputs: alu_result, rd, reg_write
                        Outputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                    Memory: 
                        Inputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                        Output: None (JALR doesn't access memory)
                    MEM/WB Register:
                        Inputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                        Outputs: MEM_WB_alu_result, MEM_WB_rd, MEM_WB_reg_write
                    Write Back: 
                        Inputs: MEM_WB_alu_result, MEM_WB_rd, MEM_WB_reg_write
                        Output: register_file[MEM_WB_rd] (write back the return address (PC + 4))
                */
                // JALR (I-Type for jumps, opcode: 1100111)
                7'b1100111: begin
                    rs2 = 0;
                    imm_signed = {{20{input_bin[31]}}, input_bin[31:20]};
                    //imm = imm_signed;
                    funct7 = 0;
                    decoded_instruction = "JALR";  // Jump and link register
                    alu_op = 4'b0010;              // ALU operation for address calculation (addition)
                    $display("I-Type %x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rd, rs1, imm_signed);
                end

                /* I-type Load Instruction Datapath
                    ID Stage: Decode instruction (opcode, rs1, imm, funct3, rd)
                        Output: rs1, rd, imm, funct3, opcode, alu_op
                    Register File: 
                        Inputs: rs1 (from ID stage)
                        Outputs: reg_data1 (data from register file)
                    ALU Control:
                        Inputs: opcode, funct3
                        Output: alu_op (ALU operation for load, which typically does addition for address calculation)
                    ALU:
                        Inputs: reg_data1 (base address from rs1), imm (immediate offset), alu_op
                        Output: alu_result (computed memory address)
                    EX/MEM Register: 
                        Inputs: alu_result (memory address), rd, reg_write
                        Outputs: EX_MEM_alu_result (address), EX_MEM_rd (destination register), EX_MEM_reg_write
                    Memory: 
                        Inputs: EX_MEM_alu_result (memory address), EX_MEM_rd (destination register), EX_MEM_reg_write
                        Output: mem_data (data read from memory)
                    MEM/WB Register:
                        Inputs: mem_data (data read from memory), EX_MEM_rd (destination register), EX_MEM_reg_write
                        Outputs: MEM_WB_mem_data (data from memory), MEM_WB_rd (destination register), MEM_WB_reg_write
                    Write Back: 
                        Inputs: MEM_WB_mem_data (data from memory), MEM_WB_rd (destination register), MEM_WB_reg_write
                        Output: register_file[MEM_WB_rd] (data written to register file from memory)
                */

                // Load double word (I-Type for load, opcode: 0000011, funct3: 011 for LD)
                7'b0000011: begin
                    rs2 = 0;
                    alu_op = 4'b0000;             
                    imm_signed = {{20{input_bin[31]}}, input_bin[31:20]};
                    //imm = imm_signed;
                    funct7 = 0;
                    case (funct3)
                        3'b011: decoded_instruction = "LD";  // Load doubleword (64-bit load)
                        3'b010: decoded_instruction = "LW";  // Load word
                        3'b100: decoded_instruction = "LBU"; // LBU
                    endcase
                    $display("I-Type %x :%h %s x%d, %d(x%d)", address, input_bin, decoded_instruction, rd, imm_signed, rs1);
                end
                /* S-type Datapath
                ID Stage: Decode instruction (opcode, rs1, rs2, imm, funct3)
                    Output: rs1, rs2, imm, funct3, opcode, alu_op 
                Register File: 
                    Inputs: rs1, rs2 (from ID stage)
                    Outputs: reg_data1 (base address), reg_data2 (data to store)
                ALU Control:
                    Inputs: opcode, funct3
                    Output: alu_op (typically addition for address calculation)
                ALU:
                    Inputs: reg_data1, imm, alu_op
                    Output: alu_result (effective memory address)
                EX/MEM Register: 
                    Inputs: alu_result, reg_data2, mem_write
                    Outputs: EX_MEM_alu_result, EX_MEM_write_data, EX_MEM_mem_write
                Memory: 
                    Inputs: EX_MEM_alu_result (address), EX_MEM_write_data, EX_MEM_mem_write
                    Output: None (S-type writes to memory)
                MEM/WB Register:
                    Not used for writeback (S-type doesn't write to register file)
                Write Back: 
                    Not applicable (no data is written back to registers)
                */
                // S-Type Instructions (opcode: 0100011) // NO RD
                7'b0100011: begin
                    rd = 0;
                    imm_signed = {{20{input_bin[31]}}, input_bin[31:25], input_bin[11:7]};
                    //imm = imm_signed;
                    funct7 = 0;
                    //Ex: input_bin = 32'hFFF50513
                    //bits [31:25] → upper part of the immediate = 1111111
                    //bits [11:7] → lower part of the immediate  = 01010
                    //Combined: {input_bin[31:25], input_bin[11:7]} → 12-bit immediate = 111111101010
                    //input_bin[31] is the sign bit of the immediate = 1
                    //{{20{input_bin[31]}}} replicates the sign bit 20 times to extend it from 12 bits to 32 bits.
                    alu_op = 4'b0010;
                    case (funct3)
                        3'b000: decoded_instruction = "SB";  // Store byte
                        3'b001: decoded_instruction = "SH";  // Store halfword
                        3'b010: decoded_instruction = "SW";  // Store word
                        3'b011: decoded_instruction = "SD";  // Store doubleword (64-bit store)
                    endcase
                    $display("S-Type %x :%h %s x%d, %d(x%d)", address, input_bin, decoded_instruction, rs2, imm_signed, rs1);
                end

                /* B-type Datapath (Branch)
                ID Stage: Decode instruction (opcode, rs1, rs2, imm, funct3)
                    Output: rs1, rs2, imm, funct3, opcode, branch_op
                Register File: 
                    Inputs: rs1, rs2
                    Outputs: reg_data1, reg_data2
                Branch Control:
                    Inputs: reg_data1, reg_data2, funct3
                    Output: branch_taken (1 if condition met, else 0)
                ALU (optional, for comparison):
                    Inputs: reg_data1, reg_data2
                    Output: comparison_result
                Branch Target Calculation:
                    Inputs: PC, imm
                    Output: branch_target (PC + offset)
                PC Mux:
                    Selects between PC + 4 and branch_target based on branch_taken
                Memory, WB:
                    Not used in B-type
                */
                // B-Type Instructions (opcode: 1100011) // NO RD
                7'b1100011: begin
                    rd = 0;
                    imm_signed = {{19{input_bin[31]}}, input_bin[31], input_bin[7], input_bin[30:25], input_bin[11:8], 1'b0}; 
                    imm_unsigned = {1'b0, input_bin[7], input_bin[30:25], input_bin[11:8], 1'b0}; // zero-extended
                    funct7 = 0;
                    case (funct3)
                        3'b000: begin
                            decoded_instruction = "BEQ";   // Branch if equal
                            //imm = imm_signed;
                            alu_op = 4'b1000;              // ALU operation for equality check
                
                        end
                        3'b001: begin
                            decoded_instruction = "BNE";   // Branch if not equal
                            //imm = imm_signed;
                            alu_op = 4'b1001;              // ALU operation for inequality check
                        end
                        3'b100: begin
                            decoded_instruction = "BLT";   // Branch if less than (signed)
                            //imm = imm_signed;
                            alu_op = 4'b1010;              // ALU operation for signed less than
                        end
                        3'b101: begin
                            decoded_instruction = "BGE";   // Branch if greater or equal (signed)
                            //imm = imm_signed;
                            alu_op = 4'b1011;              // ALU operation for signed greater/equal
                        end
                        3'b110: begin
                            decoded_instruction = "BLTU";  // Branch if less than (unsigned)
                            //imm = imm_unsigned;
                            alu_op = 4'b1100;              // ALU operation for unsigned less than
                        end
                        3'b111: begin
                            decoded_instruction = "BGEU";  // Branch if greater or equal (unsigned)
                            //imm = imm_unsigned;
                            alu_op = 4'b1101;              // ALU operation for unsigned greater/equal
                        end
                    endcase
                    if (funct3 == 3'b110 || funct3 == 3'b111)
                        $display("B-Type %x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rs1, rs2, imm_unsigned);
                    else 
                        $display("B-Type %x :%h %s x%d, x%d, %d", address, input_bin, decoded_instruction, rs1, rs2, imm_signed);
                end

                /* U-type Datapath (e.g., LUI, AUIPC)
                ID Stage: Decode instruction (opcode, rd, imm)
                    Output: rd, imm, opcode, alu_op
                ALU Control:
                    Inputs: opcode
                    Output: alu_op (pass-through or add PC)
                ALU:
                    Inputs: (LUI) imm, (AUIPC) PC, imm
                    Output: alu_result
                EX/MEM Register: 
                    Inputs: alu_result, rd, reg_write
                    Outputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                Memory:
                    Not used
                MEM/WB Register:
                    Inputs: EX_MEM_alu_result, EX_MEM_rd, EX_MEM_reg_write
                    Outputs: MEM_WB_alu_result, MEM_WB_rd, MEM_WB_reg_write
                Write Back:
                    Inputs: MEM_WB_alu_result, MEM_WB_rd, MEM_WB_reg_write
                    Output: register_file[MEM_WB_rd]
                */
                // U-Type Instructions (opcode: 0110111 for LUI, 0010111 for AUIPC)
                7'b0110111: begin
                    rs1 = 0;
                    rs2 = 0;
                    imm_signed = {input_bin[31:12], 12'b0}; 
                    //imm = imm_signed;
                    funct7 = 0;
                    funct3 = 0;
                    decoded_instruction = "LUI";  // Load upper immediate
                    alu_op = 4'b0000;             // ALU pass-through or immediate load (depends on implementation)
                    $display("%x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm_signed);
                end
                7'b0010111: begin
                    rs1 = 0;
                    rs2 = 0;
                    imm_signed = {input_bin[31:12], 12'b0}; 
                    //imm = imm_signed;
                    funct7 = 0;
                    funct3 = 0;
                    decoded_instruction = "AUIPC";  // Add upper immediate to PC
                    alu_op = 4'b0010; 
                    $display("U-Type %x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm_signed);
                end

                /* J-type Datapath (e.g., JAL)
                ID Stage: Decode instruction (opcode, rd, imm)
                    Output: rd, imm, opcode
                ALU (for return address):
                    Inputs: PC, 4
                    Output: PC + 4 (to save in rd)
                Branch Target Calculation:
                    Inputs: PC, imm
                    Output: jump_target (PC + offset)
                PC Mux:
                    Selects jump_target unconditionally
                EX/MEM Register: 
                    Inputs: PC + 4, rd, reg_write
                    Outputs: EX_MEM_return_addr, EX_MEM_rd, EX_MEM_reg_write
                Memory:
                    Not used
                MEM/WB Register:
                    Inputs: EX_MEM_return_addr, EX_MEM_rd, EX_MEM_reg_write
                    Outputs: MEM_WB_return_addr, MEM_WB_rd, MEM_WB_reg_write
                Write Back:
                    Inputs: MEM_WB_return_addr, MEM_WB_rd, MEM_WB_reg_write
                    Output: register_file[MEM_WB_rd] (return address)
                */
                // J-Type Instructions (opcode: 1101111)
                7'b1101111: begin
                    rs1 = 0;
                    rs2 = 0;
                    imm_signed = {{11{input_bin[31]}}, input_bin[31], input_bin[19:12], input_bin[20], input_bin[30:21], 1'b0};
                    //imm = imm_signed;
                    funct7 = 0;
                    funct3 = 0;
                    decoded_instruction = "JAL";  // Jump and link
                    alu_op = 4'b1110; 
                    $display("J-Type %x :%h %s x%d, %d", address, input_bin, decoded_instruction, rd, imm_signed);
                end
            endcase
    end

    assign id_reg_rs1_out = rs1;
    assign id_reg_rs2_out = rs2;
    assign id_reg_rd_out = rd;
    //assign id_reg_imm_out = imm;
    assign id_reg_imm_signed_out = imm_signed;
    assign id_reg_imm_unsigned_out = imm_unsigned;
    assign id_reg_opcode_out = opcode;
    assign id_reg_funct7_out = funct7;
    assign id_reg_funct3_out = funct3;
    assign id_alu_op_out = alu_op;

endmodule
