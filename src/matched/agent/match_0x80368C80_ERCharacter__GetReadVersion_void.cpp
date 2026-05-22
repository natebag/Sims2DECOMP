// 0x80368C80 ERCharacter::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10222(9)"
extern "C" int f_80368C80() {}
