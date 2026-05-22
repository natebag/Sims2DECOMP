// 0x800AD260 WaitForControllerButton(bool) (572 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f30,0x30(1); stfd f31,0x38(1); stmw 27,0x1c(1); stw 0,0x44(1); lis 9,-32697; mr 29,3; lwz 0,0x616c(9); li 27,0; cmpwi 0,0; li 3,1; bne 7f; lwz 3,-26524(13); cmpwi 3,0; beq 6f; li 4,0; bl _s800AD260_0; mr 30,3; lis 3,-32706; addi 3,3,-27712; crxor 6,6,6; bl _s800AD260_1; lwz 11,-26524(13); lwz 9,0x20(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lis 3,-32706; addi 3,3,-27664; crxor 6,6,6; bl _s800AD260_2; b 1f; 0:; lis 9,-32706; lis 10,-32706; lfs f0,-27532(9); addi 11,1,8; lfs f13,-27528(10); lis 3,-32706; stfs f0,0x8(1); addi 3,3,-27644; stfs f13,0x8(11); mr 4,11; stfs f0,0xc(11); mr 5,29; stfs f13,0x4(11); bl _s800AD260_3; 1:; li 4,-1; mr 3,30; bl _s800AD260_4; mr 4,3; li 5,0; mr 3,30; li 6,64; bl _s800AD260_5; cmpwi 3,0; beq 0b; lis 3,-32706; addi 31,1,8; addi 3,3,-27600; lis 28,-32706; crxor 6,6,6; bl _s800AD260_6; lis 3,-32706; addi 3,3,-27596; crxor 6,6,6; bl _s800AD260_7; lis 9,-32706; lfs f31,-27532(9); b 3f; 2:; stfs f31,0x8(1); addi 3,28,-27572; stfs f31,0x4(31); mr 4,31; stfs f31,0x8(31); mr 5,29; stfs f31,0xc(31); li 27,1; bl _s800AD260_8; 3:; li 4,-1; mr 3,30; bl _s800AD260_9; mr 4,3; li 5,0; mr 3,30; li 6,64; bl _s800AD260_10; cmpwi 3,0; bne 2b; lis 3,-32706; addi 31,1,8; addi 3,3,-27600; lis 28,-32706; crxor 6,6,6; bl _s800AD260_11; lis 3,-32706; addi 3,3,-27664; crxor 6,6,6; bl _s800AD260_12; lis 9,-32706; lis 11,-32706; lfs f30,-27532(9); lfs f31,-27528(11); b 5f; 4:; stfs f30,0x8(1); addi 3,28,-27644; stfs f31,0x4(31); mr 4,31; stfs f31,0x8(31); mr 5,29; stfs f30,0xc(31); bl _s800AD260_13; 5:; li 4,-1; mr 3,30; bl _s800AD260_14; mr 4,3; li 5,0; mr 3,30; li 6,64; bl _s800AD260_15; cmpwi 3,0; beq 4b; lis 3,-32706; addi 3,3,-27600; crxor 6,6,6; bl _s800AD260_16; lwz 11,-26524(13); lwz 9,0x20(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; 6:; xori 3,27,1; 7:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x1c(1); lfd f30,0x30(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s800AD260_0();
extern "C" void _s800AD260_1();
extern "C" void _s800AD260_2();
extern "C" void _s800AD260_3();
extern "C" void _s800AD260_4();
extern "C" void _s800AD260_5();
extern "C" void _s800AD260_6();
extern "C" void _s800AD260_7();
extern "C" void _s800AD260_8();
extern "C" void _s800AD260_9();
extern "C" void _s800AD260_10();
extern "C" void _s800AD260_11();
extern "C" void _s800AD260_12();
extern "C" void _s800AD260_13();
extern "C" void _s800AD260_14();
extern "C" void _s800AD260_15();
extern "C" void _s800AD260_16();
extern "C" void f_800AD260() {}
