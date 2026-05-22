// 0x802F1390 EGraphics::AllocRC(RCMode) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,116; bl _s802F1390_0; bl _s802F1390_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802F1390_0();
extern "C" void _s802F1390_1();
extern "C" void f_802F1390() {}
