`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2014 01:30:02 AM
// Design Name: 
// Module Name: latch
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


module latch(
input I0,I1,I2,I3,
input S0,S1,
output reg O0=0,O1=0,O2=0,O3=0
);

wire [1:0]S;
assign S = {S0, S1};

always @ (I0,I1,I2,I3,S0,S1)
case (S)
2'b00:
    O0 = I0;
2'b01:
    O1 = I1;
2'b10:
    O2 = I2;
2'b11:
    O3 = I3;
endcase

endmodule
