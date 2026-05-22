// 0x802AFFA0 AptTextFormat::operator (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; lwz 3,-23016(13); bl _s802AFFA0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802AFFA0_0();
extern "C" void f_802AFFA0() {}
