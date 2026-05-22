// 0x8009FB54 operator+(char (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,3; mr 31,5; mr. 30,4; beq 0f; mr 3,30; bl _s8009FB54_0; mr 28,3; b 1f; 0:; li 28,0; 1:; mr 3,31; bl _s8009FB54_1; mr 6,3; mr 4,30; mr 5,28; addi 3,1,8; bl _s8009FB54_2; mr 3,31; bl _s8009FB54_3; cmpwi 3,0; beq 2f; addi 3,1,8; bl _s8009FB54_4; mr 29,3; mr 3,31; bl _s8009FB54_5; mr 30,3; mr 3,31; bl _s8009FB54_6; addi 5,3,1; mr 4,30; add 3,29,28; bl _s8009FB54_7; 2:; addi 3,1,8; bl _s8009FB54_8; mr 30,3; mr 3,31; bl _s8009FB54_9; lwz 0,0x0(30); addi 4,1,8; li 5,0; li 6,-1; add 0,0,3; stw 0,0x0(30); mr 3,27; bl _s8009FB54_10; addi 3,1,8; li 4,2; bl _s8009FB54_11; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8009FB54_0();
extern "C" void _s8009FB54_1();
extern "C" void _s8009FB54_2();
extern "C" void _s8009FB54_3();
extern "C" void _s8009FB54_4();
extern "C" void _s8009FB54_5();
extern "C" void _s8009FB54_6();
extern "C" void _s8009FB54_7();
extern "C" void _s8009FB54_8();
extern "C" void _s8009FB54_9();
extern "C" void _s8009FB54_10();
extern "C" void _s8009FB54_11();
extern "C" void f_8009FB54() {}
