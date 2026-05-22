// 0x800A1EB4 BString2::operator=(wchar_t) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; sth 4,0x8(1); bl _s800A1EB4_0; mr 29,3; cmpwi 29,1; bne 0f; mr 3,31; bl _s800A1EB4_1; cmplwi 3,1; ble 0f; mr 3,31; bl _s800A1EB4_2; lhz 0,0x8(1); sth 0,0x0(3); mr 3,31; bl _s800A1EB4_3; mr 30,3; bl _s800A1EB4_4; sth 3,0x2(30); lwz 9,0x0(31); stw 29,0x4(9); b 1f; 0:; mr 3,31; bl _s800A1EB4_5; bl _s800A1EB4_6; li 4,16; li 5,0; bl _s800A1EB4_7; lhz 4,0x8(1); li 5,1; bl _s800A1EB4_8; stw 3,0x0(31); 1:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800A1EB4_0();
extern "C" void _s800A1EB4_1();
extern "C" void _s800A1EB4_2();
extern "C" void _s800A1EB4_3();
extern "C" void _s800A1EB4_4();
extern "C" void _s800A1EB4_5();
extern "C" void _s800A1EB4_6();
extern "C" void _s800A1EB4_7();
extern "C" void _s800A1EB4_8();
extern "C" void f_800A1EB4() {}
