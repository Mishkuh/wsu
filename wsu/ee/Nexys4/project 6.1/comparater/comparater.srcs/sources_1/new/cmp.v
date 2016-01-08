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
    input [3:0]A,
    input [3:0]B,
    output GT_o,
    output EQ_o,
    output LT_o
    );
    
    wire [3:0] GT_int;
    wire [3:0] EQ_int;
    wire [3:0] LT_int;
    
    bit_slice_cmp slice_0(
        .A(A[0]),
        .B(B[0]),
        .GT_i(1'b0),
        .EQ_i(1'b1),
        .LT_i(1'b0),
        .GT_o(GT_int[0]),
        .EQ_o(EQ_int[0]),
        .LT_o(LT_int[0])
    );
    
    bit_slice_cmp slice_1(
        .A(A[1]),
        .B(B[1]),
        .GT_i(GT_int[0]),
        .EQ_i(EQ_int[0]),
        .LT_i(LT_int[0]),
        .GT_o(GT_int[1]),
        .EQ_o(EQ_int[1]),
        .LT_o(LT_int[1])
        );
    
     bit_slice_cmp slice_2(
        .A(A[2]),
        .B(B[2]),
        .GT_i(GT_int[1]),
        .EQ_i(EQ_int[1]),
        .LT_i(LT_int[1]),
        .GT_o(GT_int[2]),
        .EQ_o(EQ_int[2]),
        .LT_o(LT_int[2])
        );
    
     bit_slice_cmp slice_3(
        .A(A[3]),
        .B(B[3]),
        .GT_i(GT_int[2]),
        .EQ_i(EQ_int[2]),
        .LT_i(LT_int[2]),
        .GT_o(GT_int[3]),
        .EQ_o(EQ_int[3]),
        .LT_o(LT_int[3])
     );
     
     
     assign GT_o = GT_int[3];
     assign EQ_o = EQ_int[3];
     assign LT_o = LT_int[3];
            
endmodule
