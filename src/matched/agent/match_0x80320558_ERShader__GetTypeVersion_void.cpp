// 0x80320558 ERShader::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12524(9)"
extern "C" int f_80320558() {}
