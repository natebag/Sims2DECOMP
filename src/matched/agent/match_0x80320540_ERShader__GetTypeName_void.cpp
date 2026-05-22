// 0x80320540 ERShader::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-12532(9)"
extern "C" int f_80320540() {}
