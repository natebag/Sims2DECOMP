// 0x803742A0 C_MTXOrtho (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fsubs f8,f4,f3; lfs f9,-17872(13); fsubs f0,f1,f2; lfs f7,-17868(13); fadds f3,f4,f3; fdivs f10,f9,f8; fdivs f8,f9,f0; fmuls f4,f7,f10; fneg f3,f3; fsubs f0,f6,f5; stfs f4,0x0(3); fadds f1,f1,f2; fmuls f2,f10,f3; lfs f3,-17864(13); fneg f1,f1; stfs f3,0x4(3); fdivs f4,f9,f0; stfs f3,0x8(3); stfs f2,0xc(3); stfs f3,0x10(3); fmuls f2,f7,f8; fneg f0,f6; fmuls f1,f8,f1; stfs f2,0x14(3); fmuls f0,f0,f4; stfs f3,0x18(3); stfs f1,0x1c(3); stfs f3,0x20(3); stfs f3,0x24(3); lfs f1,-17860(13); fmuls f1,f1,f4; stfs f1,0x28(3); stfs f0,0x2c(3); stfs f3,0x30(3); stfs f3,0x34(3); stfs f3,0x38(3); stfs f9,0x3c(3)"
extern "C" void f_803742A0() {}
