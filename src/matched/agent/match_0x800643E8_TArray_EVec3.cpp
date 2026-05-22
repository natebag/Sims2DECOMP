// 0x800643E8 TArray<EVec3, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,820; li 7,0; bl _s800643E8_0; mr 30,3; cmpwi 30,0; beq 0f; lwz 3,0x8(31); mr 4,30; lfs f1,0xfc(31); addi 3,3,820; bl _s800643E8_1; li 0,0; stb 0,0xd(30); 0:; lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x34(1); lfd f31,0x40(1); addi 1,1,72"
extern "C" void _s800643E8_0();
extern "C" void _s800643E8_1();
extern "C" void f_800643E8() {}
