// 0x802F0D9C EGraphics::EGraphics(void) (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 28,0x28(1); stw 0,0x44(1); lis 9,-32697; mr 31,3; addi 9,9,-24288; stw 9,0x0(31); li 4,4; bl _s802F0D9C_0; lis 9,-32697; li 0,16; addi 9,9,-22520; mtspr 9,0; stw 9,0x0(31); addi 29,1,8; addi 28,1,24; 0:; bdnz 0b; li 0,16; addi 6,31,128; mtspr 9,0; 1:; bdnz 1b; lis 9,-32702; li 0,0; lfs f31,-4088(9); li 30,1; stw 0,0x4(31); li 10,-1; stfs f31,0x8(29); li 7,255; stfs f31,0x4(29); mr 3,31; stfs f31,0x8(1); fmr f1,f31; stw 0,0x8(31); fmr f2,f31; fmr f3,f31; lwz 11,0x8(1); fmr f4,f31; lwz 8,0x4(29); lwz 9,0x8(29); stw 11,0x80(31); stw 30,0x10(31); stw 30,0xc(31); stw 9,0x8(6); stw 8,0x4(6); stw 7,0x8c(31); stw 0,0x31c(31); stw 0,0x24(31); stw 0,0x20(31); stw 0,0x38(31); stw 0,0x34(31); stw 0,0x3c(31); stw 0,0x30(31); stw 0,0x2cc(31); stw 0,0x98(31); stw 0,0x90(31); stw 0,0x324(31); stw 0,0x14(31); stw 10,0x2c(31); stw 10,0x1c(31); stw 10,0x18(31); stw 10,0x28(31); bl _s802F0D9C_1; lis 9,-32702; lis 10,-32702; lfs f1,-4084(9); lis 11,-32702; lfs f4,-4076(10); mr 3,31; lfs f2,-4080(11); fmr f3,f1; bl _s802F0D9C_2; lis 9,-32702; lis 11,-32702; lfs f3,-4072(9); mr 3,31; lfs f4,-4068(11); fmr f1,f31; fmr f2,f31; bl _s802F0D9C_3; lis 9,-32702; mr 3,31; lfs f0,-4064(9); mr 4,29; mr 5,28; stfs f0,0x8(29); stfs f0,0x4(29); stfs f0,0x8(1); stfs f31,0x8(28); stfs f31,0x4(28); stfs f31,0x18(1); bl _s802F0D9C_4; stw 30,0x320(31); mr 3,31; lwz 0,0x44(1); mtspr 8,0; lmw 28,0x28(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s802F0D9C_0();
extern "C" void _s802F0D9C_1();
extern "C" void _s802F0D9C_2();
extern "C" void _s802F0D9C_3();
extern "C" void _s802F0D9C_4();
extern "C" void f_802F0D9C() {}
