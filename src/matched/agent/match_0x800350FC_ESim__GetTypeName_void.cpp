// 0x800350FC ESim::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-19404(9)"
extern "C" int f_800350FC() {}
