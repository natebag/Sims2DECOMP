// 0x800BAB6C TArray<EVec3, (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f0,0x1c(30); stw 11,0x18(30); stw 10,0x8(30); stw 8,0x20(30); stw 8,0x4(30); bl _s800BAB6C_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800BAB6C_0();
extern "C" void f_800BAB6C() {}
