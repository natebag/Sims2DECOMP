// 0x801B5B14 G2DTarget::SpawnDialog(UIDialog (804 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 0,0x134(31); cmpwi 0,0; beq 1f; addi 3,31,252; addi 4,30,40; li 5,0; li 6,-1; bl _s801B5B14_0; cmpwi 3,0; bne 0f; addi 3,31,260; addi 4,30,48; li 5,0; li 6,-1; bl _s801B5B14_1; cmpwi 3,0; bne 0f; addi 3,31,264; addi 4,30,52; li 5,0; li 6,-1; bl _s801B5B14_2; cmpwi 3,0; bne 0f; addi 3,31,268; addi 4,30,56; li 5,0; li 6,-1; bl _s801B5B14_3; cmpwi 3,0; bne 0f; lwz 9,0x110(31); addi 0,30,80; cmpw 9,0; bne 0f; lwz 9,0x114(31); addi 0,30,96; cmpw 9,0; bne 0f; lwz 9,0x118(31); addi 0,30,112; cmpw 9,0; bne 0f; lwz 9,0xa8(31); lwz 0,0x4(30); cmpw 9,0; bne 0f; lwz 9,0xa4(31); lwz 0,0x0(30); cmpw 9,0; beq 13f; 0:; stw 30,0x98(31); b 13f; 1:; li 7,3; addi 8,31,336; mtspr 9,7; li 0,2; addi 10,31,348; addi 11,31,360; li 9,0; 2:; stwx 0,9,8; stwx 0,9,10; stwx 0,9,11; addi 9,9,4; bdnz 2b; li 0,0; li 3,0; stw 0,0x98(31); lwz 9,0x4(30); stw 0,0x114(31); stw 9,0xb0(31); stw 0,0x110(31); bl _s801B5B14_4; bl _s801B5B14_5; mr. 29,3; beq 4f; mr 3,29; bl _s801B5B14_6; cmpwi 3,0; beq 4f; mr 3,29; li 4,0; li 5,-1; bl _s801B5B14_7; mr. 11,3; beq 3f; lwz 9,0x5c(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; 3:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 4f; mr 3,29; li 4,1; li 5,-1; bl _s801B5B14_8; mr. 11,3; beq 4f; lwz 9,0x5c(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; 4:; mr 3,31; mr 4,30; bl _s801B5B14_9; lis 9,-32697; lwz 0,0x6120(9); cmpwi 0,0; beq 5f; lis 9,-32705; lfs f0,0xd8c(9); b 8f; 5:; lwz 0,0x18(30); cmpwi 0,-1; bne 6f; lwz 0,-30364(13); lis 8,17200; lis 11,-32705; stw 0,0x14(1); lis 10,-32705; lfd f13,0xd90(11); stw 8,0x10(1); lfs f12,0xd98(10); lfd f0,0x10(1); b 7f; 6:; xoris 0,0,32768; stw 0,0x14(1); lis 11,17200; lis 10,-32705; lis 8,-32705; stw 11,0x10(1); lfd f13,0xda0(10); lfd f0,0x10(1); lfs f12,0xd98(8); 7:; fsub f0,f0,f13; frsp f0,f0; fdivs f0,f0,f12; 8:; stfs f0,0x128(31); stfs f0,0x12c(31); lwz 0,0x0(31); cmpwi 0,0; beq 11f; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 5,9; cmpwi 0,0; bne 9f; lwz 0,0x58(31); cmpwi 0,0; beq 10f; 9:; li 11,1; 10:; cmpwi 11,0; beq 11f; lwz 3,0x10(31); li 4,75; lwz 6,0x7c(31); bl _s801B5B14_10; 11:; lha 6,0x4a(30); mr 3,31; lwz 4,0x3c(30); lha 5,0x48(30); bl _s801B5B14_11; mr 3,31; bl _s801B5B14_12; lis 9,-32697; li 4,47; lwz 3,0x5f10(9); li 5,2; bl _s801B5B14_13; lwz 0,-31536(13); cmpwi 0,0; bne 12f; li 3,120; bl _s801B5B14_14; bl _s801B5B14_15; stw 3,-31536(13); 12:; lwz 3,-31536(13); lis 4,-20864; ori 4,4,63784; bl _s801B5B14_16; li 0,1; stw 0,0x134(31); stw 0,0x84(31); 13:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801B5B14_0();
extern "C" void _s801B5B14_1();
extern "C" void _s801B5B14_2();
extern "C" void _s801B5B14_3();
extern "C" void _s801B5B14_4();
extern "C" void _s801B5B14_5();
extern "C" void _s801B5B14_6();
extern "C" void _s801B5B14_7();
extern "C" void _s801B5B14_8();
extern "C" void _s801B5B14_9();
extern "C" void _s801B5B14_10();
extern "C" void _s801B5B14_11();
extern "C" void _s801B5B14_12();
extern "C" void _s801B5B14_13();
extern "C" void _s801B5B14_14();
extern "C" void _s801B5B14_15();
extern "C" void _s801B5B14_16();
extern "C" void f_801B5B14() {}
