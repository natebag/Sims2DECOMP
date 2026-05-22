// 0x800BFFE8 IFFResFile2::InvalBlockHeader(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 30,0x58(1); stw 0,0x64(1); mr 30,4; mr 31,3; addi 4,1,8; mr 5,30; bl _s800BFFE8_0; mr. 3,3; bne 0f; lhz 9,0x12(1); lis 0,22616; lwz 11,0x138(31); ori 0,0,22616; ori 9,9,4; stw 0,0x8(1); sth 9,0x12(1); mr 3,31; lwz 9,0xc(1); mr 5,30; lwz 0,0x10(11); addi 4,1,8; add 0,0,9; stw 0,0x10(11); bl _s800BFFE8_1; 0:; lwz 0,0x64(1); mtspr 8,0; lmw 30,0x58(1); addi 1,1,96"
extern "C" void _s800BFFE8_0();
extern "C" void _s800BFFE8_1();
extern "C" void f_800BFFE8() {}
