// 0x801CE920 O2TTarget::SetTopLevelState(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,5; mr 29,4; mr 3,28; bl _s801CE920_0; lwz 0,0x88(30); mr 4,29; stw 3,0x88(30); mr 5,28; stw 0,0x8c(30); mr 3,30; bl _s801CE920_1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801CE920_0();
extern "C" void _s801CE920_1();
extern "C" void f_801CE920() {}
