// 0x8018CCE8 LoadGameTarget::GetPlayerNum(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x118(3); lwz 3,0x190(9)"
extern "C" int f_8018CCE8() {}
