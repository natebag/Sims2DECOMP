// 0x8039AD38 _restfpr_25_x (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f25,-56(11); lfd f26,-48(11); lfd f27,-40(11); lfd f28,-32(11); lfd f29,-24(11); lfd f30,-16(11); lwz 0,0x4(11); lfd f31,-8(11); mtspr 8,0; mr 1,11"
extern "C" float f_8039AD38() {}
