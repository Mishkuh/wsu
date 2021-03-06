`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/19/2014 02:04:08 AM
// Design Name: 
// Module Name: Adder_subtractor
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


module Adder_subtractor(
    input [3:0] A,
    input [3:0] B,
    input Cin,
    output [3:0]led,
    output Cout
    );
    
wire [2:0] Cin_Cout;

Add_Sub_bitslice kitty_poop0(
    .A(A[0]),
    .B(B[0]),
    .Cin(Cin),
    .S(S[0]),
    .Cout(Cin_Cout[0])
    );

Add_Sub_bitslice kitty_poop1(
    .A(A[1]),
    .B(B[1]),
    .Cin(Cin_Cout[0]),
    .S(S[1]),
    .Cout(Cin_Cout[1])
    );
    
Add_Sub_bitslice kitty_poop2(
    .A(A[2]),
    .B(B[2]),
    .Cin(Cin_Cout[1]),
    .S(S[2]),
    .Cout(Cin_Cout[2])
    ); 
    
Add_Sub_bitslice kitty_poop3(
    .A(A[3]),
    .B(B[3]),
    .Cin(Cin_Cout[2]),
    .S(S[3]),
    .Cout(Cout)
    );
   
endmodule
