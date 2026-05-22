// 0x8015B650 IFFBehaviorTree::SaveDataByID(ObjectDataID (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lwz 9,-21508(13); mr 29,3; mr 25,4; lwz 11,0x0(9); lwz 4,0x0(25); lha 3,0x38(11); lwz 0,0x3c(11); add 3,9,3; mtspr 8,0; blrl; mr 26,3; mr 3,29; bl _s8015B650_0; mulli 30,3,12; bl _s8015B650_1; li 4,12; li 5,0; bl _s8015B650_2; addi 30,30,12; mr 27,3; cmpwi 30,0; stw 30,0x0(27); beq 0f; bl _s8015B650_3; mr 4,30; li 5,0; bl _s8015B650_4; stw 3,0x4(27); b 1f; 0:; stw 30,0x4(27); 1:; li 0,1; lwz 31,0x4(27); stw 0,0x8(27); mr 3,29; bl _s8015B650_5; li 30,0; stb 3,0x6(31); li 28,0; mr 3,29; bl _s8015B650_6; sth 3,0x2(31); mr 3,29; bl _s8015B650_7; stb 3,0x5(31); mr 3,29; bl _s8015B650_8; sth 3,0x0(31); mr 3,29; bl _s8015B650_9; stw 3,0x8(31); mr 3,29; bl _s8015B650_10; stb 3,0x4(31); stb 30,0x7(31); addi 30,29,12; b 3f; 2:; mr 4,28; mr 3,29; bl _s8015B650_11; mulli 9,28,12; lwz 0,0x0(3); lwz 11,0x8(3); addi 28,28,1; lwz 10,0x4(3); add 9,9,31; stw 0,0xc(9); addi 9,9,12; stw 11,0x8(9); stw 10,0x4(9); 3:; mr 3,29; bl _s8015B650_12; cmpw 28,3; blt 2b; lwz 9,0xc(26); lis 5,16968; lha 6,0x4(25); mr 7,30; lha 3,0xf8(9); mr 4,27; lwz 0,0xfc(9); ori 5,5,16726; add 3,26,3; li 8,0; mtspr 8,0; blrl; mr 3,26; bl _s8015B650_13; cmpwi 3,0; bne 4f; lwz 9,0xc(26); mr 4,27; lwz 0,0x10c(9); lha 3,0x108(9); mtspr 8,0; add 3,26,3; blrl; mr 3,26; bl _s8015B650_14; lwz 9,0xc(26); lha 3,0x48(9); lwz 0,0x4c(9); add 3,26,3; mtspr 8,0; blrl; 4:; li 3,1; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8015B650_0();
extern "C" void _s8015B650_1();
extern "C" void _s8015B650_2();
extern "C" void _s8015B650_3();
extern "C" void _s8015B650_4();
extern "C" void _s8015B650_5();
extern "C" void _s8015B650_6();
extern "C" void _s8015B650_7();
extern "C" void _s8015B650_8();
extern "C" void _s8015B650_9();
extern "C" void _s8015B650_10();
extern "C" void _s8015B650_11();
extern "C" void _s8015B650_12();
extern "C" void _s8015B650_13();
extern "C" void _s8015B650_14();
extern "C" void f_8015B650() {}
