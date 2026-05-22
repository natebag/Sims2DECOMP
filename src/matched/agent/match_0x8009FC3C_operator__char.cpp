// 0x8009FC3C operator+(char, (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,5; mr 27,3; stb 4,0x8(1); mr 3,31; bl _s8009FC3C_0; addi 28,1,16; mr 6,3; addi 4,1,8; li 5,1; mr 3,28; bl _s8009FC3C_1; mr 3,31; bl _s8009FC3C_2; cmpwi 3,0; beq 0f; mr 3,28; bl _s8009FC3C_3; mr 29,3; mr 3,31; bl _s8009FC3C_4; mr 30,3; mr 3,31; bl _s8009FC3C_5; addi 5,3,1; mr 4,30; addi 3,29,1; bl _s8009FC3C_6; 0:; mr 3,28; bl _s8009FC3C_7; mr 30,3; mr 3,31; bl _s8009FC3C_8; lwz 0,0x0(30); mr 4,28; li 5,0; li 6,-1; add 0,0,3; stw 0,0x0(30); mr 3,27; bl _s8009FC3C_9; mr 3,28; li 4,2; bl _s8009FC3C_10; mr 3,27; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8009FC3C_0();
extern "C" void _s8009FC3C_1();
extern "C" void _s8009FC3C_2();
extern "C" void _s8009FC3C_3();
extern "C" void _s8009FC3C_4();
extern "C" void _s8009FC3C_5();
extern "C" void _s8009FC3C_6();
extern "C" void _s8009FC3C_7();
extern "C" void _s8009FC3C_8();
extern "C" void _s8009FC3C_9();
extern "C" void _s8009FC3C_10();
extern "C" void f_8009FC3C() {}
