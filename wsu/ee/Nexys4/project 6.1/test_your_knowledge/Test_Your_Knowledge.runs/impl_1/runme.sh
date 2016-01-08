#!/bin/sh

# 
# Vivado(TM)
# runme.sh: a Vivado-generated Runs Script for UNIX
# Copyright 1986-2014 Xilinx, Inc. All Rights Reserved.
# 

if [ -z "$PATH" ]; then
  PATH=/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/lin:/opt/Xilinx/Vivado/2014.2/bin
else
  PATH=/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/bin/lin:/opt/Xilinx/Vivado/2014.2/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/lin
else
  LD_LIBRARY_PATH=/opt/Xilinx/Vivado/2014.2/ids_lite/ISE/lib/lin:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD=`dirname "$0"`
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

# pre-commands:
/bin/touch .init_design.begin.rst
EAStep vivado -log OpCode_mux.vdi -applog -m32 -messageDb vivado.pb -mode batch -source OpCode_mux.tcl -notrace

