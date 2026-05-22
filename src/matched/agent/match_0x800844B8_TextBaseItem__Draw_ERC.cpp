// 0x800844B8 TextBaseItem::Draw(ERC (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f30,0x18(1); stfd f31,0x20(1); stmw 28,0x8(1); stw 0,0x2c(1); mr 31,3; mr 28,4; lwz 0,0x4(31); fmr f30,f1; andi. 9,0,1; beq 1f; addi 9,31,32; lwz 29,0x6c(31); mr 30,9; lfs f31,0x34(9); andi. 9,0,4; beq 0f; lis 9,-32707; mr 3,30; lfs f0,0x7240(9); fmuls f0,f31,f0; stfs f0,0x34(30); bl _s800844B8_0; lwz 0,0x4(31); cmpwi 29,7; ori 0,0,2; stw 0,0x4(31); beq 0f; mr 3,31; li 4,9; bl _s800844B8_1; 0:; mr 4,28; fmr f1,f30; mr 3,30; bl _s800844B8_2; lwz 0,0x4(31); andi. 9,0,4; beq 1f; stfs f31,0x34(30); mr 3,30; bl _s800844B8_3; lwz 0,0x4(31); mr 3,31; mr 4,29; ori 0,0,2; stw 0,0x4(31); bl _s800844B8_4; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x8(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s800844B8_0();
extern "C" void _s800844B8_1();
extern "C" void _s800844B8_2();
extern "C" void _s800844B8_3();
extern "C" void _s800844B8_4();
extern "C" void f_800844B8() {}
