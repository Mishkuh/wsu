`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2014 01:33:21 PM
// Design Name: 
// Module Name: wrapper
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module wrapper(
    input [7:0]I, 
    input clk,
    output [6:0]seg,
    output [3:0]AN
    );

wire Y;
wire [4:0]bus2seg;

assign AN[0] = ~Y;
assign AN[1] = Y;
assign AN[2] = 1;
assign AN[3] = 1;

counter input_counter(
    .clk(clk),
    .Y(Y),
    .AN()
);

mux input_mux(
    .I(I),
    .Y(bus2seg),
    .sel(Y)
);

bin2seg output_bin2seg(
    .I(bus2seg),
    .seg(seg)
);

endmodule
