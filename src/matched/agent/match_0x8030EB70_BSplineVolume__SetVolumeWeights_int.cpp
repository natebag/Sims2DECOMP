// 0x8030EB70 BSplineVolume::SetVolumeWeights(int, (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0xa4(3); rlwinm 4,4,2,0,29; lfsx f0,4,9; fcmpu 0,f0,f1; bne 0f; lwz 3,0xa0(3); blr; 0:; stfsx f1,4,9; li 0,1; stw 0,0xa0(3); li 3,1"
extern "C" void f_8030EB70() {}
