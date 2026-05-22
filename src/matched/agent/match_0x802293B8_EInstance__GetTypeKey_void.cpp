// 0x802293B8 EInstance::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18512(9)"
extern "C" int f_802293B8() {}
