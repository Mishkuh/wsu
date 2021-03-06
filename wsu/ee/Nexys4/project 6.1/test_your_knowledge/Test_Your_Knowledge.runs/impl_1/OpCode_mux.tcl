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
set_msg_config -id {Labtools 27-147} -limit 4294967295

start_step init_design
set rc [catch {
  create_msg_db init_design.pb
  set_param gui.test TreeTableDev
  set_param xicom.use_bs_reader 1
  set_property design_mode GateLvl [current_fileset]
  set_property webtalk.parent_dir {/home/mikel/Desktop/Project 6/Project 6.1/Test_Your_Knowledge/Test_Your_Knowledge.cache/wt} [current_project]
  set_property parent.project_dir {/home/mikel/Desktop/Project 6/Project 6.1/Test_Your_Knowledge} [current_project]
  add_files -quiet {{/home/mikel/Desktop/Project 6/Project 6.1/Test_Your_Knowledge/Test_Your_Knowledge.runs/synth_1/OpCode_mux.dcp}}
  read_xdc {{/home/mikel/Desktop/Project 6/Project 6.1/Test_Your_Knowledge/Test_Your_Knowledge.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc}}
  link_design -top OpCode_mux -part xc7a100tcsg324-1
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
  catch {update_ip_catalog -quiet -current_ip_cache {/home/mikel/Desktop/Project 6/Project 6.1/Test_Your_Knowledge/Test_Your_Knowledge.cache} }
  opt_design 
  write_checkpoint -force OpCode_mux_opt.dcp
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
  write_checkpoint -force OpCode_mux_placed.dcp
  catch { report_io -file OpCode_mux_io_placed.rpt }
  catch { report_clock_utilization -file OpCode_mux_clock_utilization_placed.rpt }
  catch { report_utilization -file OpCode_mux_utilization_placed.rpt -pb OpCode_mux_utilization_placed.pb }
  catch { report_control_sets -verbose -file OpCode_mux_control_sets_placed.rpt }
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
  write_checkpoint -force OpCode_mux_routed.dcp
  catch { report_drc -file OpCode_mux_drc_routed.rpt -pb OpCode_mux_drc_routed.pb }
  catch { report_timing_summary -warn_on_violation -file OpCode_mux_timing_summary_routed.rpt -pb OpCode_mux_timing_summary_routed.pb }
  catch { report_power -file OpCode_mux_power_routed.rpt -pb OpCode_mux_power_summary_routed.pb }
  catch { report_route_status -file OpCode_mux_route_status.rpt -pb OpCode_mux_route_status.pb }
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
  write_bitstream -force OpCode_mux.bit 
  if { [file exists {/home/mikel/Desktop/Project 6/Project 6.1/Test_Your_Knowledge/Test_Your_Knowledge.runs/synth_1/OpCode_mux.hwdef}] } {
    catch { write_sysdef -hwdef /home/mikel/Desktop/Project 6/Project 6.1/Test_Your_Knowledge/Test_Your_Knowledge.runs/synth_1/OpCode_mux.hwdef -bitfile OpCode_mux.bit -meminfo OpCode_mux_bd.bmm -file OpCode_mux.sysdef }
  }
  close_msg_db -file write_bitstream.pb
} RESULT]
if {$rc} {
  step_failed write_bitstream
  return -code error $RESULT
} else {
  end_step write_bitstream
}

