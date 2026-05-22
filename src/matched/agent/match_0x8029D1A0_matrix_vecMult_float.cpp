// 0x8029D1A0 _matrix_vecMult(float (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f11,0x4(3); lfs f13,0x8(4); lfs f10,0x0(3); lfs f0,0x0(4); fmuls f13,f13,f11; lfs f12,0x10(4); fmadds f0,f0,f10,f13; fadds f0,f0,f12; stfs f0,0x0(5); lfs f10,0x4(3); lfs f13,0xc(4); lfs f0,0x4(4); lfs f11,0x0(3); fmuls f13,f13,f10; lfs f12,0x14(4); fmadds f0,f0,f11,f13; fadds f0,f0,f12; stfs f0,0x4(5)"
extern "C" void f_8029D1A0() {}
