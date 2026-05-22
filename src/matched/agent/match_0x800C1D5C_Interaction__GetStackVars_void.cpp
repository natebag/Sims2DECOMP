// 0x800C1D5C Interaction::GetStackVars(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,24"
extern "C" int f_800C1D5C() {}
