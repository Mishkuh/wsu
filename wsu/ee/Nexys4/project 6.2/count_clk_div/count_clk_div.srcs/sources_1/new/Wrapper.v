`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/20/2014 12:02:21 AM
// Design Name: 
// Module Name: Wrapper
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


module Wrapper(
        input clk,
        input rst,
        output [6:0]seg,
        output [7:0]an,
        output dp,
        output [7:0]led
    );

reg [3:0]first; //register for the first digit
reg [3:0]second; //register for the second digit
reg [3:0]third;
reg [3:0]fourth;
reg [3:0]fifth;
reg [3:0]sixth;
reg [3:0]seventh;
reg [3:0]eighth;

wire [7:0]countwire;
wire newclk;
wire [7:0]ledwire;
reg [22:0] delay; //register to produce the 0.1 second delay
wire test;

always @ (posedge clk or posedge rst)
begin
    if (rst)
        delay <= 0;
    else
        delay <= delay + 1;
end
  
assign test = & delay;

ClkDivider kitty_poop0(
    .clk(clk),
    .rst(rst),
    .clk_div(newclk)
);

Counter kitty_poop1(
    .clk(test),
    .rst(rst),
    .Q(led)
);


always @ (posedge newclk , posedge rst)
begin
    if (rst) begin
        first <= 0;
        second <= 0;
        third <= 0;
        fourth <= 0;
        fifth <= 0;
        sixth <= 0;
        seventh <= 0;
        eighth <= 0;
    end
    else if (first==4'd9) 
    begin  //xxx9 reached
        first <= 0;
        if (second == 4'd9) 
        begin //xx99 reached
            second <= 0;
            if (third == 4'd9) 
            begin //x999 reached
                third <= 0;
                if (fourth == 4'd9) //9999 reached
                    fourth <= 0;
                else
                    fourth <= fourth +1;
            end
            else
               third <= third +1;
         end
         else
            second <= second + 1;
    end
    else 
        first <= first + 1;
end

reg [6:0]sseg;
reg [7:0]an_temp;

localparam N = 18;

reg [N-1:0]count;
//reg [7:0]count;

always @ (posedge clk or posedge rst)
begin
    if (rst)
        count <= 0;
    else
        count <= count + 1;
end

always @ (posedge clk)
begin
    case(count[N-1:N-2])

    3'b000 :
    begin
        sseg = first;
        an_temp = 8'b11111110;
    end
    
    3'b001:
    begin
        sseg = second;
        an_temp = 8'b11111101;
    end
    
    3'b010:
    begin
        sseg = third;
        an_temp = 8'b11111011;
    end
     
    3'b011:
    begin
        sseg = fourth;
        an_temp = 8'b11110111;
    end
    
    3'b100:
    begin
        sseg = 6'ha;//fifth;
        an_temp = 8'b11101111;
    end
    
    3'b101:
    begin
        sseg = 6'ha;//sixth;
        an_temp = 8'b11011111;
    end
            
    3'b110:
    begin
        sseg = 6'ha;//seventh;
        an_temp = 8'b10111111;
    end
    
    3'b111:
    begin
        sseg = 6'ha;//eighth;
        an_temp = 8'b01111111;
    end
         
    endcase
end

assign an = an_temp;
 
reg [6:0] sseg_temp;

always @ (posedge clk)
begin
    case(sseg)
        4'd0 : sseg_temp = 7'b1000000; //0
        4'd1 : sseg_temp = 7'b1111001; //1
        4'd2 : sseg_temp = 7'b0100100; //2
        4'd3 : sseg_temp = 7'b0110000; //3
        4'd4 : sseg_temp = 7'b0011001; //4
        4'd5 : sseg_temp = 7'b0010010; //5
        4'd6 : sseg_temp = 7'b0000010; //6
        4'd7 : sseg_temp = 7'b1111000; //7
        4'd8 : sseg_temp = 7'b0000000; //8
        4'd9 : sseg_temp = 7'b0010000; //9
        default : sseg_temp = 7'b0111111; //dash
    endcase
end
assign seg = sseg_temp;
assign dp = 1'b1;

endmodule
