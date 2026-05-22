// 0x8025A888 __DBExceptionDestinationAux (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32700; stw 0,0x4(1); addi 3,3,-15608; crxor 6,6,6; stwu 1,-24(1); stw 31,0x14(1); lwz 4,0xc0(0); addis 31,4,-32768; bl _s8025A888_0; mr 3,31; bl _s8025A888_1; bl _s8025A888_2; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025A888_0();
extern "C" void _s8025A888_1();
extern "C" void _s8025A888_2();
extern "C" void f_8025A888() {}
