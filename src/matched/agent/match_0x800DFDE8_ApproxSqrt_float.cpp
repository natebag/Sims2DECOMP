// 0x800DFDE8 ApproxSqrt(float) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fmr f11,f1; lis 9,-32706; lfs f1,-20796(9); fcmpu 0,f11,f1; cror 3,2,0; bsolr; lis 9,-32706; lis 10,-32706; lfs f1,-20792(9); lis 11,-32706; lfs f13,-20788(10); lfs f12,-20784(11); fmadds f1,f11,f1,f13; fdivs f0,f11,f1; fadds f1,f1,f0; fmuls f1,f1,f12; fdivs f0,f11,f1; fadds f1,f1,f0; fmuls f1,f1,f12"
extern "C" float f_800DFDE8() {}
