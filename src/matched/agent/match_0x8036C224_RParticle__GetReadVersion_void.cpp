// 0x8036C224 RParticle::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-9982(9)"
extern "C" int f_8036C224() {}
