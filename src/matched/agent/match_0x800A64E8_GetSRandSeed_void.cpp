// 0x800A64E8 GetSRandSeed(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-24584(13)"
extern "C" int f_800A64E8() {}
