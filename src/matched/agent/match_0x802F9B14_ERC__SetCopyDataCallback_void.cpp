// 0x802F9B14 ERC::SetCopyDataCallback(void (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 5,0x58(3); stw 4,0x54(3)"
extern "C" void f_802F9B14() {}
