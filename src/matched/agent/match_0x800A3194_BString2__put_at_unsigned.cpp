// 0x800A3194 BString2::put_at(unsigned (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 31,3; mr 27,4; sth 5,0x8(1); bl _s800A3194_0; cmplw 27,3; ble 0f; bl _s800A3194_1; 0:; mr 3,31; bl _s800A3194_2; cmplwi 3,1; bgt 1f; mr 3,31; addi 30,27,1; bl _s800A3194_3; cmpw 30,3; bne 4f; 1:; bl _s800A3194_4; li 4,16; li 5,0; bl _s800A3194_5; mr 26,3; mr 3,31; bl _s800A3194_6; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 28,0x0(9); b 3f; 2:; li 28,0; 3:; mr 3,31; bl _s800A3194_7; mr 29,3; mr 3,31; bl _s800A3194_8; mr 30,3; mr 3,31; bl _s800A3194_9; xor 0,27,3; subfic 0,0,0; addze 6,30; mr 4,28; mr 5,29; mr 3,26; bl _s800A3194_10; mr 30,3; mr 3,31; bl _s800A3194_11; stw 30,0x0(31); 4:; mr 3,31; bl _s800A3194_12; cmpw 27,3; bne 5f; lwz 11,0x0(31); lwz 9,0x4(11); addi 9,9,1; stw 9,0x4(11); 5:; mr 3,31; bl _s800A3194_13; lhz 9,0x8(1); add 0,27,27; sthx 9,3,0; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s800A3194_0();
extern "C" void _s800A3194_1();
extern "C" void _s800A3194_2();
extern "C" void _s800A3194_3();
extern "C" void _s800A3194_4();
extern "C" void _s800A3194_5();
extern "C" void _s800A3194_6();
extern "C" void _s800A3194_7();
extern "C" void _s800A3194_8();
extern "C" void _s800A3194_9();
extern "C" void _s800A3194_10();
extern "C" void _s800A3194_11();
extern "C" void _s800A3194_12();
extern "C" void _s800A3194_13();
extern "C" void f_800A3194() {}
