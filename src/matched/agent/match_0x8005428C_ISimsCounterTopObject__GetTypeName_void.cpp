// 0x8005428C ISimsCounterTopObject::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18356(9)"
extern "C" int f_8005428C() {}
