// 0x8031B460 ERModel::DontCull(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x2c(3)"
extern "C" int f_8031B460() {}
