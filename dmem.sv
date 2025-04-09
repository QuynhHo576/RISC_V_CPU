module dmem (
    input clk,
    input reset,
    input [63:0] address,        // Address from ALU result
    input [63:0] write_data,     // Data to write to memory (for store)
    input mem_write,             // Control signal for memory write
    input mem_read,              // Control signal for memory read
    output [63:0] read_data  // Data read from memory
);

    // Declare memory (for simplicity, assume a 64-bit wide memory with 1024 entries)
    reg [63:0] d_memory [1024]; 

    always_comb begin
        if (mem_read) begin 
            read_data = d_memory[address];
        end else if begin 
            read_data = 0;
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
            if (mem_write) begin
                // Perform memory write (to address)
                memory[address] <= write_data;  // Store data at address
            end
        //end
    end

endmodule
