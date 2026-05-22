// 0x80339E38 ENgcRC::TriStripDLRef(unsigned (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 22,0x10(1); stw 0,0x3c(1); stw 12,0xc(1); mr 31,3; mr 23,4; mr 29,6; mr 24,7; mr 28,8; mr 27,9; mr 26,10; lwz 22,0x40(1); mr. 25,5; blt 6f; rlwinm 30,29,3,0,28; mr 3,24; mr 4,30; bl _s80339E38_0; mr 3,23; mr 4,25; bl _s80339E38_1; cmpwi 4,22,0; cmpwi 28,0; beq 1f; mr 4,30; bne cr4,0f; rlwinm 4,29,2,0,29; 0:; mr 3,28; bl _s80339E38_2; 1:; cmpwi 27,0; beq 2f; mr 3,27; rlwinm 4,29,2,0,29; bl _s80339E38_3; 2:; cmpwi 26,0; beq 3f; mr 3,26; rlwinm 4,29,2,0,29; bl _s80339E38_4; 3:; bl _s80339E38_5; lwz 9,0x70(31); li 5,0; li 4,2; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,4; lwz 0,0x54(11); add 0,0,29; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,67; stw 29,0x4(3); stb 0,0x0(3); beq cr4,4f; li 0,1; stb 0,0x1(3); b 5f; 4:; stb 22,0x1(3); 5:; stw 25,0x1c(3); stw 24,0x8(3); stw 28,0xc(3); stw 27,0x10(3); stw 26,0x14(3); stw 23,0x18(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 6:; lwz 0,0x3c(1); lwz 12,0xc(1); mtspr 8,0; lmw 22,0x10(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s80339E38_0();
extern "C" void _s80339E38_1();
extern "C" void _s80339E38_2();
extern "C" void _s80339E38_3();
extern "C" void _s80339E38_4();
extern "C" void _s80339E38_5();
extern "C" void f_80339E38() {}
