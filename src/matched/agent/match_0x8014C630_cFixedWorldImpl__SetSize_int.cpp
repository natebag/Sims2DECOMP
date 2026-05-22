// 0x8014C630 cFixedWorldImpl::SetSize(int, (1168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 20,0x20(1); stw 0,0x54(1); mr 31,3; mr 24,4; lwz 0,0x14(31); mr 26,5; mr 30,6; cmpw 0,24; bne 0f; lwz 0,0x18(31); cmpw 0,26; bne 0f; li 3,1; b 15f; 0:; lwz 9,0x0(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; cmpw 24,3; bgt 1f; lwz 9,0x0(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; cmpw 26,3; bgt 1f; cmpwi 24,7; ble 1f; cmpwi 26,7; bgt 2f; 1:; li 3,0; b 15f; 2:; cmpwi 30,0; beq 13f; li 3,24; lis 30,-32706; bl _s8014C630_0; mr 25,24; mr 20,3; addi 4,30,-8660; addi 3,1,8; bl _s8014C630_1; addi 7,1,8; mr 5,24; mr 6,26; li 4,1; mr 3,20; bl _s8014C630_2; addi 3,1,8; li 4,2; bl _s8014C630_3; li 3,24; bl _s8014C630_4; mr 21,3; addi 4,30,-8660; addi 3,1,8; bl _s8014C630_5; addi 7,1,8; mr 5,24; mr 6,26; li 4,1; mr 3,21; bl _s8014C630_6; addi 3,1,8; li 4,2; bl _s8014C630_7; li 3,24; bl _s8014C630_8; mr 27,3; addi 4,30,-8660; addi 3,1,8; bl _s8014C630_9; li 4,8; mr 5,24; mr 6,26; addi 7,1,8; mr 3,27; bl _s8014C630_10; addi 3,1,8; li 4,2; bl _s8014C630_11; lwz 0,0x14(31); cmpw 24,0; ble 3f; mr 25,0; 3:; lwz 0,0x18(31); mr 28,26; cmpw 26,0; ble 4f; mr 28,0; 4:; li 29,0; cmpw 29,28; bge 8f; 5:; cmpwi 25,0; addi 5,29,1; ble 7f; rlwinm 6,29,3,0,28; li 7,0; mr 30,25; 6:; lwz 9,0xc(20); addic. 30,30,-1; lwz 8,0x2c(31); lwzx 10,7,9; stw 10,0x8(1); lwz 11,0xc(8); lwzx 9,7,11; stw 9,0x10(1); lbzx 0,9,29; stbx 0,10,29; lwz 9,0xc(21); lwz 8,0x34(31); lwzx 10,7,9; stw 10,0x8(1); lwz 11,0xc(8); lwzx 9,7,11; stw 9,0x18(1); lbzx 0,9,29; stbx 0,10,29; lwz 9,0xc(27); lwz 10,0x38(31); lwzx 8,7,9; stw 8,0x8(1); add 8,8,6; lwz 9,0xc(10); lwzx 11,7,9; addi 7,7,4; stw 11,0x10(1); add 11,11,6; lwz 9,0x0(11); lwz 10,0x4(11); stw 9,0x0(8); stw 10,0x4(8); bne 6b; 7:; mr 29,5; cmpw 29,28; blt 5b; 8:; cmpwi 28,0; ble 10f; addi 0,25,-1; addi 9,25,-2; rlwinm 22,0,2,0,29; rlwinm 23,9,2,0,29; li 30,0; mr 29,28; 9:; lwz 9,0xc(27); li 4,0; li 5,8; lwzx 0,22,9; add 3,0,30; stw 0,0x8(1); bl _s8014C630_12; lwz 9,0xc(27); lwzx 11,23,9; stw 11,0x8(1); lbzx 0,11,30; andi. 0,0,251; stbx 0,11,30; addic. 29,29,-1; addi 30,30,8; bne 9b; 10:; cmpwi 25,0; ble 12f; addi 0,28,-1; addi 9,28,-2; rlwinm 23,0,3,0,28; rlwinm 28,9,3,0,28; mr 30,25; li 29,0; 11:; lwz 9,0xc(27); li 4,0; li 5,8; lwzx 0,29,9; add 3,0,23; stw 0,0x8(1); bl _s8014C630_13; lwz 9,0xc(27); lwzx 11,29,9; addi 29,29,4; stw 11,0x8(1); lbzx 0,11,28; andi. 0,0,247; stbx 0,11,28; addic. 30,30,-1; bne 11b; 12:; lwz 9,0x0(31); lha 3,0x130(9); lwz 0,0x134(9); add 3,31,3; mtspr 8,0; blrl; stw 20,0x2c(31); stw 21,0x34(31); stw 27,0x38(31); b 14f; 13:; lwz 9,0x0(31); lis 29,-32706; lha 3,0x130(9); lwz 0,0x134(9); add 3,31,3; mtspr 8,0; blrl; li 3,24; bl _s8014C630_14; mr 30,3; addi 4,29,-8660; addi 3,1,8; bl _s8014C630_15; addi 7,1,8; mr 5,24; mr 6,26; li 4,1; mr 3,30; bl _s8014C630_16; addi 3,1,8; li 4,2; bl _s8014C630_17; stw 30,0x2c(31); li 3,24; bl _s8014C630_18; mr 30,3; addi 4,29,-8660; addi 3,1,8; bl _s8014C630_19; addi 7,1,8; mr 5,24; mr 6,26; li 4,1; mr 3,30; bl _s8014C630_20; addi 3,1,8; li 4,2; bl _s8014C630_21; stw 30,0x34(31); li 3,24; bl _s8014C630_22; mr 30,3; addi 4,29,-8660; addi 3,1,8; bl _s8014C630_23; li 4,8; mr 5,24; mr 6,26; addi 7,1,8; mr 3,30; bl _s8014C630_24; addi 3,1,8; li 4,2; bl _s8014C630_25; stw 30,0x38(31); 14:; li 3,24; bl _s8014C630_26; mr 30,3; lis 4,-32706; addi 3,1,8; addi 4,4,-8660; bl _s8014C630_27; mr 6,26; addi 7,1,8; mr 5,24; li 4,2; mr 3,30; bl _s8014C630_28; addi 3,1,8; li 4,2; bl _s8014C630_29; stw 30,0x30(31); li 3,12; bl _s8014C630_30; mr 4,24; mr 5,26; bl _s8014C630_31; stw 3,0x3c(31); li 3,12; bl _s8014C630_32; mr 4,24; mr 5,26; bl _s8014C630_33; stw 3,0x40(31); stw 26,0x18(31); li 3,1; stw 24,0x14(31); 15:; lwz 0,0x54(1); mtspr 8,0; lmw 20,0x20(1); addi 1,1,80"
extern "C" void _s8014C630_0();
extern "C" void _s8014C630_1();
extern "C" void _s8014C630_2();
extern "C" void _s8014C630_3();
extern "C" void _s8014C630_4();
extern "C" void _s8014C630_5();
extern "C" void _s8014C630_6();
extern "C" void _s8014C630_7();
extern "C" void _s8014C630_8();
extern "C" void _s8014C630_9();
extern "C" void _s8014C630_10();
extern "C" void _s8014C630_11();
extern "C" void _s8014C630_12();
extern "C" void _s8014C630_13();
extern "C" void _s8014C630_14();
extern "C" void _s8014C630_15();
extern "C" void _s8014C630_16();
extern "C" void _s8014C630_17();
extern "C" void _s8014C630_18();
extern "C" void _s8014C630_19();
extern "C" void _s8014C630_20();
extern "C" void _s8014C630_21();
extern "C" void _s8014C630_22();
extern "C" void _s8014C630_23();
extern "C" void _s8014C630_24();
extern "C" void _s8014C630_25();
extern "C" void _s8014C630_26();
extern "C" void _s8014C630_27();
extern "C" void _s8014C630_28();
extern "C" void _s8014C630_29();
extern "C" void _s8014C630_30();
extern "C" void _s8014C630_31();
extern "C" void _s8014C630_32();
extern "C" void _s8014C630_33();
extern "C" void f_8014C630() {}
