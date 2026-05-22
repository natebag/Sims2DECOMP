// 0x801DFB98 RMDTarget::SetupWidgets(void) (1036 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-216(1); mfspr 0,8; stfd f30,0xc8(1); stfd f31,0xd0(1); stmw 21,0x9c(1); stw 0,0xdc(1); addi 30,1,16; mr 24,3; mr 3,30; lis 22,-32705; bl _s801DFB98_0; mr 31,30; addi 28,1,104; addi 25,1,96; mr 3,30; bl _s801DFB98_1; lis 9,-32705; lis 10,-32705; lfs f0,0x5484(9); lis 11,-32698; lfs f31,0x5488(10); addi 21,11,-21552; stfs f0,0x64(1); li 8,0; stfs f0,0x60(1); addi 26,1,120; lwz 10,0x64(1); addi 27,1,40; lwz 11,0x60(1); stfs f31,0x60(1); stfs f31,0x64(1); lwz 0,0x60(1); lwz 9,0x64(1); stw 8,0x28(1); stw 11,0x2c(1); stw 0,0x54(1); stw 9,0x58(1); stw 10,0x30(1); stw 21,0x5c(1); bl _s801DFB98_2; li 4,16; li 5,16; li 6,0; li 7,0; bl _s801DFB98_3; lis 9,-32705; stw 3,0x34(1); lfs f0,0x548c(9); lis 11,-32705; stfs f31,0x4c(1); addi 3,24,160; stfs f0,0x68(1); stfs f0,0xc(28); stfs f0,0x4(28); stfs f0,0x8(28); stfs f31,0x60(1); lfs f30,0x5490(11); stfs f31,0x4(25); stfs f30,0x78(1); stfs f31,0x4(26); bl _s801DFB98_4; mr 8,3; lfs f1,0x5494(22); mr 3,27; mr 4,25; mr 5,26; mr 6,28; li 7,0; bl _s801DFB98_5; mr 3,27; bl _s801DFB98_6; lis 9,-32705; stfs f1,0x8(1); lfs f13,0x5498(9); fsubs f1,f1,f13; fctiwz f0,f1; stfd f0,0x90(1); lwz 0,0x94(1); cmpwi 0,159; bgt 0f; li 0,160; 0:; rlwinm 30,0,1,31,31; lis 4,-32705; add 30,0,30; li 5,0; rlwinm 30,30,0,0,30; addi 4,4,21552; subf 30,30,0; mr 3,31; add 30,0,30; lis 23,-32705; bl _s801DFB98_7; addi 29,30,8; addi 4,30,46; mr 3,31; rlwinm 4,4,31,1,31; subfic 4,4,320; bl _s801DFB98_8; li 4,340; mr 3,31; bl _s801DFB98_9; lis 4,-32705; li 5,0; addi 4,4,21580; mr 3,31; bl _s801DFB98_10; fmr f1,f31; mr 3,31; bl _s801DFB98_11; rlwinm 4,29,31,1,31; mr 3,31; addi 4,4,19; bl _s801DFB98_12; mr 4,29; mr 3,31; bl _s801DFB98_13; lfs f1,0x549c(23); mr 3,31; bl _s801DFB98_14; lis 4,-32705; li 5,0; addi 4,4,21596; mr 3,31; bl _s801DFB98_15; addi 4,30,36; mr 3,31; bl _s801DFB98_16; lis 4,-32705; li 5,0; addi 4,4,21308; mr 3,31; bl _s801DFB98_17; addi 4,30,38; mr 3,31; bl _s801DFB98_18; stfs f31,0x80(1); addi 9,1,128; stfs f31,0x4(9); addi 3,24,164; lwz 0,0x80(1); lwz 11,0x4(9); stw 0,0x60(1); stw 11,0x4(25); stfs f30,0x80(1); stfs f31,0x4(9); lwz 0,0x80(1); lwz 11,0x4(9); stw 0,0x78(1); stw 11,0x4(26); bl _s801DFB98_19; mr 8,3; lfs f1,0x5494(22); mr 4,25; mr 5,26; mr 6,28; mr 3,27; li 7,0; bl _s801DFB98_20; mr 3,27; bl _s801DFB98_21; lis 9,-32705; lis 11,-32705; lfs f0,0x54a0(9); lfs f12,0x54a4(11); fadds f0,f1,f0; stfs f1,0x8(1); fsubs f0,f0,f12; fctiwz f13,f0; stfd f13,0x90(1); lwz 0,0x94(1); cmpwi 0,47; bgt 1f; li 0,48; 1:; rlwinm 30,0,1,31,31; lis 4,-32705; add 30,0,30; li 5,0; rlwinm 30,30,0,0,30; addi 4,4,21532; subf 30,30,0; mr 3,31; add 30,0,30; bl _s801DFB98_22; addi 29,30,8; addi 4,30,52; mr 3,31; rlwinm 4,4,31,1,31; subfic 4,4,320; bl _s801DFB98_23; li 4,382; mr 3,31; bl _s801DFB98_24; lis 4,-32705; li 5,0; addi 4,4,21612; mr 3,31; bl _s801DFB98_25; fmr f1,f31; mr 3,31; bl _s801DFB98_26; rlwinm 4,29,31,1,31; mr 3,31; addi 4,4,22; bl _s801DFB98_27; mr 4,29; mr 3,31; bl _s801DFB98_28; lfs f1,0x549c(23); mr 3,31; bl _s801DFB98_29; lis 4,-32705; li 5,0; addi 4,4,21624; mr 3,31; bl _s801DFB98_30; addi 4,30,41; mr 3,31; bl _s801DFB98_31; lis 4,-32705; li 5,0; addi 4,4,21336; mr 3,31; bl _s801DFB98_32; mr 4,30; mr 3,31; bl _s801DFB98_33; mr 3,31; bl _s801DFB98_34; lwz 3,0x28(1); stw 21,0x5c(1); cmpwi 3,0; beq 4f; mr 11,3; 2:; lwz 30,0x0(11); cmpwi 11,0; beq 3f; lwz 9,0xc(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 3:; mr. 11,30; bne 2b; 4:; lwz 30,0x34(1); bl _s801DFB98_35; mr 4,30; bl _s801DFB98_36; mr 3,31; li 4,2; bl _s801DFB98_37; lwz 0,0xdc(1); mtspr 8,0; lmw 21,0x9c(1); lfd f30,0xc8(1); lfd f31,0xd0(1); addi 1,1,216"
extern "C" void _s801DFB98_0();
extern "C" void _s801DFB98_1();
extern "C" void _s801DFB98_2();
extern "C" void _s801DFB98_3();
extern "C" void _s801DFB98_4();
extern "C" void _s801DFB98_5();
extern "C" void _s801DFB98_6();
extern "C" void _s801DFB98_7();
extern "C" void _s801DFB98_8();
extern "C" void _s801DFB98_9();
extern "C" void _s801DFB98_10();
extern "C" void _s801DFB98_11();
extern "C" void _s801DFB98_12();
extern "C" void _s801DFB98_13();
extern "C" void _s801DFB98_14();
extern "C" void _s801DFB98_15();
extern "C" void _s801DFB98_16();
extern "C" void _s801DFB98_17();
extern "C" void _s801DFB98_18();
extern "C" void _s801DFB98_19();
extern "C" void _s801DFB98_20();
extern "C" void _s801DFB98_21();
extern "C" void _s801DFB98_22();
extern "C" void _s801DFB98_23();
extern "C" void _s801DFB98_24();
extern "C" void _s801DFB98_25();
extern "C" void _s801DFB98_26();
extern "C" void _s801DFB98_27();
extern "C" void _s801DFB98_28();
extern "C" void _s801DFB98_29();
extern "C" void _s801DFB98_30();
extern "C" void _s801DFB98_31();
extern "C" void _s801DFB98_32();
extern "C" void _s801DFB98_33();
extern "C" void _s801DFB98_34();
extern "C" void _s801DFB98_35();
extern "C" void _s801DFB98_36();
extern "C" void _s801DFB98_37();
extern "C" void f_801DFB98() {}
