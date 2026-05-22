// 0x803622E8 ScalarDecomp::Init(EBitArray (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 31,3; mr 0,4; li 9,0; mr 30,5; stb 9,0x21(31); mr 3,0; mr 4,30; stw 0,0x0(31); li 5,20; addi 30,30,20; bl _s803622E8_0; stw 3,0x18(31); mr 4,30; lwz 3,0x0(31); li 5,5; addi 30,30,5; bl _s803622E8_1; stb 3,0x1e(31); mr 4,30; lwz 3,0x0(31); li 5,5; addi 30,30,5; bl _s803622E8_2; extsb 4,3; stb 3,0x20(31); cmpwi 4,0; beq 0f; lwz 3,0x0(31); bl _s803622E8_3; stfs f1,0x24(31); b 1f; 0:; lis 9,-32702; lfs f0,0x2ed0(9); stfs f0,0x24(31); 1:; lwz 3,0x0(31); mr 4,30; li 5,5; addi 30,30,5; bl _s803622E8_4; extsb 0,3; stb 3,0x1f(31); cmpwi 0,0; bne 2f; li 0,32; stb 0,0x1f(31); 2:; lbz 4,0x1f(31); li 29,0; lwz 3,0x0(31); extsb 4,4; bl _s803622E8_5; lwz 3,0x0(31); mr 4,30; fmr f31,f1; addi 30,30,32; bl _s803622E8_6; fmuls f31,f31,f1; lwz 3,0x0(31); mr 4,30; stfs f31,0x3c(31); bl _s803622E8_7; addi 30,30,32; lbz 9,0x1e(31); li 8,0; lbz 0,0x20(31); lbz 11,0x1f(31); extsb 9,9; extsb 0,0; lwz 10,0x18(31); add 9,9,0; extsb 11,11; add 11,11,9; stfs f1,0x40(31); stw 30,0x4(31); cmpw 29,10; sth 11,0x1c(31); stw 8,0x14(31); bge 4f; 3:; lha 4,0x1c(31); lwz 0,0x4(31); mullw 4,29,4; lbz 5,0x1e(31); lwz 3,0x0(31); addi 29,29,1; extsb 5,5; add 4,0,4; bl _s803622E8_8; lwz 0,0x14(31); addi 3,3,1; lwz 9,0x18(31); add 0,0,3; stw 0,0x14(31); cmpw 29,9; blt 3b; 4:; mr 3,31; bl _s803622E8_9; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s803622E8_0();
extern "C" void _s803622E8_1();
extern "C" void _s803622E8_2();
extern "C" void _s803622E8_3();
extern "C" void _s803622E8_4();
extern "C" void _s803622E8_5();
extern "C" void _s803622E8_6();
extern "C" void _s803622E8_7();
extern "C" void _s803622E8_8();
extern "C" void _s803622E8_9();
extern "C" void f_803622E8() {}
