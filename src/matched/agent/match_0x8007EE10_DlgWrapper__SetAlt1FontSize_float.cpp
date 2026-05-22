// 0x8007EE10 DlgWrapper::SetAlt1FontSize(float) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 29,0xac(3); lwz 30,0x48(29); addi 9,30,32; mr 3,9; stfs f1,0x34(9); bl _s8007EE10_0; lwz 0,0x4(30); mr 3,29; li 4,2; ori 0,0,2; stw 0,0x4(30); bl _s8007EE10_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8007EE10_0();
extern "C" void _s8007EE10_1();
extern "C" void f_8007EE10() {}
