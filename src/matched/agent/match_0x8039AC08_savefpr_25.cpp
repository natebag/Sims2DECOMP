// 0x8039AC08 _savefpr_25 (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfd f25,-56(11); stfd f26,-48(11); stfd f27,-40(11); stfd f28,-32(11); stfd f29,-24(11); stfd f30,-16(11); stfd f31,-8(11)"
extern "C" void f_8039AC08() {}
