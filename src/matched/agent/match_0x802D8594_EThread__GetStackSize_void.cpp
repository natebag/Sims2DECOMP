// 0x802D8594 EThread::GetStackSize(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x320(3)"
extern "C" int f_802D8594() {}
