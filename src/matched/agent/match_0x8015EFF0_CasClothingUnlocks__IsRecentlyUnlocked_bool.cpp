// 0x8015EFF0 CasClothingUnlocks::IsRecentlyUnlocked(bool, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,6; mr 31,3; mr 30,4; mr 29,5; mr 4,28; bl _s8015EFF0_0; cmpwi 3,0; bne 0f; li 3,0; b 1f; 0:; mulli 0,30,240; mulli 9,29,30; add 0,0,31; add 9,9,0; add 9,9,28; lbz 3,0xa00(9); rlwinm 3,3,30,31,31; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015EFF0_0();
extern "C" void f_8015EFF0() {}
