// 0x8023825C ERLevel::WallFadeState(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; lwz 3,-7468(3)"
extern "C" int f_8023825C() {}
