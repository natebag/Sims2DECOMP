// 0x802B48D4 AptValue::SetReleaseAtEnd(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); oris 0,0,8192; stw 0,0x0(3)"
extern "C" void f_802B48D4() {}
