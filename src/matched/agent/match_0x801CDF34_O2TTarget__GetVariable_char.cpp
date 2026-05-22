// 0x801CDF34 O2TTarget::GetVariable(char (1160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801CDF34_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801CDF34_1; mr 30,3; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,14240; mr 4,31; bl _s801CDF34_2; cmpwi 3,0; bne 1f; li 0,1; lis 9,-32705; stw 0,0x84(29); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 28f; 1:; lis 3,-32705; mr 4,31; addi 3,3,14808; bl _s801CDF34_3; cmpwi 3,0; bne 2f; lis 9,-32705; lis 4,-32705; lfd f1,0x3ca8(9); b 17f; 2:; lis 3,-32705; mr 4,31; addi 3,3,14688; bl _s801CDF34_4; cmpwi 3,0; bne 3f; lis 9,-32697; lwz 10,0x5f14(9); lis 7,17200; lis 9,-32705; lis 8,-32705; lbz 0,0x29(10); b 10f; 3:; lis 3,-32705; mr 4,31; addi 3,3,14828; bl _s801CDF34_5; cmpwi 3,0; bne 4f; lis 9,-32705; lis 4,-32705; lfd f1,0x3ca8(9); b 17f; 4:; lis 3,-32705; mr 4,31; addi 3,3,14672; bl _s801CDF34_6; cmpwi 3,0; bne 5f; lis 9,-32697; lwz 10,0x5f14(9); lis 7,17200; lis 9,-32705; lis 8,-32705; lbz 0,0x28(10); b 10f; 5:; lis 3,-32705; mr 4,31; addi 3,3,14640; bl _s801CDF34_7; cmpwi 3,0; bne 6f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x18(11); b 22f; 6:; lis 3,-32705; mr 4,31; addi 3,3,14708; bl _s801CDF34_8; cmpwi 3,0; bne 7f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x24(11); b 22f; 7:; lis 3,-32705; mr 4,31; addi 3,3,14252; bl _s801CDF34_9; cmpwi 3,0; bne 8f; lis 9,-32697; lwz 10,0x5f14(9); lis 7,17200; lis 9,-32705; lis 8,-32705; lbz 0,0x1c(10); b 10f; 8:; lis 3,-32705; mr 4,31; addi 3,3,14264; bl _s801CDF34_10; cmpwi 3,0; bne 9f; lis 9,-32705; lis 4,-32705; lfd f1,0x3ca8(9); b 17f; 9:; lis 3,-32705; mr 4,31; addi 3,3,14280; bl _s801CDF34_11; cmpwi 3,0; bne 11f; lis 9,-32697; lwz 10,0x5f14(9); lis 7,17200; lis 9,-32705; lis 8,-32705; lbz 0,0x1d(10); 10:; lis 4,-32705; lfd f13,0x3cb0(9); addi 4,4,-2240; extsb 0,0; lfs f12,0x3cb8(8); xoris 0,0,32768; mr 3,30; stw 0,0x14(1); stw 7,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f0,f12; fmr f1,f0; creqv 6,6,6; bl _s801CDF34_12; b 28f; 11:; lis 3,-32705; mr 4,31; addi 3,3,14296; bl _s801CDF34_13; cmpwi 3,0; bne 12f; lis 9,-32705; lis 4,-32705; lfd f1,0x3ca8(9); b 17f; 12:; lis 3,-32705; mr 4,31; addi 3,3,14312; bl _s801CDF34_14; cmpwi 3,0; bne 13f; lis 11,-32697; mr 3,29; lwz 9,0x5f14(11); lbz 4,0x1f(9); extsb 4,4; bl _s801CDF34_15; b 14f; 13:; lis 3,-32705; mr 4,31; addi 3,3,14328; bl _s801CDF34_16; cmpwi 3,0; beq 16f; lis 3,-32705; mr 4,31; addi 3,3,14348; bl _s801CDF34_17; cmpwi 3,0; bne 15f; lis 11,-32697; mr 3,29; lwz 9,0x5f14(11); lbz 4,0x20(9); extsb 4,4; bl _s801CDF34_18; 14:; lis 4,-32705; mr 3,30; addi 4,4,-2240; creqv 6,6,6; bl _s801CDF34_19; b 28f; 15:; lis 3,-32705; mr 4,31; addi 3,3,14364; bl _s801CDF34_20; cmpwi 3,0; bne 18f; 16:; lis 9,-32705; lis 4,-32705; lfd f1,0x3cc0(9); 17:; addi 4,4,-2240; mr 3,30; creqv 6,6,6; bl _s801CDF34_21; b 28f; 18:; lis 3,-32705; mr 4,31; addi 3,3,14660; bl _s801CDF34_22; cmpwi 3,0; bne 19f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x4(11); b 22f; 19:; lis 3,-32705; mr 4,31; addi 3,3,14400; bl _s801CDF34_23; cmpwi 3,0; bne 20f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x18(11); b 22f; 20:; lwz 3,-29748(13); mr 4,31; bl _s801CDF34_24; cmpwi 3,0; bne 21f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x24(11); b 22f; 21:; lis 3,-32705; mr 4,31; addi 3,3,14384; bl _s801CDF34_25; cmpwi 3,0; bne 24f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x0(11); 22:; cmpwi 0,0; beq 23f; li 5,1; 23:; lis 4,-32705; mr 3,30; addi 4,4,-8800; crxor 6,6,6; bl _s801CDF34_26; b 28f; 24:; lis 3,-32705; mr 4,31; addi 3,3,14420; bl _s801CDF34_27; cmpwi 3,0; bne 28f; lwz 0,0x90(29); cmpwi 0,0; bne 25f; lwz 0,0x248(29); cmpwi 0,0; beq 26f; 25:; lis 9,-32705; lhz 0,-5284(9); b 27f; 26:; lis 9,-32705; lhz 0,-5288(9); 27:; sth 0,0x0(30); 28:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801CDF34_0();
extern "C" void _s801CDF34_1();
extern "C" void _s801CDF34_2();
extern "C" void _s801CDF34_3();
extern "C" void _s801CDF34_4();
extern "C" void _s801CDF34_5();
extern "C" void _s801CDF34_6();
extern "C" void _s801CDF34_7();
extern "C" void _s801CDF34_8();
extern "C" void _s801CDF34_9();
extern "C" void _s801CDF34_10();
extern "C" void _s801CDF34_11();
extern "C" void _s801CDF34_12();
extern "C" void _s801CDF34_13();
extern "C" void _s801CDF34_14();
extern "C" void _s801CDF34_15();
extern "C" void _s801CDF34_16();
extern "C" void _s801CDF34_17();
extern "C" void _s801CDF34_18();
extern "C" void _s801CDF34_19();
extern "C" void _s801CDF34_20();
extern "C" void _s801CDF34_21();
extern "C" void _s801CDF34_22();
extern "C" void _s801CDF34_23();
extern "C" void _s801CDF34_24();
extern "C" void _s801CDF34_25();
extern "C" void _s801CDF34_26();
extern "C" void _s801CDF34_27();
extern "C" void f_801CDF34() {}
