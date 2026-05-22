// 0x800FE014 _MotiveSort(void (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); lis 8,-32706; lwz 9,0x0(4); lwz 10,-31824(13); rlwinm 11,11,2,0,29; rlwinm 9,9,2,0,29; lfd f12,-16240(8); lfsx f13,9,10; lfsx f0,11,10; fsubs f0,f0,f13; fmr f13,f0; fcmpu 0,f13,f12; blt 0f; lis 9,-32706; lfd f0,-16232(9); fcmpu 7,f13,f0; mfcr 3; rlwinm 3,3,30,31,31; blr; 0:; li 3,-1"
extern "C" float f_800FE014() {}
