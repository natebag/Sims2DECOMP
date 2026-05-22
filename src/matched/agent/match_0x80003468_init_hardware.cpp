// 0x80003468 __init_hardware (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfmsr 0; ori 0,0,8192; mtmsr 0; mfspr 31,8; bl _s80003468_0; bl _s80003468_1; bl _s80003468_2; mtspr 8,31"
extern "C" void _s80003468_0();
extern "C" void _s80003468_1();
extern "C" void _s80003468_2();
extern "C" int f_80003468() {}
