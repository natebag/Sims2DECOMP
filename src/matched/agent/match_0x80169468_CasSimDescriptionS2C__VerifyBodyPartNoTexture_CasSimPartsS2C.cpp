// 0x80169468 CasSimDescriptionS2C::VerifyBodyPartNoTexture(CasSimPartsS2C (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 25,0x5c(1); stw 0,0x7c(1); mr 26,6; mr 27,3; lbz 0,0x0(26); mr 29,4; mr 31,5; mr 25,7; extsb 30,0; mr 28,8; cmpwi 30,0; blt 0f; mr 3,29; mr 4,31; bl _s80169468_0; cmplw 30,3; blt 1f; 0:; mr 4,31; mr 3,29; bl _s80169468_1; lbz 7,0x0(26); mr 6,3; lis 5,-32706; li 4,64; extsb 7,7; addi 5,5,1136; addi 3,1,8; crxor 6,6,6; bl _s80169468_2; b 2f; 1:; cmpwi 28,0; bne 3f; addi 30,1,72; mr 5,31; mr 3,30; mr 4,27; bl _s80169468_3; mr 4,31; mr 3,27; bl _s80169468_4; mr 5,3; mr 6,30; mr 3,29; mr 4,31; bl _s80169468_5; cmpwi 3,0; bne 3f; mr 4,31; mr 3,29; bl _s80169468_6; mr 6,3; lis 5,-32706; addi 5,5,1152; li 4,64; addi 3,1,8; crxor 6,6,6; bl _s80169468_7; 2:; mr 3,27; addi 4,1,8; bl _s80169468_8; stb 25,0x0(26); 3:; lwz 0,0x7c(1); mtspr 8,0; lmw 25,0x5c(1); addi 1,1,120"
extern "C" void _s80169468_0();
extern "C" void _s80169468_1();
extern "C" void _s80169468_2();
extern "C" void _s80169468_3();
extern "C" void _s80169468_4();
extern "C" void _s80169468_5();
extern "C" void _s80169468_6();
extern "C" void _s80169468_7();
extern "C" void _s80169468_8();
extern "C" void f_80169468() {}
