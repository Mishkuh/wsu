`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/11/2014 03:24:04 PM
// Design Name: 
// Module Name: two_dig_count
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


module Two_dig_count(
    input clk,
    input rst,
    output reg [1:0]Bit
    );
    
always@(posedge clk, posedge rst)
begin
    if (rst == 1'b1)
    begin
        Bit <= 2'd0;
    end
    
    else if (En)
       Bit <= Bit + 1; 
    
end        


assign En = 1'd1;

endmodule
