// 0x8022F814 EIStaticSubModel::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-13098(9)"
extern "C" int f_8022F814() {}
