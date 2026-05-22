// 0x8039AC44 _savegpr_21 (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 21,-44(11); stw 22,-40(11); stw 23,-36(11); stw 24,-32(11); stw 25,-28(11); stw 26,-24(11); stw 27,-20(11); stw 28,-16(11); stw 29,-12(11); stw 30,-8(11); stw 31,-4(11)"
extern "C" void f_8039AC44() {}
