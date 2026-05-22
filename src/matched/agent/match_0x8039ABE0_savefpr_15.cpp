// 0x8039ABE0 _savefpr_15 (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfd f15,-136(11); stfd f16,-128(11); stfd f17,-120(11); stfd f18,-112(11); stfd f19,-104(11); stfd f20,-96(11); stfd f21,-88(11); stfd f22,-80(11); stfd f23,-72(11); stfd f24,-64(11); stfd f25,-56(11); stfd f26,-48(11); stfd f27,-40(11); stfd f28,-32(11); stfd f29,-24(11); stfd f30,-16(11); stfd f31,-8(11)"
extern "C" void f_8039ABE0() {}
