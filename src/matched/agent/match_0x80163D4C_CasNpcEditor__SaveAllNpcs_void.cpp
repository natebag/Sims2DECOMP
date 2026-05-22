// 0x80163D4C CasNpcEditor::SaveAllNpcs(void) (1304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-744(1); mfspr 0,8; mfcr 12; stmw 14,0x2a0(1); stw 0,0x2ec(1); stw 12,0x29c(1); lwz 11,-32056(13); mr 31,3; lis 4,21875; addi 30,1,8; lwz 9,0xc(11); ori 4,4,25970; li 29,1; lwz 0,0x7c(9); lha 3,0x78(9); mtspr 8,0; add 3,11,3; blrl; stw 3,0x290(1); mr 3,30; lwz 9,0x0(31); lwz 17,0x14(9); bl _s80163D4C_0; li 10,0; addi 9,1,12; stb 10,0xc(1); li 0,0; stb 10,0x1(9); li 8,2; li 7,32; li 11,8; stb 11,0x13(9); li 10,0; stb 8,0x2(9); addi 3,1,40; sth 0,0x10(9); stb 7,0x12(9); sth 0,0x4(9); sth 0,0x6(9); stb 0,0x8(9); sth 0,0xa(9); sth 0,0xc(9); sth 0,0xe(9); stw 10,0x1c(30); stw 10,0x18(30); bl _s80163D4C_1; cmpwi 17,0; bne 0f; lwz 4,0x28(1); addi 3,1,40; bl _s80163D4C_2; lwz 4,0x8(1); addi 3,1,8; bl _s80163D4C_3; li 3,0; b 11f; 0:; lwz 0,0x290(1); li 30,1; cmpw 30,0; bgt 10f; 1:; addi 3,1,52; li 23,0; bl _s80163D4C_4; addi 14,30,1; addi 3,1,344; bl _s80163D4C_5; mr 3,31; mr 4,30; addi 5,1,48; bl _s80163D4C_6; cmpwi 3,0; beq 9f; stw 30,0x10(31); addi 3,1,56; addi 4,31,24; li 5,32; bl _s80163D4C_7; cmpwi 4,29,0; addi 4,31,56; li 5,32; addi 3,1,120; addi 27,31,24; bl _s80163D4C_8; addi 26,31,56; lis 9,-32698; lwz 30,0x0(31); addi 9,9,24616; lwz 0,0x30(1); stw 9,0x164(1); addi 3,1,360; stw 0,0xc(31); lis 24,-32698; bl _s80163D4C_9; lis 21,-32706; addi 9,1,52; stw 23,0x160(1); addi 28,1,352; addi 11,1,360; mr 22,9; li 10,288; addi 25,1,344; addi 29,1,40; lis 20,-32706; lis 19,-32706; addi 18,1,368; addi 16,1,364; 2:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 2b; lwz 0,0x0(9); mr 3,30; mr 4,28; li 15,0; stw 0,0x0(11); bl _s80163D4C_10; addi 0,24,24616; mr 3,28; stw 0,0x164(1); li 4,2; bl _s80163D4C_11; beq cr4,3f; mr 3,31; mr 4,22; bl _s80163D4C_12; cmpwi 3,0; beq 3f; li 15,1; 3:; lwz 5,0xc(31); mr 7,26; addi 4,21,-2280; mr 3,25; mr 6,27; crxor 6,6,6; bl _s80163D4C_13; lwz 5,0x5c(31); addi 4,20,-2260; lwz 6,0x158(1); mr 3,29; crxor 6,6,6; bl _s80163D4C_14; mr 3,29; bl _s80163D4C_15; lwz 3,0x28(1); addi 4,19,-2248; bl _s80163D4C_16; mr. 30,3; beq 4f; mr 4,30; mr 3,22; addi 5,17,8; bl _s80163D4C_17; lis 4,-32706; lwz 5,0x30(1); addi 4,4,-2244; mr 3,30; crxor 6,6,6; bl _s80163D4C_18; mr 3,30; bl _s80163D4C_19; 4:; li 0,0; addi 3,1,360; stw 0,0x160(1); stw 0,0x4(28); bl _s80163D4C_20; addi 3,1,364; bl _s80163D4C_21; addi 3,1,368; bl _s80163D4C_22; mr 3,17; li 4,64; li 5,64; li 6,32; li 7,0; li 8,0; bl _s80163D4C_23; mr. 30,3; beq 7f; li 0,64; lis 4,-32706; stw 0,0x164(1); addi 3,1,360; stw 0,0x160(1); addi 4,4,-2228; bl _s80163D4C_24; li 24,0; lis 4,-32706; mr 3,18; addi 4,4,-2216; bl _s80163D4C_25; lis 4,-32706; mr 5,27; addi 4,4,-2208; mr 6,26; mr 3,25; crxor 6,6,6; bl _s80163D4C_26; mr 3,25; bl _s80163D4C_27; lwz 6,0x158(1); lis 9,-32706; lwz 5,0x60(31); addi 4,9,-2188; mr 3,29; crxor 6,6,6; bl _s80163D4C_28; mr 3,29; bl _s80163D4C_29; lwz 4,0x28(1); li 7,1; mr 8,28; addi 3,1,8; mr 5,30; li 6,1; bl _s80163D4C_30; li 0,32; mr 23,3; lis 4,-32706; stw 0,0x164(1); stw 0,0x160(1); mr 5,27; addi 4,4,-2180; mr 6,26; mr 3,25; crxor 6,6,6; bl _s80163D4C_31; mr 3,25; bl _s80163D4C_32; lis 9,-32706; lwz 5,0x60(31); lwz 6,0x158(1); mr 3,29; addi 4,9,-2188; crxor 6,6,6; bl _s80163D4C_33; mr 3,29; bl _s80163D4C_34; cmpwi 23,0; beq 5f; lwz 4,0x28(1); mr 8,28; addi 3,1,8; mr 5,30; li 6,1; li 7,1; bl _s80163D4C_35; cmpwi 3,0; beq 5f; li 24,1; 5:; mr 23,24; cmpwi 30,0; beq 7f; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 6f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 6:; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; 7:; cmpwi 15,0; li 0,0; beq 8f; cmpwi 23,0; beq 8f; li 0,1; 8:; lwz 4,0x170(1); mr 3,18; mr 29,0; bl _s80163D4C_36; lwz 4,0x16c(1); mr 3,16; bl _s80163D4C_37; lwz 4,0x168(1); addi 3,1,360; bl _s80163D4C_38; 9:; lwz 4,0x158(1); addi 3,1,344; extsh 30,14; bl _s80163D4C_39; lwz 0,0x290(1); cmpw 30,0; ble 1b; 10:; lwz 4,0x28(1); addi 3,1,40; bl _s80163D4C_40; lwz 4,0x8(1); addi 3,1,8; bl _s80163D4C_41; li 3,1; 11:; lwz 0,0x2ec(1); lwz 12,0x29c(1); mtspr 8,0; lmw 14,0x2a0(1); mtcrf 8,12; addi 1,1,744"
extern "C" void _s80163D4C_0();
extern "C" void _s80163D4C_1();
extern "C" void _s80163D4C_2();
extern "C" void _s80163D4C_3();
extern "C" void _s80163D4C_4();
extern "C" void _s80163D4C_5();
extern "C" void _s80163D4C_6();
extern "C" void _s80163D4C_7();
extern "C" void _s80163D4C_8();
extern "C" void _s80163D4C_9();
extern "C" void _s80163D4C_10();
extern "C" void _s80163D4C_11();
extern "C" void _s80163D4C_12();
extern "C" void _s80163D4C_13();
extern "C" void _s80163D4C_14();
extern "C" void _s80163D4C_15();
extern "C" void _s80163D4C_16();
extern "C" void _s80163D4C_17();
extern "C" void _s80163D4C_18();
extern "C" void _s80163D4C_19();
extern "C" void _s80163D4C_20();
extern "C" void _s80163D4C_21();
extern "C" void _s80163D4C_22();
extern "C" void _s80163D4C_23();
extern "C" void _s80163D4C_24();
extern "C" void _s80163D4C_25();
extern "C" void _s80163D4C_26();
extern "C" void _s80163D4C_27();
extern "C" void _s80163D4C_28();
extern "C" void _s80163D4C_29();
extern "C" void _s80163D4C_30();
extern "C" void _s80163D4C_31();
extern "C" void _s80163D4C_32();
extern "C" void _s80163D4C_33();
extern "C" void _s80163D4C_34();
extern "C" void _s80163D4C_35();
extern "C" void _s80163D4C_36();
extern "C" void _s80163D4C_37();
extern "C" void _s80163D4C_38();
extern "C" void _s80163D4C_39();
extern "C" void _s80163D4C_40();
extern "C" void _s80163D4C_41();
extern "C" void f_80163D4C() {}
