// 0x8039AC1C _savefpr_30 (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfd f30,-16(11); stfd f31,-8(11)"
extern "C" void f_8039AC1C() {}
