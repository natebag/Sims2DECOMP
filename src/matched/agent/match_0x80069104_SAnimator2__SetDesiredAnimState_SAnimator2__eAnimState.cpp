// 0x80069104 SAnimator2::SetDesiredAnimState(SAnimator2::eAnimState) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xb0(3)"
extern "C" void f_80069104() {}
