// 0x8002193C ECheatDMI::GetVariable(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0xc(3); lwz 3,0x50(9)"
extern "C" int f_8002193C() {}
