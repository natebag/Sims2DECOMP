// 0x80320750 ERShader::IsDayNightShader(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x58(3); rlwinm 3,3,27,31,31"
extern "C" int f_80320750() {}
