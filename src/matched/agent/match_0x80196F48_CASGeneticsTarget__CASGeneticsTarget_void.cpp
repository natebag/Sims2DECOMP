// 0x80196F48 CASGeneticsTarget::CASGeneticsTarget(void) (1916 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stfd f31,0x88(1); stmw 16,0x48(1); stw 0,0x94(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12328; stw 9,0x80(31); addi 8,31,40; stw 0,0x0(31); addi 7,31,56; stw 0,0x4(31); addi 6,31,72; stw 0,0x8(31); addi 5,31,88; stw 0,0xc(31); addi 4,31,104; stw 0,0x10(31); lis 9,-32698; stw 0,0x14(31); lis 11,-32698; stw 0,0x18(31); addi 9,9,28456; stw 0,0x8(8); addi 11,11,28552; stw 0,0x28(31); addi 29,31,172; stw 0,0x8(7); li 28,1; stw 0,0x38(31); addi 24,1,24; stw 0,0x8(6); addi 30,1,8; stw 0,0x48(31); addi 21,1,32; stw 0,0x8(5); addi 20,1,40; stw 0,0x58(31); addi 19,1,48; stw 0,0x8(4); addi 18,1,56; stw 9,0x88(31); stw 11,0x80(31); stw 0,0x98(31); stw 0,0x68(31); stw 0,0x78(31); stw 0,0x84(31); stw 0,0x8c(31); stw 0,0x90(31); 0:; mr 3,29; bl _s80196F48_0; addi 29,29,292; cmpwi 28,0; addi 28,28,-1; bne 0b; li 0,1; li 9,0; stw 0,0x2f4(31); cmpwi 31,0; li 0,4; stw 9,0x300(31); mtspr 9,0; stw 9,0x2f8(31); stw 9,0x2fc(31); addi 23,31,40; addi 22,31,56; addi 28,31,72; addi 26,31,88; addi 25,31,104; mfcr 29; addi 17,31,772; addi 16,31,788; 1:; bdnz 1b; li 0,4; mtspr 9,0; 2:; bdnz 2b; lis 9,-32705; li 0,0; addi 9,9,-15064; stw 0,0x418(31); lwz 11,0x0(9); lwz 12,0x4(9); lis 10,-32709; addi 27,10,15272; mtcrf 128,29; stw 11,0x18(1); stw 12,0x1c(1); stw 0,0x414(31); stw 31,0x10(1); beq 3f; mr 4,24; addi 3,1,8; li 5,8; bl _s80196F48_1; b 4f; 3:; stw 31,0x8(1); 4:; lis 9,-32705; stw 27,0x14(1); addi 9,9,-15056; lwz 6,0x8(1); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; lwz 10,0x4(30); addi 27,11,15392; lwz 0,0x8(30); mtcrf 128,29; lwz 9,0xc(30); stw 6,0x28(31); stw 10,0x4(23); stw 0,0x8(23); stw 9,0xc(23); stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq 5f; mr 4,21; mr 3,30; li 5,8; bl _s80196F48_2; b 6f; 5:; stw 31,0x8(1); 6:; lis 9,-32705; stw 27,0x14(1); addi 9,9,-15244; lwz 6,0x8(1); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; lwz 10,0x4(30); addi 27,11,15512; lwz 0,0x8(30); mtcrf 128,29; lwz 9,0xc(30); stw 6,0x38(31); stw 10,0x4(22); stw 0,0x8(22); stw 9,0xc(22); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq 7f; mr 4,20; mr 3,30; li 5,8; bl _s80196F48_3; b 8f; 7:; stw 31,0x8(1); 8:; lis 9,-32705; stw 27,0x14(1); addi 9,9,-15048; lwz 6,0x8(1); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; lwz 10,0x4(30); addi 27,11,15632; lwz 9,0x8(30); mtcrf 128,29; lwz 0,0xc(30); stw 6,0x48(31); stw 0,0xc(28); stw 10,0x4(28); stw 9,0x8(28); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq 9f; mr 4,19; mr 3,30; li 5,8; bl _s80196F48_4; b 10f; 9:; stw 31,0x8(1); 10:; lis 9,-32705; stw 27,0x14(1); addi 9,9,-15040; lwz 6,0x8(1); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; lwz 10,0x4(30); addi 28,11,15752; lwz 0,0x8(30); mtcrf 128,29; lwz 9,0xc(30); stw 6,0x58(31); stw 10,0x4(26); stw 0,0x8(26); stw 9,0xc(26); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq 11f; mr 4,18; mr 3,30; li 5,8; bl _s80196F48_5; b 12f; 11:; stw 31,0x8(1); 12:; stw 28,0x14(1); lis 9,-32705; lwz 8,0x8(1); addi 9,9,-15032; lwz 7,0xc(30); lwz 11,0x4(30); lwz 10,0x8(30); lwz 0,-31532(13); stw 8,0x68(31); stw 11,0x4(25); cmpwi 0,0; stw 10,0x8(25); stw 7,0xc(25); stw 9,0x7c(31); bne 13f; li 3,16; bl _s80196F48_6; bl _s80196F48_7; stw 3,-31532(13); 13:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 14f; li 3,16; bl _s80196F48_8; bl _s80196F48_9; stw 3,-31528(13); 14:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 15f; li 3,16; bl _s80196F48_10; bl _s80196F48_11; stw 3,-31524(13); 15:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 16f; li 3,16; bl _s80196F48_12; bl _s80196F48_13; stw 3,-31488(13); 16:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 17f; li 3,16; bl _s80196F48_14; bl _s80196F48_15; stw 3,-31516(13); 17:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 18f; li 3,16; bl _s80196F48_16; bl _s80196F48_17; stw 3,-31484(13); 18:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 19f; li 3,16; bl _s80196F48_18; bl _s80196F48_19; stw 3,-31544(13); 19:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 20f; li 3,32; bl _s80196F48_20; bl _s80196F48_21; stw 3,-31540(13); 20:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 21f; li 3,120; bl _s80196F48_22; bl _s80196F48_23; stw 3,-31536(13); 21:; lwz 0,-31536(13); li 9,1; stw 9,0x0(31); li 11,0; stw 0,0x24(31); lwz 9,0x8(26); cmpwi 9,0; bne 22f; lwz 0,0x58(31); cmpwi 0,0; beq 23f; 22:; li 11,1; 23:; cmpwi 11,0; beq 24f; lwz 3,0x10(31); mr 5,26; lwz 6,0x7c(31); li 4,75; bl _s80196F48_24; 24:; lwz 0,0x0(31); cmpwi 0,0; beq 27f; lwz 0,0x8(25); li 9,0; cmpwi 0,0; bne 25f; lwz 0,0x68(31); cmpwi 0,0; beq 26f; 25:; li 9,1; 26:; cmpwi 9,0; beq 27f; lwz 3,0x14(31); mr 5,25; lwz 6,0x7c(31); li 4,25; bl _s80196F48_25; 27:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-15020; cmpwi 0,0; beq 28f; lwz 3,0x4(31); mr 5,23; bl _s80196F48_26; 28:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-15008; cmpwi 0,0; beq 29f; lwz 3,0x8(31); mr 5,22; bl _s80196F48_27; 29:; lwz 0,0x300(31); li 9,0; li 11,1; stw 9,0xa0(31); rlwinm 0,0,0,31,29; stw 11,0xa8(31); ori 0,0,5; stw 9,0x9c(31); rlwinm 0,0,0,29,27; stw 11,0xa4(31); ori 0,0,16; li 3,32; rlwinm 0,0,0,27,25; mr 28,17; stw 0,0x300(31); addi 27,28,12; bl _s80196F48_28; bl _s80196F48_29; mr 0,3; li 4,0; stw 0,0x94(31); bl _s80196F48_30; lis 29,-32705; lis 30,-32692; addi 30,30,-17444; lwz 4,-11328(29); addi 29,29,-11328; li 5,0; li 6,0; mr 3,30; bl _s80196F48_31; stw 3,0x304(31); li 5,0; li 6,0; mr 3,30; lwz 4,0x4(29); bl _s80196F48_32; stw 3,0x308(31); li 5,0; li 6,0; mr 3,30; lwz 4,0x8(29); bl _s80196F48_33; stw 3,0x30c(31); li 5,0; li 6,0; mr 3,30; lwz 4,0xc(29); bl _s80196F48_34; stw 3,0x310(31); li 5,0; li 6,0; mr 3,30; lwz 4,-21160(13); bl _s80196F48_35; stw 3,0x314(31); li 5,0; mr 3,30; li 6,0; lwz 4,-21156(13); bl _s80196F48_36; stw 3,0x318(31); 30:; lwz 3,0x0(28); addi 28,28,4; cmpwi 3,0; beq 31f; bl _s80196F48_37; 31:; cmpw 28,27; ble 30b; mr 30,16; addi 29,30,4; 32:; lwz 3,0x0(30); addi 30,30,4; cmpwi 3,0; beq 33f; bl _s80196F48_38; 33:; cmpw 30,29; ble 32b; lwz 3,-26564(13); lwz 9,0x0(3); lha 0,0x88(9); lwz 9,0x8c(9); add 3,3,0; mtspr 8,9; blrl; stw 3,0x414(31); cmpwi 3,0; beq 34f; lwz 11,-26564(13); mr 4,3; lis 5,12050; lwz 9,0x0(11); ori 5,5,32122; lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,11,3; blrl; lis 9,-32697; lwz 10,0x5f14(9); lis 7,17200; lis 9,-32705; lis 8,-32705; lbz 0,0x1c(10); li 3,24; lfd f0,-14992(9); extsb 0,0; lfs f13,-14984(8); xoris 0,0,32768; stw 0,0x44(1); stw 7,0x40(1); lfd f31,0x40(1); fsub f31,f31,f0; frsp f31,f31; fdivs f31,f31,f13; bl _s80196F48_39; lis 9,-32705; li 0,0; lfs f0,-14980(9); li 9,15; stw 0,0x10(3); stw 9,0x0(3); stfs f0,0xc(3); stw 3,0x418(31); stfs f31,0x8(3); stfs f31,0x4(3); 34:; mr 3,31; lwz 0,0x94(1); mtspr 8,0; lmw 16,0x48(1); lfd f31,0x88(1); addi 1,1,144"
extern "C" void _s80196F48_0();
extern "C" void _s80196F48_1();
extern "C" void _s80196F48_2();
extern "C" void _s80196F48_3();
extern "C" void _s80196F48_4();
extern "C" void _s80196F48_5();
extern "C" void _s80196F48_6();
extern "C" void _s80196F48_7();
extern "C" void _s80196F48_8();
extern "C" void _s80196F48_9();
extern "C" void _s80196F48_10();
extern "C" void _s80196F48_11();
extern "C" void _s80196F48_12();
extern "C" void _s80196F48_13();
extern "C" void _s80196F48_14();
extern "C" void _s80196F48_15();
extern "C" void _s80196F48_16();
extern "C" void _s80196F48_17();
extern "C" void _s80196F48_18();
extern "C" void _s80196F48_19();
extern "C" void _s80196F48_20();
extern "C" void _s80196F48_21();
extern "C" void _s80196F48_22();
extern "C" void _s80196F48_23();
extern "C" void _s80196F48_24();
extern "C" void _s80196F48_25();
extern "C" void _s80196F48_26();
extern "C" void _s80196F48_27();
extern "C" void _s80196F48_28();
extern "C" void _s80196F48_29();
extern "C" void _s80196F48_30();
extern "C" void _s80196F48_31();
extern "C" void _s80196F48_32();
extern "C" void _s80196F48_33();
extern "C" void _s80196F48_34();
extern "C" void _s80196F48_35();
extern "C" void _s80196F48_36();
extern "C" void _s80196F48_37();
extern "C" void _s80196F48_38();
extern "C" void _s80196F48_39();
extern "C" void f_80196F48() {}
