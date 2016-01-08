`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 01:45:01 PM
// Design Name: 
// Module Name: Full_adder
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


module Add_Sub_bitslice(
    input A,
    input B,
    input Cin,
    output S,
    output Cout
);

assign S = A ^ (B ^ Cin) ^ Cin;
assign Cout = (A & B) | ((A ^ B) & Cin);

endmodule
