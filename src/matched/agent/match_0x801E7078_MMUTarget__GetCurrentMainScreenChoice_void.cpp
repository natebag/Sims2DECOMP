// 0x801E7078 MMUTarget::GetCurrentMainScreenChoice(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xa4(3)"
extern "C" int f_801E7078() {}
