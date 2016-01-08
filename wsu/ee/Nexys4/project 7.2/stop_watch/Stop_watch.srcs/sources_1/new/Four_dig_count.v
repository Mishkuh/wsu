`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/11/2014 03:13:36 PM
// Design Name: 
// Module Name: 4_dig_count
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


module Four_dig_count(
    input clk,
    input rst,
    input En,
    output reg[3:0]first,
    output reg[3:0]second,
    output reg[3:0]third,
    output reg[3:0]fourth
    );
    

reg [3:0]fifth;
reg [3:0]sixth;
reg [3:0]seventh;
reg [3:0]eighth;


    always @ (posedge clk, posedge rst)
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
            else if (first==4'd9 && En) 
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
            else if (En) 
                first <= first + 1;
        end      
        
endmodule
