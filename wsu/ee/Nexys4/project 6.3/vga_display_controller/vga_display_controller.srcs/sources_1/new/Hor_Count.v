`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/16/2014 03:38:01 PM
// Design Name: 
// Module Name: Hor_Count
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


module Hor_Count(
input clk,
input rst,
output reg TC,
output reg [9:0]hCount
    );
    

always@(posedge clk, posedge rst)
    if (rst == 1'b1)
    begin
        hCount = 0;
        TC = 1'b0;
    end
    
    else if (hCount == 799)
    begin
        hCount = 0;
        TC = 1'b1;
    end
    
    else
    begin
        hCount = hCount + 1;
        TC = 1'b0;
    end
    
    
endmodule
