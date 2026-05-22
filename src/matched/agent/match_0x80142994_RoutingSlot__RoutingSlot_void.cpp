// 0x80142994 RoutingSlot::RoutingSlot(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80142994_0; lis 11,-32706; lis 10,-32706; lfs f0,-10528(11); lis 9,-32698; lfs f13,-10524(10); li 0,0; li 11,16; addi 9,9,18896; li 10,-1; li 8,-2; stw 9,0x0(30); mr 3,30; stfs f0,0xc(30); stw 0,0x18(30); stw 10,0x20(30); stfs f13,0x30(30); stw 8,0x34(30); stw 11,0x38(30); stfs f0,0x4(30); stfs f0,0x8(30); stw 0,0x1c(30); stw 0,0x10(30); stw 0,0x14(30); stw 11,0x24(30); stw 11,0x28(30); stw 11,0x2c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80142994_0();
extern "C" void f_80142994() {}
