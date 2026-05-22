// 0x801890B0 TArray<ENDummyPoint, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s801890B0_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr"
extern "C" void _s801890B0_0();
extern "C" int f_801890B0() {}
