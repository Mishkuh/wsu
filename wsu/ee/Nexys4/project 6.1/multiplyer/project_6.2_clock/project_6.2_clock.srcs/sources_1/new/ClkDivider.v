`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/06/2015 10:03:44 PM
// Design Name: 
// Module Name: ClkDivider
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


module ClkDivider (
    input clk,
    input rst,
    output reg <em>clk_div</em>
    );
    
    localparam constantNumber = 50000000;
    
     reg [31:0] count;
     
    always @ (posedge(clk), posedge(rst))
    begin
        if (rst == 1'b1)
            count <= 32'b0;
        else if (count == constantNumber - 1)
            count <= 32'b0;
        else
            count <= count + 1;
    end
    
    always @ (posedge(clk), posedge(rst))
    begin
        if (rst == 1'b1)
            clk_div <= 1'b0;
        else if (count == constNumber - 1)
            clk_div <= ~clk_div;
        else
            clk_div <= clk_div;
    end   
 
endmodule