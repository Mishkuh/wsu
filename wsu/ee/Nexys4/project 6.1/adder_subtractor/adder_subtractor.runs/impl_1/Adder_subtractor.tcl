proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000

start_step init_design
set rc [catch {
  create_msg_db init_design.pb
  set_param gui.test TreeTableDev
  set_property design_mode GateLvl [current_fileset]
  set_property webtalk.parent_dir {/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.cache/wt} [current_project]
  set_property parent.project_dir {/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor} [current_project]
  add_files -quiet {{/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.runs/synth_1/Adder_subtractor.dcp}}
  read_xdc {{/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc}}
  link_design -top Adder_subtractor -part xc7a100tcsg324-1
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
}

start_step opt_design
set rc [catch {
  create_msg_db opt_design.pb
  catch {write_debug_probes -quiet -force debug_nets}
  catch {update_ip_catalog -quiet -current_ip_cache {/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.cache} }
  opt_design 
  write_checkpoint -force Adder_subtractor_opt.dcp
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
}

start_step place_design
set rc [catch {
  create_msg_db place_design.pb
  place_design 
  write_checkpoint -force Adder_subtractor_placed.dcp
  catch { report_io -file Adder_subtractor_io_placed.rpt }
  catch { report_clock_utilization -file Adder_subtractor_clock_utilization_placed.rpt }
  catch { report_utilization -file Adder_subtractor_utilization_placed.rpt -pb Adder_subtractor_utilization_placed.pb }
  catch { report_control_sets -verbose -file Adder_subtractor_control_sets_placed.rpt }
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
}

start_step route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force Adder_subtractor_routed.dcp
  catch { report_drc -file Adder_subtractor_drc_routed.rpt -pb Adder_subtractor_drc_routed.pb }
  catch { report_timing_summary -warn_on_violation -file Adder_subtractor_timing_summary_routed.rpt -pb Adder_subtractor_timing_summary_routed.pb }
  catch { report_power -file Adder_subtractor_power_routed.rpt -pb Adder_subtractor_power_summary_routed.pb }
  catch { report_route_status -file Adder_subtractor_route_status.rpt -pb Adder_subtractor_route_status.pb }
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
}

start_step write_bitstream
set rc [catch {
  create_msg_db write_bitstream.pb
  write_bitstream -force Adder_subtractor.bit 
  if { [file exists {/home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.runs/synth_1/Adder_subtractor.hwdef}] } {
    catch { write_sysdef -hwdef /home/mikel/Desktop/Project 6/Project 6.1/Adder_Subtractor/Adder_Subtractor.runs/synth_1/Adder_subtractor.hwdef -bitfile Adder_subtractor.bit -meminfo Adder_subtractor_bd.bmm -file Adder_subtractor.sysdef }
  }
  close_msg_db -file write_bitstream.pb
} RESULT]
if {$rc} {
  step_failed write_bitstream
  return -code error $RESULT
} else {
  end_step write_bitstream
}

