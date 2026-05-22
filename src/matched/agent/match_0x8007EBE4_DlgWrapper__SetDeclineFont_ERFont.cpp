// 0x8007EBE4 DlgWrapper::SetDeclineFont(ERFont (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 29,0xac(3); lwz 30,0x44(29); addi 3,30,32; stw 4,0x30(3); bl _s8007EBE4_0; lwz 0,0x4(30); mr 3,29; li 4,1; ori 0,0,2; stw 0,0x4(30); bl _s8007EBE4_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8007EBE4_0();
extern "C" void _s8007EBE4_1();
extern "C" void f_8007EBE4() {}
