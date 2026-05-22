// 0x8025AB9C C_VECSquareMag (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x0(3); lfs f0,0x4(3); fmuls f1,f1,f1; lfs f2,0x8(3); fmuls f0,f0,f0; fmuls f2,f2,f2; fadds f0,f1,f0; fadds f1,f2,f0"
extern "C" float f_8025AB9C() {}
