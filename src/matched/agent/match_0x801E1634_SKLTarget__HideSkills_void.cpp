// 0x801E1634 SKLTarget::HideSkills(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x9c(3); stw 0,0x90(3)"
extern "C" void f_801E1634() {}
