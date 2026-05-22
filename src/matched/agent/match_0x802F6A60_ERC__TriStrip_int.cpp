// 0x802F6A60 ERC::TriStrip(int, (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 31,3; mr 26,5; mr 28,6; mr 25,7; mr 24,8; mr 27,9; mr 30,10; mr. 29,4; beq 1f; mr 4,26; rlwinm 5,29,3,0,28; bl _s802F6A60_0; mr 26,3; cmpwi 30,0; li 0,2; beq 0f; li 0,4; 0:; add 5,29,29; mr 4,28; mullw 5,0,5; mr 3,31; rlwinm 30,29,2,0,29; bl _s802F6A60_1; mr 28,3; mr 4,25; mr 5,30; mr 3,31; bl _s802F6A60_2; mr 25,3; mr 4,24; mr 5,30; mr 3,31; bl _s802F6A60_3; mr 24,3; mr 4,27; mr 5,30; mr 3,31; bl _s802F6A60_4; lwz 9,0x70(31); mr 27,3; li 4,2; li 5,1; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,4; lwz 0,0x54(11); add 0,0,29; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,56; li 9,0; stb 0,0x0(3); stw 9,0x1c(3); stw 29,0x4(3); stw 26,0x8(3); stw 28,0xc(3); stw 25,0x10(3); stw 24,0x14(3); stw 27,0x18(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s802F6A60_0();
extern "C" void _s802F6A60_1();
extern "C" void _s802F6A60_2();
extern "C" void _s802F6A60_3();
extern "C" void _s802F6A60_4();
extern "C" void f_802F6A60() {}
