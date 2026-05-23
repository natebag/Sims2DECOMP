// 0x800A0170 BString2::ref_count(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lwz 3,0xc(9)"
extern "C" int f_800A0170() {}
