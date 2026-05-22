// 0x802F1324 EGraphics::AllocDL(RCMode) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,104; bl _s802F1324_0; li 4,4096; bl _s802F1324_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802F1324_0();
extern "C" void _s802F1324_1();
extern "C" void f_802F1324() {}
