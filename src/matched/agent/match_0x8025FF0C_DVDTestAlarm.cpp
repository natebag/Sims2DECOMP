// 0x8025FF0C __DVDTestAlarm (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); addi 0,4,-17136; cmplw 3,0; stwu 1,-8(1); bne 0f; li 3,1; b 1f; 0:; bl _s8025FF0C_0; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025FF0C_0();
extern "C" void f_8025FF0C() {}
