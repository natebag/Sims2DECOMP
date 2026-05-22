// 0x8015ECA0 CasClothingUnlocks::Lock(bool, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,6; mr 30,3; mr 29,4; mr 28,5; mr 4,31; bl _s8015ECA0_0; cmpwi 3,0; beq 0f; mulli 0,29,240; mulli 11,28,30; add 0,0,30; add 10,11,0; mr 11,10; add 10,10,31; add 11,11,31; lbzu 0,0xa00(10); ori 0,0,2; stb 0,0x0(10); lbzu 9,0xa00(11); rlwinm 9,9,0,30,28; stb 9,0x0(11); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015ECA0_0();
extern "C" void f_8015ECA0() {}
