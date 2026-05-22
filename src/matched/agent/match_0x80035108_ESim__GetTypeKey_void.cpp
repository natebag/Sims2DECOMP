// 0x80035108 ESim::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-19400(9)"
extern "C" int f_80035108() {}
