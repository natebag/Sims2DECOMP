// 0x8009D834 BString::BString(char (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,6; mr 31,5; not 0,30; mr 29,3; mr 28,4; cmplw 31,0; blt 0f; bl _s8009D834_0; 0:; bl _s8009D834_1; li 4,16; li 5,0; bl _s8009D834_2; mr 5,31; mr 4,28; add 6,5,30; bl _s8009D834_3; stw 3,0x0(29); mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009D834_0();
extern "C" void _s8009D834_1();
extern "C" void _s8009D834_2();
extern "C" void _s8009D834_3();
extern "C" void f_8009D834() {}
