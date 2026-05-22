// 0x803732E4 C_MTXScale (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x0(3); lfs f0,-17964(13); stfs f0,0x4(3); stfs f0,0x8(3); stfs f0,0xc(3); stfs f0,0x10(3); stfs f2,0x14(3); stfs f0,0x18(3); stfs f0,0x1c(3); stfs f0,0x20(3); stfs f0,0x24(3); stfs f3,0x28(3); stfs f0,0x2c(3)"
extern "C" void f_803732E4() {}
