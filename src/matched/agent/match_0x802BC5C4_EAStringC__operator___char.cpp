// 0x802BC5C4 EAStringC::operator+=(char (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 29,4; lwz 9,0x0(30); lhz 31,0x2(9); cmpwi 31,0; bne 1f; addi 3,1,8; bl _s802BC5C4_0; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BC5C4_1; 0:; lwz 4,0x8(1); stw 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BC5C4_2; b 2f; 1:; mr 3,29; bl _s802BC5C4_3; mr. 28,3; beq 2f; add 4,31,28; mr 3,30; mr 8,4; li 5,0; mr 6,31; li 7,0; bl _s802BC5C4_4; lwz 3,0x0(30); mr 4,29; addi 5,28,1; addi 3,3,8; add 3,3,31; crxor 6,6,6; bl _s802BC5C4_5; 2:; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802BC5C4_0();
extern "C" void _s802BC5C4_1();
extern "C" void _s802BC5C4_2();
extern "C" void _s802BC5C4_3();
extern "C" void _s802BC5C4_4();
extern "C" void _s802BC5C4_5();
extern "C" void f_802BC5C4() {}
