// 0x800BCD0C SetLanguage(short (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x1(3); rlwinm 4,4,8,0,23; or 0,0,4; sth 0,0x0(3)"
extern "C" void f_800BCD0C() {}
