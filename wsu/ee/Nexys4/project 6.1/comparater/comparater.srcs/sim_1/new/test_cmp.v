`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 01:00:40 PM
// Design Name: 
// Module Name: test_cmp
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


module test_cmp;
    reg [3:0]A_tb;
    reg [3:0]B_tb;
    wire GT_o_tb;
    wire EQ_o_tb;
    wire LT_o_tb;
    
cmp kitty_poop(
    .A(A_tb),
    .B(B_tb),
    .GT_o(GT_o_tb),
    .EQ_o(EQ_o_tb),
    .LT_o(LT_o_tb)
    );
    
integer i, j, k;
    
initial begin
    
    i=0;
    j=0;
    k=0;
    

    for(j=0; j<16; j=j+1)
    begin
        #5 A_tb = j;
        begin
        for(k=0; k<16; k=k+1)
            #5 B_tb = k;
        end
    end

end
    
endmodule
