// 0x8001C8D4 CameraDirector::CalcSimsCam(void) (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-200(1); mfspr 0,8; stfd f31,0xc0(1); stmw 23,0x9c(1); stw 0,0xcc(1); mr 30,3; li 28,0; lwz 23,0x160(30); addi 24,1,24; lwz 3,0x170(30); addi 25,1,40; stw 28,0x160(30); addi 29,1,56; addi 27,1,120; addi 26,1,136; bl _s8001C8D4_0; lwz 3,0x170(30); addi 4,1,8; mr 5,24; mr 6,25; bl _s8001C8D4_1; lwz 3,0x170(30); bl _s8001C8D4_2; lis 9,-32707; addi 5,1,72; lfs f0,-6792(9); addi 6,1,88; mr 3,30; mr 4,29; fmuls f31,f1,f0; bl _s8001C8D4_3; lwz 3,0x170(30); mr 4,29; addi 5,30,256; addi 6,30,268; bl _s8001C8D4_4; lwz 11,0x170(30); lis 10,-32707; lfs f0,0x17c(30); lwz 9,0x0(11); lfs f1,-6788(10); stfs f0,0x64(9); lwz 11,0x170(30); lfs f0,0x178(30); lwz 9,0x0(11); stfs f0,0x60(9); lwz 11,0x170(30); lfs f0,0x180(30); lwz 9,0x0(11); stfs f0,0x70(9); lwz 11,0x170(30); lfs f0,0x184(30); lwz 9,0x0(11); stfs f0,0x6c(9); lwz 11,0x170(30); stw 28,0x540(11); lwz 3,0x170(30); bl _s8001C8D4_5; lwz 9,0x170(30); li 0,1; addi 4,1,104; mr 5,27; stw 0,0x540(9); mr 6,26; lwz 3,0x170(30); bl _s8001C8D4_6; lwz 3,0x170(30); addi 4,1,8; mr 5,27; mr 6,26; bl _s8001C8D4_7; lwz 11,0x170(30); lwz 9,0x56c(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; mr 3,30; bl _s8001C8D4_8; lwz 3,0x170(30); mr 5,24; mr 6,25; addi 4,1,8; bl _s8001C8D4_9; mr 3,30; fmr f1,f31; bl _s8001C8D4_10; lwz 11,0x170(30); lwz 9,0x56c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(30); lwz 10,0x4(30); addi 8,30,128; lwz 11,0x8(30); lwz 12,0xc(30); stw 9,0x80(30); stw 10,0x84(30); stw 11,0x8(8); stw 12,0xc(8); lwz 9,0x10(30); lwz 10,0x14(30); stw 9,0x10(8); stw 10,0x14(8); lwz 11,0x18(30); lwz 12,0x1c(30); stw 11,0x18(8); stw 12,0x1c(8); lwz 9,0x20(30); lwz 10,0x24(30); stw 9,0x20(8); stw 10,0x24(8); lwz 11,0x28(30); lwz 12,0x2c(30); stw 11,0x28(8); stw 12,0x2c(8); lwz 9,0x30(30); lwz 10,0x34(30); stw 9,0x30(8); stw 10,0x34(8); lwz 11,0x38(30); lwz 12,0x3c(30); stw 11,0x38(8); stw 12,0x3c(8); stw 23,0x160(30); lfs f0,0x174(30); stfs f0,0x1a0(30); lwz 0,0xcc(1); mtspr 8,0; lmw 23,0x9c(1); lfd f31,0xc0(1); addi 1,1,200"
extern "C" void _s8001C8D4_0();
extern "C" void _s8001C8D4_1();
extern "C" void _s8001C8D4_2();
extern "C" void _s8001C8D4_3();
extern "C" void _s8001C8D4_4();
extern "C" void _s8001C8D4_5();
extern "C" void _s8001C8D4_6();
extern "C" void _s8001C8D4_7();
extern "C" void _s8001C8D4_8();
extern "C" void _s8001C8D4_9();
extern "C" void _s8001C8D4_10();
extern "C" void f_8001C8D4() {}
