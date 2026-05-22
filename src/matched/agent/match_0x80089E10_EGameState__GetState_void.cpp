// 0x80089E10 EGameState::GetState(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(4); mr 9,3; stw 0,0x0(9)"
extern "C" void f_80089E10() {}
