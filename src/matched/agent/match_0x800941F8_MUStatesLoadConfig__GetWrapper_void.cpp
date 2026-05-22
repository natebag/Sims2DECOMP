// 0x800941F8 MUStatesLoadConfig::GetWrapper(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); lwz 3,0x98(9)"
extern "C" int f_800941F8() {}
