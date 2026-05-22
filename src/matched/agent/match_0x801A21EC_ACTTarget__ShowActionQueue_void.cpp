// 0x801A21EC ACTTarget::ShowActionQueue(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0xd8(3)"
extern "C" void f_801A21EC() {}
