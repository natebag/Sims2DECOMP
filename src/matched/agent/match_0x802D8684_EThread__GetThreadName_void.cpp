// 0x802D8684 EThread::GetThreadName(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x32c(3)"
extern "C" int f_802D8684() {}
