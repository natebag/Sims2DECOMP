// 0x802AB188 AptRenderingContext::AptRenderingContext(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 10,-32703; lis 11,-32703; lfs f0,-10204(11); mr 9,3; lfs f13,-10208(10); li 0,0; stfs f0,0x34(9); stfs f13,0x2c(9); stw 0,0x3bc(9); stfs f13,0x0(9); stfs f13,0x4(9); stfs f13,0x8(9); stfs f13,0xc(9); stfs f0,0x10(9); stfs f0,0x14(9); stfs f0,0x18(9); stfs f0,0x1c(9); stfs f13,0x20(9); stfs f0,0x24(9); stfs f0,0x28(9); stfs f0,0x30(9); stw 0,0x3b8(9)"
extern "C" void f_802AB188() {}
