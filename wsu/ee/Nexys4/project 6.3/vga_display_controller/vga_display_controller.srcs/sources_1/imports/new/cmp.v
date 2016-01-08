`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 12:40:33 PM
// Design Name: 
// Module Name: cmp
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


module cmp(
    input [9:0]A,
    input [9:0]B,
    output reg out
);

always@(A, B)
begin
    if ((A >= 10'd144 && A < 10'd784) && (B >= 10'd35 && B < 10'd515))
        out = 1'b1;
    else
        out = 1'b0;
end

endmodule
