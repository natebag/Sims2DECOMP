// 0x800B46D8 CTilePt::CTilePt(TilePtDir, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); rlwinm 0,4,1,0,30; lis 9,-32696; mr 30,3; add 0,0,4; addi 9,9,24096; mr 29,5; add 4,0,9; bl _s800B46D8_0; stb 29,0x2(30); mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B46D8_0();
extern "C" void f_800B46D8() {}
