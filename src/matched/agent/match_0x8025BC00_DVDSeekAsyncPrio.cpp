// 0x8025BC00 DVDSeekAsyncPrio (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,6,0; stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); mr. 29,4; stw 28,0x18(1); addi 28,3,0; blt 0f; lwz 0,0x34(28); cmplw 29,0; ble 1f; 0:; lis 3,-32700; crxor 6,6,6; addi 5,3,-15228; addi 3,13,-27800; li 4,907; bl _s8025BC00_0; 1:; stw 30,0x38(28); lis 3,-32730; addi 5,3,-17256; lwz 0,0x30(28); addi 3,28,0; addi 6,31,0; add 4,0,29; bl _s8025BC00_1; lwz 0,0x2c(1); li 3,1; lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8025BC00_0();
extern "C" void _s8025BC00_1();
extern "C" void f_8025BC00() {}
