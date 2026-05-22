// 0x8036AC60 REffectsEmitter::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-10084"
extern "C" int f_8036AC60() {}
