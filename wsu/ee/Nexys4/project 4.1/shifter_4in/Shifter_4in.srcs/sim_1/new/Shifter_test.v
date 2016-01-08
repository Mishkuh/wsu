`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/27/2014 01:31:40 PM
// Design Name: 
// Module Name: Shifter_test
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


module Shifter_test;
    reg [3:0] I_tb;
    reg D_tb;
    reg R_tb;
    reg F_tb;
    reg [1:0]Ein_tb;
    wire [3:0] Y_tb;

Shifter_4in kitty_poop(
    .I(I_tb),
    .D(D_tb),
    .R(R_tb),
    .F(F_tb),
    .Ein(Ein_tb),
    .Y(Y_tb)
);

integer i;
integer d;
integer r;
integer f;

initial
begin
    I_tb = 0;
    D_tb = 0;
    R_tb = 0;
    F_tb = 0;
    Ein_tb = 0;
    
    while(Ein_tb != 2)
    begin
        for (d=0; d<2; d=d+1)
            for (r=0; r<2; r=r+1)
                for (f=0; f<2; f=f+1)
                    for (i=0; i<16; i=i+1)
                        #5 I_tb = i;
            
        Ein_tb = Ein_tb+1;
        
    end
     
    #20 $finish;
end




endmodule
