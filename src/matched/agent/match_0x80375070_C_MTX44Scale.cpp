// 0x80375070 C_MTX44Scale (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x0(3); lfs f0,-17864(13); stfs f0,0x4(3); stfs f0,0x8(3); stfs f0,0xc(3); stfs f0,0x10(3); stfs f2,0x14(3); stfs f0,0x18(3); stfs f0,0x1c(3); stfs f0,0x20(3); stfs f0,0x24(3); stfs f3,0x28(3); stfs f0,0x2c(3); stfs f0,0x30(3); stfs f0,0x34(3); stfs f0,0x38(3); lfs f0,-17872(13); stfs f0,0x3c(3)"
extern "C" void f_80375070() {}
