// 0x801FBF1C OPTTarget::GetVariable(char (912 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,3; mr 31,4; li 3,128; bl _s801FBF1C_0; mr 30,3; li 0,0; lis 3,-32704; stb 0,0x0(30); addi 3,3,-20856; mr 4,31; bl _s801FBF1C_1; cmpwi 3,0; bne 0f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 20f; 0:; lis 3,-32704; mr 4,31; addi 3,3,-21224; bl _s801FBF1C_2; cmpwi 3,0; bne 1f; lis 9,-32697; lwz 10,0x5f14(9); lis 7,17200; lis 9,-32704; lis 8,-32704; lbz 0,0x1c(10); b 4f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-21212; bl _s801FBF1C_3; cmpwi 3,0; bne 2f; lis 9,-32704; lis 4,-32704; lfd f1,-20808(9); b 11f; 2:; lis 3,-32704; mr 4,31; addi 3,3,-21196; bl _s801FBF1C_4; cmpwi 3,0; bne 3f; lis 9,-32697; lwz 10,0x5f14(9); lis 7,17200; lis 9,-32704; lis 8,-32704; lbz 0,0x1d(10); b 4f; 3:; lis 3,-32704; mr 4,31; addi 3,3,-20844; bl _s801FBF1C_5; cmpwi 3,0; bne 5f; lis 9,-32697; lwz 10,0x5f14(9); lis 7,17200; lis 9,-32704; lis 8,-32704; lbz 0,0x1e(10); 4:; lis 4,-32704; lfd f13,-20824(9); addi 4,4,-30816; extsb 0,0; lfs f12,-20816(8); xoris 0,0,32768; mr 3,30; stw 0,0x14(1); stw 7,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f0,f12; fmr f1,f0; creqv 6,6,6; bl _s801FBF1C_6; b 20f; 5:; lis 3,-32704; mr 4,31; addi 3,3,-21180; bl _s801FBF1C_7; cmpwi 3,0; bne 6f; lis 9,-32704; lis 4,-32704; lfd f1,-20808(9); b 11f; 6:; lis 3,-32704; mr 4,31; addi 3,3,-21164; bl _s801FBF1C_8; cmpwi 3,0; bne 7f; lis 11,-32697; mr 3,29; lwz 9,0x5f14(11); lbz 4,0x1f(9); extsb 4,4; bl _s801FBF1C_9; b 8f; 7:; lis 3,-32704; mr 4,31; addi 3,3,-21148; bl _s801FBF1C_10; cmpwi 3,0; beq 10f; lis 3,-32704; mr 4,31; addi 3,3,-21128; bl _s801FBF1C_11; cmpwi 3,0; bne 9f; lis 11,-32697; mr 3,29; lwz 9,0x5f14(11); lbz 4,0x20(9); extsb 4,4; bl _s801FBF1C_12; 8:; lis 4,-32704; mr 3,30; addi 4,4,-30816; creqv 6,6,6; bl _s801FBF1C_13; b 20f; 9:; lis 3,-32704; mr 4,31; addi 3,3,-21112; bl _s801FBF1C_14; cmpwi 3,0; bne 12f; 10:; lis 9,-32704; lis 4,-32704; lfd f1,-20800(9); 11:; addi 4,4,-30816; mr 3,30; creqv 6,6,6; bl _s801FBF1C_15; b 20f; 12:; lis 3,-32704; mr 4,31; addi 3,3,-21092; bl _s801FBF1C_16; cmpwi 3,0; bne 13f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x4(11); b 16f; 13:; lis 3,-32704; mr 4,31; addi 3,3,-21080; bl _s801FBF1C_17; cmpwi 3,0; bne 14f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x0(11); b 16f; 14:; lis 3,-32704; mr 4,31; addi 3,3,-21064; bl _s801FBF1C_18; cmpwi 3,0; bne 15f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x14(11); b 16f; 15:; lis 3,-32704; mr 4,31; addi 3,3,-21048; bl _s801FBF1C_19; cmpwi 3,0; bne 18f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x18(11); 16:; cmpwi 0,0; beq 17f; li 5,1; 17:; lis 4,-32704; mr 3,30; addi 4,4,-30836; crxor 6,6,6; bl _s801FBF1C_20; b 20f; 18:; lis 3,-32704; mr 4,31; addi 3,3,-21028; bl _s801FBF1C_21; cmpwi 3,0; bne 20f; lis 9,-32697; li 5,0; lwz 11,0x5f14(9); lwz 0,0x10(11); cmpwi 0,0; beq 19f; li 5,1; 19:; lis 4,-32704; mr 3,30; addi 4,4,-30836; crxor 6,6,6; bl _s801FBF1C_22; 20:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801FBF1C_0();
extern "C" void _s801FBF1C_1();
extern "C" void _s801FBF1C_2();
extern "C" void _s801FBF1C_3();
extern "C" void _s801FBF1C_4();
extern "C" void _s801FBF1C_5();
extern "C" void _s801FBF1C_6();
extern "C" void _s801FBF1C_7();
extern "C" void _s801FBF1C_8();
extern "C" void _s801FBF1C_9();
extern "C" void _s801FBF1C_10();
extern "C" void _s801FBF1C_11();
extern "C" void _s801FBF1C_12();
extern "C" void _s801FBF1C_13();
extern "C" void _s801FBF1C_14();
extern "C" void _s801FBF1C_15();
extern "C" void _s801FBF1C_16();
extern "C" void _s801FBF1C_17();
extern "C" void _s801FBF1C_18();
extern "C" void _s801FBF1C_19();
extern "C" void _s801FBF1C_20();
extern "C" void _s801FBF1C_21();
extern "C" void _s801FBF1C_22();
extern "C" void f_801FBF1C() {}
