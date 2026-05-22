// 0x800A88E0 AmbientScorePlayer::Start(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s800A88E0_0; stw 3,0x38(30); li 0,1; stw 0,0x0(30); li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A88E0_0();
extern "C" void f_800A88E0() {}
