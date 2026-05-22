// 0x8009FDE8 operator+(BString (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 29,4; mr 28,3; stb 5,0x10(1); mr 3,29; bl _s8009FDE8_0; mr 30,3; mr 3,29; bl _s8009FDE8_1; mr 5,3; mr 4,30; addi 3,1,8; li 6,1; bl _s8009FDE8_2; addi 3,1,8; bl _s8009FDE8_3; mr 30,3; mr 3,29; bl _s8009FDE8_4; lbz 0,0x10(1); stbx 0,30,3; addi 3,1,8; bl _s8009FDE8_5; mr 11,3; lwz 9,0x0(11); addi 3,1,8; addi 9,9,1; stw 9,0x0(11); bl _s8009FDE8_6; mr 29,3; addi 3,1,8; bl _s8009FDE8_7; mr 30,3; bl _s8009FDE8_8; stbx 3,29,30; addi 4,1,8; li 5,0; li 6,-1; mr 3,28; bl _s8009FDE8_9; addi 3,1,8; li 4,2; bl _s8009FDE8_10; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s8009FDE8_0();
extern "C" void _s8009FDE8_1();
extern "C" void _s8009FDE8_2();
extern "C" void _s8009FDE8_3();
extern "C" void _s8009FDE8_4();
extern "C" void _s8009FDE8_5();
extern "C" void _s8009FDE8_6();
extern "C" void _s8009FDE8_7();
extern "C" void _s8009FDE8_8();
extern "C" void _s8009FDE8_9();
extern "C" void _s8009FDE8_10();
extern "C" void f_8009FDE8() {}
