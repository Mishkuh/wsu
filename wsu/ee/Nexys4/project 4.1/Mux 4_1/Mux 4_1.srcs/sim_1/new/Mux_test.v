`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2014 02:34:38 PM
// Design Name: 
// Module Name: Mux_test
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


module Mux_test;
    reg [1:0]I0_tb;
    reg [1:0]I1_tb;
    reg [1:0]I2_tb;
    reg [1:0]I3_tb;
    reg [1:0]Sel_tb;
    wire [1:0]Y_tb;

Mux_4_1 kitty_poop(
    .I0(I0_tb),
    .I1(I1_tb),
    .I2(I2_tb),
    .I3(I3_tb),
    .Sel(Sel_tb),
    .Y(Y_tb)
);

integer i;

initial
begin


{I0_tb, I1_tb, I2_tb, I3_tb, Sel_tb} = 0;

for (i=0; 2^10; i=i+1)

    #5 {I0_tb, I1_tb, I2_tb, I3_tb, Sel_tb} = i;
     
    #20 $finish;
end

endmodule
