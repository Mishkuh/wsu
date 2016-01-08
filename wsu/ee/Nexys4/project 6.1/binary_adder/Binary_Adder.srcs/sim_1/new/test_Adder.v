`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 02:53:49 PM
// Design Name: 
// Module Name: test_Adder
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


module test_Adder;
    reg [3:0] A_tb;
    reg [3:0] B_tb;
    wire [3:0] S_tb;
    wire Cout_tb;


Adder kitty_poop(
    .A(A_tb),
    .B(B_tb),
    .S(S_tb),
    .Cout(Cout_tb)
    );
    
integer i, k;

initial begin


    for(i=0; i<16; i=i+1)
    begin
        #1A_tb = i;
        
        for(k=0; k<16; k=k+1)
        begin
            #1B_tb = k;
        end
    end
end

endmodule
