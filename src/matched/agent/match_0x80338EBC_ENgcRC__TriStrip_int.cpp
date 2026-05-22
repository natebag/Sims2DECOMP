// 0x80338EBC ENgcRC::TriStrip(int, (776 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; mfcr 12; stmw 14,0x28(1); stw 0,0x74(1); stw 12,0x24(1); mr 30,3; mr 14,5; mr 19,6; mr 15,7; mr 18,8; mr 17,9; stw 10,0x1c(1); mr. 31,4; beq 13f; rlwinm 29,31,3,0,28; cmpwi 19,0; li 25,0; mr 16,29; mfcr 28; beq 0f; cmpwi 10,0; mr 25,16; bne 0f; rlwinm 25,31,2,0,29; 0:; li 22,0; cmpwi 3,18,0; beq cr3,1f; rlwinm 22,31,2,0,29; 1:; li 21,0; cmpwi 4,17,0; beq cr4,2f; rlwinm 21,31,2,0,29; 2:; li 20,0; cmpwi 2,15,0; beq cr2,3f; rlwinm 20,31,2,0,29; 3:; addi 0,29,31; mr 3,30; rlwinm 4,0,0,0,26; li 5,32; add 4,4,25; li 26,0; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,22; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,21; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,20; addi 4,4,31; rlwinm 4,4,0,0,26; bl _s80338EBC_0; mr 27,3; mtcrf 128,28; add 9,27,29; addi 0,9,31; rlwinm 9,0,0,0,26; beq 4f; mr 26,9; add 9,26,25; addi 0,9,31; rlwinm 9,0,0,0,26; 4:; li 28,0; beq cr3,5f; mr 28,9; add 9,28,22; addi 0,9,31; rlwinm 9,0,0,0,26; 5:; li 23,0; beq cr4,6f; mr 23,9; add 9,23,21; addi 0,9,31; rlwinm 9,0,0,0,26; 6:; li 24,0; beq cr2,7f; mr 24,9; 7:; mr 5,29; mr 4,14; mr 3,27; li 29,0; crxor 6,6,6; bl _s80338EBC_1; mr 4,19; mr 5,25; mr 3,26; crxor 6,6,6; bl _s80338EBC_2; mr 4,18; mr 5,22; mr 3,28; crxor 6,6,6; bl _s80338EBC_3; mr 4,17; mr 5,21; mr 3,23; crxor 6,6,6; bl _s80338EBC_4; mr 4,15; mr 5,20; mr 3,24; crxor 6,6,6; bl _s80338EBC_5; mr 4,16; stw 29,0x18(1); mr 3,27; bl _s80338EBC_6; cmpwi 26,0; beq 8f; mr 4,25; mr 3,26; bl _s80338EBC_7; 8:; cmpwi 24,0; beq 9f; mr 4,20; mr 3,24; bl _s80338EBC_8; 9:; cmpwi 28,0; beq 10f; mr 4,22; mr 3,28; bl _s80338EBC_9; 10:; cmpwi 23,0; beq 11f; mr 4,21; mr 3,23; bl _s80338EBC_10; 11:; bl _s80338EBC_11; lwz 0,-26320(13); cmpwi 0,0; beq 12f; bne cr4,12f; lwz 4,0x0(30); addi 0,1,24; stw 0,0x8(1); lis 3,-32691; lwz 0,0x1c(1); addi 3,3,21688; stw 29,0x10(1); li 5,152; stw 0,0xc(1); mr 6,31; mr 7,27; mr 8,26; mr 9,24; mr 10,28; bl _s80338EBC_12; mr 29,3; 12:; lwz 9,0x70(30); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x0(30); li 4,4; lwz 0,0x54(11); add 0,0,31; stw 0,0x54(11); lwz 9,0x70(30); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,56; sth 31,0x2(3); stb 0,0x0(3); lwz 0,0x18(1); stw 29,0x1c(3); stw 0,0x4(3); stw 27,0x8(3); stw 26,0xc(3); stw 24,0x10(3); stw 28,0x14(3); stw 23,0x18(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; 13:; lwz 0,0x74(1); lwz 12,0x24(1); mtspr 8,0; lmw 14,0x28(1); mtcrf 56,12; addi 1,1,112"
extern "C" void _s80338EBC_0();
extern "C" void _s80338EBC_1();
extern "C" void _s80338EBC_2();
extern "C" void _s80338EBC_3();
extern "C" void _s80338EBC_4();
extern "C" void _s80338EBC_5();
extern "C" void _s80338EBC_6();
extern "C" void _s80338EBC_7();
extern "C" void _s80338EBC_8();
extern "C" void _s80338EBC_9();
extern "C" void _s80338EBC_10();
extern "C" void _s80338EBC_11();
extern "C" void _s80338EBC_12();
extern "C" void f_80338EBC() {}
