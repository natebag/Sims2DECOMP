// 0x801AC9B0 E2ETarget::SaveGame(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,1; lis 9,-32705; stw 0,0xe0(3); li 4,0; addi 3,9,-2052; li 5,0; li 6,0; li 7,0; bl _s801AC9B0_0; lis 3,-32705; li 4,3; addi 3,3,-2032; bl _s801AC9B0_1; lis 3,-32705; addi 3,3,-2020; bl _s801AC9B0_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801AC9B0_0();
extern "C" void _s801AC9B0_1();
extern "C" void _s801AC9B0_2();
extern "C" void f_801AC9B0() {}
