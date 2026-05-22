// 0x800A64E0 MemFile::Writable(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x10c(3)"
extern "C" int f_800A64E0() {}
