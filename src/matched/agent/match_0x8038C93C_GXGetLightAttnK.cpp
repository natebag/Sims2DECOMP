// 0x8038C93C GXGetLightAttnK (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x1c(3); stfs f0,0x0(4); lfs f0,0x20(3); stfs f0,0x0(5); lfs f0,0x24(3); stfs f0,0x0(6)"
extern "C" void f_8038C93C() {}
