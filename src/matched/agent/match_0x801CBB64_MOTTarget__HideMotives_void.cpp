// 0x801CBB64 MOTTarget::HideMotives(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x94(3); stw 0,0x160(3)"
extern "C" void f_801CBB64() {}
