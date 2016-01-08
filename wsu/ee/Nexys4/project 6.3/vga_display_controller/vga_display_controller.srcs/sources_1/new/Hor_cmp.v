`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/16/2014 04:16:54 PM
// Design Name: 
// Module Name: Hor_cmp
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


module Hor_cmp(
    input [9:0]A,
    //input clk,
    output reg HS
);

/*always@(A)
begin
    if (A >= 144 && A <= 784)
        assign HS = A;
    else
        A;
end*/

always@(A)
begin
    HS<=(A>=0 && A < 96)? 1'b1:1'b0;
end

endmodule
