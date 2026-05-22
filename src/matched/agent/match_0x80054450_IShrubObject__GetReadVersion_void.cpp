// 0x80054450 IShrubObject::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-18306(9)"
extern "C" int f_80054450() {}
