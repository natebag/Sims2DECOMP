// 0x803217D8 ArcFileInfo::Validate(void) (672 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-2096(1); mfspr 0,8; stmw 24,0x810(1); stw 0,0x834(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 3f; lwz 4,0x4(31); cmpwi 4,0; beq 3f; lwz 27,0x10(31); cmpwi 27,0; bne 3f; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0xa0(9); lwz 9,0xa4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 3f; lwz 11,-22652(13); addi 30,1,1032; lwz 4,0x4(31); addi 29,1,2056; lwz 9,0x0(11); mr 26,30; mr 24,29; lis 25,-32694; lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; mr 28,3; li 4,0; addi 3,1,8; li 5,1024; bl _s803217D8_0; li 4,0; li 5,1024; mr 3,30; bl _s803217D8_1; lwz 10,-22652(13); addi 5,1,8; stw 27,0xc(31); li 6,0; mr 4,28; li 7,1024; lwz 11,0x0(10); li 8,1; li 9,0; lwz 0,0x7c(11); lha 3,0x78(11); mtspr 8,0; add 3,10,3; blrl; mr 3,28; bl _s803217D8_2; lwz 0,0x14(3); lis 6,-32702; lis 3,-32694; lwz 5,0x0(31); stw 0,0x8(31); addi 3,3,-10620; addi 6,6,2876; mr 4,29; li 7,0; lis 8,-32768; li 9,0; bl _s803217D8_3; cmpwi 3,0; beq 3f; lwz 11,-22652(13); mr 5,26; lwz 4,0x808(1); li 6,0; lwz 9,0x0(11); li 7,1024; li 8,1; lwz 29,0x14(4); lwz 0,0x74(9); lha 3,0x70(9); li 9,0; mtspr 8,0; add 3,11,3; blrl; addi 3,1,8; mr 4,26; li 5,1024; bl _s803217D8_4; cmpwi 3,0; bne 1f; lwz 0,0x8(31); cmplwi 0,1024; bgt 0f; cmpw 29,0; bne 1f; stw 29,0xc(31); mr 3,31; bl _s803217D8_5; b 1f; 0:; rlwinm. 9,29,10,17,21; beq 2f; cmpw 29,0; beq 2f; 1:; addi 3,25,-10620; mr 4,24; bl _s803217D8_6; b 3f; 2:; addi 3,1,8; li 4,0; li 5,1024; addi 30,29,-1024; bl _s803217D8_7; li 4,0; li 5,1024; mr 3,26; bl _s803217D8_8; lwz 10,-22652(13); addi 5,1,8; mr 4,28; mr 6,30; lwz 11,0x0(10); li 7,1024; li 8,1; li 9,0; lwz 0,0x7c(11); lha 3,0x78(11); mtspr 8,0; add 3,10,3; blrl; lwz 10,-22652(13); mr 6,30; lwz 4,0x808(1); mr 5,26; lwz 11,0x0(10); li 7,1024; li 8,1; li 9,0; lha 3,0x70(11); lwz 0,0x74(11); add 3,10,3; mtspr 8,0; blrl; lis 3,-32694; mr 4,24; addi 3,3,-10620; bl _s803217D8_9; mr 4,26; addi 3,1,8; li 5,1024; bl _s803217D8_10; cmpwi 3,0; bne 3f; lwz 0,0x8(31); stw 29,0xc(31); cmpw 29,0; bne 3f; mr 3,31; bl _s803217D8_11; 3:; lwz 0,0x834(1); mtspr 8,0; lmw 24,0x810(1); addi 1,1,2096"
extern "C" void _s803217D8_0();
extern "C" void _s803217D8_1();
extern "C" void _s803217D8_2();
extern "C" void _s803217D8_3();
extern "C" void _s803217D8_4();
extern "C" void _s803217D8_5();
extern "C" void _s803217D8_6();
extern "C" void _s803217D8_7();
extern "C" void _s803217D8_8();
extern "C" void _s803217D8_9();
extern "C" void _s803217D8_10();
extern "C" void _s803217D8_11();
extern "C" void f_803217D8() {}
