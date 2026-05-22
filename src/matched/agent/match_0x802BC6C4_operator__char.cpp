// 0x802BC6C4 operator+(char (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 26,5; mr 25,3; lwz 9,0x0(26); mr 28,4; lhz 27,0x2(9); cmpwi 27,0; bne 0f; bl _s802BC6C4_0; b 2f; 0:; mr 3,28; bl _s802BC6C4_1; mr. 31,3; bne 1f; lwz 11,0x0(26); stw 11,0x0(25); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); b 2f; 1:; add 29,31,27; addi 3,1,8; mr 4,29; bl _s802BC6C4_2; lwz 30,0x8(1); mr 4,28; mr 5,31; addi 30,30,8; mr 3,30; crxor 6,6,6; bl _s802BC6C4_3; lwz 4,0x0(26); add 3,30,31; mr 5,27; addi 4,4,8; crxor 6,6,6; bl _s802BC6C4_4; li 0,0; li 8,0; stbx 0,30,29; lwz 9,0x8(1); sth 29,0x2(9); lwz 11,0x8(1); sth 8,0x6(11); lwz 10,0x8(1); stw 10,0x0(25); lhz 9,0x0(10); addi 9,9,1; sth 9,0x0(10); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BC6C4_5; 2:; mr 3,25; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s802BC6C4_0();
extern "C" void _s802BC6C4_1();
extern "C" void _s802BC6C4_2();
extern "C" void _s802BC6C4_3();
extern "C" void _s802BC6C4_4();
extern "C" void _s802BC6C4_5();
extern "C" void f_802BC6C4() {}
