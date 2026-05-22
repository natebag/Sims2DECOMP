// 0x8039ABEC _savefpr_18 (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfd f18,-112(11); stfd f19,-104(11); stfd f20,-96(11); stfd f21,-88(11); stfd f22,-80(11); stfd f23,-72(11); stfd f24,-64(11); stfd f25,-56(11); stfd f26,-48(11); stfd f27,-40(11); stfd f28,-32(11); stfd f29,-24(11); stfd f30,-16(11); stfd f31,-8(11)"
extern "C" void f_8039ABEC() {}
