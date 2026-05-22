// 0x8023822C ERLevel::SetDayNightLightTable(LevelLighting (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; stw 4,-7084(3)"
extern "C" void f_8023822C() {}
