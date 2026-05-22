// 0x80079078 CUnlockDisplayObject::CUnlockDisplayObject(void) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 30,0x18(1); stw 0,0x2c(1); lis 9,-32707; addi 10,1,8; lfs f31,0x62b8(9); lis 11,-32698; mr 30,3; addi 11,11,-12984; stfs f31,0x8(10); li 0,0; stfs f31,0x4(10); li 8,1; stfs f31,0x8(1); addi 6,30,84; stw 11,0x84(30); addi 5,30,72; lwz 11,0x8(10); addi 4,30,60; lwz 9,0x8(1); lwz 7,0x4(10); stw 9,0x54(30); stw 8,0x38(30); stw 8,0x4(30); stw 8,0x80(30); stw 0,0x70(30); stw 0,0x8(30); stw 0,0xc(30); stw 0,0x78(30); stw 0,0x74(30); stw 0,0x7c(30); stw 0,0x10(30); stw 0,0x0(30); stw 0,0x14(30); stw 0,0x20(30); stw 0,0x30(30); stw 0,0x2c(30); stw 0,0x34(30); stw 0,0x6c(30); stw 11,0x8(6); stw 7,0x4(6); lwz 0,0x54(30); stw 0,0x48(30); stw 11,0x8(5); stw 7,0x4(5); lwz 0,0x48(30); stw 0,0x3c(30); stw 11,0x8(4); stw 7,0x4(4); bl _s80079078_0; li 4,64; li 5,16; li 6,0; li 7,0; bl _s80079078_1; mr 0,3; stw 0,0x24(30); bl _s80079078_2; stfs f31,0x28(30); bl _s80079078_3; li 4,800; li 5,16; li 6,0; li 7,0; bl _s80079078_4; bl _s80079078_5; stw 3,0x1c(30); li 0,-1; stw 0,0x18(30); mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s80079078_0();
extern "C" void _s80079078_1();
extern "C" void _s80079078_2();
extern "C" void _s80079078_3();
extern "C" void _s80079078_4();
extern "C" void _s80079078_5();
extern "C" void f_80079078() {}
