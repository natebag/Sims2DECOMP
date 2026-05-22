// 0x80320534 ERShader::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-12544"
extern "C" int f_80320534() {}
