`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 04:08:29 PM
// Design Name: 
// Module Name: Part_prod_gen
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


module Part_prod_gen(
    input [3:0]A,
    input [3:0]B,
    output [15:0]P
    );
    
    assign P[0] = A[0] & B[0];
    assign P[1] = A[0] & B[1];
    assign P[2] = A[0] & B[2];
    assign P[3] = A[0] & B[3];
    assign P[4] = A[1] & B[0];
    assign P[5] = A[1] & B[1];
    assign P[6] = A[1] & B[2];
    assign P[7] = A[1] & B[3];
    assign P[8] = A[2] & B[0];
    assign P[9] = A[2] & B[1];
    assign P[10] = A[2] & B[2];
    assign P[11] = A[2] & B[3];
    assign P[12] = A[3] & B[0];
    assign P[13] = A[3] & B[1];
    assign P[14] = A[3] & B[2];
    assign P[15] = A[3] & B[3];
    
endmodule
