`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2014 02:09:49 AM
// Design Name: 
// Module Name: De-Mux_4_2
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


module DeMux_4_2(
    I0, I1, En, Y0, Y1, Y2, Y3
    );
    
    input I0,I1,En;
    output reg Y0 = 0,Y1 = 0,Y2 = 0,Y3 = 0;
    
    always @(I0,I1,En)
    
    if (En && I0 == 0 && I1 == 0)
        Y0 = 1;
    else if (En && I0 == 0 && I1 == 1)
        Y1 = 1;
    else if (En && I0 == 1 && I1 == 0)
        Y2 = 1;
    else if (En && I0 == 1 && I1 == 1)
        Y3 = 1;
    
endmodule
