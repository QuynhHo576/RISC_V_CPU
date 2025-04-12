module ControlUnit (
    input logic [31:0] if_opcode,    
    input logic branch_compare_result,       

    output logic reg_write_control,          // control signal to write to register
    output logic mem_read_control,           // control signal for memory read
    output logic mem_write_control,          // control signal for memory write
    output logic alu_operand1_control_out,   // ALU source control signal - use for when ALU need pc or R[rs1]
    output logic alu_operand2_control_out,   // ALU source control signal - use for when ALU need imm or R[rs2]
    output logic mem_to_reg_control,
    output logic pc_sel_out
);
    //FOR B-TYPE and J-TYPE PCSELECT
    typedef enum logic [1:0] {
    PC_4    = 2'b00, // normal sequential
    PC_BR   = 2'b01, // branch target (B-type)
    PC_JAL  = 2'b10, // jal target
    PC_JALR = 2'b11  // jalr target
    } pcSel_t;

    typedef enum logic [1:0] {
    REG_TO_MEM_ALU     = 2'b00, // ALU result
    REG_TO_MEM_MEM     = 2'b01, // Data from memory
    REG_TO_MEM_JAL_JALR= 2'b10, // PC + 4 or PC + 8 (return addr)
    REG_TO_MEM_NONE    = 2'b11  // Default/undefined or no writeback
    } reg_to_mem_t;

    logic reg_write;         
    logic mem_read;           
    logic mem_write;     
    logic alu_operand1_control;  //=1 if it's B type, else others 
    logic alu_operand2_control;            
    //logic mem_to_reg;

    pcSel_t      pcSel;
    reg_to_mem_t mem_to_reg;

    always_comb begin
        case (if_opcode)
            7'b0110011: begin // R-type instructions
                reg_write = 1;
                mem_read = 0;
                mem_write = 0;
                alu_operand1_control = 0;
                alu_operand2_control = 0;
                mem_to_reg = REG_TO_MEM_ALU;     
                pcSel = PC_4;    
            end
            7'b0010011: begin // I-type instructions (e.g., ADDI, ANDI, ORI, etc.)
                reg_write = 1;
                mem_read = 0;
                mem_write = 0;
                alu_operand1_control = 0;
                alu_operand2_control = 1;  // Immediate operand used
                mem_to_reg = REG_TO_MEM_ALU;  
                pcSel = PC_4;    
            end
            7'b0011011: begin // I-type instructions (e.g., ADDIW, SLLIW, SRLIW, etc.)
                reg_write = 1;
                mem_read = 0;
                mem_write = 0;
                alu_operand1_control = 0;
                alu_operand2_control = 1;  // Immediate operand used
                mem_to_reg = REG_TO_MEM_ALU;      
                pcSel = PC_4;
            end
            7'b1100111: begin // I-type JALR (Jump and Link Register)
                reg_write = 1;      // We need to write the return address (PC + 4) to the register
                mem_read = 0;       // No memory read for JALR
                mem_write = 0;      // No memory write for JALR
                alu_operand1_control = 0;
                alu_operand2_control = 1;        // Immediate operand is used (imm is added to rs1)
                mem_to_reg = REG_TO_MEM_JAL_JALR;      // No need to write data to register (since it's a store operation)
                pcSel = PC_JALR;
            end
            7'b1101111: begin // J-type JAL - Jump and Link
                reg_write  = 1;       // Write return address (PC+4) to rd
                mem_read   = 0;
                mem_write  = 0;
                alu_operand1_control = 1;
                alu_operand2_control = 1;       // Use immediate for address calculation (if ALU is used for jump address)
                mem_to_reg = REG_TO_MEM_JAL_JALR;       // Write ALU result (target address or PC+imm) to rd
                pcSel      = PC_JAL;
            end   
            7'b0000011: begin  // I-type Load instructions (e.g., LB, LH, LW, LD)
                reg_write = 1;       // Enable register write (write data to the register file)
                mem_read = 1;        // Enable memory read (data will be read from memory)
                mem_write = 0;       // Disable memory write (no write to memory for load instructions)
                alu_operand1_control = 0;
                alu_operand2_control = 1;         // Use immediate as second operand for ALU
                mem_to_reg = REG_TO_MEM_MEM;      // Data from memory will be written back to the register
                pcSel = PC_4;
            end
            7'b0100011: begin // S-type instructions (e.g., SB, SH, SW, SD)
                reg_write = 0;       // No register write for store instructions
                mem_read = 0;        // No memory read for store instructions
                mem_write = 1;       // Memory write is enabled
                alu_operand1_control = 0;
                alu_operand2_control = 1;         // Immediate operand is used for ALU operation (calculating address)
                mem_to_reg = REG_TO_MEM_NONE;      // No need to write data to register (since it's a store operation)
                pcSel = PC_4;
            end
            7'b1100011: begin // B-Type branch instructions
                reg_write  = 0;       // No register write
                mem_read   = 0;       // No memory read
                mem_write  = 0;       // No memory write
                mem_to_reg = REG_TO_MEM_NONE;
                alu_operand1_control = 1;
                alu_operand2_control    = 1;  //=1 so choose imm
                if (branch_compare_result)
                    pcSel = PC_BR; //01
                else 
                    pcSel = PC_4;
                // alu_op will be set based on funct3 (e.g., BEQ, BNE, etc.)
            end
            7'b0110111: begin // U-type LUI - Load Upper Immediate
                reg_write  = 1;
                mem_read   = 0;
                mem_write  = 0;
                alu_operand1_control = 0;
                alu_operand2_control = 1;  // Use immediate
                mem_to_reg = REG_TO_MEM_ALU;  // ALU result to register
                pcSel       = PC_4;
            end

            7'b0010111: begin // U-type AUIPC - Add Upper Immediate to PC
                reg_write  = 1;
                mem_read   = 0;
                mem_write  = 0;
                alu_operand1_control = 0;  // use address
                alu_operand2_control = 1;  // Use immediate (added to PC in ALU)
                mem_to_reg = REG_TO_MEM_ALU;  // ALU result to register
                pcSel       = PC_4;
            end
        endcase
    end

    assign reg_write_control = reg_write;          
    assign mem_read_control = mem_read;           
    assign mem_write_control = mem_write;     
    assign alu_operand1_control_out = alu_operand1_control;   
    assign alu_operand2_control_out = alu_operand2_control;            
    assign mem_to_reg_control = mem_to_reg;
    assign pc_contrl_out = pcSel;

endmodule