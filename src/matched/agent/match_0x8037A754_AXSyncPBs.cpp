// 0x8037A754 __AXSyncPBs (632 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32690; stw 0,0x4(1); li 0,0; stwu 1,-40(1); stmw 26,0x10(1); addi 30,4,29248; lis 4,-32699; addi 26,3,0; addi 31,4,19656; addi 3,30,0; li 4,15616; stw 0,-22096(13); bl _s8037A754_0; addi 3,30,15616; li 4,4096; bl _s8037A754_1; bl _s8037A754_2; addis 0,3,1; add 29,0,26; li 28,31; addi 29,29,-22000; 0:; mr 3,28; bl _s8037A754_3; mr 27,3; b 10f; 1:; lwz 0,0x20(27); cmplwi 0,0; beq 2f; lwz 0,0x18(27); mulli 0,0,244; add 3,30,0; bl _s8037A754_4; 2:; lhz 0,0x146(27); cmplwi 0,1; beq 3f; lwz 0,0x28(27); cmplwi 0,0; beq 8f; 3:; lhz 0,0x140(27); cmplwi 0,2; beq 4f; lhz 0,0x1de(27); rlwinm 0,0,2,0,29; lwzx 0,31,0; add 29,29,0; 4:; lhz 0,0x1f2(27); cmplwi 0,0; beq 5f; addi 29,29,555; 5:; lhz 6,0x144(27); lwz 0,-22104(13); rlwinm 4,6,25,25,29; rlwinm 3,6,30,25,29; add 4,31,4; add 3,31,3; lwz 5,0x54(4); lwz 3,0x54(3); rlwinm 4,6,2,26,29; add 4,31,4; add 3,3,5; lwz 4,0x14(4); addi 3,3,140; add 29,3,29; add 29,4,29; cmplw 0,29; ble 6f; mr 3,27; bl _s8037A754_5; b 9f; 6:; lwz 0,0x18(27); mulli 0,0,244; add 26,30,0; lhz 0,0xe(26); cmplwi 0,1; bne 7f; mr 3,26; bl _s8037A754_6; 7:; li 0,0; sth 0,0x4c(26); mr 3,27; sth 0,0x4a(26); sth 0,0x48(26); sth 0,0x46(26); sth 0,0x44(26); sth 0,0xe(26); sth 0,0x146(27); bl _s8037A754_7; b 9f; 8:; mr 3,27; bl _s8037A754_8; 9:; li 3,0; stw 3,0x1c(27); addi 0,27,52; stw 3,0x20(27); stw 3,0x28(27); stw 3,0x24(27); stw 0,0x30(27); lwz 27,0x0(27); 10:; cmplwi 27,0; bne 1b; addic. 28,28,-1; bne 0b; stw 29,-22100(13); li 3,0; bl _s8037A754_9; mr 31,3; b 13f; 11:; lwz 0,0x20(31); cmplwi 0,0; beq 12f; lwz 0,0x18(31); mulli 0,0,244; add 3,30,0; bl _s8037A754_10; 12:; li 4,0; stw 4,0x20(31); lwz 0,0x18(31); mulli 3,0,244; addi 0,3,76; sthx 4,30,0; lwz 0,0x18(31); mulli 3,0,244; addi 0,3,74; sthx 4,30,0; lwz 0,0x18(31); mulli 3,0,244; addi 0,3,72; sthx 4,30,0; lwz 0,0x18(31); mulli 3,0,244; addi 0,3,70; sthx 4,30,0; lwz 0,0x18(31); mulli 3,0,244; addi 0,3,68; sthx 4,30,0; lwz 0,0x18(31); mulli 3,0,244; addi 0,3,14; sthx 4,30,0; lwz 31,0x0(31); 13:; cmplwi 31,0; bne 11b; addi 3,30,0; li 4,15616; bl _s8037A754_11; addi 3,30,15616; li 4,4096; bl _s8037A754_12; addi 3,30,19712; li 4,16384; bl _s8037A754_13; lmw 26,0x10(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8037A754_0();
extern "C" void _s8037A754_1();
extern "C" void _s8037A754_2();
extern "C" void _s8037A754_3();
extern "C" void _s8037A754_4();
extern "C" void _s8037A754_5();
extern "C" void _s8037A754_6();
extern "C" void _s8037A754_7();
extern "C" void _s8037A754_8();
extern "C" void _s8037A754_9();
extern "C" void _s8037A754_10();
extern "C" void _s8037A754_11();
extern "C" void _s8037A754_12();
extern "C" void _s8037A754_13();
extern "C" void f_8037A754() {}
