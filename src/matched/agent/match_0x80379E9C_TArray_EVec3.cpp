// 0x80379E9C TArray<EVec3, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sth 0,0x34(3); li 4,54; bl _s80379E9C_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80379E9C_0();
extern "C" void f_80379E9C() {}
