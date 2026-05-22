// 0x80303A8C PSystemSetWorldGravityDir (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x0(3); lis 11,-32702; lfs f11,0x8(3); lis 10,-32693; lfs f13,0x4(3); addi 9,10,2316; lfs f12,-1820(11); stfs f0,0x90c(10); stfs f12,0xc(9); stfs f13,0x4(9); stfs f11,0x8(9)"
extern "C" void f_80303A8C() {}
