// 0x8015ED18 CasClothingUnlocks::ClearRecentlyUnlocked(bool, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,6; mr 28,3; mr 30,4; mr 29,5; mr 4,31; bl _s8015ED18_0; cmpwi 3,0; beq 0f; mulli 9,29,40; rlwinm 0,30,2,0,29; add 0,0,30; rlwinm 0,0,8,0,23; add 0,0,28; add 9,9,0; .long 0x7D69F8EE; rlwinm 11,11,0,30,28; stb 11,0x0(9); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015ED18_0();
extern "C" void f_8015ED18() {}
