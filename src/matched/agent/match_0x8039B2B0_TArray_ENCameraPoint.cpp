// 0x8039B2B0 TArray<ENCameraPoint, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,16384; bl _s8039B2B0_0; bl _s8039B2B0_1; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B2B0_0();
extern "C" void _s8039B2B0_1();
extern "C" int f_8039B2B0() {}
