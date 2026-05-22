// 0x8016977C CasSimDescriptionS2C::VerifyBodyPartWithOneOption(CasSimPartsS2C (640 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 22,0x58(1); stw 0,0x84(1); mr 25,6; lbz 0,0x8b(1); lbz 11,0x0(25); mr 28,3; extsb 23,0; mr 29,4; extsb 30,11; mr 31,5; mr 27,7; mr 26,8; mr 22,9; mr 24,10; cmpwi 30,0; blt 0f; mr 3,29; mr 4,31; bl _s8016977C_0; cmplw 30,3; blt 1f; 0:; mr 4,31; mr 3,29; bl _s8016977C_1; lbz 7,0x0(25); mr 6,3; lis 5,-32706; li 4,64; addi 5,5,1136; extsb 7,7; addi 3,1,8; crxor 6,6,6; bl _s8016977C_2; b 9f; 1:; lbz 0,0x0(26); extsb 30,0; cmpwi 30,0; blt 2f; mr 3,29; mr 4,31; bl _s8016977C_3; cmplw 30,3; blt 3f; 2:; mr 4,31; mr 3,29; bl _s8016977C_4; lbz 7,0x0(26); mr 6,3; lis 5,-32706; li 4,64; addi 5,5,1264; extsb 7,7; addi 3,1,8; crxor 6,6,6; bl _s8016977C_5; mr 3,28; addi 4,1,8; bl _s8016977C_6; stb 23,0x0(26); 3:; addi 30,1,72; mr 5,31; mr 3,30; mr 4,28; bl _s8016977C_7; mr 4,31; mr 3,28; bl _s8016977C_8; mr 5,3; mr 6,30; mr 3,29; mr 4,31; bl _s8016977C_9; cmpwi 3,0; beq 7f; lbz 5,0x0(25); mr 3,29; mr 4,31; extsb 5,5; bl _s8016977C_10; mr. 3,3; bne 4f; mr 4,31; mr 3,29; bl _s8016977C_11; mr 6,3; lis 5,-32706; addi 5,5,1172; li 4,64; addi 3,1,8; crxor 6,6,6; bl _s8016977C_12; mr 3,28; addi 4,1,8; bl _s8016977C_13; stb 22,0x0(25); stb 24,0x0(27); stb 23,0x0(26); b 6f; 4:; lbz 0,0x0(27); extsb 0,0; cmpwi 0,0; blt 5f; cmpw 0,3; blt 6f; 5:; mr 4,31; mr 3,29; bl _s8016977C_14; lbz 7,0x0(27); mr 6,3; lis 5,-32706; li 4,64; addi 5,5,1200; extsb 7,7; addi 3,1,8; crxor 6,6,6; bl _s8016977C_15; mr 3,28; addi 4,1,8; bl _s8016977C_16; stb 24,0x0(27); 6:; mr 3,29; mr 4,31; mr 5,28; li 6,0; bl _s8016977C_17; cmpwi 3,0; bne 10f; mr 4,31; mr 3,29; bl _s8016977C_18; mr 6,3; lis 5,-32706; addi 5,5,1224; b 8f; 7:; lwz 0,0x8c(1); cmpwi 0,0; bne 10f; mr 4,31; mr 3,29; bl _s8016977C_19; mr 6,3; lis 5,-32706; addi 5,5,1244; 8:; li 4,64; addi 3,1,8; crxor 6,6,6; bl _s8016977C_20; 9:; mr 3,28; addi 4,1,8; bl _s8016977C_21; stb 22,0x0(25); stb 24,0x0(27); stb 23,0x0(26); 10:; lwz 0,0x84(1); mtspr 8,0; lmw 22,0x58(1); addi 1,1,128"
extern "C" void _s8016977C_0();
extern "C" void _s8016977C_1();
extern "C" void _s8016977C_2();
extern "C" void _s8016977C_3();
extern "C" void _s8016977C_4();
extern "C" void _s8016977C_5();
extern "C" void _s8016977C_6();
extern "C" void _s8016977C_7();
extern "C" void _s8016977C_8();
extern "C" void _s8016977C_9();
extern "C" void _s8016977C_10();
extern "C" void _s8016977C_11();
extern "C" void _s8016977C_12();
extern "C" void _s8016977C_13();
extern "C" void _s8016977C_14();
extern "C" void _s8016977C_15();
extern "C" void _s8016977C_16();
extern "C" void _s8016977C_17();
extern "C" void _s8016977C_18();
extern "C" void _s8016977C_19();
extern "C" void _s8016977C_20();
extern "C" void _s8016977C_21();
extern "C" void f_8016977C() {}
