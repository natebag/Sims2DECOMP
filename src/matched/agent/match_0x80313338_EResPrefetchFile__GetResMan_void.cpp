// 0x80313338 EResPrefetchFile::GetResMan(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x2c(3)"
extern "C" int f_80313338() {}
