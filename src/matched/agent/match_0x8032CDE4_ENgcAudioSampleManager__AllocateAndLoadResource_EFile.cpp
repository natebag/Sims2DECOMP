// 0x8032CDE4 ENgcAudioSampleManager::AllocateAndLoadResource(EFile (504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,4; mr 30,3; lwz 9,0x28(29); mr 27,5; mr 25,6; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,29,3; blrl; addi 0,27,8095; mr 26,3; rlwinm 31,0,0,0,18; 0:; mr 3,30; mr 4,31; bl _s8032CDE4_0; mr. 28,3; bne 1f; lwz 3,-22572(13); bl _s8032CDE4_1; cmpwi 3,0; beq 5f; lwz 3,-22572(13); bl _s8032CDE4_2; cmpwi 3,0; bne 0b; b 5f; 1:; lwz 3,-22572(13); li 4,40; li 5,8; li 30,0; bl _s8032CDE4_3; bl _s8032CDE4_4; mr 31,3; mr 4,29; stw 30,0x14(31); stw 30,0x18(31); bl _s8032CDE4_5; lwz 9,0x14(31); li 11,1; stw 28,0x1c(31); lhz 0,0x4a(9); cmpwi 0,0; bne 2f; li 11,0; 2:; stw 11,0x24(31); mr 3,29; mr 5,28; lwz 4,0x4(9); rlwinm 4,4,31,1,31; bl _s8032CDE4_6; lwz 9,0x14(31); lwz 0,0x4(9); rlwinm 0,0,31,1,31; subf 9,27,0; addi 9,9,97; cmpw 9,0; blt 3f; lwz 9,0x28(29); rlwinm 30,27,31,1,31; li 5,0; add 4,26,30; lha 3,0x28(9); lwz 0,0x2c(9); add 3,29,3; mtspr 8,0; blrl; mr 4,29; mr 3,31; bl _s8032CDE4_7; add 30,28,30; lwz 9,0x18(31); addi 30,30,-96; mr 3,29; stw 30,0x20(31); mr 5,30; lwz 4,0x4(9); rlwinm 4,4,31,1,31; bl _s8032CDE4_8; b 4f; 3:; stw 30,0x20(31); stw 30,0x18(31); 4:; lwz 9,0x28(29); add 4,26,27; li 5,0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,29,3; mtspr 8,0; blrl; b 6f; 5:; lwz 3,-22572(13); li 4,40; li 5,8; bl _s8032CDE4_9; bl _s8032CDE4_10; mr 31,3; li 3,96; bl _s8032CDE4_11; lwz 0,-25828(13); mr 9,3; stw 28,0x20(31); stw 0,0x1c(31); li 4,0; li 5,96; stw 9,0x14(31); bl _s8032CDE4_12; lwz 9,0x28(29); mr 4,27; li 5,1; lha 3,0x28(9); lwz 0,0x2c(9); add 3,29,3; mtspr 8,0; blrl; 6:; stw 25,0x8(31); mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8032CDE4_0();
extern "C" void _s8032CDE4_1();
extern "C" void _s8032CDE4_2();
extern "C" void _s8032CDE4_3();
extern "C" void _s8032CDE4_4();
extern "C" void _s8032CDE4_5();
extern "C" void _s8032CDE4_6();
extern "C" void _s8032CDE4_7();
extern "C" void _s8032CDE4_8();
extern "C" void _s8032CDE4_9();
extern "C" void _s8032CDE4_10();
extern "C" void _s8032CDE4_11();
extern "C" void _s8032CDE4_12();
extern "C" void f_8032CDE4() {}
