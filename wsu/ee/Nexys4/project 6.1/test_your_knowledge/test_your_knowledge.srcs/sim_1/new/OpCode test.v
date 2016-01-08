`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/03/2014 06:00:23 PM
// Design Name: 
// Module Name: OpCode test
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


module OpCode_test;
    reg [3:0]A_tb;
    reg [3:0]B_tb;
    reg [2:0]OC;
    wire [4:0]led_tb;

OpCode_mux kitty_poop(
    .sw(sw_tb),
    .OpCode(OC),
    .led(led_tb)
    );

integer i,j,k;
   
initial begin

i=0;
j=0;
k=0;

    for(i=0;i<7;i=i+1)
    begin
        for(j=0;j<16;j=j+1)
        begin
            for(k=0;k<16;k=k+1)
            begin
                A_tb = k;
            end
            B_tb = j;
        end
        OC = i;
    end
        
end

endmodule
