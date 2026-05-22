// 0x8025B9D4 DVDReadAsyncPrio (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 26,0x20(1); mr. 29,6; addi 26,3,0; addi 27,4,0; addi 28,5,0; addi 30,7,0; addi 31,8,0; blt 0f; lwz 0,0x34(26); cmplw 29,0; ble 1f; 0:; lis 3,-32700; crxor 6,6,6; addi 5,3,-15328; addi 3,13,-27800; li 4,750; bl _s8025B9D4_0; 1:; add. 4,29,28; blt 2f; lwz 3,0x34(26); addi 0,3,32; cmplw 4,0; blt 3f; 2:; lis 3,-32700; crxor 6,6,6; addi 5,3,-15328; addi 3,13,-27800; li 4,756; bl _s8025B9D4_1; 3:; stw 30,0x38(26); lis 3,-32730; addi 7,3,-17772; lwz 0,0x30(26); addi 3,26,0; addi 4,27,0; addi 5,28,0; addi 8,31,0; add 6,0,29; bl _s8025B9D4_2; lmw 26,0x20(1); li 3,1; lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8025B9D4_0();
extern "C" void _s8025B9D4_1();
extern "C" void _s8025B9D4_2();
extern "C" void f_8025B9D4() {}
