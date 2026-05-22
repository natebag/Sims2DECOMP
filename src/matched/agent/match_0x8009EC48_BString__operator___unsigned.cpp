// 0x8009EC48 BString::operator[](unsigned (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 27,4; bl _s8009EC48_0; cmplw 27,3; blt 0f; bl _s8009EC48_1; 0:; mr 3,31; bl _s8009EC48_2; cmplwi 3,1; ble 1f; bl _s8009EC48_3; li 4,16; li 5,0; bl _s8009EC48_4; mr 28,3; mr 3,31; bl _s8009EC48_5; mr 29,3; mr 3,31; bl _s8009EC48_6; mr 30,3; mr 3,31; bl _s8009EC48_7; mr 6,3; mr 5,30; mr 4,29; mr 3,28; bl _s8009EC48_8; mr 30,3; mr 3,31; bl _s8009EC48_9; stw 30,0x0(31); 1:; mr 3,31; bl _s8009EC48_10; add 3,3,27; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009EC48_0();
extern "C" void _s8009EC48_1();
extern "C" void _s8009EC48_2();
extern "C" void _s8009EC48_3();
extern "C" void _s8009EC48_4();
extern "C" void _s8009EC48_5();
extern "C" void _s8009EC48_6();
extern "C" void _s8009EC48_7();
extern "C" void _s8009EC48_8();
extern "C" void _s8009EC48_9();
extern "C" void _s8009EC48_10();
extern "C" void f_8009EC48() {}
