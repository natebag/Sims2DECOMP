// 0x803C142C EStorable::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-13308(9)"
extern "C" int f_803C142C() {}
