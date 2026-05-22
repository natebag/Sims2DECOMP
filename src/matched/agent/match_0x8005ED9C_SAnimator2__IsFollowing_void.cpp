// 0x8005ED9C SAnimator2::IsFollowing(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x10(3); li 3,1; cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_8005ED9C() {}
