// 0x803C1444 EStorable::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13300(9)"
extern "C" int f_803C1444() {}
