`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2015 03:33:39 PM
// Design Name: 
// Module Name: FS
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

module FS(
    input A,
    input B,
    input Bin,
    output D,
    output Bout
    );
     
assign D = (A ^ B) ^ Bin;
assign Bout = ~(~(~(A ^ B) & Bin) & ~(~A & B));
 
endmodule
