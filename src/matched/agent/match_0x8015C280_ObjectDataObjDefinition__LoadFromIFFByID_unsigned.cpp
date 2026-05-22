// 0x8015C280 ObjectDataObjDefinition::LoadFromIFFByID(unsigned (796 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 23,0x64(1); stw 0,0x8c(1); mr 25,3; mr 29,5; mr 30,4; bl _s8015C280_0; lwz 11,-21508(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 24,3; lis 4,20290; lwz 9,0xc(24); mr 5,29; ori 4,4,19012; li 6,0; lha 3,0x80(9); lwz 0,0x84(9); add 3,24,3; mtspr 8,0; blrl; mr. 23,3; bne 0f; li 3,0; b 20f; 0:; lwz 4,0x4(23); addi 30,1,8; mr 3,25; addi 31,25,4; bl _s8015C280_1; addi 4,30,8; li 5,64; mr 3,30; bl _s8015C280_2; lwz 9,0xc(24); mr 5,30; mr 4,23; lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,24,3; blrl; mr 3,30; bl _s8015C280_3; mr 29,3; bl _s8015C280_4; add 27,29,3; lwz 0,0x4(31); lwz 3,0x4(25); subf 30,29,27; subf 5,3,0; cmplw 30,5; bgt 2f; cmpwi 30,0; beq 1f; mr 4,29; mr 5,30; crxor 6,6,6; bl _s8015C280_5; 1:; lwz 0,0x4(25); lwz 29,0x4(31); add 30,0,30; cmpw 30,29; beq 19f; mr 3,30; mr 4,29; li 5,1; bl _s8015C280_6; lwz 0,0x4(31); subf 9,30,29; subf 0,9,0; b 18f; 2:; cmpwi 5,0; beq 3f; mr 4,29; crxor 6,6,6; bl _s8015C280_7; 3:; lwz 9,0x4(31); lwz 0,0x4(25); subf 9,0,9; add 29,29,9; cmpw 29,27; beq 19f; subf 30,29,27; li 0,-2; cmplw 30,0; stw 9,0x5c(1); bgt 4f; subfic 0,30,-2; cmplw 9,0; ble 5f; 4:; mr 3,31; bl _s8015C280_8; 5:; lwz 0,0x0(31); lwz 9,0xc(31); lwz 11,0x5c(1); subf 9,0,9; addi 9,9,-1; add 0,11,30; cmplw 0,9; ble 16f; cmplw 11,30; stw 30,0x50(1); addi 9,1,92; bge 6f; addi 9,1,80; 6:; lwz 0,0x0(9); add 0,11,0; addic. 26,0,1; beq 8f; cmplwi 26,128; ble 7f; mr 3,26; bl _s8015C280_9; mr 28,3; b 9f; 7:; mr 3,26; bl _s8015C280_10; mr 28,3; b 9f; 8:; li 28,0; 9:; lwz 4,0x0(31); lwz 30,0x4(31); cmpw 30,4; beq 10f; subf 30,4,30; mr 3,28; mr 5,30; bl _s8015C280_11; add 3,3,30; b 11f; 10:; mr 3,28; 11:; cmpw 27,29; beq 12f; subf 30,29,27; mr 4,29; mr 5,30; bl _s8015C280_12; add 30,3,30; b 13f; 12:; mr 30,3; 13:; li 0,0; stb 0,0x0(30); lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 4,3,0; beq 15f; cmplwi 4,128; ble 14f; bl _s8015C280_13; b 15f; 14:; bl _s8015C280_14; 15:; add 0,28,26; stw 30,0x4(31); stw 0,0xc(31); stw 28,0x0(31); b 19f; 16:; lwz 9,0x4(31); addi 4,29,1; cmpw 27,4; addi 3,9,1; beq 17f; subf 5,4,27; bl _s8015C280_15; 17:; lwz 9,0x4(31); li 0,0; stbx 0,9,30; lbz 11,0x0(29); lwz 9,0x4(31); stb 11,0x0(9); lwz 0,0x4(31); add 0,0,30; 18:; stw 0,0x4(31); 19:; lwz 9,0xc(24); mr 4,23; addi 5,1,88; li 0,0; lha 3,0xb0(9); lwz 9,0xb4(9); add 3,24,3; sth 0,0x58(1); mtspr 8,9; blrl; lha 4,0x58(1); mr 3,25; bl _s8015C280_16; li 3,1; 20:; lwz 0,0x8c(1); mtspr 8,0; lmw 23,0x64(1); addi 1,1,136"
extern "C" void _s8015C280_0();
extern "C" void _s8015C280_1();
extern "C" void _s8015C280_2();
extern "C" void _s8015C280_3();
extern "C" void _s8015C280_4();
extern "C" void _s8015C280_5();
extern "C" void _s8015C280_6();
extern "C" void _s8015C280_7();
extern "C" void _s8015C280_8();
extern "C" void _s8015C280_9();
extern "C" void _s8015C280_10();
extern "C" void _s8015C280_11();
extern "C" void _s8015C280_12();
extern "C" void _s8015C280_13();
extern "C" void _s8015C280_14();
extern "C" void _s8015C280_15();
extern "C" void _s8015C280_16();
extern "C" void f_8015C280() {}
