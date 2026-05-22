// 0x802A96C4 AptMovie::runFrameActions(AptCIH (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 23,0x14(1); stw 0,0x3c(1); stw 12,0x10(1); mr 23,3; mr 24,5; lwz 11,0x4(23); rlwinm 9,24,3,0,28; li 28,0; mr 29,4; lwzx 0,9,11; cmpw 28,0; bge 4f; lis 25,-32694; cmpwi 4,29,0; li 26,0; 0:; add 9,9,11; lwz 11,0x4(9); lwzx 31,26,11; lwz 0,0x0(31); cmpwi 0,1; bne 3f; addi 3,25,-16032; addi 4,1,8; bl _s802A96C4_0; addi 27,1,8; mr 30,3; beq cr4,1f; mr 3,29; bl _s802A96C4_1; lwz 7,0x4c(3); b 2f; 1:; li 7,0; 2:; lwz 4,0x4(31); mr 5,29; addi 3,25,-16032; li 6,-1; bl _s802A96C4_2; mr 4,30; mr 5,27; addi 3,25,-16032; bl _s802A96C4_3; 3:; lwz 11,0x4(23); rlwinm 9,24,3,0,28; addi 28,28,1; addi 26,26,4; lwzx 0,9,11; cmpw 28,0; blt 0b; 4:; lwz 0,0x3c(1); lwz 12,0x10(1); mtspr 8,0; lmw 23,0x14(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s802A96C4_0();
extern "C" void _s802A96C4_1();
extern "C" void _s802A96C4_2();
extern "C" void _s802A96C4_3();
extern "C" void f_802A96C4() {}
