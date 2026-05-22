// 0x80041F00 EGlobal::CheckForZeroExtentOverride(CTilePt (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); addi 30,1,8; mr 29,5; mr 3,30; li 5,0; bl _s80041F00_0; mr 31,30; lwz 0,0x4(30); cmpwi 0,0; beq 2f; 0:; lwz 11,0x4(31); cmpw 11,29; beq 1f; lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0xb6(3); li 3,1; rlwinm 0,0,0,29,30; cmpwi 0,0; bne 3f; 1:; mr 3,31; bl _s80041F00_1; lwz 0,0x4(31); cmpwi 0,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80041F00_0();
extern "C" void _s80041F00_1();
extern "C" void f_80041F00() {}
