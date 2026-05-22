// 0x800A58B4 ExtractDirectory(StringBuffer (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-568(1); mfspr 0,8; stmw 28,0x228(1); stw 0,0x23c(1); addi 29,1,8; mr 30,3; mr 28,4; li 5,260; addi 4,29,8; mr 3,29; bl _s800A58B4_0; addi 4,1,288; li 5,260; addi 3,1,280; bl _s800A58B4_1; mr 3,30; mr 4,28; mr 5,29; addi 6,1,280; bl _s800A58B4_2; lwz 0,0x23c(1); mtspr 8,0; lmw 28,0x228(1); addi 1,1,568"
extern "C" void _s800A58B4_0();
extern "C" void _s800A58B4_1();
extern "C" void _s800A58B4_2();
extern "C" void f_800A58B4() {}
