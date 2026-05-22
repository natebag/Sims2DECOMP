// 0x8009EB48 BString::put_at(unsigned (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 31,3; mr 26,4; stb 5,0x8(1); bl _s8009EB48_0; cmplw 26,3; ble 0f; bl _s8009EB48_1; 0:; mr 3,31; bl _s8009EB48_2; cmplwi 3,1; bgt 1f; mr 3,31; addi 30,26,1; bl _s8009EB48_3; cmpw 30,3; bne 2f; 1:; bl _s8009EB48_4; li 4,16; li 5,0; bl _s8009EB48_5; mr 27,3; mr 3,31; bl _s8009EB48_6; mr 28,3; mr 3,31; bl _s8009EB48_7; mr 29,3; mr 3,31; bl _s8009EB48_8; mr 30,3; mr 3,31; bl _s8009EB48_9; xor 0,26,3; subfic 0,0,0; addze 6,30; mr 4,28; mr 5,29; mr 3,27; bl _s8009EB48_10; mr 30,3; mr 3,31; bl _s8009EB48_11; stw 30,0x0(31); 2:; mr 3,31; bl _s8009EB48_12; cmpw 26,3; bne 3f; lwz 11,0x0(31); lwz 9,0x4(11); addi 9,9,1; stw 9,0x4(11); 3:; mr 3,31; bl _s8009EB48_13; lbz 0,0x8(1); stbx 0,3,26; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s8009EB48_0();
extern "C" void _s8009EB48_1();
extern "C" void _s8009EB48_2();
extern "C" void _s8009EB48_3();
extern "C" void _s8009EB48_4();
extern "C" void _s8009EB48_5();
extern "C" void _s8009EB48_6();
extern "C" void _s8009EB48_7();
extern "C" void _s8009EB48_8();
extern "C" void _s8009EB48_9();
extern "C" void _s8009EB48_10();
extern "C" void _s8009EB48_11();
extern "C" void _s8009EB48_12();
extern "C" void _s8009EB48_13();
extern "C" void f_8009EB48() {}
