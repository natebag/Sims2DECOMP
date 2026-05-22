// 0x800BCDAC IFFResList::DoStream(ReconBuffer (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 29,4; lwz 0,0x10(30); mr 28,5; mr 3,29; addi 4,1,8; stw 0,0x8(1); li 5,1; bl _s800BCDAC_0; lwz 0,0x8(1); mr 3,30; mr 5,29; mr 6,28; stw 0,0x10(30); lwz 4,0x0(3); bl _s800BCDAC_1; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800BCDAC_0();
extern "C" void _s800BCDAC_1();
extern "C" void f_800BCDAC() {}
