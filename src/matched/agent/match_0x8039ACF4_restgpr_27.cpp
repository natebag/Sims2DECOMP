// 0x8039ACF4 _restgpr_27 (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 27,-20(11); lwz 28,-16(11); lwz 29,-12(11); lwz 30,-8(11); lwz 31,-4(11)"
extern "C" int f_8039ACF4() {}
