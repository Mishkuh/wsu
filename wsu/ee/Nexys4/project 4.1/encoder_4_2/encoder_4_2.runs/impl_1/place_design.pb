
N
Command: %s
53*	vivadotcl2 
place_design2default:defaultZ4-113h px
�
@Attempting to get a license for feature '%s' and/or device '%s'
308*common2"
Implementation2default:default2
xc7a100t2default:defaultZ17-347h px
�
0Got license for feature '%s' and/or device '%s'
310*common2"
Implementation2default:default2
xc7a100t2default:defaultZ17-349h px
m
,Running DRC as a precondition to command %s
22*	vivadotcl2 
place_design2default:defaultZ4-22h px
M
Running DRC with %s threads
24*drc2
22default:defaultZ23-27h px
S
DRC finished with %s
79*	vivadotcl2
0 Errors2default:defaultZ4-198h px
b
BPlease refer to the DRC report (report_drc) for more information.
80*	vivadotclZ4-199h px
R

Starting %s Task
103*constraints2
Placer2default:defaultZ18-103h px
z
BMultithreading enabled for place_design using a maximum of %s CPUs12*	placeflow2
22default:defaultZ30-611h px
v

Phase %s%s
101*constraints2
1 2default:default2,
Placer Runtime Estimator2default:defaultZ18-101h px
I
7Phase 1 Placer Runtime Estimator | Checksum: 11d47aedd
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.03 ; elapsed = 00:00:00.02 . Memory (MB): peak = 879.352 ; gain = 0.0002default:defaulth px
s

Phase %s%s
101*constraints2
2 2default:default2)
Placer Initialization2default:defaultZ18-101h px
z

Phase %s%s
101*constraints2
2.1 2default:default2.
Placer Initialization Core2default:defaultZ18-101h px
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2
00:00:002default:default2
879.3522default:default2
0.0002default:defaultZ17-268h px
~

Phase %s%s
101*constraints2
2.1.1 2default:default20
Mandatory Logic Optimization2default:defaultZ18-101h px
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2.
Netlist sorting complete. 2default:default2
00:00:002default:default2
00:00:002default:default2
879.3522default:default2
0.0002default:defaultZ17-268h px
P
>Phase 2.1.1 Mandatory Logic Optimization | Checksum: 8af18457
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.03 ; elapsed = 00:00:00.02 . Memory (MB): peak = 879.352 ; gain = 0.0002default:defaulth px
/
%s*constraints2
 2default:defaulth px
�

