`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/23/2014 11:05:35 PM
// Design Name: 
// Module Name: Mux_4_1
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


module Mux_4_1(
    input [1:0] I0,
    input [1:0] I1,
    input [1:0] I2,
    input [1:0] I3,
    input [1:0] Sel,
    output [1:0] Y
    );
    
    reg [1:0] Y;
     
    always @ (Sel, I0, I1, I2, I3)
    begin
        if (Sel == 2'd0)
            Y = I0;
        else if (Sel == 2'd1)
            Y = I1;
        else if (Sel == 2'd2)
            Y = I2;
        else
            Y = I3;
    end
    
endmodule
