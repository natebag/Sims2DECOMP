// 0x802293D0 EInstance::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-18528"
extern "C" int f_802293D0() {}
