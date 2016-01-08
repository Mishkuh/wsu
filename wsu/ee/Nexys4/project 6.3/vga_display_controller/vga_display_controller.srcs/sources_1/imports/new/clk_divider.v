`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/06/2014 02:44:17 AM
// Design Name: 
// Module Name: clk_divider
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


module clk_divider(
    input clk,
    input rst,
    output wire clkD
    );

wire [1:0]clkDiv;
wire [1:0]din;

/*always@(posedge clk)
begin 
    if (rst == 1'b1)
        clkDiv = 0;
    else
        clkDiv = clkDiv + 1;
end*/

dff dff_inst0 (
    .clk(clk),
    .rst(rst),
    .D(din[0]),
    .Q(clkDiv[0])
);

dff dff_inst1 (
    .clk(clkDiv[0]),
    .rst(rst),
    .D(din[1]),
    .Q(clkDiv[1])
);

assign din = ~clkDiv;
assign clkD = clkDiv[1];


endmodule
