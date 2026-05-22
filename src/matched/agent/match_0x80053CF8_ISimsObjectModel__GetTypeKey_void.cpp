// 0x80053CF8 ISimsObjectModel::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18472(9)"
extern "C" int f_80053CF8() {}
