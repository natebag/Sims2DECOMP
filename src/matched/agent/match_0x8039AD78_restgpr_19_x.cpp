// 0x8039AD78 _restgpr_19_x (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 19,-52(11); lwz 20,-48(11); lwz 21,-44(11); lwz 22,-40(11); lwz 23,-36(11); lwz 24,-32(11); lwz 25,-28(11); lwz 26,-24(11); lwz 27,-20(11); lwz 28,-16(11); lwz 29,-12(11); lwz 30,-8(11); lwz 0,0x4(11); lwz 31,-4(11); mtspr 8,0; mr 1,11"
extern "C" int f_8039AD78() {}
