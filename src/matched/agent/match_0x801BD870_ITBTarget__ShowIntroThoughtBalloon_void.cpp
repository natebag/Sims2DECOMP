// 0x801BD870 ITBTarget::ShowIntroThoughtBalloon(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x98(3)"
extern "C" void f_801BD870() {}
