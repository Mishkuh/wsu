`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 12:36:14 PM
// Design Name: 
// Module Name: bit_slice_cmp
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


module bit_slice_cmp(
    input A,
    input B,
    input GT_i,
    input EQ_i,
    input LT_i,
    output GT_o,
    output EQ_o,
    output LT_o
    );
    
    assign GT_o = (A & ~B) | (GT_i & ((A & B) | (~A &~B)));
    assign EQ_o = EQ_i & ((A & B) | (~A &~B));
    assign LT_o = (~A & B) | (LT_i & ((A & B) | (~A &~B)));
    
endmodule
