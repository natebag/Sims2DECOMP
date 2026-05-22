// 0x8003AAB0 FlashPiMenu::ChooseAction(cXObject (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 26,3; mr 25,5; mr 24,6; mr. 23,4; bne 0f; li 0,1; stw 0,0x4(26); bl _s8003AAB0_0; li 3,1; b 16f; 0:; cmpwi 25,0; bne 1f; li 3,0; b 16f; 1:; lwz 31,-21484(13); li 3,0; cmpwi 31,0; beq 16f; mr 3,25; li 28,0; bl _s8003AAB0_1; mr 27,3; mr 3,25; bl _s8003AAB0_2; mr. 3,3; beq 2f; lwz 28,0x0(3); 2:; lwz 9,0x0(31); li 29,0; li 30,0; lha 3,0x98(9); lwz 0,0x9c(9); add 3,31,3; mtspr 8,0; blrl; mr 11,3; cmpwi 24,0; mfcr 24; b 4f; 3:; lwz 9,0x4(11); lha 3,0x490(9); lwz 0,0x494(9); add 3,11,3; mtspr 8,0; blrl; mr 11,3; 4:; cmpwi 11,0; beq 9f; cmpw 28,27; bne 5f; cmpw 11,28; bne 8f; li 29,1; b 7f; 5:; cmpw 11,27; bne 6f; li 29,1; b 8f; 6:; cmpw 11,28; bne 8f; 7:; li 30,1; 8:; cmpwi 30,0; beq 3b; cmpwi 29,0; beq 3b; 9:; cmpwi 30,0; beq 10f; cmpwi 29,0; beq 10f; bl _s8003AAB0_3; lwz 4,0x8(26); li 5,-1; bl _s8003AAB0_4; mr. 11,3; beq 10f; lwz 9,0x5c(11); mr 4,25; lha 3,0xa8(9); lwz 0,0xac(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; b 11f; 10:; li 30,0; 11:; lwz 0,-31536(13); cmpwi 0,0; bne 12f; li 3,120; bl _s8003AAB0_5; bl _s8003AAB0_6; stw 3,-31536(13); 12:; lis 4,28199; cmpwi 30,0; lwz 3,-31536(13); mfcr 31; ori 4,4,30903; beq 13f; lis 4,14155; ori 4,4,56554; 13:; bl _s8003AAB0_7; mtcrf 128,31; beq 14f; lwz 0,0x0(26); cmpw 0,23; bne 14f; li 0,0; stw 0,0x0(26); 14:; mtcrf 128,24; beq 15f; li 0,1; mr 3,26; stw 0,0x4(26); bl _s8003AAB0_8; 15:; mr 3,30; 16:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s8003AAB0_0();
extern "C" void _s8003AAB0_1();
extern "C" void _s8003AAB0_2();
extern "C" void _s8003AAB0_3();
extern "C" void _s8003AAB0_4();
extern "C" void _s8003AAB0_5();
extern "C" void _s8003AAB0_6();
extern "C" void _s8003AAB0_7();
extern "C" void _s8003AAB0_8();
extern "C" void f_8003AAB0() {}
