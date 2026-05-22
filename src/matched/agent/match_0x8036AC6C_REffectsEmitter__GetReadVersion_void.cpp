// 0x8036AC6C REffectsEmitter::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10062(9)"
extern "C" int f_8036AC6C() {}
