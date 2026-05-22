// 0x800D2670 GetTotalMemoryCardCacheSize(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-32056(13); bl _s800D2670_0; lis 4,-32696; addi 4,4,25388; bl _s800D2670_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800D2670_0();
extern "C" void _s800D2670_1();
extern "C" void f_800D2670() {}
