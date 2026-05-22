// 0x80043388 HoodManager::EvictFamily(int, (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-360(1); mfspr 0,8; mfcr 12; stmw 22,0x140(1); stw 0,0x16c(1); stw 12,0x13c(1); mr 22,3; mr 30,4; addi 27,22,1; lwz 3,-32056(13); li 5,0; li 6,0; mr 4,27; li 24,0; bl _s80043388_0; lwz 3,-32056(13); mr 4,27; bl _s80043388_1; lis 3,1; ori 3,3,24584; bl _s80043388_2; bl _s80043388_3; lwz 4,-32056(13); mr 26,3; bl _s80043388_4; lwz 3,-32056(13); mr 4,27; bl _s80043388_5; cmpwi 30,0; beq 0f; stw 24,0x8(1); addi 30,1,8; li 0,-1; addi 4,1,36; li 5,128; addi 3,1,28; stw 24,0xc(30); stw 0,0x10(30); stw 24,0x4(30); stw 24,0x8(30); bl _s80043388_6; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; mr 9,3; lwz 4,-32056(13); mr 6,30; stw 27,0x70(9); mr 5,27; bl _s80043388_7; lwz 24,0x14(1); 0:; addis 30,26,1; li 28,0; lwz 0,0x6004(30); mr 23,30; cmpwi 4,26,0; cmpw 28,0; bge 6f; li 25,1; addi 31,30,-32740; li 29,0; 1:; addi 9,30,-32744; lwzx 9,9,29; cmpwi 9,0; beq 5f; lwz 9,0x38(9); cmpwi 9,0; beq 5f; lha 0,0x12(9); cmpwi 0,4; beq 3f; bgt 2f; cmpwi 0,2; bgt 5f; cmpwi 0,1; blt 5f; b 4f; 2:; cmpwi 0,34; beq 4f; b 5f; 3:; lwz 3,0x1c(9); bl _s80043388_8; cmpwi 3,0; beq 5f; addi 9,30,-32740; stwx 25,9,29; b 5f; 4:; lwz 9,-4(31); lwz 11,0x38(9); lwz 3,0x1c(11); bl _s80043388_9; cmpwi 3,0; beq 5f; stw 25,0x0(31); 5:; mr 30,23; addi 28,28,1; lwz 0,0x6004(30); addi 31,31,28; addi 29,29,28; cmpw 28,0; blt 1b; 6:; lwz 4,-32056(13); mr 3,26; lwz 5,-32040(13); bl _s80043388_10; lwz 3,-32056(13); mr 4,27; li 5,0; bl _s80043388_11; lwz 3,-32056(13); mr 4,27; bl _s80043388_12; mr 3,22; mr 4,24; bl _s80043388_13; beq cr4,7f; mr 3,26; li 4,3; bl _s80043388_14; 7:; lwz 0,0x16c(1); lwz 12,0x13c(1); mtspr 8,0; lmw 22,0x140(1); mtcrf 8,12; addi 1,1,360"
extern "C" void _s80043388_0();
extern "C" void _s80043388_1();
extern "C" void _s80043388_2();
extern "C" void _s80043388_3();
extern "C" void _s80043388_4();
extern "C" void _s80043388_5();
extern "C" void _s80043388_6();
extern "C" void _s80043388_7();
extern "C" void _s80043388_8();
extern "C" void _s80043388_9();
extern "C" void _s80043388_10();
extern "C" void _s80043388_11();
extern "C" void _s80043388_12();
extern "C" void _s80043388_13();
extern "C" void _s80043388_14();
extern "C" void f_80043388() {}
