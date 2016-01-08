`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2015 06:09:49 PM
// Design Name: 
// Module Name: ALU_test
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


module ALU_test;
    reg [2:0] opCode_tb;
    reg [3:0] A_tb;
    reg [3:0] B_tb;
    wire [3:0] R_tb;
    wire cout;

My_ALU goTime(
    .opcode(opCode_tb),
    .A(A_tb),
    .B(B_tb),
    .R(R_tb),
    .cout(cout)
);

integer i,j,k;

initial begin

    i=0;
    j=0;
    k=0;
        
    for(k=0;k<6;k=k+1)
    begin
        #5 opCode_tb = k;
        for(i=0;i<16;i=i+1)
        begin
            #5 A_tb = i;
            for(j=0;j<16;j=j+1)
            begin
                #5 B_tb = j;
            end
        end
    end

end


endmodule