Phase %s%s
101*constraints2
2.1.2 2default:default2;
'Build Super Logic Region (SLR) Database2default:defaultZ18-101h px
[
IPhase 2.1.2 Build Super Logic Region (SLR) Database | Checksum: 8af18457
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.05 ; elapsed = 00:00:00.04 . Memory (MB): peak = 879.352 ; gain = 0.0002default:defaulth px
q

Phase %s%s
101*constraints2
2.1.3 2default:default2#
Add Constraints2default:defaultZ18-101h px
C
1Phase 2.1.3 Add Constraints | Checksum: 8af18457
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.05 ; elapsed = 00:00:00.05 . Memory (MB): peak = 879.352 ; gain = 0.0002default:defaulth px
y

Phase %s%s
101*constraints2
2.1.4 2default:default2+
Build Shapes/ HD Config2default:defaultZ18-101h px
p

Phase %s%s
101*constraints2
2.1.4.1 2default:default2 
Build Macros2default:defaultZ18-101h px
/
%s*constraints2
 2default:defaulth px
C
1Phase 2.1.4.1 Build Macros | Checksum: 11d47aedd
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.07 ; elapsed = 00:00:00.06 . Memory (MB): peak = 887.352 ; gain = 8.0002default:defaulth px
L
:Phase 2.1.4 Build Shapes/ HD Config | Checksum: 11d47aedd
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.07 ; elapsed = 00:00:00.07 . Memory (MB): peak = 887.352 ; gain = 8.0002default:defaulth px
�

Phase %s%s
101*constraints2
2.1.5 2default:default2F
2IO Placement/ Clock Placement/ Build Placer Device2default:defaultZ18-101h px
s

Phase %s%s
101*constraints2
2.1.5.1 2default:default2#
Pre-Place Cells2default:defaultZ18-101h px
E
3Phase 2.1.5.1 Pre-Place Cells | Checksum: 8af18457
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.08 ; elapsed = 00:00:00.07 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
B
%Done setting XDC timing constraints.
35*timingZ38-35h px
u

Phase %s%s
101*constraints2
2.1.5.2 2default:default2%
IO & Clk Clean Up2default:defaultZ18-101h px
G
5Phase 2.1.5.2 IO & Clk Clean Up | Checksum: 8af18457
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.49 ; elapsed = 00:00:00.49 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
�

Phase %s%s
101*constraints2
2.1.5.3 2default:default2>
*Implementation Feasibility check On IDelay2default:defaultZ18-101h px
`
NPhase 2.1.5.3 Implementation Feasibility check On IDelay | Checksum: 8af18457
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.50 ; elapsed = 00:00:00.49 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
w

Phase %s%s
101*constraints2
2.1.5.4 2default:default2'
Commit IO Placement2default:defaultZ18-101h px
I
7Phase 2.1.5.4 Commit IO Placement | Checksum: 8af18457
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.50 ; elapsed = 00:00:00.49 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
g
UPhase 2.1.5 IO Placement/ Clock Placement/ Build Placer Device | Checksum: 11d47aedd
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.50 ; elapsed = 00:00:00.49 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
|

Phase %s%s
101*constraints2
2.1.6 2default:default2.
Build Placer Netlist Model2default:defaultZ18-101h px
u

Phase %s%s
101*constraints2
2.1.6.1 2default:default2%
Place Init Design2default:defaultZ18-101h px
H
6Phase 2.1.6.1 Place Init Design | Checksum: 1aba896a3
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.51 ; elapsed = 00:00:00.50 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
O
=Phase 2.1.6 Build Placer Netlist Model | Checksum: 1aba896a3
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.51 ; elapsed = 00:00:00.51 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
y

Phase %s%s
101*constraints2
2.1.7 2default:default2+
Constrain Clocks/Macros2default:defaultZ18-101h px
�

Phase %s%s
101*constraints2
2.1.7.1 2default:default24
 Constrain Global/Regional Clocks2default:defaultZ18-101h px
W
EPhase 2.1.7.1 Constrain Global/Regional Clocks | Checksum: 1aba896a3
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.52 ; elapsed = 00:00:00.51 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
L
:Phase 2.1.7 Constrain Clocks/Macros | Checksum: 1aba896a3
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.52 ; elapsed = 00:00:00.51 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
M
;Phase 2.1 Placer Initialization Core | Checksum: 1aba896a3
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.52 ; elapsed = 00:00:00.52 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
F
4Phase 2 Placer Initialization | Checksum: 1aba896a3
*commonh px
�

%s
*constraints2t
`Time (s): cpu = 00:00:00.52 ; elapsed = 00:00:00.52 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
n

Phase %s%s
101*constraints2
3 2default:default2$
Global Placement2default:defaultZ18-101h px
A
/Phase 3 Global Placement | Checksum: 13e638ec5
*commonh px
�

%s
*constraints2n
ZTime (s): cpu = 00:00:01 ; elapsed = 00:00:01 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
n

Phase %s%s
101*constraints2
4 2default:default2$
Detail Placement2default:defaultZ18-101h px
z

Phase %s%s
101*constraints2
4.1 2default:default2.
Commit Multi Column Macros2default:defaultZ18-101h px
M
;Phase 4.1 Commit Multi Column Macros | Checksum: 13e638ec5
*commonh px
�

%s
*constraints2n
ZTime (s): cpu = 00:00:01 ; elapsed = 00:00:01 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
|

Phase %s%s
101*constraints2
4.2 2default:default20
Commit Most Macros & LUTRAMs2default:defaultZ18-101h px
O
=Phase 4.2 Commit Most Macros & LUTRAMs | Checksum: 1b5d98d70
*commonh px
�

%s
*constraints2n
ZTime (s): cpu = 00:00:01 ; elapsed = 00:00:01 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
v

Phase %s%s
101*constraints2
4.3 2default:default2*
Area Swap Optimization2default:defaultZ18-101h px
I
7Phase 4.3 Area Swap Optimization | Checksum: 1d8ea02da
*commonh px
�

%s
*constraints2n
ZTime (s): cpu = 00:00:01 ; elapsed = 00:00:01 . Memory (MB): peak = 887.355 ; gain = 8.0042default:defaulth px
�

Phase %s%s
101*constraints2
4.4 2default:default24
 Commit Small Macros & Core Logic2default:defaultZ18-101h px
S
APhase 4.4 Commit Small Macros & Core Logic | Checksum: 1e9a1848f
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
r

Phase %s%s
101*constraints2
4.5 2default:default2&
Re-assign LUT pins2default:defaultZ18-101h px
E
3Phase 4.5 Re-assign LUT pins | Checksum: 1e9a1848f
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
A
/Phase 4 Detail Placement | Checksum: 1e9a1848f
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
�

Phase %s%s
101*constraints2
5 2default:default2<
(Post Placement Optimization and Clean-Up2default:defaultZ18-101h px
s

Phase %s%s
101*constraints2
5.1 2default:default2'
PCOPT Shape updates2default:defaultZ18-101h px
F
4Phase 5.1 PCOPT Shape updates | Checksum: 2c001955d
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
v

Phase %s%s
101*constraints2
5.2 2default:default2*
Post Placement Cleanup2default:defaultZ18-101h px
I
7Phase 5.2 Post Placement Cleanup | Checksum: 2c001955d
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
p

Phase %s%s
101*constraints2
5.3 2default:default2$
Placer Reporting2default:defaultZ18-101h px
C
1Phase 5.3 Placer Reporting | Checksum: 2c001955d
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
w

Phase %s%s
101*constraints2
5.4 2default:default2+
Final Placement Cleanup2default:defaultZ18-101h px
J
8Phase 5.4 Final Placement Cleanup | Checksum: 2c001955d
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
Y
GPhase 5 Post Placement Optimization and Clean-Up | Checksum: 2c001955d
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
;
)Ending Placer Task | Checksum: 1d0f486e0
*commonh px
�

%s
*constraints2o
[Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 895.355 ; gain = 16.0042default:defaulth px
W
Releasing license: %s
83*common2"
Implementation2default:defaultZ17-83h px
�
G%s Infos, %s Warnings, %s Critical Warnings and %s Errors encountered.
28*	vivadotcl2
292default:default2
02default:default2
42default:default2
02default:defaultZ4-41h px
[
%s completed successfully
29*	vivadotcl2 
place_design2default:defaultZ4-42h px
:
Writing XDEF routing.
211*designutilsZ20-211h px
G
#Writing XDEF routing logical nets.
209*designutilsZ20-209h px
G
#Writing XDEF routing special nets.
210*designutilsZ20-210h px
�
I%sTime (s): cpu = %s ; elapsed = %s . Memory (MB): peak = %s ; gain = %s
268*common2)
Write XDEF Complete: 2default:default2
00:00:00.112default:default2
00:00:00.152default:default2
895.3592default:default2
0.0002default:defaultZ17-268h px
�
ureport_utilization: Time (s): cpu = 00:00:00.14 ; elapsed = 00:00:00.20 . Memory (MB): peak = 896.355 ; gain = 0.000
*commonh px


End Record