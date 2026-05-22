// 0x803C1DE0 operator*(float, (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f12,0xc(4); mr 9,3; lfs f0,0x0(4); lfs f13,0x4(4); fmuls f12,f1,f12; lfs f11,0x8(4); fmuls f0,f1,f0; fmuls f13,f1,f13; stfs f0,0x0(9); fmuls f1,f1,f11; stfs f13,0x4(9); stfs f1,0x8(9); stfs f12,0xc(9)"
extern "C" void f_803C1DE0() {}
