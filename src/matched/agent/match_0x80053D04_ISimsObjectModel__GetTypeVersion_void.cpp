// 0x80053D04 ISimsObjectModel::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-18468(9)"
extern "C" int f_80053D04() {}
