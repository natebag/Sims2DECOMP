// 0x8012811C operator<(ScoredInteraction (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x8(3); lfs f13,0x8(4); fcmpu 7,f0,f13; mfcr 3; rlwinm 3,3,30,31,31"
extern "C" float f_8012811C() {}
