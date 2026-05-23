// 0x801E7088 E2ETarget::GetTopLevelState(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xd8(3)"
extern "C" int f_801E7088() {}
