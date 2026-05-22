// 0x8039AD00 _restgpr_30 (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 30,-8(11); lwz 31,-4(11)"
extern "C" int f_8039AD00() {}
