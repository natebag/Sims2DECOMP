// 0x800D25FC TArray<EVec3, (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 30,3; lwz 3,-32056(13); bl _s800D25FC_0; mr 4,30; bl _s800D25FC_1; subfic 0,3,0; adde 3,0,3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800D25FC_0();
extern "C" void _s800D25FC_1();
extern "C" int f_800D25FC() {}
