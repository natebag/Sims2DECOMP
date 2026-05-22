// 0x800A64F0 SetSRandSeed(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-24584(13)"
extern "C" void f_800A64F0() {}
