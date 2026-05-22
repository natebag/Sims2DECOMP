// 0x8009CBB8 BString::append_str(char (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 27,5; mr 26,4; bl _s8009CBB8_0; not 0,27; cmplw 3,0; blt 0f; bl _s8009CBB8_1; 0:; mr 3,31; bl _s8009CBB8_2; cmplwi 3,1; bgt 1f; mr 3,31; addi 29,27,1; bl _s8009CBB8_3; mr 30,3; mr 3,31; bl _s8009CBB8_4; subf 30,3,30; cmplw 29,30; ble 2f; 1:; bl _s8009CBB8_5; li 4,16; li 5,0; bl _s8009CBB8_6; mr 28,3; mr 3,31; bl _s8009CBB8_7; mr 29,3; mr 3,31; bl _s8009CBB8_8; mr 30,3; mr 3,31; bl _s8009CBB8_9; add 6,3,27; mr 5,30; mr 4,29; mr 3,28; bl _s8009CBB8_10; mr 30,3; mr 3,31; bl _s8009CBB8_11; stw 30,0x0(31); 2:; cmpwi 27,0; beq 3f; mr 3,31; bl _s8009CBB8_12; mr 30,3; mr 3,31; bl _s8009CBB8_13; mr 4,26; mr 5,27; add 3,30,3; bl _s8009CBB8_14; mr 3,31; bl _s8009CBB8_15; mr 30,3; mr 3,31; bl _s8009CBB8_16; mr 29,3; bl _s8009CBB8_17; add 30,30,29; stbx 3,30,27; 3:; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,27; stw 0,0x4(9); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8009CBB8_0();
extern "C" void _s8009CBB8_1();
extern "C" void _s8009CBB8_2();
extern "C" void _s8009CBB8_3();
extern "C" void _s8009CBB8_4();
extern "C" void _s8009CBB8_5();
extern "C" void _s8009CBB8_6();
extern "C" void _s8009CBB8_7();
extern "C" void _s8009CBB8_8();
extern "C" void _s8009CBB8_9();
extern "C" void _s8009CBB8_10();
extern "C" void _s8009CBB8_11();
extern "C" void _s8009CBB8_12();
extern "C" void _s8009CBB8_13();
extern "C" void _s8009CBB8_14();
extern "C" void _s8009CBB8_15();
extern "C" void _s8009CBB8_16();
extern "C" void _s8009CBB8_17();
extern "C" void f_8009CBB8() {}
