// 0x8029B024 _drawCharacterInst(AptRenderingContext (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,5; mr 31,4; bl _s8029B024_0; li 29,0; addi 4,31,40; mr 3,30; bl _s8029B024_1; mr 3,30; bl _s8029B024_2; mr 3,31; bl _s8029B024_3; cmpwi 3,15; bne 0f; mr 3,31; bl _s8029B024_4; subfic 0,3,0; adde 29,0,3; 0:; cmpwi 29,0; beq 1f; lwz 4,0x48(31); mr 3,31; bl _s8029B024_5; 1:; mr 3,30; addi 4,31,16; bl _s8029B024_6; mr 6,28; li 5,0; mr 3,31; mr 4,30; bl _s8029B024_7; mr 3,30; bl _s8029B024_8; mr 3,30; bl _s8029B024_9; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8029B024_0();
extern "C" void _s8029B024_1();
extern "C" void _s8029B024_2();
extern "C" void _s8029B024_3();
extern "C" void _s8029B024_4();
extern "C" void _s8029B024_5();
extern "C" void _s8029B024_6();
extern "C" void _s8029B024_7();
extern "C" void _s8029B024_8();
extern "C" void _s8029B024_9();
extern "C" void f_8029B024() {}
