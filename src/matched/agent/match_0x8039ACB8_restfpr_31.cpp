// 0x8039ACB8 _restfpr_31 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f31,-8(11)"
extern "C" int f_8039ACB8() {}
