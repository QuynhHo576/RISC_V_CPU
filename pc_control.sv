// module PCControl(
//     input clk,
//     input [63:0] entry,
//     input        reset,
//     input logic [63:0] pc_from_alu_result,
//     input logic pcsel,

//     output [63:0] pc_fetch,
//     output [63:0] next_pc_fetch
// );
//     assign next_pc_fetch = pc_fetch + 4;
//     always_ff @(posedge clk) begin
//         if (reset) begin
//             pc_fetch <= entry;
//         end else begin //PC CONTROL (B-type)
//             if (pcsel == 1)
//                 pc_fetch <= pc_from_alu_result;
//             else 
//                 pc_fetch <= next_pc_fetch;
//         end 
//     end
// endmodule