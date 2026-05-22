// 0x800955B4 StartScreenVars::Reset(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32706; lis 11,-32706; lfs f0,-30844(9); addi 8,1,8; lfs f13,-30840(11); lis 9,-32706; stfs f0,0x8(1); lis 11,-32706; stfs f13,0x4(8); lis 10,-32706; lfs f0,-30852(9); li 0,0; lwz 7,0x4(8); lwz 9,0x8(1); lfs f13,-30848(11); lfs f12,-30836(10); li 11,1; stfs f0,0x34(3); stfs f13,0x4(3); stw 11,0xc(3); stw 9,0x10(3); stw 7,0x14(3); stfs f12,0x18(3); stw 0,0x30(3); stfs f0,0x0(3); stfs f0,0x8(3); stfs f0,0x1c(3); stw 0,0x24(3); stw 0,0x28(3); stw 0,0x2c(3); addi 1,1,16"
extern "C" void f_800955B4() {}
