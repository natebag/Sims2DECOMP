// 0x800B48D8 CTilePt::operator+(CTilePt (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lbz 11,0x1(5); mr 30,3; lbz 0,0x0(5); lbz 9,0x0(4); extsb 11,11; lbz 5,0x1(4); extsb 0,0; lbz 6,0x2(4); extsb 9,9; extsb 5,5; add 4,9,0; add 5,5,11; extsb 6,6; bl _s800B48D8_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B48D8_0();
extern "C" void f_800B48D8() {}
