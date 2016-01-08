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
  debug::add_scope template.lib 1
  set_property design_mode GateLvl [current_fileset]
  set_property webtalk.parent_dir {C:/Users/mikey/Documents/EE214/EE 214/Project 6/project 6.3/vga_display_controller/VGA_Display_controller.cache/wt} [current_project]
  set_property parent.project_path {C:/Users/mikey/Documents/EE214/EE 214/Project 6/project 6.3/vga_display_controller/VGA_Display_controller.xpr} [current_project]
  set_property ip_repo_paths {{c:/Users/mikey/Documents/EE214/EE 214/Project 6/project 6.3/vga_display_controller/VGA_Display_controller.cache/ip}} [current_project]
  set_property ip_output_repo {{c:/Users/mikey/Documents/EE214/EE 214/Project 6/project 6.3/vga_display_controller/VGA_Display_controller.cache/ip}} [current_project]
  add_files -quiet {{C:/Users/mikey/Documents/EE214/EE 214/Project 6/project 6.3/vga_display_controller/VGA_Display_controller.runs/synth_1/VGA_Controller.dcp}}
  read_xdc {{C:/Users/mikey/Documents/EE214/EE 214/Project 6/project 6.3/vga_display_controller/VGA_Display_controller.srcs/constrs_1/imports/Desktop/Nexys4_Master.xdc}}
  link_design -top VGA_Controller -part xc7a100tcsg324-1
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
  opt_design 
  write_checkpoint -force VGA_Controller_opt.dcp
  catch {report_drc -file VGA_Controller_drc_opted.rpt}
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
  write_checkpoint -force VGA_Controller_placed.dcp
  catch { report_io -file VGA_Controller_io_placed.rpt }
  catch { report_clock_utilization -file VGA_Controller_clock_utilization_placed.rpt }
  catch { report_utilization -file VGA_Controller_utilization_placed.rpt -pb VGA_Controller_utilization_placed.pb }
  catch { report_control_sets -verbose -file VGA_Controller_control_sets_placed.rpt }
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
  write_checkpoint -force VGA_Controller_routed.dcp
  catch { report_drc -file VGA_Controller_drc_routed.rpt -pb VGA_Controller_drc_routed.pb }
  catch { report_timing_summary -warn_on_violation -max_paths 10 -file VGA_Controller_timing_summary_routed.rpt -rpx VGA_Controller_timing_summary_routed.rpx }
  catch { report_power -file VGA_Controller_power_routed.rpt -pb VGA_Controller_power_summary_routed.pb }
  catch { report_route_status -file VGA_Controller_route_status.rpt -pb VGA_Controller_route_status.pb }
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
  write_bitstream -force VGA_Controller.bit 
  if { [file exists {C:/Users/mikey/Documents/EE214/EE 214/Project 6/project 6.3/vga_display_controller/VGA_Display_controller.runs/synth_1/VGA_Controller.hwdef}] } {
    catch { write_sysdef -hwdef C:/Users/mikey/Documents/EE214/EE 214/Project 6/project 6.3/vga_display_controller/VGA_Display_controller.runs/synth_1/VGA_Controller.hwdef -bitfile VGA_Controller.bit -meminfo VGA_Controller.mmi -file VGA_Controller.sysdef }
  }
  close_msg_db -file write_bitstream.pb
} RESULT]
if {$rc} {
  step_failed write_bitstream
  return -code error $RESULT
} else {
  end_step write_bitstream
}

