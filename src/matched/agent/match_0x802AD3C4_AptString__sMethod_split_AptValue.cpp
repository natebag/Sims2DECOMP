// 0x802AD3C4 AptString::sMethod_split(AptValue (1440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 20,0x30(1); stw 0,0x64(1); mr 30,3; mr 29,4; lwz 3,-23016(13); li 4,48; bl _s802AD3C4_0; bl _s802AD3C4_1; mr 22,3; cmpwi 29,0; bne 0f; mr 5,30; li 4,0; bl _s802AD3C4_2; b 31f; 0:; ble 31f; lis 10,-32700; lis 31,-32694; lhz 9,-6476(10); addi 28,31,-16032; lwz 11,-16032(31); addi 25,10,-6476; lwz 0,0x8(28); addi 9,9,1; sth 9,-6476(10); rlwinm 11,11,2,0,29; stw 25,0x8(1); add 11,11,0; addi 4,1,8; lis 26,15; lwz 3,-4(11); ori 26,26,16959; bl _s802AD3C4_3; cmpwi 29,1; ble 1f; lwz 9,-16032(31); lwz 0,0x8(28); addi 9,9,-1; rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s802AD3C4_4; mr 26,3; 1:; lwz 0,0x0(30); mr 3,30; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 2f; lwz 3,0x24(3); 2:; lwz 9,0xc(3); stw 9,0x10(1); lhz 11,0x0(9); addi 11,11,1; sth 11,0x0(9); lwz 10,0x8(1); lhz 23,0x2(10); cmpwi 23,0; bne 15f; lwz 9,0x10(1); cmpw 23,26; li 28,0; addi 29,9,8; bge 29f; addi 25,1,40; lis 27,-32700; 3:; lbz 9,0x0(29); mr 11,9; andi. 0,9,128; bne 4f; mr 10,9; addi 7,29,1; b 8f; 4:; rlwinm 0,9,0,24,26; cmpwi 0,192; bne 5f; lbz 0,0x1(29); rlwinm 10,9,6,21,25; addi 7,29,2; rlwinm 0,0,0,26,31; or 10,10,0; b 8f; 5:; rlwinm 0,9,0,24,27; cmpwi 0,224; bne 6f; lbz 0,0x1(29); rlwinm 10,9,12,16,19; lbz 8,0x2(29); addi 7,29,3; rlwinm 0,0,6,20,25; or 10,10,0; rlwinm 9,8,0,26,31; b 7f; 6:; lbz 0,0x1(29); rlwinm 10,11,18,11,13; lbz 8,0x2(29); addi 7,29,4; rlwinm 11,0,12,14,19; lbz 9,0x3(29); or 10,10,11; rlwinm 0,8,6,20,25; or 10,10,0; rlwinm 9,9,0,26,31; 7:; or 10,10,9; 8:; stw 10,0x0(25); mr 29,7; lwz 4,0x28(1); cmpwi 4,0; beq 29f; lhz 9,-6476(27); addi 0,27,-6476; stw 0,0x18(1); addi 3,1,24; addi 9,9,1; sth 9,-6476(27); bl _s802AD3C4_5; lwz 30,-26892(13); cmpwi 30,0; beq 12f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 9f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 10f; 9:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 10:; addi 31,30,12; mr 3,31; bl _s802AD3C4_6; cmpwi 3,0; bne 11f; mr 3,31; li 4,0; bl _s802AD3C4_7; 11:; mr 31,30; b 13f; 12:; lwz 3,-23020(13); li 4,20; bl _s802AD3C4_8; bl _s802AD3C4_9; mr 31,3; 13:; lwz 4,0x18(1); addi 3,1,32; addi 30,31,12; addi 4,4,8; bl _s802AD3C4_10; addi 4,1,32; mr 3,30; bl _s802AD3C4_11; addi 3,1,32; li 4,2; bl _s802AD3C4_12; mr 4,28; mr 5,31; mr 3,22; bl _s802AD3C4_13; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD3C4_14; 14:; addi 28,28,1; cmpw 28,26; blt 3b; b 29f; 15:; lwz 9,0x10(1); li 27,0; li 28,0; cmpw 27,26; addi 20,9,8; bge 29f; mr 21,25; lis 24,-32700; addi 25,1,24; 16:; lwz 4,0x8(1); addi 3,1,16; mr 5,28; addi 4,4,8; bl _s802AD3C4_15; mr 29,3; cmpwi 29,-1; bne 23f; lwz 30,-26892(13); cmpwi 30,0; beq 20f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 17f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 18f; 17:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 18:; addi 31,30,12; mr 3,31; bl _s802AD3C4_16; cmpwi 3,0; bne 19f; mr 3,31; li 4,0; bl _s802AD3C4_17; 19:; mr 31,30; b 21f; 20:; lwz 3,-23020(13); li 4,20; bl _s802AD3C4_18; bl _s802AD3C4_19; mr 31,3; 21:; lhz 9,-6476(24); cmpw 28,29; stw 21,0x18(1); addi 9,9,1; sth 9,-6476(24); beq 22f; lwz 4,0x10(1); subf 5,28,29; addi 3,1,24; addi 4,4,8; add 4,4,28; bl _s802AD3C4_20; 22:; addi 4,1,24; addi 3,31,12; bl _s802AD3C4_21; mr 4,27; mr 5,31; mr 3,22; bl _s802AD3C4_22; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 29f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD3C4_23; b 29f; 23:; lwz 30,-26892(13); cmpwi 30,0; beq 26f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 24f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 25f; 24:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 25:; addi 31,30,12; mr 3,31; bl _s802AD3C4_24; cmpwi 3,0; bne 27f; mr 3,31; li 4,0; bl _s802AD3C4_25; b 27f; 26:; lwz 3,-23020(13); li 4,20; bl _s802AD3C4_26; bl _s802AD3C4_27; mr 30,3; 27:; lhz 9,-6476(24); subf 5,28,29; add 4,20,28; stw 21,0x18(1); addi 9,9,1; mr 3,25; sth 9,-6476(24); add 28,29,23; bl _s802AD3C4_28; mr 4,25; addi 3,30,12; bl _s802AD3C4_29; mr 4,27; mr 5,30; mr 3,22; addi 27,27,1; bl _s802AD3C4_30; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 28f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD3C4_31; 28:; cmpw 27,26; blt 16b; 29:; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 30f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD3C4_32; 30:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 31f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD3C4_33; 31:; mr 3,22; lwz 0,0x64(1); mtspr 8,0; lmw 20,0x30(1); addi 1,1,96"
extern "C" void _s802AD3C4_0();
extern "C" void _s802AD3C4_1();
extern "C" void _s802AD3C4_2();
extern "C" void _s802AD3C4_3();
extern "C" void _s802AD3C4_4();
extern "C" void _s802AD3C4_5();
extern "C" void _s802AD3C4_6();
extern "C" void _s802AD3C4_7();
extern "C" void _s802AD3C4_8();
extern "C" void _s802AD3C4_9();
extern "C" void _s802AD3C4_10();
extern "C" void _s802AD3C4_11();
extern "C" void _s802AD3C4_12();
extern "C" void _s802AD3C4_13();
extern "C" void _s802AD3C4_14();
extern "C" void _s802AD3C4_15();
extern "C" void _s802AD3C4_16();
extern "C" void _s802AD3C4_17();
extern "C" void _s802AD3C4_18();
extern "C" void _s802AD3C4_19();
extern "C" void _s802AD3C4_20();
extern "C" void _s802AD3C4_21();
extern "C" void _s802AD3C4_22();
extern "C" void _s802AD3C4_23();
extern "C" void _s802AD3C4_24();
extern "C" void _s802AD3C4_25();
extern "C" void _s802AD3C4_26();
extern "C" void _s802AD3C4_27();
extern "C" void _s802AD3C4_28();
extern "C" void _s802AD3C4_29();
extern "C" void _s802AD3C4_30();
extern "C" void _s802AD3C4_31();
extern "C" void _s802AD3C4_32();
extern "C" void _s802AD3C4_33();
extern "C" void f_802AD3C4() {}
