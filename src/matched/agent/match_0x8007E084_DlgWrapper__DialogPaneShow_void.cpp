// 0x8007E084 DlgWrapper::DialogPaneShow(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 29,0; lwz 9,0xb8(30); addi 9,9,1; stw 9,0xb8(30); bl _s8007E084_0; lis 4,-32707; mr 3,30; addi 4,4,27072; bl _s8007E084_1; lwz 3,0xac(30); stw 29,0xb4(30); bl _s8007E084_2; lwz 9,0xac(30); lwz 0,0x4(9); mr 3,9; ori 0,0,1; stw 0,0x4(9); bl _s8007E084_3; lwz 9,0xac(30); stw 29,0x34(9); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8007E084_0();
extern "C" void _s8007E084_1();
extern "C" void _s8007E084_2();
extern "C" void _s8007E084_3();
extern "C" void f_8007E084() {}
