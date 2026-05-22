// 0x802BCB18 EAStringC::vsFormat(char (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,4; mr 29,3; mr 27,5; mr 3,28; bl _s802BCB18_0; rlwinm 31,3,2,0,29; b 1f; 0:; add 31,31,31; 1:; mr 3,29; mr 4,31; li 5,0; li 6,0; li 7,0; li 8,0; bl _s802BCB18_1; lwz 9,0x0(29); mr 5,28; mr 6,27; addi 30,9,8; lhz 4,0x4(9); mr 3,30; bl _s802BCB18_2; mr. 3,3; blt 0b; li 0,0; li 10,0; stbx 0,30,3; lwz 9,0x0(29); sth 3,0x2(9); lwz 11,0x0(29); sth 10,0x6(11); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802BCB18_0();
extern "C" void _s802BCB18_1();
extern "C" void _s802BCB18_2();
extern "C" void f_802BCB18() {}
