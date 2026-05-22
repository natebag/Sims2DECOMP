// 0x800D93CC NghResFile::GetSourceType(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x20(3)"
extern "C" int f_800D93CC() {}
