// 0x80248500 TArray<EVec3, (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-27948(13); bl _s80248500_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80248500_0();
extern "C" void f_80248500() {}
