`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/27/2014 01:14:21 PM
// Design Name: 
// Module Name: Test_decode
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


module Test_decode;
    reg [2:0]I_tb;
    wire [7:0]Y_tb;


Decoder kitty_poop(
    .I(I_tb),
    .Y(Y_tb)
);

integer i;

always
begin

    I_tb = 0;

    for (i=0; i<8; i=i+1)
    begin
        #5 I_tb = i;

    end
     
    #20 $finish;
end
 
endmodule
