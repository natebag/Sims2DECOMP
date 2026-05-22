// 0x803A2D84 cHitTimer::Stop(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x0(3); li 3,1"
extern "C" void f_803A2D84() {}
