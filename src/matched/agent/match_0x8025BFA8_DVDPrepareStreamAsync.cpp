// 0x8025BFA8 DVDPrepareStreamAsync (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 27,0x24(1); addi 29,5,0; mr 27,3; addi 28,4,0; addi 30,6,0; lwz 7,0x30(3); lis 3,-32700; addi 31,3,-15584; add 0,7,29; rlwinm. 0,0,0,17,31; beq 0f; addi 6,7,0; crxor 6,6,6; addi 7,29,0; addi 5,31,456; addi 3,13,-27800; li 4,1211; bl _s8025BFA8_0; 0:; cmplwi 28,0; bne 1f; lwz 0,0x34(27); subf 28,29,0; 1:; rlwinm. 0,28,0,17,31; beq 2f; addi 6,28,0; crxor 6,6,6; addi 5,31,560; addi 3,13,-27800; li 4,1221; bl _s8025BFA8_1; 2:; lwz 3,0x34(27); cmplw 29,3; bgt 3f; add 0,29,28; cmplw 0,3; ble 4f; 3:; addi 6,29,0; crxor 6,6,6; addi 7,28,0; addi 5,31,648; addi 3,13,-27800; li 4,1229; bl _s8025BFA8_2; 4:; stw 30,0x38(27); lis 3,-32730; addi 6,3,-16236; lwz 0,0x30(27); addi 3,27,0; addi 4,28,0; add 5,0,29; bl _s8025BFA8_3; lmw 27,0x24(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8025BFA8_0();
extern "C" void _s8025BFA8_1();
extern "C" void _s8025BFA8_2();
extern "C" void _s8025BFA8_3();
extern "C" void f_8025BFA8() {}
