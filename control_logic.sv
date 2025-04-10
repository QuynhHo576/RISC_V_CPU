module ControlUnit (
    input logic [31:0] if_instr,           

    output logic reg_write_control,          // control signal to write to register
    output logic mem_read_control,           // control signal for memory read
    output logic mem_write_control,          // control signal for memory write
    output logic alu_src_control,            // ALU source control signal - use for when ALU need imm or rs2
    output logic mem_to_reg_control,
    output logic pc_contrl
);
    //logic [4:0]  rs1, rs2, rd;
    logic [6:0]  opcode, funct7;
    logic [2:0]  funct3;
    //logic signed [31:0] imm;
    //logic signed [31:0] imm_signed;
    //logic unsigned [31:0] imm_unsigned;
    //logic [3:0]  alu_op;

    logic reg_write;         
    logic mem_read;           
    logic mem_write;          
    logic alu_src;            
    logic mem_to_reg;

    always_comb begin
        opcode = if_instr[6:0];

        case (opcode)
            7'b0110011: begin // R-type instructions
                reg_write = 1;
                mem_read = 0;
                mem_write = 0;
                alu_src = 0;
                mem_to_reg = 0;      // No need to write data to register (since it's a store operation)
            end
            7'b0010011: begin // I-type instructions (e.g., ADDI, ANDI, ORI, etc.)
                reg_write = 1;
                mem_read = 0;
                mem_write = 0;
                alu_src = 1;  // Immediate operand used
                mem_to_reg = 0;      // No need to write data to register (since it's a store operation)
            end
            7'b0011011: begin // I-type instructions (e.g., ADDIW, SLLIW, SRLIW, etc.)
                reg_write = 1;
                mem_read = 0;
                mem_write = 0;
                alu_src = 1;  // Immediate operand used
                mem_to_reg = 0;      // No need to write data to register (since it's a store operation)
            end
            7'b1100111: begin // I-type JALR (Jump and Link Register)
                reg_write = 1;      // We need to write the return address (PC + 4) to the register
                mem_read = 0;       // No memory read for JALR
                mem_write = 0;      // No memory write for JALR
                alu_src = 1;        // Immediate operand is used (imm is added to rs1)
                mem_to_reg = 0;      // No need to write data to register (since it's a store operation)
            end
            7'b0000011: begin  // I-type Load instructions (e.g., LB, LH, LW, LD)
                reg_write = 1;       // Enable register write (write data to the register file)
                mem_read = 1;        // Enable memory read (data will be read from memory)
                mem_write = 0;       // Disable memory write (no write to memory for load instructions)
                alu_src = 1;         // Use immediate as second operand for ALU
                mem_to_reg = 1;      // Data from memory will be written back to the register
            end
            7'b0100011: begin // S-type instructions (e.g., SB, SH, SW, SD)
                reg_write = 0;       // No register write for store instructions
                mem_read = 0;        // No memory read for store instructions
                mem_write = 1;       // Memory write is enabled
                alu_src = 1;         // Immediate operand is used for ALU operation (calculating address)
                mem_to_reg = 0;      // No need to write data to register (since it's a store operation)
            end
            7'b1100011: begin // B-Type branch instructions
                reg_write  = 0;       // No register write
                mem_read   = 0;       // No memory read
                mem_write  = 0;       // No memory write
                alu_src    = 0;       // ALU input is from registers (rs1 and rs2)
                // alu_op will be set based on funct3 (e.g., BEQ, BNE, etc.)
            end
            7'b0110111: begin // U-type LUI - Load Upper Immediate
                reg_write  = 1;
                mem_read   = 0;
                mem_write  = 0;
                alu_src    = 1;  // Use immediate
                mem_to_reg = 0;  // ALU result to register
            end

            7'b0010111: begin // U-type AUIPC - Add Upper Immediate to PC
                reg_write  = 1;
                mem_read   = 0;
                mem_write  = 0;
                alu_src    = 1;  // Use immediate (added to PC in ALU)
                mem_to_reg = 0;  // ALU result to register
            end

            7'b1101111: begin // J-type JAL - Jump and Link
                reg_write  = 1;       // Write return address (PC+4) to rd
                mem_read   = 0;
                mem_write  = 0;
                alu_src    = 1;       // Use immediate for address calculation (if ALU is used for jump address)
                mem_to_reg = 0;       // Write ALU result (target address or PC+imm) to rd
            end                             
        endcase
    end

    assign reg_write_control = reg_write;          
    assign mem_read_control = mem_read;           
    assign mem_write_control = mem_write;          
    assign alu_src_control = alu_src;            
    assign mem_to_reg_control = mem_to_reg;

endmodule