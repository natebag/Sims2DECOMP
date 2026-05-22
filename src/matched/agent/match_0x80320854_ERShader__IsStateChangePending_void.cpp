// 0x80320854 ERShader::IsStateChangePending(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x58(3); rlwinm 3,3,30,31,31"
extern "C" int f_80320854() {}
