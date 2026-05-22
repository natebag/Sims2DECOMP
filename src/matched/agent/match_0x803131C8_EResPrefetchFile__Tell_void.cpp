// 0x803131C8 EResPrefetchFile::Tell(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x40(3)"
extern "C" int f_803131C8() {}
