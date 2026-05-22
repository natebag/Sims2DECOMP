// 0x80306F70 LineLineIntersect(EVec2, (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f28,0x20(1); stfd f29,0x28(1); stfd f30,0x30(1); stfd f31,0x38(1); stmw 27,0xc(1); stw 0,0x44(1); mr 31,3; mr 30,4; lfs f0,0x0(31); mr 29,5; lfs f1,0x0(30); mr 28,6; lfs f13,0x4(31); mr 27,7; fsubs f1,f0,f1; lfs f2,0x4(30); lfs f0,0x4(29); lfs f12,0x0(29); fsubs f2,f13,f2; lfs f3,0x0(28); lfs f4,0x4(28); fsubs f3,f12,f3; fsubs f4,f0,f4; bl _s80306F70_0; lis 9,-32702; fmr f28,f1; lfs f0,-1296(9); fcmpu 0,f28,f0; beq 0f; lfs f2,0x4(31); lfs f3,0x0(30); lfs f4,0x4(30); lfs f1,0x0(31); bl _s80306F70_1; fmr f29,f1; lfs f2,0x4(29); lfs f4,0x4(28); lfs f3,0x0(28); lfs f1,0x0(29); bl _s80306F70_2; lfs f13,0x0(31); fmr f30,f1; lfs f0,0x0(29); fmr f3,f30; lfs f2,0x0(30); fmr f1,f29; lfs f4,0x0(28); fsubs f2,f13,f2; fsubs f4,f0,f4; bl _s80306F70_3; lfs f13,0x4(31); fmr f31,f1; lfs f2,0x4(30); fmr f1,f29; lfs f0,0x4(29); fmr f3,f30; lfs f4,0x4(28); fsubs f2,f13,f2; fsubs f4,f0,f4; bl _s80306F70_4; fdivs f1,f1,f28; li 3,1; fdivs f31,f31,f28; stfs f1,0x4(27); stfs f31,0x0(27); b 1f; 0:; li 3,0; 1:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0xc(1); lfd f28,0x20(1); lfd f29,0x28(1); lfd f30,0x30(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s80306F70_0();
extern "C" void _s80306F70_1();
extern "C" void _s80306F70_2();
extern "C" void _s80306F70_3();
extern "C" void _s80306F70_4();
extern "C" void f_80306F70() {}
