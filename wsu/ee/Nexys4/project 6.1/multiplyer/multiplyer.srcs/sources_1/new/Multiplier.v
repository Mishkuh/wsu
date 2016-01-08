`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2014 04:02:12 PM
// Design Name: 
// Module Name: Multiplier
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


module Multiplier(
    input [3:0]A,
    input [3:0]B,
    output [7:0]R
    );
    
    wire [15:0]P_wire;
    wire [14:0]out;
    //Layer 1
Part_prod_gen kitty_poop1(
    .A(A),
    .B(B),
    .P(P_wire)
    );
    
    //Layer 2
    
Half_adder kitty_poop2(
    .B(P_wire[1]),
    .A(P_wire[4]),
    .S(R[1]),
    .Cout(out[0])
    );
    
Full_adder kitty_poop3(
    .B(P_wire[5]),
    .A(P_wire[8]),
    .Cin(P_wire[2]),
    .S(out[1]),
    .Cout(out[2])
    );
    
Full_adder kitty_poop4(
    .B(P_wire[9]),
    .A(P_wire[12]),
    .Cin(P_wire[6]),
    .S(out[3]),
    .Cout(out[4])
    );
    
Half_adder kitty_poop5(
    .B(P_wire[10]),
    .A(P_wire[13]),
    .S(out[5]),
    .Cout(out[6])
    );    
    
    //Layer 3
    
Half_adder kitty_poop6(
    .B(out[0]),
    .A(out[1]),
    .S(R[2]),
    .Cout(out[7])
    );
    
Full_adder kitty_poop7(
    .B(P_wire[3]),
    .A(out[3]),
    .Cin(out[2]),
    .S(out[8]),
    .Cout(out[9])
    );
        
Full_adder kitty_poop8(
    .B(P_wire[7]),
    .A(out[5]),
    .Cin(out[4]),
    .S(out[10]),
    .Cout(out[11])
    );
        
Full_adder kitty_poop9(
    .B(P_wire[11]),
    .A(P_wire[14]),
    .Cin(out[6]),
    .S(out[12]),
    .Cout(out[13])
    ); 
    
    //Layer 4
Adder kitty_poop10(
    .A({P_wire[15],out[12],out[10],out[8]}),
    .B({out[13],out[11],out[9],out[7]}),
    .S(R[6:3]),
    .Cout(R[7])
    //.Cin(1'b0)
    );
    
assign R[0] = P_wire[0];
    
    
endmodule
