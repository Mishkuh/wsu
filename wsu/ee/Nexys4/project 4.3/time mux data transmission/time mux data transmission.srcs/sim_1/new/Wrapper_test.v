`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2014 01:53:22 PM
// Design Name: 
// Module Name: Wrapper_test
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


module Wrapper_test;
    reg I0_tb, I1_tb, I2_tb, I3_tb, clk_tb;
    wire Y0_tb, Y1_tb, Y2_tb, Y3_tb, tData_tb;


wrapper kitty_poop(
    .I0(I0_tb),
    .I1(I1_tb),
    .I2(I2_tb),
    .I3(I3_tb),
    .clk(clk_tb),
    .Y0(Y0_tb),
    .Y1(Y1_tb),
    .Y2(Y2_tb),
    .Y3(Y3_tb),
    .tData(tData_tb)
);  

integer v;
always 
#10 clk_tb = ~clk_tb;

initial
begin

clk_tb = 0;
for (v=0; v<16; v=v+1)
begin
    #5 {I0_tb, I1_tb, I2_tb, I3_tb} = v;
end

     
    #20 $finish;
end
    
endmodule
