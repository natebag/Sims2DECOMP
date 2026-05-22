// 0x8039AD24 _restfpr_20_x (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f20,-96(11); lfd f21,-88(11); lfd f22,-80(11); lfd f23,-72(11); lfd f24,-64(11); lfd f25,-56(11); lfd f26,-48(11); lfd f27,-40(11); lfd f28,-32(11); lfd f29,-24(11); lfd f30,-16(11); lwz 0,0x4(11); lfd f31,-8(11); mtspr 8,0; mr 1,11"
extern "C" float f_8039AD24() {}
