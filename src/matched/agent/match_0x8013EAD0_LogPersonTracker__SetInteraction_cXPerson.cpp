// 0x8013EAD0 LogPersonTracker::SetInteraction(cXPerson (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 27,0x34(1); stw 0,0x4c(1); mr 30,3; mr 27,4; mr. 28,5; beq 0f; mr 3,28; bl _s8013EAD0_0; mr 31,3; b 1f; 0:; li 31,0; 1:; li 29,0; li 3,0; li 9,-1; cmpwi 31,0; beq 2f; lwz 9,0x4(31); lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,31,3; blrl; bl _s8013EAD0_1; bl _s8013EAD0_2; lwz 9,0x4(31); mr 29,3; lha 3,0x328(9); lwz 0,0x32c(9); add 3,31,3; mtspr 8,0; blrl; lwz 9,0x14(28); 2:; li 0,0; sth 3,0xc(30); stw 29,0x8(30); mr 4,27; stw 9,0x10(30); addi 3,1,8; stw 0,0x44(30); stw 0,0x3c(30); stw 0,0x40(30); bl _s8013EAD0_3; addi 9,30,20; addi 11,1,8; li 10,24; 3:; lwz 0,0x0(11); addic. 10,10,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 3b; lwz 0,0x0(11); lwz 3,-21496(13); stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 9,0x0(3); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; mtspr 8,9; blrl; stw 3,0x48(30); lwz 0,0x4c(1); mtspr 8,0; lmw 27,0x34(1); addi 1,1,72"
extern "C" void _s8013EAD0_0();
extern "C" void _s8013EAD0_1();
extern "C" void _s8013EAD0_2();
extern "C" void _s8013EAD0_3();
extern "C" void f_8013EAD0() {}
