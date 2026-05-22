// 0x80079A54 CUnlockDisplayObject::IsSimple(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x80(3)"
extern "C" int f_80079A54() {}
