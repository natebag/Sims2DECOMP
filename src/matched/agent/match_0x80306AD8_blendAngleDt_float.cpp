// 0x80306AD8 blendAngleDt(float, (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32702; fsubs f13,f1,f2; lfs f0,-1372(9); fcmpu 0,f13,f0; cror 3,2,1; bns 0f; lis 9,-32702; lfs f0,-1368(9); fcmpu 0,f13,f0; bgt 1f; b 5f; 0:; lis 9,-32702; fneg f13,f13; lfs f0,-1368(9); fcmpu 0,f13,f0; ble 5f; 1:; fcmpu 0,f1,f2; ble 3f; lis 9,-32702; lfs f13,-1368(9); fadds f0,f2,f13; fcmpu 0,f1,f0; ble 5f; lis 9,-32702; fmr f12,f13; lfs f13,-1364(9); 2:; fadds f2,f2,f13; fadds f0,f2,f12; fcmpu 0,f1,f0; bgt 2b; b 5f; 3:; lis 9,-32702; lfs f0,-1368(9); fadds f0,f1,f0; fcmpu 0,f2,f0; ble 5f; lis 9,-32702; lfs f13,-1364(9); 4:; fsubs f2,f2,f13; fcmpu 0,f2,f0; bgt 4b; 5:; bl _s80306AD8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80306AD8_0();
extern "C" void f_80306AD8() {}
