`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/31/2014 01:24:32 AM
// Design Name: 
// Module Name: counter
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


module counter(
input clk,
output Y1, Y0
);

reg [27:0] counter = 0;

always @ (posedge clk)
begin
    
    counter <= counter + 1;
end

assign Y1 = counter[27];
assign Y0 = counter[26];

endmodule