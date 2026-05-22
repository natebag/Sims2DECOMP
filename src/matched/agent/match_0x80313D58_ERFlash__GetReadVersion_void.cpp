// 0x80313D58 ERFlash::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12642(9)"
extern "C" int f_80313D58() {}
