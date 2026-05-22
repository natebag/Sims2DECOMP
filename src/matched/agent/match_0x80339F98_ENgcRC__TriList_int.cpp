// 0x80339F98 ENgcRC::TriList(int, (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 21,0x24(1); stw 0,0x54(1); stw 12,0x20(1); mr 30,3; mr 23,5; mr 27,6; mr 26,7; mr 25,8; mr 28,9; mr 22,10; mr. 24,4; beq 9f; rlwinm 29,24,3,0,28; mr 4,23; mr 5,29; bl _s80339F98_0; cmpwi 3,22,0; mr 23,3; mr 5,29; rlwinm 31,24,2,0,29; bne cr3,0f; mr 5,31; 0:; mr 4,27; mr 3,30; bl _s80339F98_1; li 21,0; mr 27,3; mr 4,26; mr 5,31; mr 3,30; bl _s80339F98_2; mr 26,3; mr 4,25; mr 5,31; mr 3,30; bl _s80339F98_3; mr 25,3; mr 4,28; mr 5,31; mr 3,30; bl _s80339F98_4; mr 28,3; mr 4,29; mr 3,23; bl _s80339F98_5; cmpwi 27,0; beq 2f; mr 4,31; beq cr3,1f; mr 4,29; 1:; mr 3,27; bl _s80339F98_6; 2:; cmpwi 26,0; beq 3f; mr 3,26; mr 4,31; bl _s80339F98_7; 3:; cmpwi 25,0; beq 4f; mr 3,25; mr 4,31; bl _s80339F98_8; 4:; cmpwi 4,28,0; beq cr4,5f; mr 4,31; mr 3,28; bl _s80339F98_9; 5:; bl _s80339F98_10; lwz 0,-26320(13); cmpwi 0,0; beq 6f; bne cr4,6f; lwz 4,0x0(30); addi 0,1,24; lis 3,-32691; stw 28,0x10(1); stw 0,0x8(1); addi 3,3,21688; stw 22,0xc(1); li 5,144; mr 6,24; mr 7,23; mr 8,27; mr 9,26; mr 10,25; bl _s80339F98_11; lwz 28,0x18(1); mr 21,3; 6:; lwz 9,0x70(30); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x0(30); li 4,4; lwz 0,0x54(11); add 0,0,24; stw 0,0x54(11); lwz 9,0x70(30); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,69; stw 24,0x4(3); stb 0,0x0(3); beq cr3,7f; li 0,1; stb 0,0x1(3); b 8f; 7:; stb 22,0x1(3); 8:; stw 21,0x1c(3); stw 23,0x8(3); stw 27,0xc(3); stw 26,0x10(3); stw 25,0x14(3); stw 28,0x18(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; 9:; lwz 0,0x54(1); lwz 12,0x20(1); mtspr 8,0; lmw 21,0x24(1); mtcrf 24,12; addi 1,1,80"
extern "C" void _s80339F98_0();
extern "C" void _s80339F98_1();
extern "C" void _s80339F98_2();
extern "C" void _s80339F98_3();
extern "C" void _s80339F98_4();
extern "C" void _s80339F98_5();
extern "C" void _s80339F98_6();
extern "C" void _s80339F98_7();
extern "C" void _s80339F98_8();
extern "C" void _s80339F98_9();
extern "C" void _s80339F98_10();
extern "C" void _s80339F98_11();
extern "C" void f_80339F98() {}
