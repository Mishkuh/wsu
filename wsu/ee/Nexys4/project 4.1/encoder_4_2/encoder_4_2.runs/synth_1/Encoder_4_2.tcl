# 
# Synthesis run script generated by Vivado
# 

  set_param gui.test TreeTableDev
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1
set_property target_language Verilog [current_project]
set_param project.compositeFile.enableAutoGeneration 0
set_property default_lib xil_defaultlib [current_project]
read_verilog -library xil_defaultlib /home/mikel/Desktop/Encoder_4_2/Encoder_4_2.srcs/sources_1/new/Encoder_4_2.v
read_xdc /home/mikel/Desktop/Encoder_4_2/Encoder_4_2.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc
set_property used_in_implementation false [get_files /home/mikel/Desktop/Encoder_4_2/Encoder_4_2.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc]

set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir /home/mikel/Desktop/Encoder_4_2/Encoder_4_2.cache/wt [current_project]
set_property parent.project_dir /home/mikel/Desktop/Encoder_4_2 [current_project]
catch { write_hwdef -file Encoder_4_2.hwdef }
synth_design -top Encoder_4_2 -part xc7a100tcsg324-1
write_checkpoint Encoder_4_2.dcp
report_utilization -file Encoder_4_2_utilization_synth.rpt -pb Encoder_4_2_utilization_synth.pb
