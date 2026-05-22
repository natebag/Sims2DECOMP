// 0x80317884 ERFont::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12602(9)"
extern "C" int f_80317884() {}
