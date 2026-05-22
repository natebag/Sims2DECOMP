// 0x800D93C0 NghResFile::GetCurrentHouse(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x24(3); addi 3,3,1"
extern "C" int f_800D93C0() {}
