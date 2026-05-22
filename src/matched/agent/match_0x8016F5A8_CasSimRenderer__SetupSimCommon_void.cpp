// 0x8016F5A8 CasSimRenderer::SetupSimCommon(void) (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 27,0x54(1); stw 0,0x6c(1); mr 31,3; lwz 3,0x0(31); bl _s8016F5A8_0; mr. 27,3; beq 3f; lwz 0,0x84(27); li 4,0; cmpwi 0,0; beq 0f; li 4,1; 0:; lis 3,-32706; lis 29,8120; addi 3,3,5972; ori 29,29,2804; bl _s8016F5A8_1; lwz 0,0x84(27); cmpwi 0,0; beq 1f; lis 29,-90; ori 29,29,848; 1:; addi 30,31,372; mr 3,30; bl _s8016F5A8_2; mr 4,29; mr 3,30; li 5,3; li 6,0; bl _s8016F5A8_3; lis 9,-32706; lis 11,-32706; lfs f0,0x1768(9); lfs f13,0x176c(11); stfs f0,0x58(30); stfs f13,0x54(30); lwz 0,0x170(31); cmpwi 0,0; bne 2f; lis 3,-32692; lis 4,28402; addi 3,3,-27556; ori 4,4,62170; li 5,0; li 6,0; bl _s8016F5A8_4; stw 3,0x170(31); 2:; li 0,0; addi 28,31,8; mr 4,27; li 5,1; mr 3,28; stw 0,0x118(27); bl _s8016F5A8_5; lwz 9,0x4(31); addi 30,1,72; addi 29,1,40; lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; mtspr 8,0; blrl; addi 3,1,72; bl _s8016F5A8_6; addi 4,1,8; li 5,32; addi 3,27,4; bl _s8016F5A8_7; mr 4,29; li 5,32; addi 3,27,68; bl _s8016F5A8_8; lis 4,-32706; mr 6,29; addi 4,4,5984; addi 5,1,8; mr 3,30; crxor 6,6,6; bl _s8016F5A8_9; mr 3,30; bl _s8016F5A8_10; lwz 4,0x48(1); mr 3,28; bl _s8016F5A8_11; lwz 4,0x48(1); mr 3,30; bl _s8016F5A8_12; 3:; lwz 0,0x6c(1); mtspr 8,0; lmw 27,0x54(1); addi 1,1,104"
extern "C" void _s8016F5A8_0();
extern "C" void _s8016F5A8_1();
extern "C" void _s8016F5A8_2();
extern "C" void _s8016F5A8_3();
extern "C" void _s8016F5A8_4();
extern "C" void _s8016F5A8_5();
extern "C" void _s8016F5A8_6();
extern "C" void _s8016F5A8_7();
extern "C" void _s8016F5A8_8();
extern "C" void _s8016F5A8_9();
extern "C" void _s8016F5A8_10();
extern "C" void _s8016F5A8_11();
extern "C" void _s8016F5A8_12();
extern "C" void f_8016F5A8() {}
