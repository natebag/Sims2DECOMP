// 0x80079C60 CUnlockDisplayObject::HasDrawn(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x7c(3)"
extern "C" int f_80079C60() {}
