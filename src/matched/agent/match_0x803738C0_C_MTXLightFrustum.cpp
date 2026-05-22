// 0x803738C0 C_MTXLightFrustum (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); lfs f12,0x38(1); fsubs f10,f4,f3; lfs f11,-17968(13); fsubs f0,f1,f2; lfs f9,-17952(13); fadds f3,f4,f3; fdivs f10,f11,f10; fmuls f5,f9,f5; fdivs f9,f11,f0; fmuls f4,f5,f10; fmuls f3,f10,f3; fadds f0,f1,f2; fmuls f1,f6,f4; fmuls f2,f6,f3; fmuls f0,f9,f0; stfs f1,0x0(3); fmuls f1,f5,f9; fsubs f2,f2,f8; lfs f3,-17964(13); fmuls f0,f7,f0; stfs f3,0x4(3); fmuls f1,f7,f1; stfs f2,0x8(3); fsubs f0,f0,f12; stfs f3,0xc(3); stfs f3,0x10(3); stfs f1,0x14(3); stfs f0,0x18(3); stfs f3,0x1c(3); stfs f3,0x20(3); stfs f3,0x24(3); lfs f0,-17944(13); stfs f0,0x28(3); stfs f3,0x2c(3); addi 1,1,48"
extern "C" void f_803738C0() {}
