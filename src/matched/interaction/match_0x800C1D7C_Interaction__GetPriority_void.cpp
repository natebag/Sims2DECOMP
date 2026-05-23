// 0x800C1D7C Interaction::GetPriority(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x28(3)"
extern "C" int f_800C1D7C() {}
