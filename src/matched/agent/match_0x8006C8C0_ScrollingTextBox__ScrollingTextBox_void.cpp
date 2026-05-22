// 0x8006C8C0 ScrollingTextBox::ScrollingTextBox(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 11,-32707; lis 10,-32707; lfs f0,0x4f40(11); lis 9,-32698; lfs f13,0x4f44(10); mr 30,3; li 0,0; addi 9,9,-13072; stw 9,0x40(30); stfs f13,0x28(30); stfs f0,0x38(30); stw 0,0x3c(30); stw 0,0x0(30); stfs f0,0x4(30); stfs f0,0x8(30); stfs f0,0xc(30); stfs f0,0x10(30); stfs f0,0x14(30); stfs f0,0x18(30); stfs f0,0x1c(30); stfs f0,0x20(30); stfs f0,0x2c(30); stfs f0,0x30(30); stfs f0,0x34(30); bl _s8006C8C0_0; li 5,16; li 6,0; li 7,0; li 4,16; bl _s8006C8C0_1; lis 11,-32707; mr 9,3; lfs f0,0x4f48(11); lis 3,-32692; lis 4,-31585; addi 3,3,-17444; stfs f0,0x0(9); ori 4,4,21693; stfs f0,0xc(9); stfs f0,0x8(9); stfs f0,0x4(9); stw 9,0x24(30); bl _s8006C8C0_2; stw 3,0x3c(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8006C8C0_0();
extern "C" void _s8006C8C0_1();
extern "C" void _s8006C8C0_2();
extern "C" void f_8006C8C0() {}
