// 0x8020B1B8 InteractorModule::InteractorManager::Initialize(InteractorModule::InteractorManager::InteractorParams (664 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); lwz 9,0x0(4); lwz 10,0x4(4); mr 31,3; stw 9,0x4(31); stw 10,0x8(31); lwz 9,0x4(31); cmpwi 9,0; blt 17f; lwz 0,0x8(31); cmpwi 0,0; blt 17f; cmpw 9,0; bgt 17f; lwz 3,-28512(13); cmpwi 3,0; beq 0f; li 4,3; bl _s8020B1B8_0; li 0,0; stw 0,-28512(13); 0:; li 3,8; bl _s8020B1B8_1; lwz 4,0x4(31); bl _s8020B1B8_2; lwz 0,-28508(13); stw 3,-28512(13); cmpwi 0,0; beq 1f; mr 3,0; li 4,3; bl _s8020B1B8_3; li 0,0; stw 0,-28508(13); 1:; li 3,276; bl _s8020B1B8_4; bl _s8020B1B8_5; mr 0,3; stw 0,-28508(13); bl _s8020B1B8_6; lwz 0,0x0(31); cmpwi 0,0; beq 2f; mr 3,31; bl _s8020B1B8_7; 2:; mr 3,31; addi 27,1,32; bl _s8020B1B8_8; addi 28,31,44; addi 10,31,28; lwz 11,0x1c(31); mr 30,10; addi 26,1,8; addi 29,31,64; addi 24,1,16; addi 25,1,24; lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 4f; 3:; addi 9,9,8; cmpw 9,0; bne 3b; 4:; stw 11,0x4(10); mr 3,30; lwz 4,0x4(31); bl _s8020B1B8_9; lwz 4,0x4(30); li 0,-1; lwz 10,0x1c(31); li 11,0; lwz 5,0x4(31); subf 9,10,4; stw 0,0x20(1); srawi 9,9,3; stw 11,0x4(27); cmplw 5,9; bge 7f; rlwinm 0,5,3,0,28; add 0,0,10; lwz 11,0x4(30); mr 9,0; cmpw 0,11; beq 6f; 5:; addi 9,9,8; cmpw 9,11; bne 5b; 6:; stw 0,0x4(30); b 8f; 7:; subf 5,9,5; mr 3,30; mr 6,27; bl _s8020B1B8_10; 8:; li 0,0; lwz 11,0x2c(31); stb 0,0x3c(31); lwz 0,0x4(28); mr 9,11; cmpw 11,0; beq 10f; 9:; addi 9,9,8; cmpw 9,0; bne 9b; 10:; stw 11,0x4(28); mr 3,28; lwz 4,0x4(31); bl _s8020B1B8_11; lwz 4,0x2c(31); li 0,-1; lwz 5,0x4(31); li 9,0; stw 0,0x8(1); mr 3,28; stw 9,0xc(1); mr 6,26; bl _s8020B1B8_12; lwz 11,0x40(31); lwz 0,0x4(29); mr 9,11; cmpw 11,0; beq 12f; 11:; addi 9,9,16; cmpw 9,0; bne 11b; 12:; stw 11,0x4(29); mr 3,29; lwz 4,0x4(31); bl _s8020B1B8_13; lwz 4,0x4(29); lis 9,-32704; lwz 11,0x40(31); lfs f0,-11684(9); lwz 5,0x4(31); subf 0,11,4; srawi 0,0,4; stfs f0,0x10(1); stfs f0,0x14(1); cmplw 5,0; stfs f0,0x18(1); stfs f0,0x4(25); bge 15f; rlwinm 0,5,4,0,27; add 0,0,11; lwz 11,0x4(29); mr 9,0; cmpw 0,11; beq 14f; 13:; addi 9,9,16; cmpw 9,11; bne 13b; 14:; stw 0,0x4(29); b 16f; 15:; subf 5,0,5; mr 3,29; mr 6,24; bl _s8020B1B8_14; 16:; li 0,1; stw 0,0x0(31); 17:; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s8020B1B8_0();
extern "C" void _s8020B1B8_1();
extern "C" void _s8020B1B8_2();
extern "C" void _s8020B1B8_3();
extern "C" void _s8020B1B8_4();
extern "C" void _s8020B1B8_5();
extern "C" void _s8020B1B8_6();
extern "C" void _s8020B1B8_7();
extern "C" void _s8020B1B8_8();
extern "C" void _s8020B1B8_9();
extern "C" void _s8020B1B8_10();
extern "C" void _s8020B1B8_11();
extern "C" void _s8020B1B8_12();
extern "C" void _s8020B1B8_13();
extern "C" void _s8020B1B8_14();
extern "C" void f_8020B1B8() {}
