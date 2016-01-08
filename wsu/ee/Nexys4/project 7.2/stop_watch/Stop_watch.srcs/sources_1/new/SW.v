`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/11/2014 01:42:45 PM
// Design Name: 
// Module Name: SW
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


module SW(
    input clk,
    input rst,
    input start,
    input stop,
    input inc,
    output [6:0]seg,
    output [7:0]an,
    output reg dp
        );
    
    wire [3:0]firstw;
    wire [3:0]secondw;
    wire [3:0]thirdw;
    wire [3:0]fourthw;

    
    
    reg [6:0]sseg;
    reg [7:0]an_temp;
    reg [6:0] sseg_temp;
    wire [1:0]B;
    wire En;
    reg [16:0] delay; //register to produce the 0.1 second delay
    wire test;
    wire slowtest;
    wire millsec_clk;

    localparam S0 = 3'b000;
    localparam S1 = 3'b001;
    localparam S2 = 3'b011;
    localparam S3 = 3'b111;
    localparam S4 = 3'b110;
    
    reg [1:0] pState, nState;
    reg [1:0]test2;

ClkDivider kitty_poop(
    .rst(rst),
    .clk(clk),
    .clk_div(millsec_clk)
    );


Four_dig_count kitty_poop1(
    .rst(rst),
    .clk(slowtest),
    .En(En),
    .first(firstw),
    .second(secondw),
    .third(thirdw),
    .fourth(fourthw)
    );    

Two_dig_count kitty_poop2(
    .clk(test),
    .rst(rst),
    .Bit(B)
    );



always@(posedge test or posedge rst)
begin
     if (rst)
       test2 <= 0;
   else
       test2 <= test2 + 1;
end



always @ (posedge clk or posedge rst)
begin
    if (rst)
        delay <= 0;
    else if (delay == 15'd24999)
        delay <= 0;
    else
        delay <= delay + 1;
end

assign slowtest = &test2;
assign test = (delay == 17'd100000) ? 1'b1: 1'b0;

always @(pState, start, stop, rst, inc)
begin
    case(pState)
        S0:begin
            if (inc == 1'b0 && start == 1'b0 && stop == 1'b0)
                nState = S0;
            else if (start == 1'b1 && stop == 1'b0 && inc == 1'b0)
                nState = S1;
            else if (stop == 1'b1 && start == 1'b0 && inc == 1'b0)
                nState = S2;
            else if (inc == 1'b1 && stop == 1'b0 && start == 1'b0)
                nState = S3;
            end
           
        S1:begin
            if (rst == 1'b1)
                nState = S0;
            else if (stop == 1'b1)
                nState = S2;
            else
                nState = S1;
            end
            
        S2:begin
            if (rst == 1'b1)
                nState = S0;
            else if (start == 1'b1 && inc == 1'b0)
                nState = S1;
            else if (inc == 1'b1)
                nState = S3;
            else
                nState = S2;
            end
        
        S3:begin
                nState = S4;
            end
            
        S4:begin
            if (inc == 1'b1)
                nState = S4;
            else 
                nState = S2;
            end
           
        default:
                nState = S0;
            
   endcase
end
    
    
    
    always @ (posedge (test), posedge (rst) )
    begin
        if (rst == 1'b1)
            pState <= S0;
        else
            pState <= nState;
    end
 
assign En = (pState == S1 || pState == S3) ? 1'd1: 1'd0;
    


    always@(B, firstw, secondw, thirdw, fourthw)
    begin
        case(B)
    
        2'b00:
        begin
            sseg = firstw;
            an_temp = 4'b1110;
            dp = 1'b1;
        end
        
        2'b01:
        begin
            sseg = secondw;
            an_temp = 4'b1101;
            dp = 1'b1;
        end
        
        2'b10:
        begin
            sseg = thirdw;
            an_temp = 4'b1011;
            dp = 1'b1;
        end
         
        2'b11:
        begin
            sseg = fourthw;
            an_temp = 4'b0111;
            dp = 1'd0;
        end
             
        endcase
    end
    
    assign an = an_temp;
  
    
    always @ (sseg)
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
    assign an[7:4] = 4'b1111;

endmodule
