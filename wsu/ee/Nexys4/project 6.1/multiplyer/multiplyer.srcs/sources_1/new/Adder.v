`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 04:00:25 PM
// Design Name: 
// Module Name: Adder
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


module Adder(
    input [3:0] A,
    input [3:0] B,
    output [3:0] S,
    output Cout
);

wire [3:0] Carry;

Half_adder add_0 (
.A(A[0]),
.B(B[0]),
.S(S[0]),
.Cout(Carry[0])
);

Full_adder add_1 (
.A(A[1]),
.B(B[1]),
.Cin(Carry[0]),
.S(S[1]),
.Cout(Carry[1])
);

Full_adder add_2 (
.A(A[2]),
.B(B[2]),
.Cin(Carry[1]),
.S(S[2]),
.Cout(Carry[2])
);

Full_adder add_3 (
.A(A[3]),
.B(B[3]),
.Cin(Carry[2]),
.S(S[3]),
.Cout(Carry[3])
);

assign Cout = Carry[3];

endmodule