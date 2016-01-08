`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/30/2014 02:20:51 AM
// Design Name: 
// Module Name: wrapper
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


module wrapper(
    input I0,I1,I2,I3,clk,
    output Y0,Y1,Y2,Y3, tData
    );
    
    wire sdata;
    wire S0;
    wire S1;
    wire t0;
    wire t1;
    wire t2;
    wire t3;
    
    assign tData = sdata;
    
    counter input_counter(
        .clk(clk),
        .Y0(S0),
        .Y1(S1)
    );
    
    Mux_4_1 input_mux (
        .I3(I3),
        .I2(I2),
        .I1(I1),
        .I0(I0),
        .S1(S1),
        .S0(S0),
        .Y(sdata)
    );
    
    DeMux_4_2 output_demux (
        .En(sdata),
        .I1(S1),
        .I0(S0),
        .Y0(t0),
        .Y1(t1),
        .Y2(t2),
        .Y3(t3)
    );
    
        latch output_latch (
        .I0(t0),
        .I1(t1),
        .I2(t2),
        .I3(t3),
        .O0(Y0),
        .O1(Y1),
        .O2(Y2),
        .O3(Y3),
        .S0(S0),
        .S1(S1)
    );
    
    
endmodule
