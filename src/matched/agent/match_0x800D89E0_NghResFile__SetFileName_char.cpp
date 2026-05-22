// 0x800D89E0 NghResFile::SetFileName(char (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); addi 30,3,40; mr 29,4; mr 3,30; bl _s800D89E0_0; mr 3,30; mr 4,29; li 5,-1; bl _s800D89E0_1; li 3,1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800D89E0_0();
extern "C" void _s800D89E0_1();
extern "C" void f_800D89E0() {}
