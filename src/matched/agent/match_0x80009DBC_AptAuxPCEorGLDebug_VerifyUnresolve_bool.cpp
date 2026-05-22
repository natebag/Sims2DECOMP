// 0x80009DBC AptAuxPCEorGLDebug_VerifyUnresolve(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-32736(13)"
extern "C" void f_80009DBC() {}
