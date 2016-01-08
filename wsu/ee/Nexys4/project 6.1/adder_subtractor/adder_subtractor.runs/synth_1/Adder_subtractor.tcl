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
read_verilog -library xil_defaultlib {
  {/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.srcs/sources_1/imports/new/Full_adder.v}
  {/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.srcs/sources_1/imports/new/Adder_subtractor.v}
}
read_xdc {{/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc}}
set_property used_in_implementation false [get_files {{/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc}}]

set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir {/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.cache/wt} [current_project]
set_property parent.project_dir {/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor} [current_project]
catch { write_hwdef -file Adder_subtractor.hwdef }
synth_design -top Adder_subtractor -part xc7a100tcsg324-1
write_checkpoint Adder_subtractor.dcp
report_utilization -file Adder_subtractor_utilization_synth.rpt -pb Adder_subtractor_utilization_synth.pb