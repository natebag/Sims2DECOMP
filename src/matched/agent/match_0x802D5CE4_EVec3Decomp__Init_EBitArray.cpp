// 0x802D5CE4 EVec3Decomp::Init(EBitArray (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 26,0x8(1); stw 0,0x2c(1); mr 31,3; mr 0,4; li 9,0; mr 30,5; stb 9,0x21(31); mr 3,0; mr 4,30; stw 0,0x0(31); li 5,20; addi 30,30,20; bl _s802D5CE4_0; stw 3,0x18(31); mr 4,30; lwz 3,0x0(31); li 5,5; addi 30,30,5; bl _s802D5CE4_1; stb 3,0x1e(31); mr 4,30; lwz 3,0x0(31); li 5,5; addi 30,30,5; bl _s802D5CE4_2; extsb 4,3; stb 3,0x20(31); cmpwi 4,0; beq 0f; lwz 3,0x0(31); bl _s802D5CE4_3; stfs f1,0x24(31); b 1f; 0:; lis 9,-32702; lfs f0,-6792(9); stfs f0,0x24(31); 1:; lwz 3,0x0(31); mr 4,30; li 5,5; bl _s802D5CE4_4; extsb 0,3; stb 3,0x1f(31); cmpwi 0,0; bne 2f; li 0,32; stb 0,0x1f(31); 2:; lbz 4,0x1f(31); addi 30,30,5; lwz 3,0x0(31); addi 26,31,92; extsb 4,4; addi 27,31,104; bl _s802D5CE4_5; li 29,0; fmr f31,f1; li 28,3; 3:; lwz 3,0x0(31); mr 4,30; addi 30,30,32; bl _s802D5CE4_6; fmuls f1,f31,f1; mr 4,30; stfsx f1,29,26; addi 30,30,32; lwz 3,0x0(31); bl _s802D5CE4_7; stfsx f1,29,27; addic. 28,28,-1; addi 29,29,4; bne 3b; lbz 10,0x1f(31); li 29,0; lbz 0,0x1e(31); extsb 10,10; lbz 11,0x20(31); rlwinm 9,10,1,0,30; extsb 0,0; add 9,9,10; extsb 11,11; add 0,0,11; lwz 10,0x18(31); add 0,0,9; stw 30,0x4(31); sth 0,0x1c(31); cmpw 29,10; stw 28,0x14(31); bge 5f; 4:; lha 4,0x1c(31); lwz 0,0x4(31); mullw 4,29,4; lbz 5,0x1e(31); lwz 3,0x0(31); addi 29,29,1; extsb 5,5; add 4,0,4; bl _s802D5CE4_8; lwz 0,0x14(31); addi 3,3,1; lwz 9,0x18(31); add 0,0,3; stw 0,0x14(31); cmpw 29,9; blt 4b; 5:; mr 3,31; bl _s802D5CE4_9; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x8(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s802D5CE4_0();
extern "C" void _s802D5CE4_1();
extern "C" void _s802D5CE4_2();
extern "C" void _s802D5CE4_3();
extern "C" void _s802D5CE4_4();
extern "C" void _s802D5CE4_5();
extern "C" void _s802D5CE4_6();
extern "C" void _s802D5CE4_7();
extern "C" void _s802D5CE4_8();
extern "C" void _s802D5CE4_9();
extern "C" void f_802D5CE4() {}
