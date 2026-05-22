// 0x800A598C ExtractExtension(StringBuffer (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-576(1); mfspr 0,8; stmw 26,0x228(1); stw 0,0x244(1); addi 30,1,8; mr 26,4; mr 27,3; mr 28,5; addi 29,1,280; addi 4,30,8; li 5,260; mr 3,30; bl _s800A598C_0; addi 4,1,288; addi 3,1,280; li 5,260; bl _s800A598C_1; mr 5,29; mr 6,28; mr 3,27; mr 4,30; bl _s800A598C_2; mr 4,30; mr 3,26; bl _s800A598C_3; mr 3,26; mr 4,29; li 5,-1; bl _s800A598C_4; lwz 0,0x244(1); mtspr 8,0; lmw 26,0x228(1); addi 1,1,576"
extern "C" void _s800A598C_0();
extern "C" void _s800A598C_1();
extern "C" void _s800A598C_2();
extern "C" void _s800A598C_3();
extern "C" void _s800A598C_4();
extern "C" void f_800A598C() {}
