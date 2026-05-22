// 0x800568AC ISimInstance::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-19376"
extern "C" int f_800568AC() {}
