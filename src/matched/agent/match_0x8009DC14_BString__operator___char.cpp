// 0x8009DC14 BString::operator+=(char) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; stb 4,0x8(1); bl _s8009DC14_0; li 0,-3; cmplw 3,0; ble 0f; bl _s8009DC14_1; 0:; mr 3,31; bl _s8009DC14_2; cmpwi 3,1; bne 1f; mr 3,31; bl _s8009DC14_3; mr 30,3; mr 3,31; bl _s8009DC14_4; addi 3,3,1; cmplw 30,3; bgt 2f; 1:; bl _s8009DC14_5; li 4,16; li 5,0; bl _s8009DC14_6; mr 28,3; mr 3,31; bl _s8009DC14_7; mr 29,3; mr 3,31; bl _s8009DC14_8; mr 30,3; mr 3,31; bl _s8009DC14_9; addi 6,3,1; mr 5,30; mr 4,29; mr 3,28; bl _s8009DC14_10; mr 30,3; mr 3,31; bl _s8009DC14_11; stw 30,0x0(31); 2:; mr 3,31; bl _s8009DC14_12; mr 30,3; mr 3,31; bl _s8009DC14_13; lbz 0,0x8(1); stbx 0,30,3; mr 3,31; bl _s8009DC14_14; mr 30,3; mr 3,31; bl _s8009DC14_15; mr 29,3; bl _s8009DC14_16; add 30,30,29; stb 3,0x1(30); mr 3,31; lwz 11,0x0(31); lwz 9,0x4(11); addi 9,9,1; stw 9,0x4(11); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8009DC14_0();
extern "C" void _s8009DC14_1();
extern "C" void _s8009DC14_2();
extern "C" void _s8009DC14_3();
extern "C" void _s8009DC14_4();
extern "C" void _s8009DC14_5();
extern "C" void _s8009DC14_6();
extern "C" void _s8009DC14_7();
extern "C" void _s8009DC14_8();
extern "C" void _s8009DC14_9();
extern "C" void _s8009DC14_10();
extern "C" void _s8009DC14_11();
extern "C" void _s8009DC14_12();
extern "C" void _s8009DC14_13();
extern "C" void _s8009DC14_14();
extern "C" void _s8009DC14_15();
extern "C" void _s8009DC14_16();
extern "C" void f_8009DC14() {}
