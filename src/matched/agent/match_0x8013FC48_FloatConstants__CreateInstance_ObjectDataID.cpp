// 0x8013FC48 FloatConstants::CreateInstance(ObjectDataID (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s8013FC48_0; b 0f; lis 3,-32696; li 4,2; addi 3,3,26884; bl _s8013FC48_1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8013FC48_0();
extern "C" void _s8013FC48_1();
extern "C" int f_8013FC48() {}
