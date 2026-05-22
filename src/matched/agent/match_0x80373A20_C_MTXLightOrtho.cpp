// 0x80373A20 C_MTXLightOrtho (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fsubs f10,f4,f3; lfs f11,-17968(13); fsubs f0,f1,f2; lfs f9,-17952(13); fadds f3,f4,f3; fdivs f12,f11,f10; fdivs f10,f11,f0; fmuls f4,f9,f12; fneg f3,f3; fadds f0,f1,f2; fmuls f1,f4,f5; fmuls f2,f12,f3; fneg f0,f0; stfs f1,0x0(3); fmuls f1,f9,f10; fmuls f2,f5,f2; lfs f3,-17964(13); fmuls f0,f10,f0; stfs f3,0x4(3); fadds f2,f7,f2; fmuls f1,f1,f6; stfs f3,0x8(3); fmuls f0,f6,f0; stfs f2,0xc(3); stfs f3,0x10(3); fadds f0,f8,f0; stfs f1,0x14(3); stfs f3,0x18(3); stfs f0,0x1c(3); stfs f3,0x20(3); stfs f3,0x24(3); stfs f3,0x28(3); stfs f11,0x2c(3)"
extern "C" void f_80373A20() {}
