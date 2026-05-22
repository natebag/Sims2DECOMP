// 0x80339928 ENgcRC::TriStripDL(unsigned (560 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 16,0x10(1); stw 0,0x54(1); stw 12,0xc(1); mr 30,3; mr 16,4; mr 31,6; mr 18,7; mr 21,8; mr 20,9; mr 19,10; mr. 17,5; blt 9f; rlwinm 29,31,4,0,27; li 27,0; cmpwi 4,21,0; beq cr4,0f; rlwinm 27,31,3,0,28; 0:; li 26,0; cmpwi 3,20,0; beq cr3,1f; rlwinm 26,31,2,0,29; 1:; li 23,0; cmpwi 2,19,0; beq cr2,2f; rlwinm 23,31,2,0,29; 2:; addi 0,29,31; mr 3,30; rlwinm 4,0,0,0,26; li 5,32; add 4,4,27; li 22,0; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,26; addi 0,4,31; rlwinm 4,0,0,0,26; add 4,4,23; addi 4,4,31; rlwinm 4,4,0,0,26; bl _s80339928_0; mr 28,3; add 9,28,29; addi 0,9,31; rlwinm 9,0,0,0,26; beq cr4,3f; mr 22,9; add 9,22,27; addi 0,9,31; rlwinm 9,0,0,0,26; 3:; li 25,0; beq cr3,4f; mr 25,9; add 9,25,26; addi 0,9,31; rlwinm 9,0,0,0,26; 4:; li 24,0; beq cr2,5f; mr 24,9; 5:; mr 4,18; mr 5,29; mr 3,28; bl _s80339928_1; mr 4,21; mr 5,27; mr 3,22; bl _s80339928_2; mr 4,20; mr 5,26; mr 3,25; bl _s80339928_3; mr 5,23; mr 4,19; mr 3,24; bl _s80339928_4; mr 4,29; mr 3,28; bl _s80339928_5; mr 3,16; mr 4,17; bl _s80339928_6; cmpwi 22,0; beq 6f; mr 3,22; rlwinm 4,31,3,0,28; bl _s80339928_7; 6:; cmpwi 25,0; beq 7f; mr 3,25; rlwinm 4,31,2,0,29; bl _s80339928_8; 7:; cmpwi 24,0; beq 8f; mr 3,24; rlwinm 4,31,2,0,29; bl _s80339928_9; 8:; bl _s80339928_10; lwz 9,0x70(30); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x0(30); li 4,4; lwz 0,0x54(11); add 0,0,31; stw 0,0x54(11); lwz 9,0x70(30); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,68; stw 17,0x1c(3); stb 0,0x0(3); stw 31,0x4(3); stw 28,0x8(3); stw 22,0xc(3); stw 25,0x10(3); stw 24,0x14(3); stw 16,0x18(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; 9:; lwz 0,0x54(1); lwz 12,0xc(1); mtspr 8,0; lmw 16,0x10(1); mtcrf 56,12; addi 1,1,80"
extern "C" void _s80339928_0();
extern "C" void _s80339928_1();
extern "C" void _s80339928_2();
extern "C" void _s80339928_3();
extern "C" void _s80339928_4();
extern "C" void _s80339928_5();
extern "C" void _s80339928_6();
extern "C" void _s80339928_7();
extern "C" void _s80339928_8();
extern "C" void _s80339928_9();
extern "C" void _s80339928_10();
extern "C" void f_80339928() {}
