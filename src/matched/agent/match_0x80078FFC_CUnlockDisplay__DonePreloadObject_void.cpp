// 0x80078FFC CUnlockDisplay::DonePreloadObject(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x450(3)"
extern "C" int f_80078FFC() {}
