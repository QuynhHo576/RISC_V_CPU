module Dmem #(
    parameter ID_WIDTH   = 13,
    parameter ADDR_WIDTH = 64,
    parameter DATA_WIDTH = 64,
    parameter STRB_WIDTH = DATA_WIDTH / 8
)(
    input  logic                     clk,
    input  logic                     reset,

    // CPU-side interface
    input  logic                     mem_read,
    input  logic                     mem_write,
    input  logic [ADDR_WIDTH-1:0]    mem_addr,
    input  logic [DATA_WIDTH-1:0]    mem_wdata,
    output logic [DATA_WIDTH-1:0]    mem_rdata,
    output logic                     mem_ready,

    // AXI Write Address Channel
    output logic [ID_WIDTH-1:0]      m_axi_awid,
    output logic [ADDR_WIDTH-1:0]    m_axi_awaddr,
    output logic [7:0]               m_axi_awlen,
    output logic [2:0]               m_axi_awsize,
    output logic [1:0]               m_axi_awburst,
    output logic                     m_axi_awlock,
    output logic [3:0]               m_axi_awcache,
    output logic [2:0]               m_axi_awprot,
    output logic                     m_axi_awvalid,
    input  logic                     m_axi_awready,

    // AXI Write Data Channel
    output logic [DATA_WIDTH-1:0]    m_axi_wdata,
    output logic [STRB_WIDTH-1:0]    m_axi_wstrb,
    output logic                     m_axi_wlast,
    output logic                     m_axi_wvalid,
    input  logic                     m_axi_wready,

    // AXI Write Response Channel
    input  logic [ID_WIDTH-1:0]      m_axi_bid,
    input  logic [1:0]               m_axi_bresp,
    input  logic                     m_axi_bvalid,
    output logic                     m_axi_bready,

    // AXI Read Address Channel
    output logic [ID_WIDTH-1:0]      m_axi_arid,
    output logic [ADDR_WIDTH-1:0]    m_axi_araddr,
    output logic [7:0]               m_axi_arlen,
    output logic [2:0]               m_axi_arsize,
    output logic [1:0]               m_axi_arburst,
    output logic                     m_axi_arlock,
    output logic [3:0]               m_axi_arcache,
    output logic [2:0]               m_axi_arprot,
    output logic                     m_axi_arvalid,
    input  logic                     m_axi_arready,

    // AXI Read Data Channel
    input  logic [ID_WIDTH-1:0]      m_axi_rid,
    input  logic [DATA_WIDTH-1:0]    m_axi_rdata_axi,
    input  logic [1:0]               m_axi_rresp,
    input  logic                     m_axi_rlast,
    input  logic                     m_axi_rvalid,
    output logic                     m_axi_rready
);

    // State machine for memory access
    typedef enum logic [1:0] {
        IDLE,
        READ,
        WRITE,
        RESP
    } mem_state_t;

    mem_state_t state, next_state;

    always_ff @(posedge clk or posedge reset) begin
        if (reset)
            state <= IDLE;
        else
            state <= next_state;
    end

    always_comb begin
        next_state = state;
        case (state)
            IDLE: begin
                if (mem_read)
                    next_state = READ;
                else if (mem_write)
                    next_state = WRITE;
            end
            READ: begin
                if (m_axi_rvalid && m_axi_rlast)
                    next_state = IDLE;
            end
            WRITE: begin
                if (m_axi_awready && m_axi_wready)
                    next_state = RESP;
            end
            RESP: begin
                if (m_axi_bvalid)
                    next_state = IDLE;
            end
        endcase
    end

    // AXI Defaults
    assign m_axi_awid     = '0;
    assign m_axi_awlen    = 8'd0;
    assign m_axi_awsize   = 3'b011;  // 8 bytes (64-bit)
    assign m_axi_awburst  = 2'b01;   // INCR
    assign m_axi_awlock   = 1'b0;
    assign m_axi_awcache  = 4'b0010;
    assign m_axi_awprot   = 3'b000;

    assign m_axi_wstrb    = {STRB_WIDTH{1'b1}};
    assign m_axi_wlast    = 1'b1;

    assign m_axi_arid     = '0;
    assign m_axi_arlen    = 8'd0;
    assign m_axi_arsize   = 3'b011;
    assign m_axi_arburst  = 2'b01;
    assign m_axi_arlock   = 1'b0;
    assign m_axi_arcache  = 4'b0010;
    assign m_axi_arprot   = 3'b000;

    // Control signals
    assign m_axi_awaddr   = mem_addr;
    assign m_axi_awvalid  = (state == WRITE);
    assign m_axi_wdata    = mem_wdata;
    assign m_axi_wvalid   = (state == WRITE);
    assign m_axi_bready   = (state == RESP);

    assign m_axi_araddr   = mem_addr;
    assign m_axi_arvalid  = (state == READ);
    assign m_axi_rready   = (state == READ);

    assign mem_rdata      = m_axi_rdata_axi;
    assign mem_ready      = (state == IDLE);

endmodule
