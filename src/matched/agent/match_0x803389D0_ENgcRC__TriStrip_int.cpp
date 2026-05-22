// 0x803389D0 ENgcRC::TriStrip(int, (780 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; mfcr 12; stmw 14,0x28(1); stw 0,0x74(1); stw 12,0x24(1); mr 31,3; mr 14,4; stw 6,0x1c(1); mr 15,7; mr 18,8; mr 16,9; mr 17,10; mr. 30,5; beq 13f; cmpwi 18,0; rlwinm 28,30,4,0,27; li 24,0; mfcr 29; beq 0f; rlwinm 24,30,3,0,28; 0:; li 22,0; cmpwi 3,17,0; beq cr3,1f; rlwinm 22,30,2,0,29; 1:; lwz 0,0x78(1); li 21,0; cmpwi 4,0,0; beq cr4,2f; rlwinm 21,30,2,0,29; 2:; li 20,0; cmpwi 2,16,0; beq cr2,3f; rlwinm 20,30,2,0,29; 3:; addi 0,28,31; mr 3,31; rlwinm 4,0,0,0,26; li 5,32; add 4,4,24; li 26,0; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,22; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,21; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,20; addi 4,4,31; rlwinm 4,4,0,0,26; bl _s803389D0_0; mr 25,3; mtcrf 128,29; add 9,25,28; addi 0,9,31; rlwinm 9,0,0,0,26; beq 4f; mr 26,9; add 9,26,24; addi 0,9,31; rlwinm 9,0,0,0,26; 4:; li 27,0; beq cr3,5f; mr 27,9; add 9,27,22; addi 0,9,31; rlwinm 9,0,0,0,26; 5:; li 29,0; beq cr4,6f; mr 29,9; add 9,29,21; addi 0,9,31; rlwinm 9,0,0,0,26; 6:; li 23,0; beq cr2,7f; mr 23,9; 7:; mr 4,15; mr 5,28; mr 3,25; li 19,0; crxor 6,6,6; bl _s803389D0_1; mr 4,18; mr 5,24; mr 3,26; crxor 6,6,6; bl _s803389D0_2; mr 4,17; mr 5,22; mr 3,27; crxor 6,6,6; bl _s803389D0_3; lwz 4,0x78(1); mr 5,21; mr 3,29; crxor 6,6,6; bl _s803389D0_4; mr 5,20; mr 4,16; mr 3,23; crxor 6,6,6; bl _s803389D0_5; mr 3,15; mr 4,28; bl _s803389D0_6; lwz 3,0x1c(1); rlwinm 4,14,1,0,30; bl _s803389D0_7; cmpwi 26,0; beq 8f; mr 4,24; mr 3,26; bl _s803389D0_8; 8:; cmpwi 23,0; beq 9f; mr 4,20; mr 3,23; bl _s803389D0_9; 9:; cmpwi 27,0; beq 10f; mr 4,22; mr 3,27; bl _s803389D0_10; 10:; cmpwi 29,0; beq 11f; mr 4,21; mr 3,29; bl _s803389D0_11; 11:; bl _s803389D0_12; lwz 0,-26320(13); cmpwi 0,0; beq 12f; bne cr4,12f; lwz 0,0xc(31); cmpwi 0,1; bne 12f; lwz 4,0x0(31); addi 0,1,24; lis 3,-32691; lwz 7,0x1c(1); stw 19,0x14(1); addi 3,3,21688; stw 0,0x10(1); mr 6,14; stw 23,0x8(1); li 5,152; stw 27,0xc(1); mr 8,30; mr 9,25; mr 10,26; bl _s803389D0_13; lwz 29,0x18(1); mr 19,3; 12:; lwz 9,0x70(31); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,4; lwz 0,0x54(11); add 0,0,30; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,42; stw 19,0x1c(3); stb 0,0x0(3); stw 30,0x4(3); stw 25,0x8(3); stw 26,0xc(3); stw 23,0x10(3); stw 27,0x14(3); stw 29,0x18(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 13:; lwz 0,0x74(1); lwz 12,0x24(1); mtspr 8,0; lmw 14,0x28(1); mtcrf 56,12; addi 1,1,112"
extern "C" void _s803389D0_0();
extern "C" void _s803389D0_1();
extern "C" void _s803389D0_2();
extern "C" void _s803389D0_3();
extern "C" void _s803389D0_4();
extern "C" void _s803389D0_5();
extern "C" void _s803389D0_6();
extern "C" void _s803389D0_7();
extern "C" void _s803389D0_8();
extern "C" void _s803389D0_9();
extern "C" void _s803389D0_10();
extern "C" void _s803389D0_11();
extern "C" void _s803389D0_12();
extern "C" void _s803389D0_13();
extern "C" void f_803389D0() {}
