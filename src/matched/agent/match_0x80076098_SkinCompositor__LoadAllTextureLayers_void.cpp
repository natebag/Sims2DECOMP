// 0x80076098 SkinCompositor::LoadAllTextureLayers(void) (1164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-920(1); mfspr 0,8; stmw 20,0x368(1); stw 0,0x39c(1); mr 31,3; li 5,104; li 4,0; addi 3,1,8; bl _s80076098_0; li 26,0; lbz 5,0x1c(31); cmpwi 5,1; beq 2f; bgt 0f; cmpwi 5,0; beq 1f; b 7f; 0:; cmpwi 5,2; beq 3f; cmpwi 5,3; beq 6f; b 7f; 1:; addi 9,1,8; li 10,4; li 11,11; li 6,16; stwx 11,9,10; li 0,18; stwx 0,9,6; li 7,8; li 8,14; li 26,5; stwx 8,9,7; stw 7,0x8(1); stw 6,0xc(9); b 7f; 2:; addi 30,1,8; li 9,4; li 0,9; li 11,7; stwx 0,30,9; li 26,2; stw 11,0x8(1); lwz 9,0x14(31); lwz 3,0x24(31); lbz 4,0xb4(9); lwz 5,0xb8(9); extsb 4,4; bl _s80076098_1; cmpwi 3,0; bne 7f; li 0,12; li 26,3; stw 0,0x8(30); b 7f; 3:; stw 5,0x8(1); addi 9,1,8; li 11,4; li 0,3; stwx 0,9,11; li 10,5; stw 11,0x8(9); li 29,12; stwx 10,9,29; li 8,6; li 7,19; li 6,25; stw 8,0x10(9); mr 30,9; stw 7,0x14(9); li 26,7; stw 6,0x18(9); lwz 11,0x14(31); lwz 3,0x24(31); lbz 4,0xb4(11); lwz 5,0xb8(11); extsb 4,4; bl _s80076098_2; cmpwi 3,0; beq 4f; stw 29,0x1c(30); li 26,8; b 5f; 4:; lwz 9,0x14(31); lwz 3,0x24(31); lbz 4,0xb4(9); lwz 5,0xbc(9); extsb 4,4; bl _s80076098_3; cmpwi 3,0; beq 5f; li 0,13; li 26,8; stw 0,0x1c(30); 5:; rlwinm 9,26,2,0,29; li 0,0; stwx 0,30,9; addi 26,26,1; rlwinm 11,26,2,0,29; li 0,20; stwx 0,30,11; addi 26,26,1; rlwinm 9,26,2,0,29; li 0,21; stwx 0,30,9; addi 26,26,1; rlwinm 11,26,2,0,29; li 0,22; stwx 0,30,11; addi 26,26,1; rlwinm 10,26,2,0,29; li 0,23; addi 26,26,1; stwx 0,30,10; rlwinm 9,26,2,0,29; li 0,24; stwx 0,30,9; addi 26,26,1; b 7f; 6:; li 0,15; li 26,1; stw 0,0x8(1); 7:; addi 6,1,128; addi 7,1,232; li 30,0; mr 20,6; mr 21,7; mr 3,31; stw 30,0x350(1); addi 4,1,848; addi 5,1,112; bl _s80076098_4; lbz 0,0x1c(31); cmpwi 0,2; bne 8f; lwz 3,0x8(31); stw 30,0x358(1); stw 30,0x354(1); bl _s80076098_5; lwz 11,0x8(31); mr 30,3; li 4,2; lwz 9,0x24(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x8(31); addi 5,1,852; addi 6,1,856; li 4,0; lwz 9,0x24(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lhz 5,0x0(31); li 4,0; mullw 5,5,5; rlwinm 5,5,2,0,29; bl _s80076098_6; lwz 11,0x8(31); lwz 9,0x24(11); lha 3,0x70(9); lwz 0,0x74(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,0x8(31); mr 4,30; bl _s80076098_7; b 9f; 8:; lwz 3,0x350(1); lwz 4,0x8(31); bl _s80076098_8; 9:; lwz 3,0x8(31); li 28,15; bl _s80076098_9; lwz 11,0x8(31); mr 22,3; li 4,0; lwz 9,0x24(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x8(31); addi 5,1,860; li 4,0; addi 6,1,864; lwz 9,0x24(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lhz 5,0x0(31); li 4,0; stw 3,0xc(31); mullw 5,5,5; lwz 3,0x20(31); bl _s80076098_10; lbz 0,0x1c(31); cmpwi 0,1; beq 12f; bgt 10f; cmpwi 0,0; beq 11f; b 14f; 10:; cmpwi 0,3; beq 13f; b 14f; 11:; lwz 5,0x70(1); li 28,8; b 15f; 12:; lwz 5,0x74(1); li 28,7; b 15f; 13:; lwz 5,0x78(1); b 15f; 14:; li 5,0; 15:; cmpwi 5,0; beq 16f; mr 4,28; mr 3,31; li 6,0; bl _s80076098_11; 16:; li 27,0; cmplw 27,26; bge 20f; addi 24,1,8; addi 25,1,336; lis 23,-32707; 17:; rlwinm 0,27,2,0,29; lwzx 28,24,0; rlwinm 6,28,2,0,29; lwzx 5,20,6; cmpwi 5,0; beq 19f; lwzx 6,21,6; cmpw 5,6; bne 18f; lwz 3,0x24(31); mr 4,28; bl _s80076098_12; mr 29,3; mr 4,28; lwz 3,0x14(31); bl _s80076098_13; mr 30,3; mr 4,28; lwz 3,0x14(31); bl _s80076098_14; mr 8,3; mr 6,29; mr 7,30; mr 3,25; li 4,512; addi 5,23,23204; crxor 6,6,6; bl _s80076098_15; b 19f; 18:; mr 4,28; mr 3,31; bl _s80076098_16; 19:; addi 0,27,1; rlwinm 27,0,0,24,31; cmplw 27,26; blt 17b; 20:; mr 3,31; bl _s80076098_17; lwz 11,0x8(31); lwz 9,0x24(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x8(31); mr 4,22; bl _s80076098_18; li 0,0; stw 0,0xc(31); lwz 0,0x39c(1); mtspr 8,0; lmw 20,0x368(1); addi 1,1,920"
extern "C" void _s80076098_0();
extern "C" void _s80076098_1();
extern "C" void _s80076098_2();
extern "C" void _s80076098_3();
extern "C" void _s80076098_4();
extern "C" void _s80076098_5();
extern "C" void _s80076098_6();
extern "C" void _s80076098_7();
extern "C" void _s80076098_8();
extern "C" void _s80076098_9();
extern "C" void _s80076098_10();
extern "C" void _s80076098_11();
extern "C" void _s80076098_12();
extern "C" void _s80076098_13();
extern "C" void _s80076098_14();
extern "C" void _s80076098_15();
extern "C" void _s80076098_16();
extern "C" void _s80076098_17();
extern "C" void _s80076098_18();
extern "C" void f_80076098() {}
