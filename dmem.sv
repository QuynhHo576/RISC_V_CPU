module Dmem (
    input clk,
    input reset,
    input [63:0] ex_mem_address,        // Address from ALU result
    input [63:0] ex_mem_write_data,     // Data to write to memory (for store)
    input ex_mem_memory_write,             // Control signal for memory write
    input ex_mem_memory_read,              // Control signal for memory read
    output [63:0] ex_mem_read_data_out  // Data read from memory
);

    // Declare memory (for simplicity, assume a 64-bit wide memory with 1024 entries)
    reg [63:0] d_memory [1024]; 

    always_comb begin
        if (ex_mem_memory_read) begin 
            ex_mem_read_data_out = d_memory[ex_mem_address];
        end else begin 
            ex_mem_read_data_out = 0;
        end 
    end 

    always_ff @(posedge clk) begin
        // if (reset) begin
        //     // Reset memory to some initial state (optional)
        //     // You can clear the memory or initialize it here if needed
        //     read_data <= 0;
        //end else begin
            // if (mem_read) begin
            //     // Perform memory read (from address)
            //     read_data <= d_memory[address[11:2]];  // Assuming byte addressable memory
            // end
            if (ex_mem_memory_write) begin
                // Perform memory write (to address)
                d_memory[ex_mem_address] <= ex_mem_write_data;  // Store data at address
            end
        //end
    end

endmodule
