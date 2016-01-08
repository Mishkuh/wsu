`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/20/2014 02:58:37 PM
// Design Name: 
// Module Name: test_sseg
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


module test_sseg;
    reg clk_tb;
    reg rst_tb;
    wire [6:0]seg_tb;
    wire [3:0]an_tb;
    wire dp_tb;
    wire [7:0]led_t;
    
Wrapper kitty_poop(
    .clk(clk_tb),
    .rst(rst),
    .seg(seg_tb),
    .an(an_tb),
    .dp(dp_tb),
    .led(led_tb)
);

always
   
#5 clk_tb = ~clk_tb;

initial begin
    clk_tb = 100;
    rst_tb = 1;
    #1 rst_tb = 0;
    #10;
end

endmodule
