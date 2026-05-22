// 0x8025AF34 C_VECSquareDistance (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f3,0x0(3); lfs f2,0x0(4); lfs f1,0x4(3); lfs f0,0x4(4); fsubs f3,f3,f2; lfs f2,0x8(3); fsubs f4,f1,f0; lfs f0,0x8(4); fmuls f1,f3,f3; fsubs f2,f2,f0; fmuls f0,f4,f4; fmuls f2,f2,f2; fadds f0,f1,f0; fadds f1,f2,f0"
extern "C" float f_8025AF34() {}
