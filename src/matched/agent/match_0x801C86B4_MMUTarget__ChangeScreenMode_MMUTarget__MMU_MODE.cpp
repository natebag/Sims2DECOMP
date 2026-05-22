// 0x801C86B4 MMUTarget::ChangeScreenMode(MMUTarget::MMU_MODE) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8c(3); stw 4,0x8c(3); stw 0,0x90(3)"
extern "C" void f_801C86B4() {}
