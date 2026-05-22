// 0x80372F78 C_MTXRotAxisRad (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-80(1); stfd f31,0x48(1); stfd f30,0x40(1); stfd f29,0x38(1); stw 31,0x34(1); stw 30,0x30(1); fmr f30,f1; mr 30,3; mr 31,4; fmr f1,f30; bl _s80372F78_0; fmr f29,f1; fmr f1,f30; bl _s80372F78_1; fmr f31,f1; lfs f0,-17968(13); mr 3,31; addi 4,1,32; fsubs f30,f0,f31; bl _s80372F78_2; lfs f6,0x20(1); lfs f4,0x24(1); fmuls f1,f6,f6; lfs f10,0x28(1); fmuls f3,f30,f6; fmuls f0,f4,f4; fmuls f2,f30,f1; fmuls f1,f30,f4; fmuls f7,f4,f3; fmuls f5,f29,f10; fadds f2,f31,f2; fmuls f9,f10,f3; fmuls f8,f29,f4; fsubs f4,f7,f5; stfs f2,0x0(30); fmuls f2,f30,f0; fadds f3,f9,f8; stfs f4,0x4(30); fmuls f0,f10,f10; stfs f3,0x8(30); fadds f5,f7,f5; fmuls f7,f10,f1; fmuls f1,f29,f6; lfs f6,-17964(13); fadds f4,f31,f2; fmuls f0,f30,f0; stfs f6,0xc(30); fsubs f3,f7,f1; stfs f5,0x10(30); fsubs f2,f9,f8; fadds f1,f7,f1; stfs f4,0x14(30); fadds f0,f31,f0; stfs f3,0x18(30); stfs f6,0x1c(30); stfs f2,0x20(30); stfs f1,0x24(30); stfs f0,0x28(30); stfs f6,0x2c(30); lwz 0,0x54(1); lfd f31,0x48(1); lfd f30,0x40(1); lfd f29,0x38(1); lwz 31,0x34(1); lwz 30,0x30(1); addi 1,1,80; mtspr 8,0"
extern "C" void _s80372F78_0();
extern "C" void _s80372F78_1();
extern "C" void _s80372F78_2();
extern "C" void f_80372F78() {}
