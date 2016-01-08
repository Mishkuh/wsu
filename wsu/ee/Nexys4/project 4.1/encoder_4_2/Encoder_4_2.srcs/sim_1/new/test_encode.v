`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/24/2014 02:46:40 PM
// Design Name: 
// Module Name: test_encode
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
module test_encode;
reg [3:0] I_tb;
reg Ein_tb;
wire [1:0] Y_tb;
wire Eout_tb;
wire GS_tb;

Encoder_4_2 kitty_poop(
    .I(I_tb),
    .Ein(Ein_tb[0]),
    .Y(Y_tb),
    .Eout(Eout_tb),
    .GS(GS_tb)
    );
    
integer i;
         
    
initial
begin
    I_tb = 0;
    Ein_tb = 0;
    
    while(Ein_tb != 2)
    begin
        for (i=0; i<16; i=i+1)
            #5 I_tb = i;
        Ein_tb = Ein_tb+1;
    end
     
    #20 $finish;
end

endmodule
