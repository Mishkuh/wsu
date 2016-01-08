`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/18/2014 04:03:19 PM
// Design Name: 
// Module Name: test_controller
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


module test_controller;
reg clk_tb;
reg rst_tb;
reg [2:0]sw_tb;
wire [2:0]led_tb;
wire Hor_sync_tb;
wire Vert_sync_tb;
wire [3:0]Red_tb;
wire [3:0]Green_tb;
wire [3:0]Blue_tb;


VGA_Controller uut(
    .clk(clk_tb),
    .rst(rst_tb),
    .sw(sw_tb),
    .led(led_tb),
    .HS(Hor_sync_tb),
    .VS(Vert_sync_tb),
    .Red(Red_tb),
    .Green(Green_tb),
    .Blue(Blue_tb)
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
