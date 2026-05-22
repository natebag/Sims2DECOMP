// 0x800D62EC NghResFile::LoadHouseContents(unsigned (1160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-176(1); mfspr 0,8; mfcr 12; stmw 18,0x78(1); stw 0,0xb4(1); stw 12,0x74(1); lis 11,-32696; mr 25,4; lwz 9,0x6330(11); addi 0,25,-1; mr 28,3; mr 19,5; addi 9,9,120; lwz 30,0x4(9); lwz 11,0x8(9); li 24,0; mullw 0,0,30; lis 26,-32696; add 27,11,0; bl _s800D62EC_0; cmpwi 3,0; beq 0f; li 3,1; b 19f; 0:; li 20,1; mr. 29,19; bne 5f; bl _s800D62EC_1; addi 31,28,40; mr 4,30; li 5,64; li 6,0; li 7,0; bl _s800D62EC_2; li 20,0; mr 29,3; lwz 4,-31920(13); mr 3,31; li 5,0; bl _s800D62EC_3; cmpwi 3,0; blt 1f; mr 3,31; lis 26,-32694; addi 31,1,84; bl _s800D62EC_4; mr 5,3; lis 6,-32706; mr 4,31; addi 6,6,-21732; addi 3,26,-10620; lis 7,-32768; lis 8,-32768; li 9,0; bl _s800D62EC_5; lwz 4,0x54(1); cmpwi 4,0; beq 5f; lwz 3,-22652(13); mr 6,27; mr 5,29; mr 7,30; lwz 11,0x0(3); li 8,1; li 9,0; lha 0,0x70(11); lwz 11,0x74(11); add 3,3,0; mtspr 8,11; blrl; xor 20,3,30; subfic 0,20,0; adde 20,0,20; mr 4,31; addi 3,26,-10620; bl _s800D62EC_6; b 5f; 1:; li 24,1; b 3f; 2:; lwz 0,0x4(29); mr 3,28; lwz 30,0xc(29); add 30,30,0; addi 30,30,1023; rlwinm 30,30,0,0,21; bl _s800D62EC_7; addi 4,26,25388; mr 6,27; mr 7,30; mr 5,29; bl _s800D62EC_8; cmpwi 3,0; beq 5f; b 4f; 3:; mr 3,28; li 20,1; bl _s800D62EC_9; addi 4,26,25388; mr 5,29; mr 6,27; li 7,1024; bl _s800D62EC_10; cmpwi 3,0; beq 2b; 4:; li 20,0; 5:; cmpwi 20,1; bne 17f; lwz 9,0x24(28); mr 4,25; mr 3,28; cmpwi 4,24,0; addi 18,9,1; bl _s800D62EC_11; lwz 0,0x4(29); lwz 9,0xc(29); stw 0,0x58(1); stw 9,0x5c(1); bne cr4,6f; addi 4,1,88; mr 3,28; bl _s800D62EC_12; mr 3,28; addi 4,1,92; bl _s800D62EC_13; mr 3,28; addi 4,29,16; bl _s800D62EC_14; 6:; lwz 0,0x5c(1); li 9,0; lwz 4,0x58(1); mr 3,29; lwz 30,0x10(29); add 4,0,4; stw 9,0x10(29); bl _s800D62EC_15; cmpw 30,3; stw 30,0x10(29); li 0,-4; bne 7f; li 0,1; 7:; cmpwi 0,1; beq 9f; 8:; li 3,-4; b 19f; 9:; bne cr4,10f; mr 3,28; mr 4,29; bl _s800D62EC_16; mr 3,28; addi 4,29,4; bl _s800D62EC_17; mr 3,28; addi 4,29,8; bl _s800D62EC_18; mr 3,28; addi 4,29,12; bl _s800D62EC_19; mr 3,28; addi 4,29,20; bl _s800D62EC_20; mr 3,28; addi 4,29,24; bl _s800D62EC_21; 10:; bl _s800D62EC_22; lwz 0,0x4(29); li 5,64; lwz 4,0x8(29); li 6,0; li 7,0; add 4,0,4; bl _s800D62EC_23; mr 24,3; lwz 5,0x4(29); mr 4,29; crxor 6,6,6; bl _s800D62EC_24; lwz 0,0x14(29); cmplwi 0,8; bgt 8b; cmplwi 0,7; blt 8b; lwz 3,0x4(29); lwz 4,0xc(29); add 5,24,3; lwz 6,0x8(29); add 3,29,3; bl _s800D62EC_25; lwz 0,0x8(29); cmpw 3,0; beq 11f; bl _s800D62EC_26; mr 4,24; bl _s800D62EC_27; b 8b; 11:; lwz 21,0x18(24); addi 3,1,8; lwz 9,0x4(24); addi 4,3,8; rlwinm 0,21,2,0,29; li 5,64; add 25,24,9; li 22,0; add 26,25,0; add 27,26,0; add 23,27,0; bl _s800D62EC_28; cmplw 22,21; bge 16f; 12:; lwz 0,0x0(25); addi 25,25,4; stw 0,0x60(1); lwz 9,0x0(26); addi 26,26,4; stw 9,0x64(1); lwz 0,0x0(27); addi 27,27,4; stw 0,0x68(1); lhz 9,0x0(23); addi 23,23,2; sth 9,0x50(1); bne cr4,13f; addi 4,1,96; mr 3,28; bl _s800D62EC_29; addi 4,1,100; mr 3,28; bl _s800D62EC_30; mr 3,28; addi 4,1,104; bl _s800D62EC_31; mr 3,28; addi 4,1,80; bl _s800D62EC_32; 13:; lwz 30,0x68(1); bl _s800D62EC_33; li 4,12; li 5,0; bl _s800D62EC_34; mr 31,3; cmpwi 30,0; stw 30,0x0(31); beq 14f; bl _s800D62EC_35; mr 4,30; li 5,0; bl _s800D62EC_36; stw 3,0x4(31); b 15f; 14:; stw 30,0x4(31); 15:; li 0,1; lwz 3,0x4(31); stw 0,0x8(31); addi 22,22,1; lwz 4,0x64(1); lwz 5,0x68(1); add 4,24,4; crxor 6,6,6; bl _s800D62EC_37; lwz 9,0xc(28); mr 4,31; lwz 5,0x60(1); addi 7,1,8; lha 3,0xf8(9); li 8,1; lwz 0,0xfc(9); add 3,28,3; lha 6,0x50(1); mtspr 8,0; blrl; cmplw 22,21; blt 12b; 16:; bl _s800D62EC_38; mr 4,24; bl _s800D62EC_39; mr 3,28; mr 4,18; bl _s800D62EC_40; 17:; cmpwi 19,0; bne 18f; bl _s800D62EC_41; mr 4,29; bl _s800D62EC_42; 18:; mr 3,20; 19:; lwz 0,0xb4(1); lwz 12,0x74(1); mtspr 8,0; lmw 18,0x78(1); mtcrf 8,12; addi 1,1,176"
extern "C" void _s800D62EC_0();
extern "C" void _s800D62EC_1();
extern "C" void _s800D62EC_2();
extern "C" void _s800D62EC_3();
extern "C" void _s800D62EC_4();
extern "C" void _s800D62EC_5();
extern "C" void _s800D62EC_6();
extern "C" void _s800D62EC_7();
extern "C" void _s800D62EC_8();
extern "C" void _s800D62EC_9();
extern "C" void _s800D62EC_10();
extern "C" void _s800D62EC_11();
extern "C" void _s800D62EC_12();
extern "C" void _s800D62EC_13();
extern "C" void _s800D62EC_14();
extern "C" void _s800D62EC_15();
extern "C" void _s800D62EC_16();
extern "C" void _s800D62EC_17();
extern "C" void _s800D62EC_18();
extern "C" void _s800D62EC_19();
extern "C" void _s800D62EC_20();
extern "C" void _s800D62EC_21();
extern "C" void _s800D62EC_22();
extern "C" void _s800D62EC_23();
extern "C" void _s800D62EC_24();
extern "C" void _s800D62EC_25();
extern "C" void _s800D62EC_26();
extern "C" void _s800D62EC_27();
extern "C" void _s800D62EC_28();
extern "C" void _s800D62EC_29();
extern "C" void _s800D62EC_30();
extern "C" void _s800D62EC_31();
extern "C" void _s800D62EC_32();
extern "C" void _s800D62EC_33();
extern "C" void _s800D62EC_34();
extern "C" void _s800D62EC_35();
extern "C" void _s800D62EC_36();
extern "C" void _s800D62EC_37();
extern "C" void _s800D62EC_38();
extern "C" void _s800D62EC_39();
extern "C" void _s800D62EC_40();
extern "C" void _s800D62EC_41();
extern "C" void _s800D62EC_42();
extern "C" void f_800D62EC() {}
