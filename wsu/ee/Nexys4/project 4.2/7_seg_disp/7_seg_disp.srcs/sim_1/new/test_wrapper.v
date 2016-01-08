`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2014 02:34:58 PM
// Design Name: 
// Module Name: test_wrapper
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


module test_wrapper;
    reg [7:0]I_tb;
    reg clk_tb;
    wire [6:0]seg_tb;
    wire [3:0]AN_tb;
    
wrapper kitty_poop(
    .I(I_tb),
    .clk(clk_tb),
    .seg(seg_tb),
    .AN(AN_tb)
);

integer c;
always 
#10 clk_tb = ~clk_tb;

initial begin

clk_tb = 0;

I_tb = 8'hf0;

    /*for ( c=0; c<2**8 ; c=c+1 )
    begin
        #100 I_tb = c;
    end*/

end

endmodule
