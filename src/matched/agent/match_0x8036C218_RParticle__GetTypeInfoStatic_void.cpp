// 0x8036C218 RParticle::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-10004"
extern "C" int f_8036C218() {}
