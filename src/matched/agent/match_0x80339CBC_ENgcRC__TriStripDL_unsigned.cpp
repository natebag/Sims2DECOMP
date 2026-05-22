// 0x80339CBC ENgcRC::TriStripDL(unsigned (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); mr 31,3; mr 22,4; mr 24,6; mr 25,7; mr 28,8; mr 27,9; mr 26,10; mr. 23,5; blt 3f; rlwinm 30,24,3,0,28; mr 4,25; mr 5,30; bl _s80339CBC_0; rlwinm 29,24,2,0,29; mr 25,3; mr 4,28; mr 5,29; mr 3,31; bl _s80339CBC_1; mr 28,3; mr 4,27; mr 5,29; mr 3,31; bl _s80339CBC_2; mr 27,3; mr 4,26; mr 5,29; mr 3,31; bl _s80339CBC_3; mr 26,3; mr 4,30; mr 3,25; bl _s80339CBC_4; mr 3,22; mr 4,23; bl _s80339CBC_5; cmpwi 28,0; beq 0f; mr 3,28; mr 4,29; bl _s80339CBC_6; 0:; cmpwi 27,0; beq 1f; mr 3,27; mr 4,29; bl _s80339CBC_7; 1:; cmpwi 26,0; beq 2f; mr 4,29; mr 3,26; bl _s80339CBC_8; 2:; bl _s80339CBC_9; lwz 9,0x70(31); li 4,2; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,4; lwz 0,0x54(11); add 0,0,24; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,67; stw 23,0x1c(3); stb 0,0x0(3); stw 24,0x4(3); stw 25,0x8(3); stw 28,0xc(3); stw 27,0x10(3); stw 26,0x14(3); stw 22,0x18(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 3:; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s80339CBC_0();
extern "C" void _s80339CBC_1();
extern "C" void _s80339CBC_2();
extern "C" void _s80339CBC_3();
extern "C" void _s80339CBC_4();
extern "C" void _s80339CBC_5();
extern "C" void _s80339CBC_6();
extern "C" void _s80339CBC_7();
extern "C" void _s80339CBC_8();
extern "C" void _s80339CBC_9();
extern "C" void f_80339CBC() {}
