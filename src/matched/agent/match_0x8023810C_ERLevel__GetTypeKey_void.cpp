// 0x8023810C ERLevel::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13064(9)"
extern "C" int f_8023810C() {}
