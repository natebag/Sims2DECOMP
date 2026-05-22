// 0x801B941C INGTarget::TabInfo::TabInfo(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 0,0; stw 0,0x8(9); stw 0,0x0(9); sth 0,0x4(9)"
extern "C" void f_801B941C() {}
