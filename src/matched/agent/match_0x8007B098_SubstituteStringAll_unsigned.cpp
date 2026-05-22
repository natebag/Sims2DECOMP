// 0x8007B098 SubstituteStringAll(unsigned (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-552(1); mfspr 0,8; stmw 26,0x210(1); stw 0,0x22c(1); addi 30,1,8; mr 29,3; mr 26,4; mr 27,5; mr 31,6; addi 4,30,8; li 5,256; mr 3,30; bl _s8007B098_0; li 28,0; mr 4,29; li 5,-1; mr 3,30; bl _s8007B098_1; mr 3,31; bl _s8007B098_2; mr 4,30; mr 3,31; li 5,-1; bl _s8007B098_3; 0:; mr 3,31; bl _s8007B098_4; mr 4,26; mr 5,27; mr 6,31; bl _s8007B098_5; cmpwi 28,0; bne 1f; cmpwi 3,0; beq 2f; li 28,1; 1:; cmpwi 3,0; bne 0b; 2:; mr 3,28; lwz 0,0x22c(1); mtspr 8,0; lmw 26,0x210(1); addi 1,1,552"
extern "C" void _s8007B098_0();
extern "C" void _s8007B098_1();
extern "C" void _s8007B098_2();
extern "C" void _s8007B098_3();
extern "C" void _s8007B098_4();
extern "C" void _s8007B098_5();
extern "C" void f_8007B098() {}
