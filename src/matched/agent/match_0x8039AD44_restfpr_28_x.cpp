// 0x8039AD44 _restfpr_28_x (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfd f28,-32(11); lfd f29,-24(11); lfd f30,-16(11); lwz 0,0x4(11); lfd f31,-8(11); mtspr 8,0; mr 1,11"
extern "C" float f_8039AD44() {}
