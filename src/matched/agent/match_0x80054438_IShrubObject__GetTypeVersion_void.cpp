// 0x80054438 IShrubObject::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-18308(9)"
extern "C" int f_80054438() {}
