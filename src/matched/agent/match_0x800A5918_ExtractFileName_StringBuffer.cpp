// 0x800A5918 ExtractFileName(StringBuffer (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-568(1); mfspr 0,8; stmw 28,0x228(1); stw 0,0x23c(1); addi 29,1,8; mr 30,4; mr 28,3; li 5,260; addi 4,29,8; mr 3,29; bl _s800A5918_0; addi 4,1,288; li 5,260; addi 3,1,280; bl _s800A5918_1; mr 3,28; addi 4,1,280; mr 5,30; mr 6,29; bl _s800A5918_2; mr 3,30; mr 4,29; li 5,-1; bl _s800A5918_3; lwz 0,0x23c(1); mtspr 8,0; lmw 28,0x228(1); addi 1,1,568"
extern "C" void _s800A5918_0();
extern "C" void _s800A5918_1();
extern "C" void _s800A5918_2();
extern "C" void _s800A5918_3();
extern "C" void f_800A5918() {}
