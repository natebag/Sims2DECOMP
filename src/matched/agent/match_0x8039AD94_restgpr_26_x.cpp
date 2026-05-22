// 0x8039AD94 _restgpr_26_x (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 26,-24(11); lwz 27,-20(11); lwz 28,-16(11); lwz 29,-12(11); lwz 30,-8(11); lwz 0,0x4(11); lwz 31,-4(11); mtspr 8,0; mr 1,11"
extern "C" int f_8039AD94() {}
