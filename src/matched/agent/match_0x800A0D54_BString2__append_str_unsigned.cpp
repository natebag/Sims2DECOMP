// 0x800A0D54 BString2::append_str(unsigned (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 27,5; mr 26,4; bl _s800A0D54_0; not 0,27; cmplw 3,0; blt 0f; bl _s800A0D54_1; 0:; mr 3,31; bl _s800A0D54_2; cmplwi 3,1; bgt 1f; mr 3,31; addi 29,27,1; bl _s800A0D54_3; mr 30,3; mr 3,31; bl _s800A0D54_4; subf 30,3,30; cmplw 29,30; ble 4f; 1:; bl _s800A0D54_5; li 4,16; li 5,0; bl _s800A0D54_6; mr 28,3; mr 3,31; bl _s800A0D54_7; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 29,0x0(9); b 3f; 2:; li 29,0; 3:; mr 3,31; bl _s800A0D54_8; mr 30,3; mr 3,31; bl _s800A0D54_9; add 6,3,27; mr 5,30; mr 4,29; mr 3,28; bl _s800A0D54_10; mr 30,3; mr 3,31; bl _s800A0D54_11; stw 30,0x0(31); 4:; cmpwi 27,0; beq 5f; mr 3,31; add 28,27,27; bl _s800A0D54_12; mr 30,3; mr 3,31; bl _s800A0D54_13; rlwinm 3,3,1,0,30; mr 4,26; mr 5,28; add 3,3,30; bl _s800A0D54_14; mr 3,31; bl _s800A0D54_15; mr 29,3; mr 3,31; bl _s800A0D54_16; mr 30,3; bl _s800A0D54_17; add 30,30,30; add 30,30,29; sthx 3,28,30; 5:; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,27; stw 0,0x4(9); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800A0D54_0();
extern "C" void _s800A0D54_1();
extern "C" void _s800A0D54_2();
extern "C" void _s800A0D54_3();
extern "C" void _s800A0D54_4();
extern "C" void _s800A0D54_5();
extern "C" void _s800A0D54_6();
extern "C" void _s800A0D54_7();
extern "C" void _s800A0D54_8();
extern "C" void _s800A0D54_9();
extern "C" void _s800A0D54_10();
extern "C" void _s800A0D54_11();
extern "C" void _s800A0D54_12();
extern "C" void _s800A0D54_13();
extern "C" void _s800A0D54_14();
extern "C" void _s800A0D54_15();
extern "C" void _s800A0D54_16();
extern "C" void _s800A0D54_17();
extern "C" void f_800A0D54() {}
