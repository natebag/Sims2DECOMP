// 0x8039DD88 TArray<EVec3, (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="ble 1f; subf 30,29,31; 0:; mr 4,31; mr 3,29; mr 5,28; addi 30,30,-4; bl _s8039DD88_0; addi 31,31,-4; srawi 0,30,2; cmpwi 0,1; bgt 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8039DD88_0();
extern "C" int f_8039DD88() {}
