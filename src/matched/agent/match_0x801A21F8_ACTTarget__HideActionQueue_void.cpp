// 0x801A21F8 ACTTarget::HideActionQueue(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0xd8(3)"
extern "C" void f_801A21F8() {}
