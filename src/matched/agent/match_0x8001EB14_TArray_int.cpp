// 0x8001EB14 TArray<int, (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0xc(1); li 4,0; li 3,0; ori 4,4,65535; bl _s8001EB14_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; mr 9,3; li 0,0; stw 0,0x4(9); stw 0,0x0(9); blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); andi. 0,4,1; beq 0f; bl _s8001EB14_1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; blr; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32697; lwz 0,0x0(31); addi 30,9,24012; lwz 29,0xe0(30); cmpwi 0,0; beq 1f; lwz 4,0x118(30); mr 3,30; bl _s8001EB14_2; lwz 11,0x0(31); lwz 9,0x56c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(31); lfs f0,0x44c(9); stfs f0,0x164(30); 1:; lwz 0,0x4(31); cmpwi 0,0; beq 2f; lis 3,-32697; li 4,1; addi 3,3,23428; bl _s8001EB14_3; cmpwi 3,0; beq 2f; mr 3,30; lwz 4,0x11c(3); bl _s8001EB14_4; lwz 3,0x4(31); lwz 9,0x56c(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; 2:; lis 3,-32697; mr 4,29; addi 3,3,24012; bl _s8001EB14_5; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-32672(13); cmpwi 0,0; bne 3f; li 3,8; bl _s8001EB14_6; bl _s8001EB14_7; mr 0,3; stw 0,-32672(13); bl _s8001EB14_8; 3:; lwz 3,-32672(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; rlwinm 4,4,2,0,29; stwx 5,3,4; blr; rlwinm 4,4,2,0,29; lwzx 3,3,4; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,0; li 5,256; bl _s8001EB14_9; mr 3,30; bl _s8001EB14_10; li 0,0; mr 3,30; stw 0,0x104(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8001EB14_0();
extern "C" void _s8001EB14_1();
extern "C" void _s8001EB14_2();
extern "C" void _s8001EB14_3();
extern "C" void _s8001EB14_4();
extern "C" void _s8001EB14_5();
extern "C" void _s8001EB14_6();
extern "C" void _s8001EB14_7();
extern "C" void _s8001EB14_8();
extern "C" void _s8001EB14_9();
extern "C" void _s8001EB14_10();
extern "C" void f_8001EB14() {}
