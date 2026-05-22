// 0x80069024 SAnimator2::SetPauseMultiplier(float) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fmr f0,f1; lfs f1,0x104(3); stfs f0,0x650(3); stfs f0,0x104(3)"
extern "C" void f_80069024() {}
