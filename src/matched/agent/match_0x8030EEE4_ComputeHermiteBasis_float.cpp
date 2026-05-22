// 0x8030EEE4 ComputeHermiteBasis(float, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; fmuls f0,f1,f1; lfs f11,0x2f0(9); fmuls f9,f0,f1; lis 9,-32702; fadds f13,f9,f9; fmuls f11,f0,f11; lfs f10,0x2f4(9); fadds f12,f0,f0; fsubs f13,f13,f11; fadds f10,f13,f10; fsubs f1,f1,f12; stfs f10,0x0(3); fneg f0,f0; fadds f0,f0,f9; fneg f13,f13; stfs f0,0xc(3); fadds f1,f1,f9; stfs f13,0x4(3); stfs f1,0x8(3)"
extern "C" void f_8030EEE4() {}
