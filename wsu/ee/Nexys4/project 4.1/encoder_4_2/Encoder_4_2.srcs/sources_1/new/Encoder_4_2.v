`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/24/2014 12:24:51 PM
// Design Name: 
// Module Name: Encoder_4_2
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


module Encoder_4_2(
    input [3:0] I,
    input Ein,
    output reg [1:0] Y,
    output reg Eout,
    output reg GS
    );
    
 
always @ (I, Ein)
begin
    if(Ein == 1)
        Y = (I[3] == 1) ? 2'd3 : (
                (I[2] == 1) ? 2'd2 : (
                    (I[1] == 1) ? 2'd1 : 2'd0
                )
            );
    else
        Y = 2'd0;
end
 
always @ (I, Ein)
begin
    if (Ein == 1 && I == 0)
        Eout = 1'b1;
    else
        Eout = 1'b0;
end
 
always @ (I, Ein)
begin
    if (Ein == 1 && I != 0)
        GS = 1'b1;
    else
        GS = 1'b0;
end
    
endmodule
