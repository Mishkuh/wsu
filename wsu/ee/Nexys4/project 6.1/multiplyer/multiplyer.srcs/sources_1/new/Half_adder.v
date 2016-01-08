`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 03:52:34 PM
// Design Name: 
// Module Name: Half_adder
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


module Half_adder(
    input A,
    input B,
    output S,
    output Cout
);

assign S = A ^ B;
assign Cout = A & B;

endmodule