// 0x8005442C IShrubObject::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18312(9)"
extern "C" int f_8005442C() {}
