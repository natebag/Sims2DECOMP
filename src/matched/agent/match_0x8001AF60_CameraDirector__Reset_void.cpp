// 0x8001AF60 CameraDirector::Reset(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 30,3; li 29,0; lwz 0,0x240(30); rlwinm 0,0,0,0,30; stw 0,0x240(30); bl _s8001AF60_0; stw 29,0x160(30); addi 3,30,656; stw 29,0x164(30); stw 29,0x24c(30); bl _s8001AF60_1; addi 3,30,592; bl _s8001AF60_2; lis 9,-32707; stw 29,0x170(30); lfs f31,-6948(9); addi 3,30,128; stw 29,0x198(30); stfs f31,0x194(30); stfs f31,0x190(30); bl _s8001AF60_3; li 0,1; stfs f31,0x2d8(30); stw 29,0x240(30); addi 3,30,424; stfs f31,0x1a0(30); stw 29,0x118(30); stw 29,0x11c(30); stw 29,0x1a4(30); stw 29,0x220(30); stfs f31,0x224(30); stfs f31,0x228(30); stfs f31,0x22c(30); stw 29,0x238(30); stw 29,0x23c(30); stw 29,0x31c(30); stfs f31,0x2d4(30); stw 0,0x234(30); stw 0,0x230(30); bl _s8001AF60_4; mr 3,30; li 4,0; bl _s8001AF60_5; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s8001AF60_0();
extern "C" void _s8001AF60_1();
extern "C" void _s8001AF60_2();
extern "C" void _s8001AF60_3();
extern "C" void _s8001AF60_4();
extern "C" void _s8001AF60_5();
extern "C" void f_8001AF60() {}
