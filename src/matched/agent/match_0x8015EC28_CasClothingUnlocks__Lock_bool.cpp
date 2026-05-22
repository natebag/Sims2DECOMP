// 0x8015EC28 CasClothingUnlocks::Lock(bool, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,6; mr 28,3; mr 30,4; mr 29,5; mr 4,31; bl _s8015EC28_0; cmpwi 3,0; beq 0f; mulli 10,29,40; rlwinm 0,30,2,0,29; add 0,0,30; rlwinm 0,0,8,0,23; add 0,0,28; add 11,10,0; mr 10,11; .long 0x7D2BF8EE; ori 9,9,2; stb 9,0x0(11); .long 0x7C0AF8EE; rlwinm 0,0,0,30,28; stb 0,0x0(10); 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8015EC28_0();
extern "C" void f_8015EC28() {}
