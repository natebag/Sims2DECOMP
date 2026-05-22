// 0x802F6CA4 ERC::LineStrip(EGEVert (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr. 29,5; beq 0f; mulli 5,29,80; bl _s802F6CA4_0; lwz 9,0x70(31); mr 30,3; li 4,2; li 5,4; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0x0(31); li 4,1; lwz 0,0x54(11); add 0,0,29; stw 0,0x54(11); lwz 9,0x70(31); lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,27; stw 30,0x4(3); stb 0,0x0(3); sth 29,0x2(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F6CA4_0();
extern "C" void f_802F6CA4() {}
