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
    input [9:0]A,
    input [8:0]B,
    output out
    );
    
always@(A, B)
begin
    if ((A >= 144 && A <= 784) && (B >= 35 && B <= 515))
        out = 1'b1;
    else
        out = 1'b0;
end
    
endmodule
