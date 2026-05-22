// 0x803C774C float (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; fsubs f11,f4,f3; lfs f12,0x2af0(9); fabs f0,f11; fmr f13,f1; fmr f1,f2; fcmpu 0,f0,f12; bltlr; fsubs f0,f4,f12; fcmpu 0,f5,f0; bgtlr; fadds f0,f3,f12; fcmpu 0,f5,f0; blt 0f; fsubs f0,f5,f3; fsubs f1,f1,f13; fmuls f1,f1,f0; fdivs f1,f1,f11; fadds f1,f13,f1; blr; 0:; fmr f1,f13"
extern "C" float f_803C774C() {}
