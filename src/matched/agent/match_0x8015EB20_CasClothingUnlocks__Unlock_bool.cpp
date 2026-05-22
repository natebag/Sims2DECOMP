// 0x8015EB20 CasClothingUnlocks::Unlock(bool, (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,6; mr 28,3; mr 30,4; mr 29,5; mr 27,7; mr 4,31; bl _s8015EB20_0; cmpwi 3,0; beq 0f; mulli 5,29,40; rlwinm 0,30,2,0,29; add 0,0,30; rlwinm 0,0,8,0,23; cmpwi 27,0; add 3,0,28; add 9,5,3; .long 0x7C09F8EE; rlwinm 0,0,0,31,29; stb 0,0x0(9); beq 0f; add 9,5,3; .long 0x7C09F8EE; ori 0,0,4; stb 0,0x0(9); 0:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8015EB20_0();
extern "C" void f_8015EB20() {}
