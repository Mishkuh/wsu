`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/24/2014 12:55:03 PM
// Design Name: 
// Module Name: Shifter_4in
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


module Shifter_4in(
    input [3:0] I,
    input D,
    input R,
    input F,
    input Ein,
    output [3:0] Y
    );
    
reg [3:0] Y;
     
always @ (I, Ein)
begin
    if (Ein == 0)
        Y = I;
    else
        if (R == 0)
            Y = (D == 0) ? {I[2:0], F} : {F, I[3:1]};
        else
            Y = (D == 0) ? {I[2:0], I[3]} : {I[0], I[3:1]};
end

endmodule
