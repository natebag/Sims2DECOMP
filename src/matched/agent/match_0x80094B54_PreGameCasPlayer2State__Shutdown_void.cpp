// 0x80094B54 PreGameCasPlayer2State::Shutdown(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; li 0,-1; lwz 11,0x5e80(9); stw 0,0x3ac(11)"
extern "C" void f_80094B54() {}
