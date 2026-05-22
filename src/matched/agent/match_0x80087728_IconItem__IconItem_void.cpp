// 0x80087728 IconItem::IconItem(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,-10872; li 7,0; li 29,1; li 0,3; stw 9,0x1c(30); lis 8,-32707; stw 0,0x0(30); lis 11,-32707; stw 29,0x4(30); lis 9,-32698; stw 7,0x8(30); addi 9,9,-12008; lfs f13,0x731c(11); addi 10,30,32; lfs f0,0x7318(8); stw 9,0x1c(30); stfs f0,0x18(30); stfs f0,0xc(30); stfs f0,0x10(30); stfs f0,0x14(30); stfs f13,0x20(30); stfs f13,0x8(10); stfs f13,0x4(10); stfs f13,0x2c(30); stw 7,0x30(30); bl _s80087728_0; stw 29,0x4(30); mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80087728_0();
extern "C" void f_80087728() {}
