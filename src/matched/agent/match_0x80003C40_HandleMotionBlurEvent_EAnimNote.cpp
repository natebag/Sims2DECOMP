// 0x80003C40 HandleMotionBlurEvent(EAnimNote (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 27,0x44(1); stw 0,0x5c(1); mr 30,3; mr. 31,4; beq 3f; lwz 11,-21508(13); lwz 9,0x0(11); lha 3,0x170(9); lwz 0,0x174(9); add 3,11,3; mtspr 8,0; blrl; mr 28,3; lis 4,-32707; addi 4,4,-20752; bl _s80003C40_0; mr. 27,3; beq 3f; mr 3,31; bl _s80003C40_1; mr. 31,3; beq 3f; addi 30,30,8; lwz 4,-32768(13); mr 3,30; bl _s80003C40_2; cmpwi 3,0; bne 0f; mr 3,31; li 4,0; bl _s80003C40_3; b 3f; 0:; addi 3,1,8; bl _s80003C40_4; lwz 4,-32764(13); mr 3,30; addi 5,1,8; bl _s80003C40_5; mr. 29,3; ble 2f; lwz 9,0x8(1); mr 3,28; mr 4,27; lwz 5,0x0(9); bl _s80003C40_6; mr. 3,3; beq 2f; mr 8,3; cmpwi 29,1; ble 1f; lwz 10,0x0(8); addi 30,1,24; lwz 0,0x8(8); addi 5,29,-1; lwz 11,0x4(8); mr 3,30; lwz 9,0xc(8); stw 10,0x18(1); stw 11,0x4(30); stw 0,0x8(30); stw 9,0xc(30); lwz 0,0x10(8); stw 0,0x10(30); lwz 4,0x8(1); addi 4,4,4; bl _s80003C40_7; mr 8,30; 1:; lfs f0,0xc(8); lis 9,-32707; lis 11,-32707; li 0,0; stfs f0,0x0(31); addi 10,31,20; mr 3,31; li 4,1; lfs f0,0x10(8); stfs f0,0x4(31); stw 0,0x38(1); lfs f0,-20716(9); lfs f13,-20712(11); stfs f0,0x30(1); stfs f13,0x34(1); lfs f0,0x0(8); stfs f0,0x30(1); lwz 9,0x8(8); lwz 11,0x30(1); stw 9,0x38(1); lfs f0,0x4(8); stfs f0,0x34(1); lwz 0,0x34(1); stw 11,0x14(31); stw 9,0x8(10); stw 0,0x4(10); bl _s80003C40_8; 2:; addi 3,1,8; li 4,2; bl _s80003C40_9; 3:; lwz 0,0x5c(1); mtspr 8,0; lmw 27,0x44(1); addi 1,1,88"
extern "C" void _s80003C40_0();
extern "C" void _s80003C40_1();
extern "C" void _s80003C40_2();
extern "C" void _s80003C40_3();
extern "C" void _s80003C40_4();
extern "C" void _s80003C40_5();
extern "C" void _s80003C40_6();
extern "C" void _s80003C40_7();
extern "C" void _s80003C40_8();
extern "C" void _s80003C40_9();
extern "C" void f_80003C40() {}
