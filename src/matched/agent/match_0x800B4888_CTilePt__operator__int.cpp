// 0x800B4888 CTilePt::operator*(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lbz 0,0x0(4); mr 30,3; lbz 9,0x1(4); lbz 6,0x2(4); extsb 0,0; extsb 9,9; mullw 4,5,0; extsb 6,6; mullw 5,5,9; bl _s800B4888_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B4888_0();
extern "C" void f_800B4888() {}
