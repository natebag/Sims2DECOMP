// 0x80338484 ENgcRC::TriStrip(int, (852 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; mfcr 12; stmw 14,0x20(1); stw 0,0x6c(1); stw 12,0x1c(1); mr 31,3; mr 14,5; mr 25,6; mr 21,7; mr 24,8; mr 22,9; mr 15,10; mr. 30,4; beq 16f; lwz 0,0xc(31); cmpwi 0,0; bne 0f; lwz 9,0x0(31); lis 3,-32691; addi 3,3,21688; mr 4,30; lwz 0,0x54(9); add 0,0,30; stw 0,0x54(9); li 10,0; mr 9,22; stw 15,0x8(1); bl _s80338484_0; b 16f; 0:; cmpwi 25,0; rlwinm 29,30,4,0,27; li 20,0; mfcr 27; cmpwi 2,15,0; beq 1f; mr 20,29; bne cr2,1f; rlwinm 20,30,3,0,28; 1:; cmpwi 7,24,0; li 18,0; mfcr 28; rlwinm 28,28,28,0,3; mcrf cr0,cr7; beq 2f; rlwinm 18,30,2,0,29; 2:; li 16,0; cmpwi 4,22,0; beq cr4,3f; rlwinm 16,30,2,0,29; 3:; li 17,0; cmpwi 3,21,0; beq cr3,4f; rlwinm 17,30,2,0,29; 4:; addi 0,29,31; mr 3,31; rlwinm 4,0,0,0,26; li 5,32; add 4,4,20; li 23,0; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,18; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,16; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,17; addi 4,4,31; rlwinm 4,4,0,0,26; bl _s80338484_1; mr 26,3; mtcrf 128,27; add 9,26,29; addi 0,9,31; rlwinm 9,0,0,0,26; beq 5f; mr 23,9; add 9,23,20; addi 0,9,31; rlwinm 9,0,0,0,26; 5:; li 27,0; mtcrf 128,28; beq 6f; mr 27,9; add 9,27,18; addi 0,9,31; rlwinm 9,0,0,0,26; 6:; li 28,0; beq cr4,7f; mr 28,9; add 9,28,16; addi 0,9,31; rlwinm 9,0,0,0,26; 7:; li 19,0; beq cr3,8f; mr 19,9; 8:; mr 4,14; mr 5,29; mr 3,26; li 14,0; crxor 6,6,6; bl _s80338484_2; mr 4,25; mr 5,20; mr 3,23; crxor 6,6,6; bl _s80338484_3; mr 4,24; mr 5,18; mr 3,27; crxor 6,6,6; bl _s80338484_4; mr 4,22; mr 5,16; mr 3,28; crxor 6,6,6; bl _s80338484_5; mr 4,21; mr 5,17; mr 3,19; crxor 6,6,6; bl _s80338484_6; mr 4,29; mr 3,26; bl _s80338484_7; cmpwi 23,0; beq 9f; mr 4,20; mr 3,23; bl _s80338484_8; 9:; cmpwi 19,0; beq 10f; mr 4,17; mr 3,19; bl _s80338484_9; 10:; cmpwi 27,0; beq 11f; mr 4,18; mr 3,27; bl _s80338484_10; 11:; cmpwi 28,0; beq 12f; mr 4,16; mr 3,28; bl _s80338484_11; 12:; bl _s80338484_12; lwz 0,-26320(13); cmpwi 0,0; beq 13f; bne cr4,13f; lwz 4,0x0(31); addi 0,1,16; lis 3,-32691; stw 0,0x8(1); addi 3,3,21688; stw 15,0xc(1); li 5,152; mr 6,30; mr 7,26; mr 8,23; mr 9,19; mr 10,27; bl _s80338484_13; lwz 28,0x10(1); mr 14,3; 13:; lwz 9,0x70(31); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,4; lwz 0,0x54(11); add 0,0,30; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,42; stw 30,0x4(3); stb 0,0x0(3); beq cr2,14f; li 0,1; stb 0,0x1(3); b 15f; 14:; stb 15,0x1(3); 15:; stw 14,0x1c(3); stw 26,0x8(3); stw 23,0xc(3); stw 19,0x10(3); stw 27,0x14(3); stw 28,0x18(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 16:; lwz 0,0x6c(1); lwz 12,0x1c(1); mtspr 8,0; lmw 14,0x20(1); mtcrf 56,12; addi 1,1,104"
extern "C" void _s80338484_0();
extern "C" void _s80338484_1();
extern "C" void _s80338484_2();
extern "C" void _s80338484_3();
extern "C" void _s80338484_4();
extern "C" void _s80338484_5();
extern "C" void _s80338484_6();
extern "C" void _s80338484_7();
extern "C" void _s80338484_8();
extern "C" void _s80338484_9();
extern "C" void _s80338484_10();
extern "C" void _s80338484_11();
extern "C" void _s80338484_12();
extern "C" void _s80338484_13();
extern "C" void f_80338484() {}
