// 0x8002DCF0 ERoom::InitRoomLookupTab(void) (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 25,3; lwz 9,0x94(25); addi 29,25,148; b 2f; 0:; lwz 30,0x1c(9); lwz 31,0x10(9); mr 3,30; cmpwi 30,0; beq 1f; bl _s8002DCF0_0; mr 3,30; bl _s8002DCF0_1; 1:; mr 9,31; 2:; li 0,1; cmpwi 9,0; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; mr 3,29; addi 31,25,160; bl _s8002DCF0_2; lwz 30,0xa0(25); mr 23,31; addi 21,25,112; b 5f; 4:; lwz 3,0x1c(30); lwz 30,0x10(30); bl _s8002DCF0_3; 5:; li 0,1; cmpwi 30,0; bne 6f; li 0,0; 6:; cmpwi 0,0; bne 4b; mr 3,31; bl _s8002DCF0_4; li 9,0; 7:; rlwinm 0,9,2,0,29; addi 24,9,1; lwzx 9,21,0; cmpwi 9,0; beq 11f; lwz 27,0x0(9); cmpwi 27,0; beq 11f; addi 26,25,148; li 22,1; 8:; lwz 29,0x0(27); mr 3,26; li 5,0; lhz 28,0x28(29); mr 4,28; bl _s8002DCF0_5; mr. 31,3; beq 9f; lwz 3,0x1c(31); mr 4,29; bl _s8002DCF0_6; b 10f; 9:; li 3,12; bl _s8002DCF0_7; mr 30,3; li 6,0; mr 5,30; mr 4,28; stw 31,0x0(30); mr 3,26; stw 31,0x4(30); stw 22,0x8(30); bl _s8002DCF0_8; mr 4,29; mr 3,30; bl _s8002DCF0_9; li 3,32; bl _s8002DCF0_10; mr 5,3; mr 4,28; mr 3,23; li 6,0; bl _s8002DCF0_11; 10:; lwz 27,0x8(27); cmpwi 27,0; bne 8b; 11:; mr 9,24; cmpwi 9,7; ble 7b; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s8002DCF0_0();
extern "C" void _s8002DCF0_1();
extern "C" void _s8002DCF0_2();
extern "C" void _s8002DCF0_3();
extern "C" void _s8002DCF0_4();
extern "C" void _s8002DCF0_5();
extern "C" void _s8002DCF0_6();
extern "C" void _s8002DCF0_7();
extern "C" void _s8002DCF0_8();
extern "C" void _s8002DCF0_9();
extern "C" void _s8002DCF0_10();
extern "C" void _s8002DCF0_11();
extern "C" void f_8002DCF0() {}
