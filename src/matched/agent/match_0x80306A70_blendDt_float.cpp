// 0x80306A70 blendDt(float, (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fmr f12,f1; fcmpu 0,f2,f12; beqlr; lfs f0,-26800(13); lis 9,-32702; lfs f13,-1380(9); fmuls f1,f3,f0; fcmpu 0,f1,f13; ble 0f; fmr f1,f13; 0:; fsubs f0,f12,f2; lis 9,-32702; fmadds f1,f0,f1,f2; lfs f13,-1376(9); fsubs f0,f1,f12; fcmpu 0,f0,f13; cror 3,2,1; bns 1f; fcmpu 0,f0,f4; blt 2f; blr; 1:; fneg f0,f0; fcmpu 0,f0,f4; bgelr; 2:; fmr f1,f12"
extern "C" float f_80306A70() {}
