// 0x8039D620 float (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fmr f12,f1; fmr f1,f2; fcmpu 0,f5,f4; bgtlr; fcmpu 0,f5,f3; blt 0f; fsubs f1,f1,f12; fsubs f0,f5,f3; fmuls f1,f1,f0; fsubs f13,f4,f3; fdivs f1,f1,f13; fadds f1,f12,f1; blr; 0:; fmr f1,f12"
extern "C" float f_8039D620() {}
