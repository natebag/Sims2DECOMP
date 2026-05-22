// 0x802380F4 ERLevel::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-13080"
extern "C" int f_802380F4() {}
