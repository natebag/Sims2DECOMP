// 0x800550C0 EIObjectMan::AllocSimsObjectInstance(cXObject (800 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,4; mr 28,3; lwz 9,0x4(29); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,29,3; blrl; mr 30,3; lwz 0,0x1c(30); cmpwi 0,1988; bne 0f; li 3,0; b 13f; 0:; lwz 9,0x4(29); addi 3,1,8; lha 4,0x358(9); lwz 0,0x35c(9); add 4,29,4; mtspr 8,0; blrl; cmpwi 30,0; beq 3f; lwz 0,0xc0(30); mr 11,0; cmpwi 0,0; beq 1f; lwz 9,0x0(11); li 0,0; cmpwi 9,0; beq 2f; lwz 0,-4(9); b 2f; 1:; li 0,0; 2:; cmpwi 0,0; ble 3f; lwz 9,0x0(11); lwz 31,0x0(9); cmpwi 31,0; bne 4f; 3:; addi 3,1,8; li 4,2; bl _s800550C0_0; li 3,0; b 13f; 4:; lha 0,0x14(30); cmpwi 0,0; bne 8f; lbz 0,0x5(11); cmpwi 0,1; bne 5f; bl _s800550C0_1; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s800550C0_2; mr 30,3; li 4,0; li 5,1216; bl _s800550C0_3; mr 3,30; bl _s800550C0_4; b 11f; 5:; lbz 0,0x6(11); cmpwi 0,1; bne 6f; bl _s800550C0_5; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s800550C0_6; mr 30,3; li 4,0; li 5,1216; bl _s800550C0_7; mr 3,30; bl _s800550C0_8; b 11f; 6:; lis 3,-32707; addi 3,3,13676; bl _s800550C0_9; cmpw 3,31; bne 7f; bl _s800550C0_10; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s800550C0_11; mr 30,3; li 4,0; li 5,1216; bl _s800550C0_12; mr 3,30; bl _s800550C0_13; b 11f; 7:; bl _s800550C0_14; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s800550C0_15; mr 30,3; li 4,0; li 5,1216; bl _s800550C0_16; mr 3,30; bl _s800550C0_17; b 11f; 8:; lwz 9,0x4(29); lwz 0,0x394(9); lha 3,0x390(9); mtspr 8,0; add 3,29,3; blrl; lwz 3,0xc0(30); lbz 0,0x5(3); cmpwi 0,1; bne 9f; bl _s800550C0_18; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s800550C0_19; mr 30,3; li 4,0; li 5,1216; bl _s800550C0_20; mr 3,30; bl _s800550C0_21; b 11f; 9:; lbz 0,0x6(3); cmpwi 0,1; bne 10f; bl _s800550C0_22; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s800550C0_23; mr 30,3; li 4,0; li 5,1216; bl _s800550C0_24; mr 3,30; bl _s800550C0_25; b 11f; 10:; bl _s800550C0_26; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s800550C0_27; mr 30,3; li 4,0; li 5,1216; bl _s800550C0_28; mr 3,30; bl _s800550C0_29; 11:; mr 30,3; lwz 9,0x0(30); mr 4,29; lwz 5,0x10(28); lwz 0,0x16c(9); lha 3,0x168(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x4(29); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,29,3; blrl; lhz 0,0xb6(3); rlwinm 0,0,0,29,30; cmpwi 0,0; bne 12f; lwz 9,0x0(30); lha 3,0x180(9); lwz 0,0x184(9); add 3,30,3; mtspr 8,0; blrl; 12:; addi 3,1,8; li 4,2; bl _s800550C0_30; mr 3,30; 13:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800550C0_0();
extern "C" void _s800550C0_1();
extern "C" void _s800550C0_2();
extern "C" void _s800550C0_3();
extern "C" void _s800550C0_4();
extern "C" void _s800550C0_5();
extern "C" void _s800550C0_6();
extern "C" void _s800550C0_7();
extern "C" void _s800550C0_8();
extern "C" void _s800550C0_9();
extern "C" void _s800550C0_10();
extern "C" void _s800550C0_11();
extern "C" void _s800550C0_12();
extern "C" void _s800550C0_13();
extern "C" void _s800550C0_14();
extern "C" void _s800550C0_15();
extern "C" void _s800550C0_16();
extern "C" void _s800550C0_17();
extern "C" void _s800550C0_18();
extern "C" void _s800550C0_19();
extern "C" void _s800550C0_20();
extern "C" void _s800550C0_21();
extern "C" void _s800550C0_22();
extern "C" void _s800550C0_23();
extern "C" void _s800550C0_24();
extern "C" void _s800550C0_25();
extern "C" void _s800550C0_26();
extern "C" void _s800550C0_27();
extern "C" void _s800550C0_28();
extern "C" void _s800550C0_29();
extern "C" void _s800550C0_30();
extern "C" void f_800550C0() {}
