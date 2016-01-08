`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2015 04:32:07 PM
// Design Name: 
// Module Name: My_ALU
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


module My_ALU(
    input [2:0] opcode,
    input [3:0] A,
    input [3:0] B,
    output [3:0] R,
    output cout
    );

reg [3:0] adderA;
reg [3:0] adderB;
wire [3:0] adderR;
wire adderCout;

reg  [3:0] subA;
reg  [3:0] subB;
wire [3:0] subR;
wire subCout;

reg [3:0] Rtemp;
wire [3:0] tempRA;
wire [3:0] tempRS;
reg tempCout;
wire Couttemp;

adder add_0(
    .A(adderA),
    .B(adderB),
    .S(tempRA),
    .Cout(Couttemp)
);

Subtractor sub_0(
    .A(subA),
    .B(subB),
    .D(tempRS),
    .Bout(Couttemp)
);

always @(*) begin
 
    if( opcode == 3'b000 )
    begin
        adderA = A;
        adderB = B;
        Rtemp = tempRA;
        tempCout = Couttemp;
    end
    else if( opcode == 3'b001 )
    begin
        adderA = A;
        adderB = 1;
        Rtemp = tempRA;
        tempCout = Couttemp;
    end
    else if( opcode == 3'b010 )
    begin
        subA = A;
        subB = B;
        Rtemp = tempRS;
        tempCout = Couttemp;
    end
    else if( opcode == 3'b011 )
    begin
        Rtemp = A ^ B;
    end
    else if( opcode == 3'b100 )
    begin
        Rtemp = A | B;
    end
    else if( opcode == 3'b101 )
    begin
        Rtemp = A & B;
    end
end

assign R = Rtemp;


endmodule
