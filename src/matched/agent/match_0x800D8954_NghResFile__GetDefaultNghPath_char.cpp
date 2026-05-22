// 0x800D8954 NghResFile::GetDefaultNghPath(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-304(1); mfspr 0,8; stmw 27,0x11c(1); stw 0,0x134(1); lwz 11,-26824(13); addi 30,1,8; mr 28,5; mr 27,4; lwz 9,0x338(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; mr 29,3; addi 4,30,8; li 5,260; mr 3,30; bl _s800D8954_0; li 5,-1; mr 4,29; mr 3,30; bl _s800D8954_1; mr 4,30; mr 3,28; bl _s800D8954_2; mr 3,28; mr 4,27; li 5,-1; bl _s800D8954_3; lwz 0,0x134(1); mtspr 8,0; lmw 27,0x11c(1); addi 1,1,304"
extern "C" void _s800D8954_0();
extern "C" void _s800D8954_1();
extern "C" void _s800D8954_2();
extern "C" void _s800D8954_3();
extern "C" void f_800D8954() {}
