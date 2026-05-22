// 0x800568B8 ISimInstance::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-19364(9)"
extern "C" int f_800568B8() {}
