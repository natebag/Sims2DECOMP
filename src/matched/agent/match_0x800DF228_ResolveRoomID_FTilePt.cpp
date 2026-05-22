// 0x800DF228 ResolveRoomID(FTilePt (680 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 23,0x5c(1); stw 0,0x84(1); mr 5,4; mr 27,3; mr 4,27; addi 3,1,8; bl _s800DF228_0; lwz 31,-21488(13); addi 4,1,8; lwz 9,0x0(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; addi 3,1,8; li 4,2; bl _s800DF228_1; li 3,0; ori 3,3,65531; b 9f; 0:; lwz 9,0x0(31); addi 4,1,8; lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; mr 24,3; ori 0,0,65531; cmpw 24,0; bne 8f; lwz 9,0x0(31); addi 30,1,16; addi 5,1,8; mr 3,30; lha 4,0xa8(9); addi 29,1,72; lwz 0,0xac(9); addi 28,1,80; add 4,31,4; mr 23,30; mtspr 8,0; mr 25,29; mr 26,28; blrl; addi 4,1,8; mr 3,29; bl _s800DF228_2; addi 4,1,8; mr 3,28; bl _s800DF228_3; mr 3,30; li 4,16; bl _s800DF228_4; cmpwi 3,0; beq 2f; lwz 0,0x0(27); lwz 9,0x4(27); rlwinm 0,0,0,28,31; subfic 0,0,16; rlwinm 9,9,0,28,31; cmpw 9,0; bge 1f; mr 3,25; bl _s800DF228_5; addi 4,3,-1; mr 3,25; bl _s800DF228_6; mr 3,26; bl _s800DF228_7; addi 4,3,-1; b 4f; 1:; mr 3,25; bl _s800DF228_8; addi 4,3,1; b 3f; 2:; mr 3,23; li 4,32; bl _s800DF228_9; cmpwi 3,0; beq 6f; lwz 9,0x0(27); lwz 0,0x4(27); rlwinm 9,9,0,28,31; rlwinm 0,0,0,28,31; cmpw 0,9; bge 5f; mr 3,25; bl _s800DF228_10; addi 4,3,-1; 3:; mr 3,25; bl _s800DF228_11; mr 3,26; bl _s800DF228_12; addi 4,3,1; 4:; mr 3,26; bl _s800DF228_13; b 6f; 5:; mr 3,25; bl _s800DF228_14; addi 4,3,1; mr 3,25; bl _s800DF228_15; mr 3,26; bl _s800DF228_16; addi 4,3,-1; mr 3,26; bl _s800DF228_17; 6:; lwz 9,0x0(31); mr 4,25; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 7f; lwz 9,0x0(31); mr 4,25; lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; mr 24,3; ori 0,0,65531; cmpw 24,0; bne 7f; lwz 9,0x0(31); mr 4,26; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 7f; lwz 9,0x0(31); mr 4,26; lha 3,0xe8(9); lwz 0,0xec(9); add 3,31,3; mtspr 8,0; blrl; mr 24,3; 7:; mr 3,26; li 4,2; bl _s800DF228_18; mr 3,25; li 4,2; bl _s800DF228_19; mr 3,23; li 4,2; bl _s800DF228_20; 8:; addi 3,1,8; li 4,2; bl _s800DF228_21; mr 3,24; 9:; lwz 0,0x84(1); mtspr 8,0; lmw 23,0x5c(1); addi 1,1,128"
extern "C" void _s800DF228_0();
extern "C" void _s800DF228_1();
extern "C" void _s800DF228_2();
extern "C" void _s800DF228_3();
extern "C" void _s800DF228_4();
extern "C" void _s800DF228_5();
extern "C" void _s800DF228_6();
extern "C" void _s800DF228_7();
extern "C" void _s800DF228_8();
extern "C" void _s800DF228_9();
extern "C" void _s800DF228_10();
extern "C" void _s800DF228_11();
extern "C" void _s800DF228_12();
extern "C" void _s800DF228_13();
extern "C" void _s800DF228_14();
extern "C" void _s800DF228_15();
extern "C" void _s800DF228_16();
extern "C" void _s800DF228_17();
extern "C" void _s800DF228_18();
extern "C" void _s800DF228_19();
extern "C" void _s800DF228_20();
extern "C" void _s800DF228_21();
extern "C" void f_800DF228() {}
