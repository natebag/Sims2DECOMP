// 0x80014D2C BGExec_FlushResQueue(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-22652(13); lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; stw 0,-21480(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80014D2C() {}
