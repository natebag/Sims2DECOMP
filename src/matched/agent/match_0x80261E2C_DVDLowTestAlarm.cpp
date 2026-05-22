// 0x80261E2C __DVDLowTestAlarm (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32694; addi 0,4,-16808; cmplw 3,0; bne 0f; li 3,1; blr; 0:; lis 4,-32694; addi 0,4,-16848; cmplw 3,0; bne 1f; li 3,1; blr; 1:; li 3,0"
extern "C" int f_80261E2C() {}
