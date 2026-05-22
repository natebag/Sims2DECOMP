// 0x800B4BF4 CTilePt::SameColumnParity(CTilePt (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; bl _s800B4BF4_0; mr 30,3; mr 3,29; bl _s800B4BF4_1; rlwinm 30,30,0,31,31; rlwinm 3,3,0,31,31; xor 3,30,3; subfic 0,3,0; adde 3,0,3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B4BF4_0();
extern "C" void _s800B4BF4_1();
extern "C" void f_800B4BF4() {}
