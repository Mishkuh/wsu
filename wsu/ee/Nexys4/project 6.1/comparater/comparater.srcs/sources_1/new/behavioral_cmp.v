`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 12:57:18 PM
// Design Name: 
// Module Name: behavioral_cmp
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


module behavioral_cmp(
    input [3:0] A,
    input [3:0] B,
    output LT_O,
    output EQ_O,
    output GT_O
    );
    
    assign LT_O = (A < B) ? 1'b1 : 1'b0;
    assign EQ_O = (A == B) ? 1'b1 : 1'b0;
    assign GT_O = (A > B) ? 1'b1 : 1'b0;

endmodule
