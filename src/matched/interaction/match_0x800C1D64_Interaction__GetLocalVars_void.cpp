// 0x800C1D64 Interaction::GetLocalVars(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x24(3)"
extern "C" int f_800C1D64() {}
