// 0x8002D88C ERoom::~ERoom(void) (1124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 17,0xc(1); stw 0,0x4c(1); mr 29,3; mr 17,4; addi 31,29,4; lwz 9,0x4(31); b 2f; 0:; lwz 0,0x8(31); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 1f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 1:; mr 9,30; 2:; li 0,1; cmpwi 9,0; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; mr 3,31; addi 31,29,16; bl _s8002D88C_0; lwz 9,0x4(31); addi 18,29,4; mr 19,31; addi 22,29,28; addi 23,29,40; addi 24,29,52; addi 25,29,64; addi 26,29,76; addi 27,29,88; addi 28,29,100; addi 20,29,148; addi 21,29,160; b 6f; 4:; lwz 0,0x8(31); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 5f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 5:; mr 9,30; 6:; li 0,1; cmpwi 9,0; bne 7f; li 0,0; 7:; cmpwi 0,0; bne 4b; mr 3,31; bl _s8002D88C_1; lwz 9,0x4(22); b 10f; 8:; lwz 0,0x8(22); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 9f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 9:; mr 9,30; 10:; li 0,1; cmpwi 9,0; bne 11f; li 0,0; 11:; cmpwi 0,0; bne 8b; mr 3,22; bl _s8002D88C_2; lwz 9,0x4(23); b 14f; 12:; lwz 0,0x8(23); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 13f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 13:; mr 9,30; 14:; li 0,1; cmpwi 9,0; bne 15f; li 0,0; 15:; cmpwi 0,0; bne 12b; mr 3,23; bl _s8002D88C_3; lwz 9,0x4(24); b 18f; 16:; lwz 0,0x8(24); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 17f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 17:; mr 9,30; 18:; li 0,1; cmpwi 9,0; bne 19f; li 0,0; 19:; cmpwi 0,0; bne 16b; mr 3,24; bl _s8002D88C_4; lwz 9,0x4(25); b 22f; 20:; lwz 0,0x8(25); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 21f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 21:; mr 9,30; 22:; li 0,1; cmpwi 9,0; bne 23f; li 0,0; 23:; cmpwi 0,0; bne 20b; mr 3,25; bl _s8002D88C_5; lwz 9,0x4(26); b 26f; 24:; lwz 0,0x8(26); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 25f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 25:; mr 9,30; 26:; li 0,1; cmpwi 9,0; bne 27f; li 0,0; 27:; cmpwi 0,0; bne 24b; mr 3,26; bl _s8002D88C_6; lwz 9,0x4(27); b 30f; 28:; lwz 0,0x8(27); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 29f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 29:; mr 9,30; 30:; li 0,1; cmpwi 9,0; bne 31f; li 0,0; 31:; cmpwi 0,0; bne 28b; mr 3,27; bl _s8002D88C_7; lwz 9,0x4(28); b 34f; 32:; lwz 0,0x8(28); lwz 11,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 33f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 33:; mr 9,30; 34:; li 0,1; cmpwi 9,0; bne 35f; li 0,0; 35:; cmpwi 0,0; bne 32b; mr 3,28; bl _s8002D88C_8; lwz 9,0x94(29); b 38f; 36:; lwz 30,0x1c(9); lwz 31,0x10(9); cmpwi 30,0; beq 37f; mr 3,30; bl _s8002D88C_9; mr 3,30; bl _s8002D88C_10; 37:; mr 9,31; 38:; li 0,1; cmpwi 9,0; bne 39f; li 0,0; 39:; cmpwi 0,0; bne 36b; mr 3,20; bl _s8002D88C_11; lwz 30,0xa0(29); b 41f; 40:; lwz 3,0x1c(30); lwz 30,0x10(30); bl _s8002D88C_12; 41:; li 31,1; cmpwi 30,0; bne 42f; li 31,0; 42:; cmpwi 31,0; bne 40b; mr 3,21; bl _s8002D88C_13; stw 31,0x0(29); mr 3,21; bl _s8002D88C_14; mr 3,20; bl _s8002D88C_15; mr 3,28; bl _s8002D88C_16; mr 3,27; bl _s8002D88C_17; mr 3,26; bl _s8002D88C_18; mr 3,25; bl _s8002D88C_19; mr 3,24; bl _s8002D88C_20; mr 3,23; bl _s8002D88C_21; mr 3,22; bl _s8002D88C_22; mr 3,19; bl _s8002D88C_23; mr 3,18; bl _s8002D88C_24; andi. 0,17,1; beq 43f; mr 3,29; bl _s8002D88C_25; 43:; lwz 0,0x4c(1); mtspr 8,0; lmw 17,0xc(1); addi 1,1,72"
extern "C" void _s8002D88C_0();
extern "C" void _s8002D88C_1();
extern "C" void _s8002D88C_2();
extern "C" void _s8002D88C_3();
extern "C" void _s8002D88C_4();
extern "C" void _s8002D88C_5();
extern "C" void _s8002D88C_6();
extern "C" void _s8002D88C_7();
extern "C" void _s8002D88C_8();
extern "C" void _s8002D88C_9();
extern "C" void _s8002D88C_10();
extern "C" void _s8002D88C_11();
extern "C" void _s8002D88C_12();
extern "C" void _s8002D88C_13();
extern "C" void _s8002D88C_14();
extern "C" void _s8002D88C_15();
extern "C" void _s8002D88C_16();
extern "C" void _s8002D88C_17();
extern "C" void _s8002D88C_18();
extern "C" void _s8002D88C_19();
extern "C" void _s8002D88C_20();
extern "C" void _s8002D88C_21();
extern "C" void _s8002D88C_22();
extern "C" void _s8002D88C_23();
extern "C" void _s8002D88C_24();
extern "C" void _s8002D88C_25();
extern "C" void f_8002D88C() {}
