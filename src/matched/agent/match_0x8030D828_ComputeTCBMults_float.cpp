// 0x8030D828 ComputeTCBMults(float, (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; lis 11,-32702; lfs f0,0x298(9); lis 10,-32702; lfs f12,0x29c(11); fsubs f1,f0,f1; lfs f13,0x2a0(10); fsubs f0,f0,f2; fmuls f1,f1,f12; fsubs f13,f13,f0; fmuls f0,f1,f0; stfs f0,0x0(3); fmuls f1,f1,f13; stfs f1,0x0(4)"
extern "C" void f_8030D828() {}
