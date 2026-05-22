// 0x800CF028 NeighborhoodImpl::AddToFamily(Neighbor (420 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 28,5; mr 31,4; lwz 30,0x0(28); mr 27,3; mr 3,31; lha 29,0x58(30); addi 30,30,88; add 29,28,29; bl _s800CF028_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 25,3; li 3,-1; bne 2f; mr 3,31; addi 26,31,112; bl _s800CF028_1; mr 4,3; mr 3,28; bl _s800CF028_2; lwz 9,0x0(27); lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,27,3; blrl; lwz 30,0x0(28); mr 3,31; lha 29,0x48(30); addi 30,30,72; add 29,28,29; bl _s800CF028_3; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; li 3,-1; b 2f; 0:; lwz 29,-21484(13); mr 3,31; lwz 30,0x0(29); lha 0,0xe8(30); addi 30,30,232; add 29,29,0; bl _s800CF028_4; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 31,3; beq 1f; lwz 9,0x0(28); lwz 11,0x4(31); lwz 0,0x9c(9); lha 3,0x98(9); addi 29,11,320; mtspr 8,0; lha 30,0x140(11); add 3,28,3; add 30,31,30; blrl; lwz 0,0x4(29); extsh 5,3; mr 3,30; li 4,61; mtspr 8,0; blrl; lwz 9,0x4(31); li 4,67; li 5,0; lha 3,0x140(9); lwz 0,0x144(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 9,0x0(28); lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,28,3; blrl; sth 3,0x7a(26); li 0,1; sth 25,0x86(26); li 4,0; stw 0,0x20(28); li 3,228; bl _s800CF028_5; li 3,0; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800CF028_0();
extern "C" void _s800CF028_1();
extern "C" void _s800CF028_2();
extern "C" void _s800CF028_3();
extern "C" void _s800CF028_4();
extern "C" void _s800CF028_5();
extern "C" void f_800CF028() {}
