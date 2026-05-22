// 0x802C96D8 EMat4::Id(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32702; lis 10,-32702; lfs f0,-7504(11); mr 9,3; lfs f13,-7500(10); stfs f0,0x38(9); stfs f13,0x3c(9); stfs f0,0x4(9); stfs f0,0x8(9); stfs f0,0xc(9); stfs f0,0x10(9); stfs f0,0x18(9); stfs f0,0x1c(9); stfs f0,0x20(9); stfs f0,0x24(9); stfs f0,0x2c(9); stfs f0,0x30(9); stfs f0,0x34(9); stfs f13,0x0(9); stfs f13,0x14(9); stfs f13,0x28(9)"
extern "C" void f_802C96D8() {}
