`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2015 03:13:46 PM
// Design Name: 
// Module Name: Subtractor
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


module Subtractor(
    input [3:0] A,
    input [3:0] B,
    output [3:0] D,
    output Bout
    );
 
 
 
wire [3:0] Borrow;

 
FS subtract_0 (
    .A(A[0]), 
    .B(B[0]),
    .Bin(0), 
    .D(D[0]),
    .Bout(Borrow[0])
    );
 
FS subtract_1 (
    .A(A[1]), 
    .B(B[1]), 
    .Bin(Borrow[0]), 
    .D(D[1]), 
    .Bout(Borrow[1])
    );
 
FS subtract_2 (
    .A(A[2]), 
    .B(B[2]), 
    .Bin(Borrow[1]), 
    .D(D[2]), 
    .Bout(Borrow[2])
    );
 
FS subtract_3 (
    .A(A[3]), 
    .B(B[3]), 
    .Bin(Borrow[2]), 
    .D(D[3]), 
    .Bout(Borrow[3])
    );
 
assign Bout = Borrow[3];
 
endmodule
