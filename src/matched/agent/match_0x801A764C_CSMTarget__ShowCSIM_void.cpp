// 0x801A764C CSMTarget::ShowCSIM(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; li 9,0; stw 0,0x90(3); stw 9,0x98(3)"
extern "C" void f_801A764C() {}
