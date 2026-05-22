// 0x801A0810 CASTarget::GetCurrentSimNumber(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x134c(3)"
extern "C" int f_801A0810() {}
