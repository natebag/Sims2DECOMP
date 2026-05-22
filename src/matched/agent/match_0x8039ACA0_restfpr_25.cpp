// 0x8039ACA0 _restfpr_25 (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f25,-56(11); lfd f26,-48(11); lfd f27,-40(11); lfd f28,-32(11); lfd f29,-24(11); lfd f30,-16(11); lfd f31,-8(11)"
extern "C" float f_8039ACA0() {}
