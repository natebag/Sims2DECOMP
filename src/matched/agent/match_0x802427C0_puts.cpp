// 0x802427C0 puts (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; lwz 3,-27948(13); bl _s802427C0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802427C0_0();
extern "C" void f_802427C0() {}
