// 0x8039AC20 _savefpr_31 (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfd f31,-8(11)"
extern "C" void f_8039AC20() {}
