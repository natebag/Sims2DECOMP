// 0x8007D748 InitPerformanceCounter(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-24664(13); cmpwi 0,0; bne 0f; lwz 11,-26532(13); lis 4,-32696; addi 4,4,22528; lwz 9,0x0(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; stw 0,-24664(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_8007D748() {}
