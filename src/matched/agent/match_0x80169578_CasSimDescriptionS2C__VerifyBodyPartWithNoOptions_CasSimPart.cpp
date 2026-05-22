// 0x80169578 CasSimDescriptionS2C::VerifyBodyPartWithNoOptions(CasSimPartsS2C (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 23,0x5c(1); stw 0,0x84(1); mr 26,6; mr 28,3; lbz 0,0x0(26); mr 29,4; mr 31,5; mr 27,7; extsb 30,0; mr 24,8; mr 25,9; mr 23,10; cmpwi 30,0; blt 0f; mr 3,29; mr 4,31; bl _s80169578_0; cmplw 30,3; blt 1f; 0:; mr 4,31; mr 3,29; bl _s80169578_1; lbz 7,0x0(26); mr 6,3; lis 5,-32706; li 4,64; addi 5,5,1136; extsb 7,7; addi 3,1,8; crxor 6,6,6; bl _s80169578_2; b 8f; 1:; addi 30,1,72; mr 5,31; mr 3,30; mr 4,28; bl _s80169578_3; mr 4,31; mr 3,28; bl _s80169578_4; mr 5,3; mr 6,30; mr 3,29; mr 4,31; bl _s80169578_5; cmpwi 3,0; beq 6f; lbz 5,0x0(26); mr 3,29; mr 4,31; extsb 5,5; bl _s80169578_6; mr. 3,3; bne 2f; mr 4,31; mr 3,29; bl _s80169578_7; mr 6,3; lis 5,-32706; addi 5,5,1172; li 4,64; addi 3,1,8; crxor 6,6,6; bl _s80169578_8; mr 3,28; addi 4,1,8; bl _s80169578_9; stb 24,0x0(26); b 4f; 2:; lbz 0,0x0(27); extsb 0,0; cmpwi 0,0; blt 3f; cmpw 0,3; blt 5f; 3:; mr 4,31; mr 3,29; bl _s80169578_10; lbz 7,0x0(27); mr 6,3; lis 5,-32706; li 4,64; addi 5,5,1200; extsb 7,7; addi 3,1,8; crxor 6,6,6; bl _s80169578_11; mr 3,28; addi 4,1,8; bl _s80169578_12; 4:; stb 25,0x0(27); 5:; mr 3,29; mr 4,31; mr 5,28; li 6,0; bl _s80169578_13; cmpwi 3,0; bne 9f; mr 4,31; mr 3,29; bl _s80169578_14; mr 6,3; lis 5,-32706; addi 5,5,1224; b 7f; 6:; cmpwi 23,0; bne 9f; mr 4,31; mr 3,29; bl _s80169578_15; mr 6,3; lis 5,-32706; addi 5,5,1244; 7:; li 4,64; addi 3,1,8; crxor 6,6,6; bl _s80169578_16; 8:; mr 3,28; addi 4,1,8; bl _s80169578_17; stb 24,0x0(26); stb 25,0x0(27); 9:; lwz 0,0x84(1); mtspr 8,0; lmw 23,0x5c(1); addi 1,1,128"
extern "C" void _s80169578_0();
extern "C" void _s80169578_1();
extern "C" void _s80169578_2();
extern "C" void _s80169578_3();
extern "C" void _s80169578_4();
extern "C" void _s80169578_5();
extern "C" void _s80169578_6();
extern "C" void _s80169578_7();
extern "C" void _s80169578_8();
extern "C" void _s80169578_9();
extern "C" void _s80169578_10();
extern "C" void _s80169578_11();
extern "C" void _s80169578_12();
extern "C" void _s80169578_13();
extern "C" void _s80169578_14();
extern "C" void _s80169578_15();
extern "C" void _s80169578_16();
extern "C" void _s80169578_17();
extern "C" void f_80169578() {}
