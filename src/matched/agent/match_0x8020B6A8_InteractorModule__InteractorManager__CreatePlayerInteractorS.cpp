// 0x8020B6A8 InteractorModule::InteractorManager::CreatePlayerInteractorSets(void) (936 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stfd f31,0x60(1); stmw 19,0x2c(1); stw 0,0x6c(1); mr 27,3; addi 28,27,12; lwz 4,0x4(27); mr 3,28; bl _s8020B6A8_0; lwz 4,0x4(28); li 9,0; lwz 8,0xc(27); addi 11,1,8; lwz 5,0x4(27); addi 10,1,16; stw 9,0x8(1); subf 0,8,4; stw 9,0x4(11); srawi 0,0,4; mr 26,11; stw 9,0x4(10); cmplw 5,0; bge 4f; rlwinm 0,5,4,0,27; add 29,0,8; lwz 31,0x4(28); mr 30,29; cmpw 29,31; beq 3f; 0:; lwz 3,0x0(30); cmpwi 3,0; beq 2f; lwz 0,0xc(30); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 1f; bl _s8020B6A8_1; b 2f; 1:; bl _s8020B6A8_2; 2:; addi 30,30,16; cmpw 30,31; bne 0b; 3:; stw 29,0x4(28); b 5f; 4:; subf 5,0,5; mr 3,28; mr 6,26; bl _s8020B6A8_3; 5:; lwz 3,0x8(1); cmpwi 3,0; beq 7f; lwz 0,0xc(26); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 6f; bl _s8020B6A8_4; b 7f; 6:; bl _s8020B6A8_5; 7:; lwz 0,0x4(27); li 25,0; cmpw 25,0; bge 11f; lis 9,-32704; lis 11,-32697; lfs f31,-11680(9); addi 19,11,-31704; lis 9,-32698; lis 11,-32697; addi 21,9,29056; addi 20,11,-31936; lis 9,-32698; li 23,8; addi 22,9,29032; li 28,0; addi 24,1,32; li 26,0; 8:; lwz 9,0xc(27); stw 28,0x20(1); add 31,9,26; lwzx 11,9,26; lwz 4,0x4(31); subf 0,11,4; srawi 0,0,2; cmplw 23,0; bge 9f; addi 0,11,32; stw 0,0x4(31); b 10f; 9:; subfic 5,0,8; mr 3,31; mr 6,24; bl _s8020B6A8_6; 10:; lwz 30,0x0(31); li 3,140; bl _s8020B6A8_7; addi 25,25,1; bl _s8020B6A8_8; addi 26,26,16; stw 3,0x0(30); lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x5c(10); lwz 0,0x14(11); lha 3,0x10(11); mtspr 8,0; add 3,10,3; blrl; lwz 30,0x0(31); li 3,556; bl _s8020B6A8_9; bl _s8020B6A8_10; stw 3,0x4(30); lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x5c(10); lwz 0,0x14(11); lha 3,0x10(11); mtspr 8,0; add 3,10,3; blrl; lwz 29,0x0(31); li 3,212; bl _s8020B6A8_11; mr 30,3; bl _s8020B6A8_12; stw 19,0x5c(30); addi 11,30,172; stw 21,0x10(11); addi 9,30,200; stfs f31,0x4(9); li 0,2; stfs f31,0x8(9); stw 0,0xac(30); stfs f31,0xc8(30); stw 28,0x18(11); sth 28,0x14(11); stw 30,0x8(29); lwz 9,0x0(31); lwz 10,0x8(9); lwz 11,0x5c(10); lwz 0,0x14(11); lha 3,0x10(11); mtspr 8,0; add 3,10,3; blrl; lwz 29,0x0(31); li 3,212; bl _s8020B6A8_13; mr 30,3; bl _s8020B6A8_14; stw 20,0x5c(30); addi 9,30,172; li 0,1; stw 22,0x10(9); stw 0,0x24(9); li 11,6; stw 28,0x14(9); stb 28,0x18(9); stw 28,0x1c(9); sth 28,0x20(9); stw 11,0xac(30); stw 30,0x18(29); lwz 9,0x0(31); lwz 10,0x18(9); lwz 11,0x5c(10); lwz 0,0x14(11); lha 3,0x10(11); mtspr 8,0; add 3,10,3; blrl; lwz 30,0x0(31); li 3,264; bl _s8020B6A8_15; bl _s8020B6A8_16; stw 3,0xc(30); lwz 9,0x0(31); lwz 10,0xc(9); lwz 11,0x5c(10); lwz 0,0x14(11); lha 3,0x10(11); mtspr 8,0; add 3,10,3; blrl; lwz 30,0x0(31); li 3,208; bl _s8020B6A8_17; bl _s8020B6A8_18; stw 3,0x10(30); lwz 9,0x0(31); lwz 10,0x10(9); lwz 11,0x5c(10); lwz 0,0x14(11); lha 3,0x10(11); mtspr 8,0; add 3,10,3; blrl; lwz 30,0x0(31); li 3,188; bl _s8020B6A8_19; bl _s8020B6A8_20; stw 3,0x14(30); lwz 9,0x0(31); lwz 10,0x14(9); lwz 11,0x5c(10); lwz 0,0x14(11); lha 3,0x10(11); mtspr 8,0; add 3,10,3; blrl; lwz 30,0x0(31); li 3,112; bl _s8020B6A8_21; bl _s8020B6A8_22; stw 3,0x1c(30); lwz 9,0x0(31); lwz 10,0x1c(9); lwz 11,0x5c(10); lwz 0,0x14(11); lha 3,0x10(11); mtspr 8,0; add 3,10,3; blrl; lwz 0,0x4(27); cmpw 25,0; blt 8b; 11:; lwz 0,0x6c(1); mtspr 8,0; lmw 19,0x2c(1); lfd f31,0x60(1); addi 1,1,104"
extern "C" void _s8020B6A8_0();
extern "C" void _s8020B6A8_1();
extern "C" void _s8020B6A8_2();
extern "C" void _s8020B6A8_3();
extern "C" void _s8020B6A8_4();
extern "C" void _s8020B6A8_5();
extern "C" void _s8020B6A8_6();
extern "C" void _s8020B6A8_7();
extern "C" void _s8020B6A8_8();
extern "C" void _s8020B6A8_9();
extern "C" void _s8020B6A8_10();
extern "C" void _s8020B6A8_11();
extern "C" void _s8020B6A8_12();
extern "C" void _s8020B6A8_13();
extern "C" void _s8020B6A8_14();
extern "C" void _s8020B6A8_15();
extern "C" void _s8020B6A8_16();
extern "C" void _s8020B6A8_17();
extern "C" void _s8020B6A8_18();
extern "C" void _s8020B6A8_19();
extern "C" void _s8020B6A8_20();
extern "C" void _s8020B6A8_21();
extern "C" void _s8020B6A8_22();
extern "C" void f_8020B6A8() {}
