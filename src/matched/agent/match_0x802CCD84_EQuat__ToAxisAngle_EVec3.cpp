// 0x802CCD84 EQuat::ToAxisAngle(EVec3 (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f30,0x18(1); stfd f31,0x20(1); stmw 29,0xc(1); stw 0,0x2c(1); mr 30,3; lis 9,-32702; lfs f1,0xc(30); lis 11,-32702; lfs f30,-7320(9); mr 31,4; lfs f13,-7316(11); fmuls f0,f1,f1; fsubs f31,f30,f0; mr 29,5; fcmpu 0,f31,f13; cror 3,2,0; bns 0f; stfs f13,0x0(29); stfs f13,0x8(31); stfs f30,0x0(31); stfs f13,0x4(31); b 1f; 0:; bl _s802CCD84_0; fadds f1,f1,f1; stfs f1,0x0(29); fmr f1,f31; bl _s802CCD84_1; fdivs f1,f30,f1; lfs f0,0x0(30); fmuls f0,f0,f1; stfs f0,0x0(31); lfs f13,0x4(30); fmuls f13,f13,f1; stfs f13,0x4(31); lfs f0,0x8(30); fmuls f0,f0,f1; stfs f0,0x8(31); 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0xc(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s802CCD84_0();
extern "C" void _s802CCD84_1();
extern "C" void f_802CCD84() {}
