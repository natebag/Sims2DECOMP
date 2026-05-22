// 0x80003DE0 HandleDepthOfFieldEvent(EAnimNote (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 27,0x64(1); stw 0,0x7c(1); mr 30,3; mr. 31,4; beq 3f; lwz 11,-21508(13); lwz 9,0x0(11); lha 3,0x170(9); lwz 0,0x174(9); add 3,11,3; mtspr 8,0; blrl; mr 28,3; lis 4,-32707; addi 4,4,-20708; bl _s80003DE0_0; mr. 27,3; beq 3f; mr 3,31; bl _s80003DE0_1; mr. 29,3; beq 3f; addi 30,30,8; lwz 4,-32768(13); mr 3,30; bl _s80003DE0_2; cmpwi 3,0; bne 0f; mr 3,29; li 4,0; bl _s80003DE0_3; b 3f; 0:; addi 3,1,8; bl _s80003DE0_4; lwz 4,-32764(13); mr 3,30; addi 5,1,8; bl _s80003DE0_5; mr. 31,3; ble 2f; lwz 9,0x8(1); mr 3,28; mr 4,27; lwz 5,0x0(9); bl _s80003DE0_6; mr. 3,3; beq 2f; mr 6,3; cmpwi 31,1; ble 1f; lwz 10,0x0(6); addi 30,1,24; lwz 11,0x4(6); addi 5,31,-1; lwz 9,0x8(6); mr 3,30; lwz 0,0xc(6); stw 10,0x18(1); stw 11,0x4(30); stw 9,0x8(30); stw 0,0xc(30); lwz 11,0x18(6); lwz 0,0x10(6); lwz 9,0x14(6); stw 0,0x10(30); stw 9,0x14(30); stw 11,0x18(30); lwz 4,0x8(1); addi 4,4,4; bl _s80003DE0_7; mr 6,30; 1:; lfs f0,0x14(6); lis 9,-32707; lis 11,-32707; li 0,0; stfs f0,0x0(29); addi 10,1,80; addi 7,1,60; addi 8,29,20; lfs f0,0x18(6); mr 3,29; li 4,1; stfs f0,0x4(29); stw 0,0x38(1); lfs f0,-20672(9); lfs f13,-20668(11); stfs f0,0x3c(1); stfs f0,0x44(1); stfs f13,0x48(1); stfs f0,0x40(1); lwz 0,0x0(6); stw 0,0x38(1); lfs f0,0x4(6); lfs f13,0x8(6); lfs f12,0xc(6); stfs f0,0x50(1); stfs f13,0x54(1); stfs f12,0x58(1); lwz 0,0x50(1); lwz 9,0x8(10); lwz 11,0x4(10); stw 0,0x3c(1); stw 9,0x8(7); stw 11,0x4(7); lfs f0,0x10(6); lwz 11,0x38(1); lwz 10,0x44(1); lwz 0,0x3c(1); stfs f0,0x48(1); lwz 9,0x40(1); stw 11,0x14(29); stw 0,0x4(8); stw 9,0x8(8); stw 10,0xc(8); lwz 0,0x48(1); stw 0,0x10(8); bl _s80003DE0_8; 2:; addi 3,1,8; li 4,2; bl _s80003DE0_9; 3:; lwz 0,0x7c(1); mtspr 8,0; lmw 27,0x64(1); addi 1,1,120"
extern "C" void _s80003DE0_0();
extern "C" void _s80003DE0_1();
extern "C" void _s80003DE0_2();
extern "C" void _s80003DE0_3();
extern "C" void _s80003DE0_4();
extern "C" void _s80003DE0_5();
extern "C" void _s80003DE0_6();
extern "C" void _s80003DE0_7();
extern "C" void _s80003DE0_8();
extern "C" void _s80003DE0_9();
extern "C" void f_80003DE0() {}
