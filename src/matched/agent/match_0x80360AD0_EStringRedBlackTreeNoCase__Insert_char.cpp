// 0x80360AD0 EStringRedBlackTreeNoCase::Insert(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; mr 28,5; cmpwi 6,0; beq 0f; bl _s80360AD0_0; mr 4,3; mr 5,31; mr 3,30; b 2f; 0:; mr 3,30; mr 4,31; bl _s80360AD0_1; mr. 29,3; beq 1f; addi 3,29,28; mr 4,31; bl _s80360AD0_2; cmpwi 3,0; li 3,0; beq 3f; 1:; mr 3,30; mr 4,29; mr 5,31; 2:; mr 6,28; bl _s80360AD0_3; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80360AD0_0();
extern "C" void _s80360AD0_1();
extern "C" void _s80360AD0_2();
extern "C" void _s80360AD0_3();
extern "C" void f_80360AD0() {}
