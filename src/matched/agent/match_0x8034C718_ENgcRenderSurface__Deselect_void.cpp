// 0x8034C718 ENgcRenderSurface::Deselect(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; li 4,0; li 3,0; li 5,0; li 6,0; bl _s8034C718_0; lhz 5,0x2(29); li 4,0; lhz 6,0x6(29); li 3,0; bl _s8034C718_1; lwz 9,0x28(29); lhz 28,0x10(9); mr 3,9; lhz 30,0x12(9); bl _s8034C718_2; mr 5,3; li 6,0; mr 4,30; mr 3,28; bl _s8034C718_3; lwz 11,0x28(29); li 4,1; lwz 9,0x28(11); lwz 3,0x74(9); bl _s8034C718_4; bl _s8034C718_5; bl _s8034C718_6; bl _s8034C718_7; li 0,0; stw 0,0x24(29); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8034C718_0();
extern "C" void _s8034C718_1();
extern "C" void _s8034C718_2();
extern "C" void _s8034C718_3();
extern "C" void _s8034C718_4();
extern "C" void _s8034C718_5();
extern "C" void _s8034C718_6();
extern "C" void _s8034C718_7();
extern "C" void f_8034C718() {}
