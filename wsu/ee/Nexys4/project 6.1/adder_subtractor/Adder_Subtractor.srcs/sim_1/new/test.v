`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/03/2014 09:21:27 PM
// Design Name: 
// Module Name: test
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


module test;
    reg [3:0] A_tb;
    reg [3:0] B_tb;
    reg Cin_tb;
    wire Cout_tb;
    wire [3:0]led_tb;
    
Adder_subtractor kitty_poop(
    .A(A_tb),
    .B(B_tb),
    .Cin(Cin_tb),
    .Cout(Cout_tb),
    .led(led_tb)
    );
    
integer i,j,k;

initial begin

i = 0;
j = 0;
k = 0;
    
    for(i=0;i<2;i=i+1)
    begin
        for(j=0;j<16;j=j+1)
        begin
            for(k=0;k<16;k=k+1)
            begin
                A_tb = k;
            end
            B_tb = j;
        end
        Cin_tb = i;
    end
end        
    
endmodule
