// 0x8039AC68 _savegpr_30 (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 30,-8(11); stw 31,-4(11)"
extern "C" void f_8039AC68() {}
