`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/16/2014 03:25:11 PM
// Design Name: 
// Module Name: Vert_Count
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


module Vert_Count(
input clk,
input rst,
input En,
output reg [9:0]vCount
    );


always@(posedge clk, posedge rst)
begin
    if (rst == 1'b1)
        vCount <= 0;
    else if (vCount == 524)
        vCount <= 0;
    else if (En == 1'b1)
        vCount <= vCount + 1;
end

endmodule
