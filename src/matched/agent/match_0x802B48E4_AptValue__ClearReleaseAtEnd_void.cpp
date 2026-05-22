// 0x802B48E4 AptValue::ClearReleaseAtEnd(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 0,0,0,3,1; stw 0,0x0(3)"
extern "C" void f_802B48E4() {}
