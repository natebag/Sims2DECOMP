// 0x80290C60 AptCIH::render(AptRenderingContext (1840 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-200(1); mfspr 0,8; stfd f26,0x98(1); stfd f27,0xa0(1); stfd f28,0xa8(1); stfd f29,0xb0(1); stfd f30,0xb8(1); stfd f31,0xc0(1); stmw 20,0x68(1); stw 0,0xcc(1); mr 31,3; mr 25,4; mr 21,6; li 4,11; lis 20,-32704; bl _s80290C60_0; lis 9,-32704; lfs f0,0x5ac8(9); fcmpu 0,f1,f0; beq 33f; mr 3,31; li 29,0; bl _s80290C60_1; li 30,0; cmpwi 3,13; bne 0f; mr 3,31; bl _s80290C60_2; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 2f; mr 3,31; li 30,0; bl _s80290C60_3; cmpwi 3,18; bne 1f; mr 3,31; bl _s80290C60_4; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; beq 3f; 2:; li 29,1; 3:; cmpwi 29,0; beq 17f; lwz 30,0x4c(31); lwz 0,0x1c(30); andi. 9,0,48; bne 8f; lwz 3,0xc(30); cmpwi 3,0; beq 4f; lis 4,-32694; addi 4,4,-11332; addi 4,4,72; bl _s80290C60_5; b 5f; 4:; li 3,0; 5:; cmpwi 3,0; beq 6f; lwz 0,0x1c(30); li 9,1; b 7f; 6:; lwz 0,0x1c(30); li 9,2; 7:; rlwimi 0,9,4,26,27; stw 0,0x1c(30); 8:; lwz 0,0x1c(30); rlwinm 0,0,0,26,27; cmpwi 0,16; bne 16f; lwz 3,0xc(30); cmpwi 3,0; beq 9f; lis 4,-32694; addi 4,4,-11332; addi 4,4,72; bl _s80290C60_6; mr 29,3; b 10f; 9:; li 29,0; 10:; lwz 9,0x24(30); lis 6,-32694; addi 6,6,-11332; lis 3,-32694; lwz 11,0x0(9); mr 4,31; li 5,0; li 9,0; lwz 28,0x54(11); addi 6,6,64; li 7,1; li 8,1; addi 3,3,-16032; bl _s80290C60_7; mr 30,3; lis 4,-32704; lwz 9,0x8(30); lis 5,-32704; addi 4,4,23144; addi 5,5,22800; lwz 0,0xc(9); li 6,871; lha 3,0x8(9); mtspr 8,0; add 3,30,3; blrl; lis 9,-32694; lis 11,-32700; lwz 10,-16152(9); addi 0,11,-6476; lhz 9,-6476(11); stw 0,0x8(1); cmpwi 10,0; addi 9,9,1; sth 9,-6476(11); beq 11f; lwz 9,0x4c(28); mtspr 8,10; lwz 11,0x8(9); lwz 3,0x18(11); blrl; cmpwi 3,1; bne 13f; 11:; mr 4,31; addi 3,1,16; bl _s80290C60_8; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 12f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80290C60_9; 12:; lwz 4,0x10(1); stw 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 13f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80290C60_10; 13:; lwz 0,0x0(29); lis 9,-32694; addi 10,9,-16288; mr 3,29; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 14f; lwz 3,0x24(3); 14:; lwz 0,0x0(30); mr 11,30; lwz 9,0xc(3); rlwinm 0,0,0,25,31; addi 3,9,8; cmpwi 0,1; beq 15f; lwz 11,0x24(30); 15:; lwz 9,0x4c(28); lwz 4,0xc(11); lwz 11,0x8(9); lwz 0,0x84(10); addi 4,4,8; lwz 6,0x8(1); lwz 5,0x18(11); mtspr 8,0; addi 6,6,8; blrl; lwz 9,0x8(30); lis 4,-32704; lis 5,-32704; addi 4,4,23144; lwz 0,0x14(9); addi 5,5,22800; lha 3,0x10(9); li 6,881; mtspr 8,0; add 3,30,3; blrl; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 33f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80290C60_11; b 33f; 16:; addi 3,30,36; mr 4,25; mr 5,21; bl _s80290C60_12; b 33f; 17:; mr 3,31; li 30,0; bl _s80290C60_13; cmpwi 3,14; bne 18f; mr 3,31; bl _s80290C60_14; subfic 0,3,0; adde 30,0,3; 18:; cmpwi 30,0; beq 19f; addi 30,1,24; mr 3,25; mr 4,30; bl _s80290C60_15; lwz 3,-23008(13); mr 5,30; mr 4,31; bl _s80290C60_16; lwz 3,0x4c(31); mr 4,25; mr 5,21; addi 3,3,28; bl _s80290C60_17; b 33f; 19:; mr 3,31; li 30,0; bl _s80290C60_18; cmpwi 3,15; bne 20f; mr 3,31; bl _s80290C60_19; subfic 0,3,0; adde 30,0,3; 20:; cmpwi 30,0; beq 21f; lwz 9,0x4c(31); lwz 3,0x20(9); cmpwi 3,0; beq 33f; addi 0,13,-27404; cmpw 3,0; beq 33f; lis 9,-32694; mr 4,21; lwz 0,-16208(9); mtspr 8,0; blrl; b 33f; 21:; mr 3,31; li 30,0; bl _s80290C60_20; cmpwi 3,16; bne 22f; mr 3,31; bl _s80290C60_21; subfic 0,3,0; adde 30,0,3; 22:; cmpwi 30,0; beq 29f; lwz 31,0x4c(31); mr 3,25; bl _s80290C60_22; li 28,0; lwz 4,0x8(31); mr 3,25; addi 4,4,24; bl _s80290C60_23; lis 9,-32694; addi 11,1,8; lwz 5,-11388(9); lis 4,-32704; addi 9,9,-11388; lfs f29,0x5acc(4); lwz 0,0x8(9); lis 3,-32704; lwz 6,0x14(9); fmr f28,f29; lwz 7,0x4(9); lwz 10,0xc(9); lwz 8,0x10(9); stw 5,0x8(1); stw 6,0x14(11); stw 7,0x4(11); stw 0,0x8(11); stw 10,0xc(11); stw 8,0x10(11); lfs f26,0x5ac8(3); b 28f; 23:; mr 3,25; mulli 30,28,56; bl _s80290C60_24; lwz 9,0x8(31); mr 3,25; lwz 4,0x34(9); add 4,4,30; addi 4,4,4; bl _s80290C60_25; lwz 9,0x8(31); mr 29,30; lwz 11,0x34(9); lwz 10,0x4(9); add 7,30,11; lwzx 9,30,11; lwz 8,0x18(10); lfs f0,0x24(7); rlwinm 9,9,2,0,29; lwzx 24,9,8; fcmpu 0,f28,f0; bne 24f; lfs f0,0x28(7); fcmpu 0,f29,f0; beq 25f; 24:; lfs f26,0x5ac8(20); 25:; lwz 9,0x8(31); mr 27,29; li 26,0; addi 23,28,1; lwz 11,0x34(9); add 11,27,11; lwz 0,0x30(11); lfs f31,0x2c(11); lfs f28,0x24(11); cmpw 26,0; lfs f29,0x28(11); bge 27f; lis 9,-32704; lis 11,-32704; lfd f30,0x5ad8(9); lis 22,17200; lfs f27,0x5ae0(11); li 28,0; 26:; fadds f0,f28,f26; stfs f29,0x1c(1); stfs f0,0x18(1); mr 4,25; stfs f31,0x8(1); mr 5,21; stfs f31,0x14(1); addi 6,1,8; mr 29,27; addi 26,26,1; lwz 11,0x8(31); lwz 10,0x10(24); lwz 9,0x34(11); add 9,27,9; lwz 30,0x34(9); lhax 11,30,28; add 30,30,28; rlwinm 11,11,2,0,29; addi 28,28,4; lwzx 3,11,10; bl _s80290C60_26; lha 0,0x2(30); lwz 10,0x8(31); xoris 0,0,32768; stw 0,0x64(1); lwz 9,0x34(10); stw 22,0x60(1); add 29,29,9; lfd f0,0x60(1); lwz 0,0x30(29); fsub f0,f0,f30; frsp f0,f0; cmpw 26,0; fmadds f26,f0,f27,f26; blt 26b; 27:; mr 3,25; mr 28,23; bl _s80290C60_27; 28:; lwz 9,0x8(31); lwz 0,0x30(9); cmpw 28,0; blt 23b; mr 3,25; bl _s80290C60_28; b 33f; 29:; mr 3,31; li 30,0; bl _s80290C60_29; cmpwi 3,17; bne 30f; mr 3,31; bl _s80290C60_30; subfic 0,3,0; adde 30,0,3; 30:; cmpwi 30,0; beq 31f; lwz 29,0x4c(31); mr 3,25; bl _s80290C60_31; lis 9,-32704; lfs f13,0x18(29); lfs f0,0x5ad0(9); lis 30,-32694; addi 30,30,-16288; mr 3,25; fsubs f0,f0,f13; stfs f0,0x0(25); lwz 9,0x7c(30); mtspr 8,9; blrl; lwz 9,0x8(29); mr 4,25; mr 5,21; li 6,0; lwz 3,0x8(9); bl _s80290C60_32; lfs f0,0x18(29); mr 3,25; stfs f0,0x0(25); lwz 0,0x7c(30); mtspr 8,0; blrl; lwz 9,0x8(29); mr 5,21; mr 4,25; li 6,0; lwz 3,0xc(9); bl _s80290C60_33; mr 3,25; bl _s80290C60_34; b 33f; 31:; mr 3,31; li 30,0; bl _s80290C60_35; cmpwi 3,12; bne 32f; mr 3,31; bl _s80290C60_36; subfic 0,3,0; adde 30,0,3; 32:; cmpwi 30,0; beq 33f; lwz 9,0x4c(31); mr 4,25; mr 5,21; li 6,0; lwz 3,0x8(9); bl _s80290C60_37; 33:; lwz 0,0xcc(1); mtspr 8,0; lmw 20,0x68(1); lfd f26,0x98(1); lfd f27,0xa0(1); lfd f28,0xa8(1); lfd f29,0xb0(1); lfd f30,0xb8(1); lfd f31,0xc0(1); addi 1,1,200"
extern "C" void _s80290C60_0();
extern "C" void _s80290C60_1();
extern "C" void _s80290C60_2();
extern "C" void _s80290C60_3();
extern "C" void _s80290C60_4();
extern "C" void _s80290C60_5();
extern "C" void _s80290C60_6();
extern "C" void _s80290C60_7();
extern "C" void _s80290C60_8();
extern "C" void _s80290C60_9();
extern "C" void _s80290C60_10();
extern "C" void _s80290C60_11();
extern "C" void _s80290C60_12();
extern "C" void _s80290C60_13();
extern "C" void _s80290C60_14();
extern "C" void _s80290C60_15();
extern "C" void _s80290C60_16();
extern "C" void _s80290C60_17();
extern "C" void _s80290C60_18();
extern "C" void _s80290C60_19();
extern "C" void _s80290C60_20();
extern "C" void _s80290C60_21();
extern "C" void _s80290C60_22();
extern "C" void _s80290C60_23();
extern "C" void _s80290C60_24();
extern "C" void _s80290C60_25();
extern "C" void _s80290C60_26();
extern "C" void _s80290C60_27();
extern "C" void _s80290C60_28();
extern "C" void _s80290C60_29();
extern "C" void _s80290C60_30();
extern "C" void _s80290C60_31();
extern "C" void _s80290C60_32();
extern "C" void _s80290C60_33();
extern "C" void _s80290C60_34();
extern "C" void _s80290C60_35();
extern "C" void _s80290C60_36();
extern "C" void _s80290C60_37();
extern "C" void f_80290C60() {}
