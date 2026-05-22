// 0x8039ACB4 _restfpr_30 (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f30,-16(11); lfd f31,-8(11)"
extern "C" float f_8039ACB4() {}
