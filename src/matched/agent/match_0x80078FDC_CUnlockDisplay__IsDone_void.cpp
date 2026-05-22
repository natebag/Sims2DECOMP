// 0x80078FDC CUnlockDisplay::IsDone(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x45c(3)"
extern "C" int f_80078FDC() {}
