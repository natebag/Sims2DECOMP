// 0x800600E0 SAnimator2::UpdatePortalMode(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; lwz 29,0x5fc(31); cmpwi 29,0; bne 6f; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0xc(31); cmpwi 3,1; lwz 10,0x0(9); lwz 0,0x4(9); subf 0,10,0; srawi 11,0,3; ble 3f; cmpwi 11,2; ble 3f; addi 11,11,-2; lwz 8,0x4(31); rlwinm 11,11,3,0,28; addi 30,1,16; add 11,10,11; lwz 9,0x0(11); lwz 10,0x4(11); stw 9,0x10(1); stw 10,0x14(1); lwz 11,0x0(8); lwz 9,0x4(11); lwz 0,0x354(9); lha 3,0x350(9); mtspr 8,0; add 3,11,3; blrl; mr 5,3; mr 4,30; addi 3,1,8; bl _s800600E0_0; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,11,3; mtspr 8,0; blrl; rlwinm 4,3,0,16,31; lwz 3,-21472(13); bl _s800600E0_1; mr. 3,3; beq 2f; addi 4,1,8; bl _s800600E0_2; cmpwi 3,0; bne 0f; li 0,1; stb 0,0x5f8(31); b 2f; 0:; lbz 0,0x5f8(31); extsb 0,0; cmpwi 0,0; beq 2f; cmpwi 0,1; bne 1f; lwz 0,0x61c(31); li 9,2; stb 9,0x5f8(31); xori 0,0,1; andi. 9,0,1; beq 2f; mr 3,31; bl _s800600E0_3; b 2f; 1:; stb 29,0x5f8(31); 2:; addi 3,1,8; li 4,2; bl _s800600E0_4; b 5f; 3:; lbz 0,0x5f8(31); extsb 0,0; cmpwi 0,0; beq 5f; cmpwi 0,1; bne 4f; lwz 0,0x61c(31); li 9,2; stb 9,0x5f8(31); xori 0,0,1; andi. 9,0,1; beq 5f; mr 3,31; bl _s800600E0_5; b 5f; 4:; li 0,0; stb 0,0x5f8(31); 5:; li 0,1; stw 0,0x5fc(31); 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s800600E0_0();
extern "C" void _s800600E0_1();
extern "C" void _s800600E0_2();
extern "C" void _s800600E0_3();
extern "C" void _s800600E0_4();
extern "C" void _s800600E0_5();
extern "C" void f_800600E0() {}
