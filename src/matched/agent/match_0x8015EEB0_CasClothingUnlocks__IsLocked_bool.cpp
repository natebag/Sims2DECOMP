// 0x8015EEB0 CasClothingUnlocks::IsLocked(bool, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,6; mr 29,3; mr 31,4; mr 30,5; mr 4,28; bl _s8015EEB0_0; cmpwi 3,0; bne 0f; li 3,0; b 1f; 0:; mulli 9,30,40; rlwinm 0,31,2,0,29; add 0,0,31; rlwinm 0,0,8,0,23; add 0,0,29; add 9,9,0; lbzx 3,9,28; rlwinm 3,3,31,31,31; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015EEB0_0();
extern "C" void f_8015EEB0() {}
