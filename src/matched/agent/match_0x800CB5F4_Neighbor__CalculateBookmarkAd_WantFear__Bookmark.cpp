// 0x800CB5F4 Neighbor::CalculateBookmarkAd(WantFear::Bookmark (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 28,3; mr 3,30; bl _s800CB5F4_0; mr 29,3; mr 3,30; bl _s800CB5F4_1; mr 4,3; mr 5,29; mr 3,28; bl _s800CB5F4_2; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800CB5F4_0();
extern "C" void _s800CB5F4_1();
extern "C" void _s800CB5F4_2();
extern "C" void f_800CB5F4() {}
