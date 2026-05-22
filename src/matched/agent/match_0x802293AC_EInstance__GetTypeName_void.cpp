// 0x802293AC EInstance::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18516(9)"
extern "C" int f_802293AC() {}
