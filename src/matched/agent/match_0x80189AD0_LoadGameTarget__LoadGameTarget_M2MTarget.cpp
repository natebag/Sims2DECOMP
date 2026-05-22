// 0x80189AD0 LoadGameTarget::LoadGameTarget(M2MTarget (1840 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 20,0x58(1); stw 0,0x8c(1); lis 9,-32698; mr 31,3; li 30,0; addi 9,9,-12328; stw 9,0x80(31); addi 11,31,40; stw 30,0x0(31); addi 10,31,56; stw 30,0x4(31); addi 8,31,72; stw 30,0x8(31); addi 7,31,88; stw 30,0xc(31); addi 28,31,104; stw 30,0x10(31); lis 9,-32698; stw 30,0x14(31); addi 29,31,132; stw 30,0x18(31); addi 9,9,30832; stw 30,0x8(11); li 23,-1; stw 30,0x28(31); li 0,1; stw 30,0x8(10); addi 25,31,172; stw 30,0x38(31); mr 21,5; stw 30,0x8(8); mr 20,6; stw 30,0x48(31); mr 22,4; stw 30,0x8(7); mr 3,25; stw 30,0x58(31); addi 27,31,180; stw 30,0x8(28); addi 26,31,184; stw 30,0x68(31); addi 24,31,188; stw 30,0x78(31); lis 28,-32705; stw 9,0x84(29); stw 30,0x84(31); stw 30,0x4(29); stw 30,0x8(29); stw 30,0xc(29); stw 30,0x10(29); stw 23,0x18(29); stw 30,0x1c(29); stw 30,0x20(29); stw 30,0x24(29); stw 0,0x14(29); bl _s80189AD0_0; addi 3,31,176; bl _s80189AD0_1; mr 3,27; bl _s80189AD0_2; mr 3,26; bl _s80189AD0_3; mr 3,24; bl _s80189AD0_4; li 0,3; stw 30,0x3c(29); stw 0,0x4c(29); addi 9,31,212; stw 30,0x40(29); addi 11,31,228; stw 30,0x44(29); addi 10,31,244; sth 30,0x48(29); addi 4,28,-19228; sth 30,0x4a(29); mr 3,25; stw 30,0x8(9); stw 30,0xd4(31); stw 30,0x8(11); stw 30,0xe4(31); stw 30,0x8(10); stw 30,0xf4(31); bl _s80189AD0_5; addi 4,28,-19228; mr 3,27; bl _s80189AD0_6; addi 4,28,-19228; mr 3,26; bl _s80189AD0_7; addi 4,28,-19228; mr 3,24; bl _s80189AD0_8; lis 9,-32705; lis 10,-32698; addi 9,9,-19184; lis 8,-32698; lis 7,-32698; lwz 5,0x0(9); lwz 6,0x4(9); addi 10,10,26856; addi 8,8,26824; addi 7,7,26904; stw 10,0x108(31); stw 8,0x114(31); lis 9,-32709; stw 7,0x80(31); addi 4,1,24; stw 22,0x118(31); addi 29,9,10276; stw 21,0x128(31); cmpwi 31,0; stw 23,0x12c(31); stw 20,0x138(31); stw 30,0x10c(31); stw 5,0x18(1); stw 6,0x1c(1); stw 30,0x11c(31); stw 30,0x120(31); stw 30,0x130(31); stw 30,0x134(31); stw 30,0x13c(31); stw 30,0x140(31); stw 30,0x144(31); stw 31,0x10(1); beq 0f; addi 3,1,8; li 5,8; bl _s80189AD0_9; b 1f; 0:; stw 31,0x8(1); 1:; stw 29,0x14(1); lis 9,-32705; addi 11,1,8; lwz 5,0x8(1); addi 9,9,-19176; lwz 4,0x4(11); lwz 6,0x8(11); addi 10,31,40; lwz 0,0xc(11); cmpwi 31,0; lwz 7,0x0(9); lwz 8,0x4(9); mr 30,11; stw 5,0x28(31); lis 9,-32709; stw 0,0xc(10); addi 28,9,10396; stw 4,0x4(10); addi 9,1,32; stw 6,0x8(10); mfcr 29; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq 2f; mr 4,9; mr 3,30; li 5,8; bl _s80189AD0_10; b 3f; 2:; stw 31,0x8(1); 3:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-19168; lwz 5,0x8(30); addi 11,31,56; lwz 10,0x4(30); addi 4,1,40; lwz 0,0xc(30); mtcrf 128,29; stw 6,0x38(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 28,9,10516; stw 5,0x8(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq 4f; mr 3,30; li 5,8; bl _s80189AD0_11; b 5f; 4:; stw 31,0x8(1); 5:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-19160; lwz 5,0x8(30); addi 11,31,72; lwz 10,0x4(30); addi 4,1,48; lwz 0,0xc(30); mtcrf 128,29; stw 6,0x48(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 28,9,10636; stw 5,0x8(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq 6f; mr 3,30; li 5,8; bl _s80189AD0_12; b 7f; 6:; stw 31,0x8(1); 7:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-19152; lwz 5,0x8(30); addi 11,31,88; lwz 0,0x4(30); mr 27,11; lwz 10,0xc(30); addi 4,1,56; stw 6,0x58(31); mtcrf 128,29; lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32709; stw 5,0x8(11); addi 28,9,10756; stw 10,0xc(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq 8f; mr 3,30; li 5,8; bl _s80189AD0_13; b 9f; 8:; stw 31,0x8(1); 9:; stw 28,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32705; lwz 7,0x4(30); addi 9,9,-19144; lwz 6,0x8(30); lwz 0,0xc(30); lwz 10,-31532(13); stw 8,0x68(31); stw 0,0xc(11); cmpwi 10,0; stw 7,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s80189AD0_14; bl _s80189AD0_15; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s80189AD0_16; bl _s80189AD0_17; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s80189AD0_18; bl _s80189AD0_19; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s80189AD0_20; bl _s80189AD0_21; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s80189AD0_22; bl _s80189AD0_23; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s80189AD0_24; bl _s80189AD0_25; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s80189AD0_26; bl _s80189AD0_27; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s80189AD0_28; bl _s80189AD0_29; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s80189AD0_30; bl _s80189AD0_31; stw 3,-31536(13); 18:; lis 9,-32705; lwz 10,-31536(13); addi 9,9,-19128; li 0,1; lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; stw 10,0x24(31); addi 28,11,10876; stw 0,0x0(31); addi 4,1,64; stw 7,0x40(1); stw 8,0x44(1); mtcrf 128,29; stw 31,0x10(1); beq 19f; mr 3,30; li 5,8; bl _s80189AD0_32; b 20f; 19:; stw 31,0x8(1); 20:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-19120; lwz 5,0x8(30); addi 11,31,212; lwz 10,0x4(30); addi 4,1,72; lwz 0,0xc(30); mtcrf 128,29; stw 6,0xd4(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 28,9,10636; stw 5,0x8(11); stw 7,0x48(1); stw 8,0x4c(1); stw 31,0x10(1); beq 21f; mr 3,30; li 5,8; bl _s80189AD0_33; b 22f; 21:; stw 31,0x8(1); 22:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-19112; lwz 5,0x8(30); addi 11,31,228; lwz 10,0x4(30); addi 4,1,80; lwz 0,0xc(30); mtcrf 128,29; stw 6,0xe4(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 28,9,10996; stw 5,0x8(11); stw 7,0x50(1); stw 8,0x54(1); stw 31,0x10(1); beq 23f; mr 3,30; li 5,8; bl _s80189AD0_34; b 24f; 23:; stw 31,0x8(1); 24:; stw 28,0x14(1); addi 11,31,244; lwz 7,0x8(1); lis 9,-32705; lwz 0,0x4(30); addi 9,9,-19144; lwz 8,0xc(30); lwz 10,0x8(30); stw 7,0xf4(31); stw 8,0xc(11); stw 0,0x4(11); stw 10,0x8(11); stw 9,0x104(31); lwz 0,0x0(31); cmpwi 0,0; beq 27f; lwz 0,0x8(27); li 9,0; cmpwi 0,0; bne 25f; lwz 0,0x58(31); cmpwi 0,0; beq 26f; 25:; li 9,1; 26:; cmpwi 9,0; beq 27f; lwz 3,0x10(31); mr 5,27; lwz 6,0x7c(31); li 4,75; bl _s80189AD0_35; 27:; lwz 3,0x118(31); bl _s80189AD0_36; cmpwi 3,-1; bne 28f; lwz 4,0x128(31); lis 3,-32705; addi 3,3,-19104; neg 4,4; bl _s80189AD0_37; 28:; lwz 0,-26460(13); mr 3,31; stw 0,0x124(31); lwz 0,0x8c(1); mtspr 8,0; lmw 20,0x58(1); addi 1,1,136"
extern "C" void _s80189AD0_0();
extern "C" void _s80189AD0_1();
extern "C" void _s80189AD0_2();
extern "C" void _s80189AD0_3();
extern "C" void _s80189AD0_4();
extern "C" void _s80189AD0_5();
extern "C" void _s80189AD0_6();
extern "C" void _s80189AD0_7();
extern "C" void _s80189AD0_8();
extern "C" void _s80189AD0_9();
extern "C" void _s80189AD0_10();
extern "C" void _s80189AD0_11();
extern "C" void _s80189AD0_12();
extern "C" void _s80189AD0_13();
extern "C" void _s80189AD0_14();
extern "C" void _s80189AD0_15();
extern "C" void _s80189AD0_16();
extern "C" void _s80189AD0_17();
extern "C" void _s80189AD0_18();
extern "C" void _s80189AD0_19();
extern "C" void _s80189AD0_20();
extern "C" void _s80189AD0_21();
extern "C" void _s80189AD0_22();
extern "C" void _s80189AD0_23();
extern "C" void _s80189AD0_24();
extern "C" void _s80189AD0_25();
extern "C" void _s80189AD0_26();
extern "C" void _s80189AD0_27();
extern "C" void _s80189AD0_28();
extern "C" void _s80189AD0_29();
extern "C" void _s80189AD0_30();
extern "C" void _s80189AD0_31();
extern "C" void _s80189AD0_32();
extern "C" void _s80189AD0_33();
extern "C" void _s80189AD0_34();
extern "C" void _s80189AD0_35();
extern "C" void _s80189AD0_36();
extern "C" void _s80189AD0_37();
extern "C" void f_80189AD0() {}
