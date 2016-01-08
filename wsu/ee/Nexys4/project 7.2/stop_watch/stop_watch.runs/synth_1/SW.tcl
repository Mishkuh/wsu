# 
# Synthesis run script generated by Vivado
# 

  set_param gui.test TreeTableDev
  set_param xicom.use_bs_reader 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
set_msg_config -id {Labtools 27-147} -limit 4294967295
create_project -in_memory -part xc7a100tcsg324-1
set_property target_language Verilog [current_project]
set_param project.compositeFile.enableAutoGeneration 0
set_property default_lib xil_defaultlib [current_project]
read_verilog -library xil_defaultlib {
  {/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch/Stop_watch.srcs/sources_1/new/two_dig_count.v}
  {/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch/Stop_watch.srcs/sources_1/new/Four_dig_count.v}
  {/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch/Stop_watch.srcs/sources_1/imports/new/ClkDivider.v}
  {/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch/Stop_watch.srcs/sources_1/new/SW.v}
}
read_xdc {{/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch/Stop_watch.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc}}
set_property used_in_implementation false [get_files {{/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch/Stop_watch.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc}}]

set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir {/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch/Stop_watch.cache/wt} [current_project]
set_property parent.project_dir {/home/mikel/Desktop/Project 7/Project 7.2/Stop_watch} [current_project]
catch { write_hwdef -file SW.hwdef }
synth_design -top SW -part xc7a100tcsg324-1
write_checkpoint SW.dcp
report_utilization -file SW_utilization_synth.rpt -pb SW_utilization_synth.pb
