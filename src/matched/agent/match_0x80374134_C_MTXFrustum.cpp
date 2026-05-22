// 0x80374134 C_MTXFrustum (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fsubs f9,f4,f3; lfs f10,-17872(13); fsubs f0,f1,f2; lfs f8,-17868(13); fsubs f7,f6,f5; fdivs f11,f10,f9; fmuls f8,f8,f5; fdivs f9,f10,f0; fmuls f0,f8,f11; fadds f3,f4,f3; fadds f2,f1,f2; stfs f0,0x0(3); fmuls f0,f6,f5; fdivs f6,f10,f7; lfs f4,-17864(13); stfs f4,0x4(3); fmuls f3,f11,f3; fneg f1,f5; fneg f0,f0; stfs f3,0x8(3); fmuls f3,f8,f9; fmuls f2,f9,f2; stfs f4,0xc(3); fmuls f1,f1,f6; stfs f4,0x10(3); fmuls f0,f6,f0; stfs f3,0x14(3); stfs f2,0x18(3); stfs f4,0x1c(3); stfs f4,0x20(3); stfs f4,0x24(3); stfs f1,0x28(3); stfs f0,0x2c(3); stfs f4,0x30(3); stfs f4,0x34(3); lfs f0,-17860(13); stfs f0,0x38(3); stfs f4,0x3c(3)"
extern "C" void f_80374134() {}
