// 0x800BEA00 IFFResFile2::Writable(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x11c(3)"
extern "C" int f_800BEA00() {}
