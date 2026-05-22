// 0x802F20EC EGraphics::GetCameraBloom(float (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x2ac(3); stfs f0,0x0(4); lfs f13,0x2b0(3); stfs f13,0x0(5); lfs f0,0x2b4(3); stfs f0,0x0(6); lfs f13,0x2b8(3); stfs f13,0x0(7)"
extern "C" void f_802F20EC() {}
