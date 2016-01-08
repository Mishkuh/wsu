`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/16/2014 04:16:54 PM
// Design Name: 
// Module Name: Vert_cmp
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


module Vert_cmp(
    input [9:0]A,
    //input clk,
    output reg VS
);


/*always@(A)
begin
    if (A >= 35 & A <= 515)
        assign VS <= A;
    else
        A;
end*/

always@(A)
begin
    VS <=(A>=0 && A<2)? 1'b1:1'b0;
end
    
endmodule
