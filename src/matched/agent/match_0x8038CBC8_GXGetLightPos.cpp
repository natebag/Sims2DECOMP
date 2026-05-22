// 0x8038CBC8 GXGetLightPos (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x28(3); stfs f0,0x0(4); lfs f0,0x2c(3); stfs f0,0x0(5); lfs f0,0x30(3); stfs f0,0x0(6)"
extern "C" void f_8038CBC8() {}
