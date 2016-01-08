`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/20/2014 04:43:04 PM
// Design Name: 
// Module Name: test_Mult
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


module test_Mult;
    reg [3:0]A_tb;
    reg [3:0]B_tb;
    wire [7:0]R_tb;

Multiplier kitty_poop(
    .A(A_tb),
    .B(B_tb),
    .R(R_tb)
    );
    
integer i,j;

initial begin
A_tb = 0;
B_tb = 0;

    for(i=0;i<16;i=i+1)
    begin
        for(j=0;j<16;j=j+1)
            B_tb = B_tb + 1;
        A_tb = A_tb+1;
    end
    
end
endmodule
