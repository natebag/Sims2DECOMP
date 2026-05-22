// 0x800874D4 MenuItem::MenuItem(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,-10872; li 28,1; li 29,0; stw 9,0x1c(30); stw 28,0x0(30); lis 10,-32707; stw 28,0x4(30); lis 9,-32698; stw 29,0x8(30); addi 9,9,-11112; addi 11,30,32; lfs f0,0x7310(10); mr 3,11; stw 9,0x1c(30); stfs f0,0x18(30); stfs f0,0xc(30); stfs f0,0x10(30); stfs f0,0x14(30); stw 29,0x24(11); bl _s800874D4_0; stw 29,0x6c(30); mr 3,30; bl _s800874D4_1; mr 3,30; bl _s800874D4_2; lis 9,-32698; mr 3,30; addi 9,9,-11592; stw 9,0x1c(30); bl _s800874D4_3; stw 28,0x4(30); mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800874D4_0();
extern "C" void _s800874D4_1();
extern "C" void _s800874D4_2();
extern "C" void _s800874D4_3();
extern "C" void f_800874D4() {}
