`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/19/2014 02:11:22 AM
// Design Name: 
// Module Name: OpCode_mux
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


module OpCode_mux(
    input [3:0]A,
    input [3:0]B,
    input [2:0]OpCode,
    //output reg [4:0]Y,
    output [4:0]led
    );

reg [4:0]Y;
wire [4:0]out;


always@(OpCode, A, B)
begin
    if(OpCode == 3'b000)          // A+B
        Y <= A+B;
    else if (OpCode == 3'b001)    // A+1
        Y <= A+1;
    else if (OpCode == 3'b010)    // A-B
        Y <= A-B;
    else if (OpCode == 3'b011)
        Y <= A^B;
    else if (OpCode == 3'b100)
        Y <= A|B;
    else if (OpCode == 3'b101)
        Y <= A&B;                
end                
                

//assign out = Y;
assign led = Y;
//assign led[4:4] = ERR;
//assign OpCode = sw[10:8];

   
endmodule
