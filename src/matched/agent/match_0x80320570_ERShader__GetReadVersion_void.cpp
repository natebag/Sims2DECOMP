// 0x80320570 ERShader::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12522(9)"
extern "C" int f_80320570() {}
