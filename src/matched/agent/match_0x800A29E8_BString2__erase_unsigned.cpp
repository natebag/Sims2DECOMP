// 0x800A29E8 BString2::erase(unsigned (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 29,5; bl _s800A29E8_0; cmplw 30,3; ble 0f; bl _s800A29E8_1; 0:; mr 3,31; bl _s800A29E8_2; subf 3,30,3; cmplw 29,3; ble 1f; mr 3,31; bl _s800A29E8_3; subf 28,30,3; b 2f; 1:; mr 28,29; 2:; mr 3,31; bl _s800A29E8_4; cmplwi 3,1; ble 7f; bl _s800A29E8_5; li 4,16; li 5,0; bl _s800A29E8_6; mr 27,3; mr 3,31; bl _s800A29E8_7; cmpwi 3,0; beq 3f; lwz 9,0x0(31); lwz 29,0x0(9); b 4f; 3:; li 29,0; 4:; mr 3,31; bl _s800A29E8_8; mr 6,3; mr 4,29; mr 3,27; mr 5,30; bl _s800A29E8_9; mr 27,3; mr 3,31; bl _s800A29E8_10; cmpwi 3,0; beq 5f; lwz 9,0x0(31); lwz 29,0x0(9); b 6f; 5:; li 29,0; 6:; mr 3,31; bl _s800A29E8_11; subf 5,28,3; lwz 9,0x0(27); add 3,30,30; subf 5,30,5; add 0,3,29; add 4,28,28; add 4,4,0; add 3,3,9; rlwinm 5,5,1,0,30; bl _s800A29E8_12; mr 3,31; bl _s800A29E8_13; subf 3,28,3; stw 3,0x4(27); mr 3,31; bl _s800A29E8_14; stw 27,0x0(31); b 12f; 7:; mr 3,31; bl _s800A29E8_15; cmpw 28,3; bne 8f; lwz 9,0x0(31); li 0,0; b 11f; 8:; cmpwi 28,0; beq 12f; mr 3,31; bl _s800A29E8_16; mr 27,3; mr 3,31; bl _s800A29E8_17; cmpwi 3,0; beq 9f; lwz 9,0x0(31); lwz 29,0x0(9); b 10f; 9:; li 29,0; 10:; mr 3,31; bl _s800A29E8_18; subf 5,28,3; add 4,30,30; add 0,28,28; add 4,4,29; subf 5,30,5; add 3,30,30; add 4,0,4; add 3,3,27; rlwinm 5,5,1,0,30; bl _s800A29E8_19; lwz 9,0x0(31); lwz 0,0x4(9); subf 0,28,0; 11:; stw 0,0x4(9); 12:; mr 3,31; bl _s800A29E8_20; cmpwi 3,0; beq 13f; mr 3,31; bl _s800A29E8_21; mr 29,3; mr 3,31; bl _s800A29E8_22; mr 30,3; bl _s800A29E8_23; add 30,30,30; sthx 3,30,29; 13:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A29E8_0();
extern "C" void _s800A29E8_1();
extern "C" void _s800A29E8_2();
extern "C" void _s800A29E8_3();
extern "C" void _s800A29E8_4();
extern "C" void _s800A29E8_5();
extern "C" void _s800A29E8_6();
extern "C" void _s800A29E8_7();
extern "C" void _s800A29E8_8();
extern "C" void _s800A29E8_9();
extern "C" void _s800A29E8_10();
extern "C" void _s800A29E8_11();
extern "C" void _s800A29E8_12();
extern "C" void _s800A29E8_13();
extern "C" void _s800A29E8_14();
extern "C" void _s800A29E8_15();
extern "C" void _s800A29E8_16();
extern "C" void _s800A29E8_17();
extern "C" void _s800A29E8_18();
extern "C" void _s800A29E8_19();
extern "C" void _s800A29E8_20();
extern "C" void _s800A29E8_21();
extern "C" void _s800A29E8_22();
extern "C" void _s800A29E8_23();
extern "C" void f_800A29E8() {}
