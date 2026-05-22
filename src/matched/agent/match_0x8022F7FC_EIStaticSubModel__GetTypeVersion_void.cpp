// 0x8022F7FC EIStaticSubModel::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13100(9)"
extern "C" int f_8022F7FC() {}
