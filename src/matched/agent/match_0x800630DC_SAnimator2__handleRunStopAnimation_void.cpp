// 0x800630DC SAnimator2::handleRunStopAnimation(void) (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 29,0x14(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x61c(31); andis. 9,0,128; bne 3f; lwz 3,0x8(31); lis 4,1; addi 3,3,820; bl _s800630DC_0; lis 9,-32707; li 0,1; lfs f0,0x49f0(9); fcmpu 0,f1,f0; cror 3,2,1; bns 0f; lis 9,-32707; lfs f0,0x49f4(9); fcmpu 0,f1,f0; bge 0f; li 0,0; 0:; cmpwi 0,0; beq 1f; lwz 3,0x4(31); li 4,49; addi 5,1,8; bl _s800630DC_1; b 2f; 1:; lwz 3,0x4(31); li 4,50; addi 5,1,8; bl _s800630DC_2; 2:; lwz 9,0x8(1); lis 3,-32707; addi 3,3,18872; li 4,1; lwz 5,0x0(9); li 6,5797; li 29,1; crxor 6,6,6; bl _s800630DC_3; lfs f1,-32336(13); li 9,0; stw 9,0xc8(31); lis 11,-32707; lwz 0,0x61c(31); li 7,0; lwz 9,0x8(1); li 6,-1; lfs f31,0x49f8(11); oris 0,0,1; stw 0,0x61c(31); li 4,1; stw 9,0xd4(31); stfs f31,0xd0(31); lwz 3,0x8(31); lwz 5,0x0(9); addi 3,3,820; bl _s800630DC_4; mr 30,3; fmr f1,f31; stb 29,0xd(30); mr 4,30; li 5,1; lwz 3,0x8(31); addi 3,3,820; bl _s800630DC_5; lwz 3,0x8(31); mr 4,30; lfs f0,0xfc(31); lfs f1,0x104(31); addi 3,3,820; fmuls f1,f0,f1; bl _s800630DC_6; lwz 0,0x61c(31); oris 0,0,128; stw 0,0x61c(31); 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x14(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s800630DC_0();
extern "C" void _s800630DC_1();
extern "C" void _s800630DC_2();
extern "C" void _s800630DC_3();
extern "C" void _s800630DC_4();
extern "C" void _s800630DC_5();
extern "C" void _s800630DC_6();
extern "C" void f_800630DC() {}
