// 0x8025BAC4 DVDReadPrio (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 27,0x24(1); mr. 29,6; addi 31,3,0; addi 27,4,0; addi 28,5,0; addi 30,7,0; blt 0f; lwz 0,0x34(31); cmplw 29,0; ble 1f; 0:; lis 3,-32700; crxor 6,6,6; addi 5,3,-15276; addi 3,13,-27800; li 4,820; bl _s8025BAC4_0; 1:; add. 4,29,28; blt 2f; lwz 3,0x34(31); addi 0,3,32; cmplw 4,0; blt 3f; 2:; lis 3,-32700; crxor 6,6,6; addi 5,3,-15276; addi 3,13,-27800; li 4,826; bl _s8025BAC4_1; 3:; lwz 0,0x30(31); lis 4,-32730; addi 7,4,-17444; addi 3,31,0; addi 4,27,0; addi 5,28,0; addi 8,30,0; add 6,0,29; bl _s8025BAC4_2; cmpwi 3,0; bne 4f; li 3,-1; b 10f; 4:; bl _s8025BAC4_3; mr 30,3; 5:; lwz 0,0xc(31); cmpwi 0,0; bne 6f; lwz 31,0x20(31); b 9f; 6:; cmpwi 0,-1; bne 7f; li 31,-1; b 9f; 7:; cmpwi 0,10; bne 8f; li 31,-3; b 9f; 8:; addi 3,13,-23488; bl _s8025BAC4_4; b 5b; 9:; mr 3,30; bl _s8025BAC4_5; mr 3,31; 10:; lmw 27,0x24(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8025BAC4_0();
extern "C" void _s8025BAC4_1();
extern "C" void _s8025BAC4_2();
extern "C" void _s8025BAC4_3();
extern "C" void _s8025BAC4_4();
extern "C" void _s8025BAC4_5();
extern "C" void f_8025BAC4() {}
