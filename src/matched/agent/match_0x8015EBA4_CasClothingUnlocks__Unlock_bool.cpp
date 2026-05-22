// 0x8015EBA4 CasClothingUnlocks::Unlock(bool, (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,6; mr 29,3; mr 28,4; mr 27,5; mr 30,7; mr 4,31; bl _s8015EBA4_0; cmpwi 3,0; beq 0f; mulli 0,28,240; cmpwi 30,0; mulli 5,27,30; add 3,0,29; add 9,5,3; add 9,9,31; lbzu 0,0xa00(9); rlwinm 0,0,0,31,29; stb 0,0x0(9); beq 0f; add 9,5,3; add 9,9,31; lbzu 0,0xa00(9); ori 0,0,4; stb 0,0x0(9); 0:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8015EBA4_0();
extern "C" void f_8015EBA4() {}
