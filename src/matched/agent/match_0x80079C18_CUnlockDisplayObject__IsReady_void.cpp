// 0x80079C18 CUnlockDisplayObject::IsReady(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x74(3)"
extern "C" int f_80079C18() {}
