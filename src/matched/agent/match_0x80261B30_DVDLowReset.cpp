// 0x80261B30 DVDLowReset (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-13312; stw 0,0x4(1); li 0,2; stwu 1,-32(1); stmw 26,0x8(1); addi 31,4,12288; stw 0,0x6004(4); lwz 30,0x3024(4); rlwinm 0,30,0,30,28; ori 0,0,1; stwu 0,0x24(31); bl _s80261B30_0; lis 5,-32768; lwz 0,0xf8(5); lis 5,17180; addi 5,5,-8573; rlwinm 0,0,30,2,31; mulhwu 0,5,0; rlwinm 0,0,17,15,31; mulli 0,0,12; addi 26,4,0; addi 27,3,0; rlwinm 28,0,29,3,31; li 29,0; 0:; bl _s80261B30_1; subfc 5,26,4; subfe 0,27,3; xoris 4,0,32768; xoris 3,29,32768; subfc 0,28,5; subfe 3,3,4; subfe 3,4,4; neg. 3,3; bne 0b; ori 0,30,5; stw 0,0x0(31); li 0,1; stw 0,-23336(13); bl _s80261B30_2; stw 4,-23340(13); stw 3,-23344(13); lmw 26,0x8(1); lwz 0,0x24(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80261B30_0();
extern "C" void _s80261B30_1();
extern "C" void _s80261B30_2();
extern "C" void f_80261B30() {}
