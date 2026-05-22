// 0x801E87F8 TArray<EVec3, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 5,8; bl _s801E87F8_0; li 3,0; bl _s801E87F8_1; mr 30,3; bl _s801E87F8_2; lhz 0,0x12(30); li 5,0; lhz 4,0x10(30); mullw 4,4,0; rlwinm 4,4,1,0,30; bl _s801E87F8_3; stw 3,0xb4(31); mr 3,31; lwz 0,0xa4(1); mtspr 8,0; lmw 14,0x58(1); addi 1,1,160"
extern "C" void _s801E87F8_0();
extern "C" void _s801E87F8_1();
extern "C" void _s801E87F8_2();
extern "C" void _s801E87F8_3();
extern "C" void f_801E87F8() {}
