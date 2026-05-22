// 0x801E7080 MMUTarget::GetCurrentGameplayChoice(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xb8(3)"
extern "C" int f_801E7080() {}
