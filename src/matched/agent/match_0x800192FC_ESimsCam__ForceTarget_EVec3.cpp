// 0x800192FC ESimsCam::ForceTarget(EVec3 (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,4; mr 30,3; lwz 11,0x0(29); addi 9,30,1084; lwz 10,0x4(29); mr 5,9; lwz 0,0x8(29); stw 11,0x43c(30); addi 4,1,8; stw 10,0x4(9); stw 0,0x8(9); bl _s800192FC_0; mr 3,30; mr 5,29; addi 4,1,8; addi 6,3,1060; bl _s800192FC_1; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s800192FC_0();
extern "C" void _s800192FC_1();
extern "C" void f_800192FC() {}
