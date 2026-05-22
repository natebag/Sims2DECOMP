// 0x800AD950 cBoxX::Update(unsigned (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f30,0x50(1); stfd f31,0x58(1); stmw 27,0x3c(1); stw 0,0x64(1); lwz 0,-32088(13); mr 27,3; cmpwi 0,0; beq 7f; lwz 11,0x10(27); lwz 0,0x0(11); cmpwi 0,0; beq 0f; lwz 9,0x4(11); addi 9,9,1; stw 9,0x4(11); 0:; lwz 3,-24136(13); bl _s800AD950_0; lwz 3,-21492(13); bl _s800AD950_1; cmpwi 3,1; beq 1f; lwz 3,-21492(13); bl _s800AD950_2; cmpwi 3,4; bne 6f; 1:; lwz 0,0x64(27); cmpwi 0,0; beq 6f; lis 9,-32697; addi 9,9,23428; lwz 11,0xc4(9); cmpwi 11,0; beq 6f; lwz 0,0x2c(11); cmpwi 0,0; bne 6f; lwz 0,0xec(9); li 29,0; li 11,1; cmpwi 0,0; beq 2f; li 11,2; 2:; cmpw 29,11; bge 5f; addi 28,9,244; mr 30,11; addi 31,1,24; 3:; lwz 3,0xc(28); cmpwi 3,0; beq 4f; addi 4,1,8; mr 5,31; bl _s800AD950_3; lwz 3,0x64(27); mr 4,29; addi 5,1,8; mr 6,31; bl _s800AD950_4; addi 29,29,1; 4:; addi 28,28,16; addic. 30,30,-1; bne 3b; 5:; lwz 3,0x64(27); mr 4,29; lis 30,17200; bl _s800AD950_5; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-21496(13); xoris 3,3,32768; lis 8,-32706; lwz 11,0x0(10); li 4,5; stw 3,0x34(1); lwz 0,0x34(11); stw 30,0x30(1); lha 3,0x30(11); mtspr 8,0; lfd f31,0x30(1); lfd f30,-27040(8); add 3,10,3; fsub f31,f31,f30; frsp f31,f31; blrl; xoris 3,3,32768; stw 3,0x34(1); lis 9,-32706; lfs f0,-27032(9); stw 30,0x30(1); lwz 3,0x64(27); lfd f1,0x30(1); fsub f1,f1,f30; frsp f1,f1; fmadds f1,f1,f0,f31; bl _s800AD950_6; lwz 3,0x64(27); bl _s800AD950_7; 6:; mr 3,27; bl _s800AD950_8; 7:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x3c(1); lfd f30,0x50(1); lfd f31,0x58(1); addi 1,1,96"
extern "C" void _s800AD950_0();
extern "C" void _s800AD950_1();
extern "C" void _s800AD950_2();
extern "C" void _s800AD950_3();
extern "C" void _s800AD950_4();
extern "C" void _s800AD950_5();
extern "C" void _s800AD950_6();
extern "C" void _s800AD950_7();
extern "C" void _s800AD950_8();
extern "C" void f_800AD950() {}
