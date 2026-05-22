// 0x80061804 SAnimator2::handleMoodAnimations(void) (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); mr 30,3; lwz 3,0x4(30); lwz 9,0x4(3); lha 0,0x1f0(9); lwz 9,0x1f4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 2f; lwz 9,0x8(30); li 4,3; lis 31,28393; lwz 11,0x3d0(9); ori 31,31,29431; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; bl _s80061804_0; lis 9,-32707; lis 11,-32707; lfs f0,0x488c(9); fadds f1,f1,f1; lfs f30,0x4890(11); fsubs f31,f1,f0; fcmpu 0,f31,f30; bge 0f; lis 31,-2845; fneg f31,f31; ori 31,31,17115; 0:; lwz 0,0x178(30); cmpw 31,0; beq 1f; stw 31,0x178(30); lis 3,-32707; addi 3,3,18476; li 4,8192; li 5,4883; crxor 6,6,6; bl _s80061804_1; lwz 3,0x8(30); li 4,8192; addi 3,3,820; bl _s80061804_2; cmpwi 31,0; beq 1f; lis 3,-32707; mr 5,31; addi 3,3,18520; li 4,8192; li 6,4889; crxor 6,6,6; bl _s80061804_3; lis 9,-32707; lwz 3,0x8(30); lfs f1,0x4894(9); li 7,0; mr 5,31; li 6,-1; li 4,8192; addi 3,3,820; bl _s80061804_4; mr 31,3; fmr f1,f30; lwz 3,0x8(30); mr 4,31; li 5,1; addi 3,3,820; bl _s80061804_5; lwz 3,0x8(30); fmr f1,f30; mr 4,31; addi 3,3,820; bl _s80061804_6; lwz 9,0x8(30); lwz 9,0x358(9); cmpwi 9,0; lwz 3,0x8(30); lis 5,-32688; mr 4,31; addi 5,5,-17824; addi 3,3,820; bl _s80061804_7; 1:; lwz 3,0x8(30); li 4,8192; addi 3,3,820; bl _s80061804_8; cmpwi 3,0; beq 2f; lwz 3,0x8(30); fmr f1,f31; li 4,8192; addi 3,3,820; bl _s80061804_9; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s80061804_0();
extern "C" void _s80061804_1();
extern "C" void _s80061804_2();
extern "C" void _s80061804_3();
extern "C" void _s80061804_4();
extern "C" void _s80061804_5();
extern "C" void _s80061804_6();
extern "C" void _s80061804_7();
extern "C" void _s80061804_8();
extern "C" void _s80061804_9();
extern "C" void f_80061804() {}
