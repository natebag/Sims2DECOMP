// 0x80021930 ECheatDMI::GetType(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0xc(3); lwz 3,0x4c(9)"
extern "C" int f_80021930() {}
