`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/16/2014 05:05:52 PM
// Design Name: 
// Module Name: VGA_Controller
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


module VGA_Controller(
    input clk,
    input rst,
    input [2:0]sw,
    output [2:0]led,
    output HS,
    output VS,
    output [3:0]Red,
    output [3:0]Green,
    output [3:0]Blue
    );
    
wire newclk;
wire [9:0]hCount;
wire [9:0]vCount;
wire TC_En;
wire in_range;
wire hertclk;


ClkDivider kitty_poop(
    .clk(clk),
    .rst(rst),
    .clk_div(hertclk)
    );

clk_divider kitty_poop0(
    .clk(clk),
    .rst(rst),
    .clkD(newclk)
    );
    
Hor_Count kitty_poop1(
    .clk(newclk),
    .rst(rst),
    .TC(TC_En),
    .hCount(hCount)
    );
     
Vert_Count kitty_poop2(
    .clk(TC_En),
    .En(1'd1),
    .rst(rst),
    .vCount(vCount)
    );

Hor_cmp kitty_poop3(
    .A(hCount),
    .HS(HS)
    );
    
cmp kitty_poop4(
    .A(hCount),
    .B(vCount),
    .out(in_range)
    );
    
Vert_cmp kitty_poop5(
    .A(vCount),
    .VS(VS)
    );

M_stand kitty_poop6(
    .v(vCount),
    .h(hCount),
    .clk(hertclk),
    .in_range(in_range),
    .R(Red),
    .G(Green),
    .B(Blue)
    ); 
      
/*always@(in_range)
begin
    if(in_range == 1'd1)
        M
    
    else
    begin
        Red = 4'b0000;
        Green = 4'b0000;
        Blue = 4'b0000;
    end
end*/

assign led = sw;

endmodule
