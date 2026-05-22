// 0x802C9270 EMat4::PreScale(EVec3 (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lfs f11,0x0(4); lfs f0,0x0(9); lfs f13,0x4(9); fmuls f0,f0,f11; lfs f12,0x8(9); stfs f0,0x0(9); lfs f11,0x10(9); lfs f0,0x0(4); lfs f10,0x14(9); fmuls f13,f13,f0; lfs f9,0x18(9); stfs f13,0x4(9); lfs f8,0x20(9); lfs f0,0x0(4); lfs f13,0x24(9); fmuls f12,f12,f0; lfs f7,0x28(9); stfs f12,0x8(9); lfs f0,0x4(4); fmuls f11,f11,f0; stfs f11,0x10(9); lfs f0,0x4(4); fmuls f10,f10,f0; stfs f10,0x14(9); lfs f0,0x4(4); fmuls f9,f9,f0; stfs f9,0x18(9); lfs f0,0x8(4); fmuls f8,f8,f0; stfs f8,0x20(9); lfs f0,0x8(4); fmuls f13,f13,f0; stfs f13,0x24(9); lfs f0,0x8(4); fmuls f7,f7,f0; stfs f7,0x28(9)"
extern "C" void f_802C9270() {}
