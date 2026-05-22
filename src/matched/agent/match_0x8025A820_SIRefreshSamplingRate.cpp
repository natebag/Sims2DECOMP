// 0x8025A820 SIRefreshSamplingRate (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 3,-23528(13); bl _s8025A820_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025A820_0();
extern "C" void f_8025A820() {}
