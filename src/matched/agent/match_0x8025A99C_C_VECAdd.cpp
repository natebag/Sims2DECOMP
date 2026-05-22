// 0x8025A99C C_VECAdd (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x0(3); lfs f0,0x0(4); fadds f0,f1,f0; stfs f0,0x0(5); lfs f1,0x4(3); lfs f0,0x4(4); fadds f0,f1,f0; stfs f0,0x4(5); lfs f1,0x8(3); lfs f0,0x8(4); fadds f0,f1,f0; stfs f0,0x8(5)"
extern "C" void f_8025A99C() {}
