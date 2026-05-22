// 0x8039AC64 _savegpr_29 (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 29,-12(11); stw 30,-8(11); stw 31,-4(11)"
extern "C" void f_8039AC64() {}
