// 0x8006952C SAnimator2::determineFirstFollowMode(TileList (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,1; bl _s8006952C_0; lbz 0,0x5f8(31); cmpwi 0,0; bne 0f; lwz 9,0xc(31); lwz 8,0x0(9); lwz 0,0x4(9); subf 0,8,0; srawi 0,0,3; cmpwi 0,3; bne 0f; lwz 10,0x0(8); lwz 0,0xc(8); lwz 11,0x4(8); lwz 9,0x8(8); subf 0,11,0; subf 9,10,9; mullw 0,0,0; mullw 9,9,9; add 0,0,9; cmpwi 0,256; bgt 0f; li 30,2; 0:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8006952C_0();
extern "C" void f_8006952C() {}
