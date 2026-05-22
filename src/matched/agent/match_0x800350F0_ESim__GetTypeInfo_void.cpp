// 0x800350F0 ESim::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-19416"
extern "C" int f_800350F0() {}
