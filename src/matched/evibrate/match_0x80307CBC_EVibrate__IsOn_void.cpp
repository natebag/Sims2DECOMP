// 0x80307CBC EVibrate::IsOn(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3)"
extern "C" int f_80307CBC() {}
