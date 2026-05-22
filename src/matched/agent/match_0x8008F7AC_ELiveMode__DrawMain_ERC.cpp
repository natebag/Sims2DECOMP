// 0x8008F7AC ELiveMode::DrawMain(ERC (1060 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; mfcr 12; stfd f26,0x60(1); stfd f27,0x68(1); stfd f28,0x70(1); stfd f29,0x78(1); stfd f30,0x80(1); stfd f31,0x88(1); stmw 17,0x24(1); stw 0,0x94(1); stw 12,0x20(1); lis 9,-32697; mr 23,3; addi 9,9,23428; mr 28,4; lwz 0,0xec(9); li 21,1; cmpwi 0,0; beq 0f; li 21,2; 0:; lwz 9,0x100(9); cmpwi 9,0; beq 1f; lwz 0,0x54c(9); cmpwi 0,0; beq 1f; li 21,1; 1:; lis 31,-32697; li 27,0; addi 3,31,23428; cmpwi 4,21,2; bl _s8008F7AC_0; lis 20,-32697; mr 22,3; cmpw 27,21; bge 13f; lis 9,-32707; addi 10,31,23428; lfd f28,0x7e90(9); lis 11,-32707; lis 9,-32707; addi 24,10,244; lfs f26,0x7e98(9); mr 17,10; lfs f27,0x7e9c(11); mr 18,24; cmpwi 3,22,-1; addi 25,20,24012; lis 19,17200; addi 26,1,8; 2:; bne cr4,4f; beq cr3,3f; cmpw 27,22; bne 12f; 3:; subfic 0,27,0; adde 3,0,27; bl _s8008F7AC_1; mr. 3,3; beq 4f; li 4,0; bl _s8008F7AC_2; 4:; mr 3,27; li 29,0; bl _s8008F7AC_3; lwz 0,0x2c(23); cmpwi 0,0; bne 5f; lwz 29,0xc(24); 5:; cmpwi 29,0; beq 12f; rlwinm 0,27,2,0,29; addi 9,25,280; lwzx 4,9,0; mr 3,25; addi 31,29,16; bl _s8008F7AC_4; mr 3,25; mr 4,29; bl _s8008F7AC_5; bne cr4,6f; bne cr3,6f; mr 5,31; mr 3,23; mr 4,28; mr 6,27; bl _s8008F7AC_6; b 7f; 6:; mr 3,29; bl _s8008F7AC_7; lwz 11,-26392(13); fmr f29,f1; lwz 9,0x0(11); lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26392(13); mr 30,3; lwz 9,0x0(11); lwz 0,0x14c(9); lha 3,0x148(9); mtspr 8,0; add 3,11,3; blrl; xoris 30,30,32768; stw 30,0x1c(1); mr 11,9; xoris 3,3,32768; lwz 10,-26392(13); stw 19,0x18(1); lwz 8,0x0(10); lfd f0,0x18(1); stw 3,0x1c(1); fsub f0,f0,f28; lwz 0,0x144(8); stw 19,0x18(1); frsp f0,f0; fmuls f29,f29,f0; lha 3,0x140(8); lfd f0,0x18(1); mtspr 8,0; add 3,10,3; fsub f0,f0,f28; frsp f0,f0; fdivs f29,f29,f0; blrl; mr 3,29; fmr f31,f1; bl _s8008F7AC_8; fmr f30,f1; mr 3,29; bl _s8008F7AC_9; fmr f4,f1; mr 3,31; fmr f2,f31; fmr f3,f30; fmr f1,f29; bl _s8008F7AC_10; mr 3,31; li 4,1; bl _s8008F7AC_11; mr 3,29; mr 4,31; bl _s8008F7AC_12; stfs f26,0x8(1); mr 3,31; mr 4,26; stfs f26,0x4(26); stfs f27,0x8(26); stfs f27,0xc(26); bl _s8008F7AC_13; lwz 9,0x9c(31); mr 4,28; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 7:; addi 30,20,24012; stw 27,0xcc(30); lwz 9,0x70(28); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,28,3; blrl; lwz 0,0xc8(30); cmpwi 0,0; beq 9f; bl _s8008F7AC_14; lwz 4,0xc8(30); mr 5,27; bl _s8008F7AC_15; lwz 0,0xec(17); cmpwi 0,0; beq 8f; lwz 9,0xc(18); lwz 0,0x54c(9); cmpwi 0,0; beq 8f; bl _s8008F7AC_16; lwz 4,0xc8(30); li 5,1; bl _s8008F7AC_17; 8:; lwz 3,0x10c(25); bl _s8008F7AC_18; lwz 3,0xc8(25); mr 4,28; bl _s8008F7AC_19; 9:; lwz 9,0x70(28); addi 30,20,24012; lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,28,3; blrl; lwz 0,0xc8(30); cmpwi 0,0; bne 10f; lwz 3,0x10c(30); mr 4,28; bl _s8008F7AC_20; 10:; lwz 3,0xe0(30); mr 4,28; bl _s8008F7AC_21; lwz 3,0xd0(30); mr 4,28; bl _s8008F7AC_22; bne cr4,11f; subfic 0,27,0; adde 3,0,27; bl _s8008F7AC_23; mr. 3,3; beq 11f; li 4,1; bl _s8008F7AC_24; 11:; mr 3,27; mr 4,28; bl _s8008F7AC_25; 12:; addi 27,27,1; addi 24,24,16; cmpw 27,21; blt 2b; 13:; lis 9,-32697; addi 31,9,24012; lwz 3,0xd0(31); cmpwi 3,0; beq 14f; bl _s8008F7AC_26; lwz 3,0xd0(31); mr 4,28; addi 3,3,16; lwz 9,0x9c(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; 14:; bne cr4,16f; cmpwi 22,-1; bne 15f; mr 3,23; mr 4,28; bl _s8008F7AC_27; 15:; lis 30,-32697; addi 30,30,23428; lwz 3,0x100(30); bl _s8008F7AC_28; lwz 3,0x110(30); bl _s8008F7AC_29; 16:; lwz 0,0x94(1); lwz 12,0x20(1); mtspr 8,0; lmw 17,0x24(1); lfd f26,0x60(1); lfd f27,0x68(1); lfd f28,0x70(1); lfd f29,0x78(1); lfd f30,0x80(1); lfd f31,0x88(1); mtcrf 24,12; addi 1,1,144"
extern "C" void _s8008F7AC_0();
extern "C" void _s8008F7AC_1();
extern "C" void _s8008F7AC_2();
extern "C" void _s8008F7AC_3();
extern "C" void _s8008F7AC_4();
extern "C" void _s8008F7AC_5();
extern "C" void _s8008F7AC_6();
extern "C" void _s8008F7AC_7();
extern "C" void _s8008F7AC_8();
extern "C" void _s8008F7AC_9();
extern "C" void _s8008F7AC_10();
extern "C" void _s8008F7AC_11();
extern "C" void _s8008F7AC_12();
extern "C" void _s8008F7AC_13();
extern "C" void _s8008F7AC_14();
extern "C" void _s8008F7AC_15();
extern "C" void _s8008F7AC_16();
extern "C" void _s8008F7AC_17();
extern "C" void _s8008F7AC_18();
extern "C" void _s8008F7AC_19();
extern "C" void _s8008F7AC_20();
extern "C" void _s8008F7AC_21();
extern "C" void _s8008F7AC_22();
extern "C" void _s8008F7AC_23();
extern "C" void _s8008F7AC_24();
extern "C" void _s8008F7AC_25();
extern "C" void _s8008F7AC_26();
extern "C" void _s8008F7AC_27();
extern "C" void _s8008F7AC_28();
extern "C" void _s8008F7AC_29();
extern "C" void f_8008F7AC() {}
