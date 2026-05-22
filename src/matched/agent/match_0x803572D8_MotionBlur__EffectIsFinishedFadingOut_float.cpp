// 0x803572D8 MotionBlur::EffectIsFinishedFadingOut(float) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x4(3); fcmpu 7,f1,f0; cror 31,30,29; mfcr 3; rlwinm 3,3,0,31,31"
extern "C" float f_803572D8() {}
