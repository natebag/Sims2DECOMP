// 0x800526EC IShrubObject::SetObjOrient(void) (1792 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-248(1); mfspr 0,8; stfd f26,0xc8(1); stfd f27,0xd0(1); stfd f28,0xd8(1); stfd f29,0xe0(1); stfd f30,0xe8(1); stfd f31,0xf0(1); stmw 23,0xa4(1); stw 0,0xfc(1); mr 24,3; addi 28,1,16; lwz 10,0x328(24); addi 3,1,8; lwz 11,0x3c8(24); addi 27,1,32; lwz 9,0x4(10); lfs f27,0x50(11); lwz 0,0x35c(9); lha 4,0x358(9); mtspr 8,0; lfs f28,0x4c(11); add 4,10,4; blrl; lis 9,-32707; addi 3,1,8; lfs f29,0x32bc(9); bl _s800526EC_0; cmpwi 3,0; fmr f26,f29; blt 22f; addi 3,1,8; bl _s800526EC_1; lwz 11,-21488(13); mr 30,3; lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; cmpw 30,3; bgt 22f; addi 3,1,8; bl _s800526EC_2; cmpwi 3,0; blt 22f; addi 3,1,8; bl _s800526EC_3; lwz 11,-21488(13); mr 30,3; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; cmpw 30,3; bgt 22f; lwz 11,-21488(13); addi 5,1,8; mr 3,28; addi 29,1,88; lwz 9,0x0(11); mr 26,29; li 23,0; li 25,0; lwz 0,0xac(9); lha 4,0xa8(9); mtspr 8,0; add 4,11,4; blrl; addi 3,1,8; bl _s800526EC_4; addi 30,3,-1; addi 3,1,8; bl _s800526EC_5; mr 5,3; li 6,1; mr 4,30; mr 3,29; bl _s800526EC_6; addi 3,1,72; mr 4,29; li 5,0; bl _s800526EC_7; mr 3,29; li 4,2; bl _s800526EC_8; lwz 0,0x4c(1); cmpwi 0,0; beq 4f; lis 29,-16455; ori 29,29,60970; 0:; lwz 30,0x4c(1); li 31,0; cmpwi 30,0; beq 2f; lwz 9,0x4(30); lha 3,0x310(9); lwz 0,0x314(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0xc0(3); cmpwi 0,0; beq 2f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc0(3); li 0,0; lwz 9,0x0(9); cmpwi 9,0; beq 1f; lwz 0,-4(9); 1:; cmpwi 0,0; ble 2f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc0(3); lwz 11,0x0(9); lwz 0,0x0(11); cmpw 0,29; bne 2f; li 31,1; 2:; cmpwi 31,0; beq 3f; li 25,1; b 4f; 3:; addi 3,1,72; bl _s800526EC_9; lwz 0,0x4c(1); cmpwi 0,0; bne 0b; 4:; addi 3,1,8; bl _s800526EC_10; mr 30,3; addi 3,1,8; bl _s800526EC_11; addi 5,3,1; li 6,1; mr 4,30; mr 3,26; bl _s800526EC_12; addi 3,1,96; mr 4,26; li 5,0; bl _s800526EC_13; mr 3,26; li 4,2; bl _s800526EC_14; lwz 0,0x64(1); cmpwi 0,0; beq 9f; lis 29,-16455; ori 29,29,60970; 5:; lwz 30,0x64(1); li 31,0; cmpwi 30,0; beq 7f; lwz 9,0x4(30); lha 3,0x310(9); lwz 0,0x314(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 7f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0xc0(3); cmpwi 0,0; beq 7f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc0(3); li 0,0; lwz 9,0x0(9); cmpwi 9,0; beq 6f; lwz 0,-4(9); 6:; cmpwi 0,0; ble 7f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc0(3); lwz 11,0x0(9); lwz 0,0x0(11); cmpw 0,29; bne 7f; li 31,1; 7:; cmpwi 31,0; beq 8f; li 23,1; b 9f; 8:; addi 3,1,96; bl _s800526EC_15; lwz 0,0x64(1); cmpwi 0,0; bne 5b; 9:; addi 3,1,8; bl _s800526EC_16; addi 30,3,1; addi 3,1,8; bl _s800526EC_17; mr 5,3; li 6,1; mr 4,30; mr 3,26; bl _s800526EC_18; addi 3,1,112; mr 4,26; li 5,0; bl _s800526EC_19; mr 3,26; li 4,2; bl _s800526EC_20; lwz 0,0x74(1); cmpwi 0,0; beq 14f; lis 29,-16455; ori 29,29,60970; 10:; lwz 30,0x74(1); li 31,0; cmpwi 30,0; beq 12f; lwz 9,0x4(30); lha 3,0x310(9); lwz 0,0x314(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 12f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0xc0(3); cmpwi 0,0; beq 12f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc0(3); li 0,0; lwz 9,0x0(9); cmpwi 9,0; beq 11f; lwz 0,-4(9); 11:; cmpwi 0,0; ble 12f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc0(3); lwz 11,0x0(9); lwz 0,0x0(11); cmpw 0,29; bne 12f; li 31,1; 12:; cmpwi 31,0; beq 13f; li 25,1; b 14f; 13:; addi 3,1,112; bl _s800526EC_21; lwz 0,0x74(1); cmpwi 0,0; bne 10b; 14:; cmpwi 25,0; addi 3,1,8; mfcr 25; bl _s800526EC_22; mr 30,3; addi 3,1,8; bl _s800526EC_23; addi 5,3,-1; li 6,1; mr 4,30; mr 3,26; bl _s800526EC_24; addi 3,1,128; mr 4,26; li 5,0; bl _s800526EC_25; mr 3,26; li 4,2; bl _s800526EC_26; lwz 0,0x84(1); cmpwi 0,0; beq 19f; lis 29,-16455; ori 29,29,60970; 15:; lwz 30,0x84(1); li 31,0; cmpwi 30,0; beq 17f; lwz 9,0x4(30); lha 3,0x310(9); lwz 0,0x314(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 17f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0xc0(3); cmpwi 0,0; beq 17f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc0(3); li 0,0; lwz 9,0x0(9); cmpwi 9,0; beq 16f; lwz 0,-4(9); 16:; cmpwi 0,0; ble 17f; lwz 9,0x4(30); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xc0(3); lwz 11,0x0(9); lwz 0,0x0(11); cmpw 0,29; bne 17f; li 31,1; 17:; cmpwi 31,0; beq 18f; li 23,1; b 19f; 18:; addi 3,1,128; bl _s800526EC_27; lwz 0,0x84(1); cmpwi 0,0; bne 15b; 19:; cmpwi 23,0; beq 20f; lis 9,-32707; lfs f26,0x32c0(9); 20:; mtcrf 128,25; beq 21f; lis 9,-32707; lfs f29,0x32c0(9); 21:; mr 3,28; li 4,2; bl _s800526EC_28; 22:; addi 3,1,8; lis 30,17200; bl _s800526EC_29; xoris 3,3,32768; stw 3,0x9c(1); lis 9,-32707; lfd f30,0x32c8(9); addi 3,1,8; stw 30,0x98(1); lfd f31,0x98(1); fsub f31,f31,f30; frsp f31,f31; fadds f31,f31,f28; bl _s800526EC_30; xoris 3,3,32768; stw 3,0x9c(1); lis 9,-32707; lfs f12,0x32d0(9); lis 10,-32707; stw 30,0x98(1); lis 9,-32707; stfs f31,0x10(1); mr 3,24; lfd f0,0x98(1); mr 4,28; lfs f13,0x32bc(10); mr 5,27; fsub f0,f0,f30; lfs f1,0x32d4(9); frsp f0,f0; fadds f0,f0,f27; stfs f0,0x14(1); stfs f12,0x8(28); stfs f26,0x20(1); stfs f29,0x24(1); stfs f13,0x8(27); bl _s800526EC_31; addi 3,1,8; li 4,2; bl _s800526EC_32; lwz 0,0xfc(1); mtspr 8,0; lmw 23,0xa4(1); lfd f26,0xc8(1); lfd f27,0xd0(1); lfd f28,0xd8(1); lfd f29,0xe0(1); lfd f30,0xe8(1); lfd f31,0xf0(1); addi 1,1,248"
extern "C" void _s800526EC_0();
extern "C" void _s800526EC_1();
extern "C" void _s800526EC_2();
extern "C" void _s800526EC_3();
extern "C" void _s800526EC_4();
extern "C" void _s800526EC_5();
extern "C" void _s800526EC_6();
extern "C" void _s800526EC_7();
extern "C" void _s800526EC_8();
extern "C" void _s800526EC_9();
extern "C" void _s800526EC_10();
extern "C" void _s800526EC_11();
extern "C" void _s800526EC_12();
extern "C" void _s800526EC_13();
extern "C" void _s800526EC_14();
extern "C" void _s800526EC_15();
extern "C" void _s800526EC_16();
extern "C" void _s800526EC_17();
extern "C" void _s800526EC_18();
extern "C" void _s800526EC_19();
extern "C" void _s800526EC_20();
extern "C" void _s800526EC_21();
extern "C" void _s800526EC_22();
extern "C" void _s800526EC_23();
extern "C" void _s800526EC_24();
extern "C" void _s800526EC_25();
extern "C" void _s800526EC_26();
extern "C" void _s800526EC_27();
extern "C" void _s800526EC_28();
extern "C" void _s800526EC_29();
extern "C" void _s800526EC_30();
extern "C" void _s800526EC_31();
extern "C" void _s800526EC_32();
extern "C" void f_800526EC() {}
