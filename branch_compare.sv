module BranchCompare(
    input signed [63:0] branch_compare_regA_data_signed; //from reg_file
    input signed [63:0] branch_compare_regB_data_signed; //from reg_file
    input unsigned [63:0] branch_compare_regA_data_unsigned; //from reg_file
    input unsigned [63:0] branch_compare_regB_data_unsigned; //from reg_file
    //input branch_unsigned; //from control logic
    input [6:0] opcode;
    input [2:0] funct3; 

    output logic branch_compare_result;
);

assign equal_result = (branch_compare_regA_data_signed == branch_compare_regB_data_signed)? 1 : 0;
assign not_equal_result = (branch_compare_regA_data_signed != branch_compare_regB_data_signed)? 1 : 0;
assign less_than_result = (branch_compare_regA_data_signed < branch_compare_regB_data_signed)? 1 : 0;
assign greater_equal_result = (branch_compare_regA_data_signed >= branch_compare_regB_data_signed)? 1 : 0;
assign less_than_result_unsigned = (branch_compare_regA_data_unsigned < branch_compare_regB_data_unsigned)? 1 : 0;
assign greater_equal_result_unsigned = (branch_compare_regA_data_unsigned >= branch_compare_regB_data_unsigned)? 1 : 0;

always_comb begin 
    if (opcode == 7'b1100011) begin
        case(funct3)
        3'b000: begin
            branch_compare_result = equal_result;
        end   
        3'b001: begin
            branch_compare_result = not_equal_result;
        end 
        3'b100: begin
            branch_compare_result = less_than_result;    // ALU operation for signed less than
        end
        3'b101: begin
                  // ALU operation for signed greater/equal
            branch_compare_result = greater_equal_result; 
        end
        3'b110: begin
                        // ALU operation for unsigned less than
            branch_compare_result = less_than_result_unsigned;
        end
        3'b111: begin
                        // ALU operation for unsigned greater/equal
            branch_compare_result = greater_equal_result_unsigned;
        end
        default begin 
            branch_compare_result = 0;
        end
        endcase 
    end else begin
        branch_compare_result = 0;
    end
end
>=,<=,<,<
endmodule