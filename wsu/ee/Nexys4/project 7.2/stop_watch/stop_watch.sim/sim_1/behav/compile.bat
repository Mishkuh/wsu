@echo off
rem  Vivado(TM)
rem  compile.bat: a Vivado-generated XSim simulation Script
rem  Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.

set PATH=$XILINX/lib/$PLATFORM:$XILINX/bin/$PLATFORM;/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/lin;/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/lin;/opt/Xilinx/Vivado/2014.2/bin;%PATH%
set XILINX_PLANAHEAD=/opt/Xilinx/Vivado/2014.2

xelab -m32 --debug typical --relax -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot SW_test_behav --prj "/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch/Stop_watch.sim/sim_1/behav/SW_test.prj"   xil_defaultlib.SW_test   xil_defaultlib.glbl
if errorlevel 1 (
   cmd /c exit /b %errorlevel%
)
