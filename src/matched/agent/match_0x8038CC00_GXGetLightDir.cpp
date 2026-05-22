// 0x8038CC00 GXGetLightDir (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x34(3); fneg f0,f0; stfs f0,0x0(4); lfs f0,0x38(3); fneg f0,f0; stfs f0,0x0(5); lfs f0,0x3c(3); fneg f0,f0; stfs f0,0x0(6)"
extern "C" void f_8038CC00() {}
