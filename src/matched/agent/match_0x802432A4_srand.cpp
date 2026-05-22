// 0x802432A4 srand (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-27948(13); stw 3,0x58(9)"
extern "C" void f_802432A4() {}
