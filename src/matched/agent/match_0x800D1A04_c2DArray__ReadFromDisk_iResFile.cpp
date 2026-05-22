// 0x800D1A04 _c2DArray::ReadFromDisk(iResFile (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 25,0x3c(1); stw 0,0x5c(1); mr 25,4; mr 26,3; lwz 9,0xc(25); mr 4,5; mr 5,6; lha 3,0x80(9); lis 6,-32755; lwz 0,0x84(9); addi 6,6,6936; add 3,25,3; stw 7,-24288(13); mtspr 8,0; blrl; mr. 27,3; bne 0f; mr 3,25; bl _s800D1A04_0; b 5f; 0:; lwz 30,0x4(27); lha 28,0x0(30); cmpwi 28,0; beq 3f; lha 31,0x2(30); mr 3,26; lha 29,0x4(30); stw 28,0x14(26); mr 4,31; mr 5,29; bl _s800D1A04_1; cmpwi 3,0; bne 1f; li 3,-1; b 5f; 1:; mullw 0,28,31; rlwinm 9,31,2,0,29; add 9,30,9; addi 4,9,8; mullw. 5,0,29; beq 2f; lwz 9,0xc(26); lwz 3,0x0(9); bl _s800D1A04_2; 2:; mr 3,25; mr 4,27; bl _s800D1A04_3; b 4f; 3:; lwz 5,0x0(27); li 6,0; li 7,0; addi 3,1,8; mr 4,30; bl _s800D1A04_4; addi 4,1,8; mr 3,26; li 5,0; bl _s800D1A04_5; addi 3,1,8; li 4,2; bl _s800D1A04_6; 4:; li 3,0; 5:; lwz 0,0x5c(1); mtspr 8,0; lmw 25,0x3c(1); addi 1,1,88"
extern "C" void _s800D1A04_0();
extern "C" void _s800D1A04_1();
extern "C" void _s800D1A04_2();
extern "C" void _s800D1A04_3();
extern "C" void _s800D1A04_4();
extern "C" void _s800D1A04_5();
extern "C" void _s800D1A04_6();
extern "C" void f_800D1A04() {}
