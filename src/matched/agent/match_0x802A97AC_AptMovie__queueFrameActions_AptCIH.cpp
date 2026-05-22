// 0x802A97AC AptMovie::queueFrameActions(AptCIH (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 26,3; rlwinm 5,5,3,0,28; lwz 11,0x4(26); li 28,0; mr 25,4; lwzx 0,5,11; cmpw 28,0; bge 2f; mr 31,5; li 27,0; 0:; add 9,31,11; lwz 11,0x4(9); lwzx 30,27,11; lwz 0,0x0(30); cmpwi 0,1; bne 1f; lwz 3,-23008(13); addi 30,30,4; lwz 29,-27612(13); bl _s802A97AC_0; mr 4,30; mr 6,29; mr 5,25; bl _s802A97AC_1; 1:; lwz 11,0x4(26); addi 28,28,1; addi 27,27,4; lwzx 0,31,11; cmpw 28,0; blt 0b; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s802A97AC_0();
extern "C" void _s802A97AC_1();
extern "C" void f_802A97AC() {}
