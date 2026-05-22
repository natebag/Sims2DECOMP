// 0x80335744 ENgcMovie::PlayerQuit(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,1; bl _s80335744_0; bl _s80335744_1; cmpwi 3,0; bne 0f; li 30,0; 0:; lwz 3,-26360(13); cmpwi 3,0; beq 1f; bl _s80335744_2; 1:; mr 3,30; bl _s80335744_3; li 0,0; stw 0,0x20(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80335744_0();
extern "C" void _s80335744_1();
extern "C" void _s80335744_2();
extern "C" void _s80335744_3();
extern "C" void f_80335744() {}
