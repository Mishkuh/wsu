#!/bin/sh
# Vivado(TM)
# compile.sh: Vivado-generated Script for launching XSim application
# Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
# 
if [ -z "$PATH" ]; then
  PATH=$XILINX/lib/$PLATFORM:$XILINX/bin/$PLATFORM:/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/lin
else
  PATH=$XILINX/lib/$PLATFORM:$XILINX/bin/$PLATFORM:/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/lin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=$XILINX/lib/$PLATFORM:/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/lin
else
  LD_LIBRARY_PATH=$XILINX/lib/$PLATFORM:/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/lin:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

#
# Setup env for Xilinx simulation libraries
#
XILINX_PLANAHEAD=/opt/Xilinx/Vivado/2014.2
export XILINX_PLANAHEAD
ExecStep()
{
   "$@"
   RETVAL=$?
   if [ $RETVAL -ne 0 ]
   then
       exit $RETVAL
   fi
}
XELAB_1="/home/mikel/Desktop/Project 4/Project 4.1/Mux 4_1/Mux 4_1.sim/sim_1/behav/Mux_test.prj"

ExecStep xelab -m32 --debug typical --relax -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot Mux_test_behav --prj "$XELAB_1"   xil_defaultlib.Mux_test   xil_defaultlib.glbl
