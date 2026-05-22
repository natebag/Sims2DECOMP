// 0x8038C910 GXGetLightAttnA (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x10(3); stfs f0,0x0(4); lfs f0,0x14(3); stfs f0,0x0(5); lfs f0,0x18(3); stfs f0,0x0(6)"
extern "C" void f_8038C910() {}
