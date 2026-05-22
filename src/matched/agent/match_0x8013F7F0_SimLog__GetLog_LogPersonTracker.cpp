// 0x8013F7F0 SimLog::GetLog(LogPersonTracker (748 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 20,0x30(1); stw 0,0x64(1); mr 28,3; mr 30,4; mr 21,28; lwzu 31,0x4(21); mr 29,21; b 1f; 0:; addi 31,31,32; 1:; lwz 0,0x4(29); cmpw 31,0; beq 2f; mr 3,31; mr 4,30; bl _s8013F7F0_0; cmpwi 3,0; beq 0b; lwz 0,0x4(29); cmpw 31,0; bne 27f; 2:; mr 4,30; addi 3,1,8; bl _s8013F7F0_1; lwz 3,0x4(29); addi 27,1,8; lwz 0,0xc(29); mr 20,27; cmpw 3,0; beq 3f; mr 4,20; bl _s8013F7F0_2; lwz 9,0x4(29); addi 23,1,24; addi 9,9,32; stw 9,0x4(29); b 22f; 3:; lwz 0,0x4(28); li 9,1; mr 28,3; stw 9,0x2c(1); subf 0,0,28; addi 11,1,44; srawi 3,0,5; addi 9,1,40; stw 3,0x28(1); cmplwi 3,1; bge 4f; mr 9,11; 4:; lwz 0,0x0(9); add. 0,3,0; beq 6f; rlwinm 0,0,5,0,26; mr 24,0; cmplwi 0,128; ble 5f; mr 3,24; bl _s8013F7F0_3; b 7f; 5:; mr 3,24; bl _s8013F7F0_4; b 7f; 6:; li 3,0; li 24,0; 7:; mr 30,3; lwz 31,0x0(29); mr 22,30; addi 23,1,24; cmpw 31,28; beq 9f; 8:; mr 3,30; mr 4,31; bl _s8013F7F0_5; addi 31,31,32; addi 30,30,32; cmpw 31,28; bne 8b; 9:; lwz 0,0x2c(1); cmpwi 0,1; bne 10f; mr 3,30; mr 4,27; bl _s8013F7F0_6; addi 30,30,32; b 13f; 10:; mr 31,30; mr. 30,0; beq 12f; 11:; mr 3,31; mr 4,27; bl _s8013F7F0_7; addi 31,31,32; addic. 30,30,-1; bne 11b; 12:; mr 30,31; 13:; lwz 25,0x4(29); lwz 3,0x0(29); cmpw 3,25; beq 19f; lis 27,-4370; ori 27,27,61167; 14:; addi 11,3,16; lwz 9,0x10(3); lwz 0,0x4(11); addi 26,3,32; addi 31,3,12; addi 28,3,8; cmpw 9,0; beq 16f; 15:; addi 9,9,60; cmpw 9,0; bne 15b; 16:; lwz 3,0x0(11); cmpwi 3,0; beq 18f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,27; srawi 0,0,2; mulli 4,0,60; cmplwi 4,128; ble 17f; bl _s8013F7F0_8; b 18f; 17:; bl _s8013F7F0_9; 18:; mr 3,31; li 4,2; bl _s8013F7F0_10; mr 3,28; li 4,2; bl _s8013F7F0_11; mr 3,26; cmpw 3,25; bne 14b; 19:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,5; beq 21f; rlwinm 4,0,5,0,26; cmplwi 4,128; ble 20f; bl _s8013F7F0_12; b 21f; 20:; bl _s8013F7F0_13; 21:; add 0,24,22; stw 22,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 22:; lwz 0,0x4(23); lwz 9,0x18(1); cmpw 9,0; beq 24f; 23:; addi 9,9,60; cmpw 9,0; bne 23b; 24:; lwz 3,0x0(23); cmpwi 3,0; beq 26f; lwz 0,0xc(23); lis 9,-4370; ori 9,9,61167; subf 0,3,0; mullw 0,0,9; srawi 0,0,2; mulli 4,0,60; cmplwi 4,128; ble 25f; bl _s8013F7F0_14; b 26f; 25:; bl _s8013F7F0_15; 26:; addi 3,20,12; li 4,2; bl _s8013F7F0_16; addi 3,20,8; li 4,2; bl _s8013F7F0_17; lwz 9,0x4(21); addi 31,9,-32; 27:; mr 3,31; lwz 0,0x64(1); mtspr 8,0; lmw 20,0x30(1); addi 1,1,96"
extern "C" void _s8013F7F0_0();
extern "C" void _s8013F7F0_1();
extern "C" void _s8013F7F0_2();
extern "C" void _s8013F7F0_3();
extern "C" void _s8013F7F0_4();
extern "C" void _s8013F7F0_5();
extern "C" void _s8013F7F0_6();
extern "C" void _s8013F7F0_7();
extern "C" void _s8013F7F0_8();
extern "C" void _s8013F7F0_9();
extern "C" void _s8013F7F0_10();
extern "C" void _s8013F7F0_11();
extern "C" void _s8013F7F0_12();
extern "C" void _s8013F7F0_13();
extern "C" void _s8013F7F0_14();
extern "C" void _s8013F7F0_15();
extern "C" void _s8013F7F0_16();
extern "C" void _s8013F7F0_17();
extern "C" void f_8013F7F0() {}
