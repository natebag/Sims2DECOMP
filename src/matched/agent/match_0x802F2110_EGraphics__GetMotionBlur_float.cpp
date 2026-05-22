// 0x802F2110 EGraphics::GetMotionBlur(float (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x2f0(3); stfs f0,0x0(4); lfs f13,0x2f4(3); stfs f13,0x0(5); lfs f0,0x2f8(3); stfs f0,0x0(6); lfs f13,0x2fc(3); stfs f13,0x0(7)"
extern "C" void f_802F2110() {}
