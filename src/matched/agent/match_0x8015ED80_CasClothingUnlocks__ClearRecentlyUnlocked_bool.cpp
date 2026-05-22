// 0x8015ED80 CasClothingUnlocks::ClearRecentlyUnlocked(bool, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,6; mr 31,3; mr 30,4; mr 29,5; mr 4,28; bl _s8015ED80_0; cmpwi 3,0; beq 0f; mulli 0,30,240; mulli 9,29,30; add 0,0,31; add 9,9,0; add 9,9,28; lbzu 0,0xa00(9); rlwinm 0,0,0,30,28; stb 0,0x0(9); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015ED80_0();
extern "C" void f_8015ED80() {}
