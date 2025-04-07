module control_unit (
    input logic [6:0] opcode, funct7,   // opcode from instruction
    input logic [2:0]  funct3
    output logic reg_write,          // control signal to write to register
    output logic mem_read,           // control signal for memory read
    output logic mem_write,          // control signal for memory write
    output logic alu_src,            // ALU source control signal
    
);
    always_comb begin
        case (opcode)
            7'b0110011: begin // R-type instructions
                reg_write = 1;
                mem_read = 0;
                mem_write = 0;
                alu_src = 0;
            end
        endcase
    end
endmodule