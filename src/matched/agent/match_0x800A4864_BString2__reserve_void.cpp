// 0x800A4864 BString2::reserve(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lwz 3,0x8(9)"
extern "C" int f_800A4864() {}
