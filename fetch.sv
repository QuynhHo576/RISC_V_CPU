module Fetch (
    input  logic                 clk,
    input  logic                 reset,
    input  logic [63:0]          entry,
    input logic [63:0]           pc_from_alu_result,
    input logic                  pcsel,

    //Read Address Channel (AR) (Retrieve address data from slave)
    output logic [63:0]           m_axi_araddr,
    output logic                  m_axi_arvalid,
    input  logic                  m_axi_arready,

    output logic [7:0]            m_axi_arlen,
    output logic [2:0]            m_axi_arsize,
    output logic [1:0]            m_axi_arburst,
    
    input  logic [63:0]           m_axi_rdata,
    input  logic                  m_axi_rvalid,
    output logic                  m_axi_rready,
    input  logic                  m_axi_rlast,

    // Outputs to Decode stage
    output logic [31:0] if_instr,
    output logic [31:0] if_address_out
    
);

    typedef enum logic [2:0] {
        SEND_READ_ADDRESS  = 3'b000,
        SEND_READ_DATA     = 3'b001,
        READ_DATA = 3'b100
    } state_t;

    state_t state, next_state;
    logic [63:0] pc, next_pc;
    logic [63:0] fetched_instr;
    logic [63:0] display_addr;
    logic [63:0] next_display_addr;

    logic [31:0] instruction_array [1000];
    logic [9:0]  index;

    logic [9:0]  pc_fetch;

    // Combinational logic for state transitions
    always_comb begin
        if (!reset) begin
            case(state)
                SEND_READ_ADDRESS: begin   
                    if (m_axi_arready && m_axi_arvalid)   
                        next_state = SEND_READ_DATA;
                end
                SEND_READ_DATA: begin
                    if (m_axi_rvalid && m_axi_rready) begin
                        if (m_axi_rdata == 64'b0) begin 
                            $finish;
                        end 
                        next_state = READ_DATA;
                    end
                end
                READ_DATA: begin
                        if (m_axi_rlast) begin
                            if (!m_axi_rvalid) begin
                                next_pc = pc + 64;
                                next_state = SEND_READ_ADDRESS;
                            end
                        end else begin
                            next_state = SEND_READ_DATA;
                        end
                end
            endcase
        end
    end

    // Sequential logic for AXI signaling and data capture
    always_ff @(posedge clk) begin 
        m_axi_araddr   <= pc;
        m_axi_arlen    <= 7;
        m_axi_arsize   <= 8;
        m_axi_arburst  <= 2;
        if(!reset) begin
            // READ ADDRESS CHANNEL
            if (state == SEND_READ_ADDRESS) 
                m_axi_arvalid <= 1;
            else m_axi_arvalid <= 0;
            if (m_axi_arvalid && m_axi_arready)
                m_axi_arvalid <= 0;

            // READ DATA CHANNEL
            if (state == SEND_READ_DATA && m_axi_rvalid)
                m_axi_rready <= 1;
            if (m_axi_rvalid == 1 && m_axi_rready == 1) begin
                m_axi_rready <= 0;

                fetched_instr <= m_axi_rdata;
                next_display_addr <= display_addr + 8;
            end

            // if (state == DECODE_INSTRUCTION) begin
            //     next_display_addr <= display_addr + 8;
            // end
        end
    end

    // State and PC update logic
    always_ff @(posedge clk) begin
        if (reset) begin
            pc            <= entry;
            state         <= SEND_READ_ADDRESS;
        end else begin
            pc            <= next_pc;
            state         <= next_state;
            display_addr  <= next_display_addr;
        end
    end
    always_ff @(posedge clk) begin
        if (reset) begin
            index <= 0;
        end else if (m_axi_rvalid && m_axi_rready && (index < 1000)) begin
            instruction_array[index + 1] <= m_axi_rdata[31:0];
            instruction_array[index + 2] <= m_axi_rdata[63:32];
            index <= index + 2;
        end
    end

    //===============PC HANDLING=====================

    typedef enum logic [1:0] {
    PC_4    = 2'b00, // normal sequential
    PC_BR   = 2'b01, // branch target (B-type)
    PC_JAL  = 2'b10, // jal target
    PC_JALR = 2'b11  // jalr target
    } pcSel_t;

    pcSel_t pcSel;

    always_ff @(posedge clk) begin
        if (reset) begin
            pc_fetch <= 0; //point to inst = 0
        end else if (index == 64) begin //pc_fetch 
            if (pcsel == PC_BR || pcsel == PC_JAL || pc == PC_JALR)
                    pc_fetch <= pc_from_alu_result;
            else if (pcsel == PC_4)
                pc_fetch <= pc_fetch + 4;
        end
    end

assign if_instr              = instruction_array[pc_fetch[9:2]];
assign if_address_out        = pc_fetch - 4;
endmodule