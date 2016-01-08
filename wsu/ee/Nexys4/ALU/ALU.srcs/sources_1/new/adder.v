`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/05/2015 05:24:54 PM
// Design Name: 
// Module Name: adder
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


module adder(
    input [3:0] A,
    input [3:0] B,
    output [3:0] S,
    output Cout
    );
 
wire [3:0] Carry;
 
HA add_0 (
    .A(A[0]), 
    .B(B[0]), 
    .S(S[0]), 
    .Cout(Carry[0])
    );
 
FA add_1 (
    .A(A[1]), 
    .B(B[1]), 
    .Cin(Carry[0]), 
    .S(S[1]), 
    .Cout(Carry[1])
    );
 
FA add_2 (
    .A(A[2]), 
    .B(B[2]), 
    .Cin(Carry[1]), 
    .S(S[2]), 
    .Cout(Carry[2])
    );
 
FA add_3 (
    .A(A[3]), 
    .B(B[3]), 
    .Cin(Carry[2]), 
    .S(S[3]), 
    .Cout(Carry[3])
    );
 
assign Cout = Carry[3];
 
endmodule