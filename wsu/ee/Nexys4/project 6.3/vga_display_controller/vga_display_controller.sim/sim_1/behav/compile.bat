@echo off
rem  Vivado(TM)
rem  compile.bat: a Vivado-generated XSim simulation Script
rem  Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.

set PATH=$XILINX/lib/$PLATFORM:$XILINX/bin/$PLATFORM;/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/lin;/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/lin;/opt/Xilinx/Vivado/2014.2/bin;%PATH%
set XILINX_PLANAHEAD=/opt/Xilinx/Vivado/2014.2

xelab -m32 --debug typical --relax -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot test_controller_behav --prj "/home/mikel/Desktop/Project 6/Project 6.3/VGA_Display_controller/VGA_Display_controller.sim/sim_1/behav/test_controller.prj"   xil_defaultlib.test_controller   xil_defaultlib.glbl
if errorlevel 1 (
   cmd /c exit /b %errorlevel%
)
