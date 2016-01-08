`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/12/2014 04:14:12 PM
// Design Name: 
// Module Name: SW_test
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


module SW_test;
    reg clk_tb;
    reg rst_tb;
    reg start_tb;
    reg stop_tb;
    reg inc_tb;
    wire [6:0]seg_tb;
    wire [7:0]an_tb;
    wire dp_tb;


SW Kitty_poop(
    .clk(clk_tb),
    .rst(rst_tb),
    .start(start_tb),
    .stop(stop_tb),
    .inc(inc_tb),
    .seg(seg_tb),
    .an(an_tb),
    .dp(dp_tb)
    );

always

#5 clk_tb = ~clk_tb;

initial begin
    
    clk_tb = 100;
    rst_tb = 1;
    start_tb = 1'b0;
    stop_tb = 1'b0;
    inc_tb = 1'b0;
    
    #1 rst_tb = 0;
    #10 start_tb = 1;
    //#10 inc_tb = 1;

end

endmodule
