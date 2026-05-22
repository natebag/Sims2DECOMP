// 0x8025AA4C C_VECScale (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x0(3); fmuls f0,f0,f1; stfs f0,0x0(4); lfs f0,0x4(3); fmuls f0,f0,f1; stfs f0,0x4(4); lfs f0,0x8(3); fmuls f0,f0,f1; stfs f0,0x8(4)"
extern "C" void f_8025AA4C() {}
