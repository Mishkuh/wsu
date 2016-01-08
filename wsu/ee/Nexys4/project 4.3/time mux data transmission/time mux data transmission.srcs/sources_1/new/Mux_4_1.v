`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2014 01:46:25 AM
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
    I0, I1, I2, I3, S0, S1, Y
    );
    
    input I0,I1,I2,I3,S0,S1;
    output reg Y;
    
    
    always @(I0,I0,I1,I2,I3,S0,S1)
    
    if (S0 == 0 && S1 == 0)
        Y = I0;
    else if (S0 == 0 && S1 == 1)
        Y = I1;
    else if (S0 == 1 && S1 == 0)
        Y = I2;
    else
        Y = I3;    
    
endmodule
