// 0x8039AD4C _restfpr_30_x (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f30,-16(11); lwz 0,0x4(11); lfd f31,-8(11); mtspr 8,0; mr 1,11"
extern "C" float f_8039AD4C() {}
