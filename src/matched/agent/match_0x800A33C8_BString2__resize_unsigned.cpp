// 0x800A33C8 BString2::resize(unsigned (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,4; mr 29,3; sth 5,0x8(1); cmpwi 31,-1; bne 0f; bl _s800A33C8_0; 0:; mr 3,29; bl _s800A33C8_1; cmplwi 3,1; bgt 1f; mr 3,29; addi 30,31,1; bl _s800A33C8_2; cmplw 30,3; ble 6f; 1:; bl _s800A33C8_3; li 4,16; li 5,0; bl _s800A33C8_4; mr 28,3; mr 3,29; bl _s800A33C8_5; cmpwi 3,0; beq 2f; lwz 9,0x0(29); lwz 30,0x0(9); b 3f; 2:; li 30,0; 3:; mr 3,29; bl _s800A33C8_6; cmplw 31,3; ble 4f; mr 3,29; bl _s800A33C8_7; b 5f; 4:; mr 3,31; 5:; mr 5,3; mr 4,30; mr 6,31; mr 3,28; bl _s800A33C8_8; mr 30,3; mr 3,29; bl _s800A33C8_9; stw 30,0x0(29); 6:; lwz 9,0x0(29); lwz 0,0x4(9); cmplw 0,31; bge 8f; 7:; mr 3,29; bl _s800A33C8_10; lwz 11,0x0(29); rlwinm 3,3,1,0,30; lhz 0,0x8(1); lwz 9,0x0(11); sthx 0,3,9; lwz 10,0x0(29); lwz 9,0x4(10); addi 9,9,1; stw 9,0x4(10); lwz 11,0x0(29); lwz 0,0x4(11); cmplw 0,31; blt 7b; 8:; lwz 9,0x0(29); mr 3,29; stw 31,0x4(9); bl _s800A33C8_11; mr 30,3; lwz 29,0x0(29); bl _s800A33C8_12; lwz 9,0x0(29); add 30,30,30; sthx 3,30,9; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800A33C8_0();
extern "C" void _s800A33C8_1();
extern "C" void _s800A33C8_2();
extern "C" void _s800A33C8_3();
extern "C" void _s800A33C8_4();
extern "C" void _s800A33C8_5();
extern "C" void _s800A33C8_6();
extern "C" void _s800A33C8_7();
extern "C" void _s800A33C8_8();
extern "C" void _s800A33C8_9();
extern "C" void _s800A33C8_10();
extern "C" void _s800A33C8_11();
extern "C" void _s800A33C8_12();
extern "C" void f_800A33C8() {}
