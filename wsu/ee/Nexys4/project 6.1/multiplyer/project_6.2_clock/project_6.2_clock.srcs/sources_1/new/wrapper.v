`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/06/2015 10:07:15 PM
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
    input clk,
    input rst,
    output [6:0]seg,
    output [7:0]an,
    output dp,
    output [7:0]led
    );
    
    wire temp;
    
    ClkDivider cdiv
    (
        .clk_div[temp];
    );
    
    counter count
    (
        
    );
    
endmodule
