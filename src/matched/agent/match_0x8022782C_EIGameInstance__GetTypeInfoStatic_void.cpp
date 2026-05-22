// 0x8022782C EIGameInstance::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-13360"
extern "C" int f_8022782C() {}
