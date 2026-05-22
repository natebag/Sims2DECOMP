// 0x80048404 EIFloor::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18556(9)"
extern "C" int f_80048404() {}
