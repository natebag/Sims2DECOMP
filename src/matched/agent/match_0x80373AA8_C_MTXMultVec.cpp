// 0x80373AA8 C_MTXMultVec (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f10,0x0(4); lfs f0,0x0(3); lfs f2,0x10(3); lfs f9,0x4(4); fmuls f1,f0,f10; lfs f0,0x4(3); fmuls f7,f2,f10; lfs f2,0x14(3); fmuls f0,f0,f9; fmuls f6,f2,f9; lfs f4,0x20(3); lfs f3,0x24(3); lfs f11,0x8(4); lfs f2,0x8(3); lfs f8,0x18(3); fadds f0,f1,f0; fmuls f1,f2,f11; lfs f5,0x28(3); fmuls f4,f4,f10; fmuls f3,f3,f9; fmuls f8,f8,f11; fadds f6,f7,f6; lfs f2,0xc(3); fadds f0,f1,f0; fmuls f5,f5,f11; fadds f1,f4,f3; fadds f3,f8,f6; lfs f4,0x1c(3); fadds f0,f2,f0; lfs f2,0x2c(3); fadds f1,f5,f1; fadds f3,f4,f3; stfs f0,0x0(5); fadds f0,f2,f1; stfs f3,0x4(5); stfs f0,0x8(5)"
extern "C" void f_80373AA8() {}
