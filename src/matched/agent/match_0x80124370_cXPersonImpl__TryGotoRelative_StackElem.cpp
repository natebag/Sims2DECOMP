// 0x80124370 cXPersonImpl::TryGotoRelative(StackElem (808 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); mr 29,3; mr 28,4; mr 30,5; bl _s80124370_0; cmpwi 3,0; bne 0f; li 3,0; li 4,2; b 23f; 0:; lwz 0,0x8(28); cmpwi 0,0; beq 1f; mr 3,29; mr 4,28; li 5,0; bl _s80124370_1; b 23f; 1:; addi 3,1,8; mr 31,3; bl _s80124370_2; addi 3,1,8; li 4,0; li 5,1; bl _s80124370_3; lis 9,-32706; addi 3,1,8; lfs f1,-13044(9); fmr f2,f1; fmr f3,f2; bl _s80124370_4; lwz 9,0x1c(31); lbz 0,0x6(30); rlwinm 9,9,0,18,16; xori 0,0,2; stw 9,0x1c(31); andi. 11,0,2; beq 2f; ori 0,9,16384; stw 0,0x1c(31); 2:; lwz 0,0x1c(31); lbz 9,0x6(30); rlwinm 0,0,0,17,15; stw 0,0x1c(31); andi. 11,9,4; beq 3f; ori 0,0,32768; stw 0,0x1c(31); 3:; lbz 0,0x2(30); mr 4,0; extsb 0,0; cmpwi 0,2; beq 9f; bgt 5f; cmpwi 0,-1; beq 8f; bgt 4f; cmpwi 0,-2; beq 7f; b 14f; 4:; cmpwi 0,0; beq 9f; cmpwi 0,1; beq 10f; b 14f; 5:; cmpwi 0,5; beq 12f; bgt 6f; cmpwi 0,3; beq 11f; cmpwi 0,4; beq 9f; b 14f; 6:; cmpwi 0,6; beq 9f; cmpwi 0,7; beq 13f; b 14f; 7:; mr 3,31; bl _s80124370_5; b 15f; 8:; mr 3,31; li 4,0; bl _s80124370_6; mr 3,31; li 4,2; bl _s80124370_7; mr 3,31; li 4,4; bl _s80124370_8; mr 3,31; li 4,6; bl _s80124370_9; lis 9,-32706; lis 11,-32706; lfs f1,-13044(9); mr 3,31; lfs f2,-13040(11); fmr f3,f1; bl _s80124370_10; b 15f; 9:; extsb 4,4; addi 3,1,8; bl _s80124370_11; b 15f; 10:; mr 3,31; li 4,0; bl _s80124370_12; mr 3,31; li 4,2; bl _s80124370_13; b 15f; 11:; mr 3,31; li 4,2; bl _s80124370_14; mr 3,31; li 4,4; bl _s80124370_15; b 15f; 12:; mr 3,31; li 4,4; bl _s80124370_16; mr 3,31; li 4,6; bl _s80124370_17; b 15f; 13:; mr 3,31; li 4,6; bl _s80124370_18; mr 3,31; li 4,0; bl _s80124370_19; b 15f; 14:; addi 3,1,8; li 4,0; bl _s80124370_20; addi 3,1,8; li 4,2; bl _s80124370_21; addi 3,1,8; li 4,4; bl _s80124370_22; addi 3,1,8; li 4,6; bl _s80124370_23; lis 9,-32706; lis 11,-32706; lfs f1,-13044(9); addi 3,1,8; lfs f2,-13040(11); fmr f3,f1; bl _s80124370_24; 15:; lbz 0,0x3(30); mr 4,0; extsb 0,0; cmpwi 0,-1; beq 18f; bgt 16f; cmpwi 0,-2; beq 17f; b 20f; 16:; cmpwi 0,7; bgt 20f; b 19f; 17:; addi 3,1,8; bl _s80124370_25; b 21f; 18:; addi 3,1,8; bl _s80124370_26; b 21f; 19:; extsb 4,4; addi 3,1,8; bl _s80124370_27; b 21f; 20:; lwz 9,0x0(29); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x508(11); lwz 0,0x50c(11); add 3,10,3; mtspr 8,0; blrl; lis 9,-32698; li 3,0; addi 9,9,18992; li 4,0; b 22f; 21:; mr 3,29; mr 4,28; addi 5,1,8; bl _s80124370_28; lis 9,-32698; addi 9,9,18992; 22:; stw 9,0x8(1); 23:; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s80124370_0();
extern "C" void _s80124370_1();
extern "C" void _s80124370_2();
extern "C" void _s80124370_3();
extern "C" void _s80124370_4();
extern "C" void _s80124370_5();
extern "C" void _s80124370_6();
extern "C" void _s80124370_7();
extern "C" void _s80124370_8();
extern "C" void _s80124370_9();
extern "C" void _s80124370_10();
extern "C" void _s80124370_11();
extern "C" void _s80124370_12();
extern "C" void _s80124370_13();
extern "C" void _s80124370_14();
extern "C" void _s80124370_15();
extern "C" void _s80124370_16();
extern "C" void _s80124370_17();
extern "C" void _s80124370_18();
extern "C" void _s80124370_19();
extern "C" void _s80124370_20();
extern "C" void _s80124370_21();
extern "C" void _s80124370_22();
extern "C" void _s80124370_23();
extern "C" void _s80124370_24();
extern "C" void _s80124370_25();
extern "C" void _s80124370_26();
extern "C" void _s80124370_27();
extern "C" void _s80124370_28();
extern "C" void f_80124370() {}
