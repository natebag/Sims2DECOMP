// 0x80339B58 ENgcRC::TriStripDLRef(unsigned (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 22,0x10(1); stw 0,0x3c(1); stw 12,0xc(1); mr 31,3; mr 24,4; mr 30,6; mr 25,7; mr 29,8; mr 28,9; mr 27,10; lwz 22,0x40(1); mr. 26,5; blt 5f; cmpwi 29,0; rlwinm 4,30,4,0,27; cmpwi 7,22,0; mcrf cr3,cr0; mfcr 23; rlwinm 23,23,28,0,3; mr 3,25; cmpwi 4,28,0; bl _s80339B58_0; cmpwi 2,27,0; mr 3,24; mr 4,26; bl _s80339B58_1; beq cr3,0f; mr 3,29; rlwinm 4,30,3,0,28; bl _s80339B58_2; 0:; beq cr4,1f; mr 3,28; rlwinm 4,30,2,0,29; bl _s80339B58_3; 1:; beq cr2,2f; mr 3,27; rlwinm 4,30,2,0,29; bl _s80339B58_4; 2:; bl _s80339B58_5; lwz 9,0x70(31); li 5,0; li 4,2; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,4; lwz 0,0x54(11); add 0,0,30; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,68; stw 30,0x4(3); stb 0,0x0(3); mtcrf 128,23; beq 3f; li 0,1; stb 0,0x1(3); b 4f; 3:; stb 22,0x1(3); 4:; stw 26,0x1c(3); stw 25,0x8(3); stw 29,0xc(3); stw 28,0x10(3); stw 27,0x14(3); stw 24,0x18(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 5:; lwz 0,0x3c(1); lwz 12,0xc(1); mtspr 8,0; lmw 22,0x10(1); mtcrf 56,12; addi 1,1,56"
extern "C" void _s80339B58_0();
extern "C" void _s80339B58_1();
extern "C" void _s80339B58_2();
extern "C" void _s80339B58_3();
extern "C" void _s80339B58_4();
extern "C" void _s80339B58_5();
extern "C" void f_80339B58() {}
