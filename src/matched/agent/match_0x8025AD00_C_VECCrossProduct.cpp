// 0x8025AD00 C_VECCrossProduct (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x8(3); lfs f6,0x4(4); lfs f5,0x0(4); lfs f7,0x4(3); fmuls f0,f1,f6; lfs f3,0x8(4); fmuls f4,f1,f5; lfs f2,0x0(3); fmuls f1,f7,f3; fmuls f3,f2,f3; fmuls f2,f2,f6; fsubs f0,f1,f0; fmuls f1,f7,f5; fsubs f3,f4,f3; stfs f0,0x0(5); fsubs f0,f2,f1; stfs f3,0x4(5); stfs f0,0x8(5)"
extern "C" void f_8025AD00() {}
