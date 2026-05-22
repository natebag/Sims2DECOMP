// 0x802CA2D4 EMat4::PostTranslate(EVec3 (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lfs f13,0x0(4); lfs f0,0x30(9); lfs f12,0x34(9); fadds f0,f0,f13; lfs f11,0x38(9); stfs f0,0x30(9); lfs f13,0x4(4); fadds f12,f12,f13; stfs f12,0x34(9); lfs f0,0x8(4); fadds f11,f11,f0; stfs f11,0x38(9)"
extern "C" void f_802CA2D4() {}
