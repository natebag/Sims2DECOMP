// 0x802C5980 EBound3::Compute(EBoundSphere (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f11,0xc(4); addi 9,3,12; lfs f0,0x0(4); lfs f13,0x4(4); lfs f12,0x8(4); fsubs f0,f0,f11; fsubs f13,f13,f11; stfs f0,0x0(3); fsubs f12,f12,f11; stfs f13,0x4(3); stfs f12,0x8(3); lfs f11,0xc(4); lfs f0,0x0(4); lfs f13,0x8(4); lfs f12,0x4(4); fadds f0,f0,f11; stfs f0,0xc(3); fadds f13,f13,f11; fadds f12,f12,f11; stfs f13,0x8(9); stfs f12,0x4(9)"
extern "C" void f_802C5980() {}
