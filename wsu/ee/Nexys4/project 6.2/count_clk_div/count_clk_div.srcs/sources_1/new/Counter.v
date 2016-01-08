`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/19/2014 11:41:29 PM
// Design Name: 
// Module Name: Counter
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


module Counter(
    input clk,
    input rst,
    output reg [7:0] Q
 );

always @ (posedge(clk), posedge(rst))
begin
 if (rst == 1'b1)
     Q <= 8'b0;
 else
     Q <= Q + 1'b1;
end

endmodule
