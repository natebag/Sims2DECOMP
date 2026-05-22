// 0x802C9640 EMat4::Transpose(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lfs f8,0x4(9); lfs f13,0x10(9); stfs f8,0x10(9); lfs f8,0x8(9); lfs f12,0x20(9); stfs f8,0x20(9); lfs f8,0xc(9); lfs f9,0x30(9); stfs f8,0x30(9); lfs f8,0x10(9); lfs f0,0x24(9); stfs f8,0x4(9); lfs f8,0x18(9); lfs f11,0x34(9); stfs f8,0x24(9); lfs f8,0x1c(9); lfs f10,0x38(9); stfs f8,0x34(9); lfs f8,0x20(9); stfs f13,0x10(9); stfs f8,0x8(9); lfs f8,0x24(9); stfs f12,0x20(9); stfs f8,0x18(9); lfs f8,0x2c(9); stfs f0,0x24(9); stfs f8,0x38(9); lfs f8,0x30(9); stfs f9,0x30(9); stfs f8,0xc(9); lfs f8,0x34(9); stfs f11,0x34(9); stfs f8,0x1c(9); lfs f8,0x38(9); stfs f10,0x38(9); stfs f8,0x2c(9)"
extern "C" void f_802C9640() {}
