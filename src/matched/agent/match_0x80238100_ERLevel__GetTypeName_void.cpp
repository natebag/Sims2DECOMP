// 0x80238100 ERLevel::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13068(9)"
extern "C" int f_80238100() {}
