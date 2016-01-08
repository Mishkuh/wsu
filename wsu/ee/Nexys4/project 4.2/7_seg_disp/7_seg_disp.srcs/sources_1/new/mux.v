`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2014 03:06:17 AM
// Design Name: 
// Module Name: mux
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


module mux(
    input [7:0]I,
    input sel,
    output reg [3:0]Y
    );
    
always @(I, sel)

    if (sel == 1'd0)
    begin
        Y = I[3:0];
    end
    
    else
    begin
        Y = I[7:4];
    end
    
endmodule
