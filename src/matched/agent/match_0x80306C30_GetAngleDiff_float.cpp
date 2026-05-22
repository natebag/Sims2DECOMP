// 0x80306C30 GetAngleDiff(float, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; lfs f13,-1348(9); fcmpu 0,f1,f13; ble 1f; 0:; fsubs f1,f1,f13; fcmpu 0,f1,f13; bgt 0b; 1:; lis 9,-32702; lfs f0,-1344(9); fcmpu 0,f1,f0; bge 4f; 2:; fadds f1,f1,f13; fcmpu 0,f1,f0; blt 2b; b 4f; 3:; fsubs f2,f2,f13; 4:; fcmpu 0,f2,f13; bgt 3b; lis 9,-32702; lfs f0,-1344(9); fcmpu 0,f2,f0; bge 6f; 5:; fadds f2,f2,f13; fcmpu 0,f2,f0; blt 5b; 6:; lis 9,-32702; fsubs f1,f2,f1; lfs f0,-1340(9); fcmpu 0,f1,f0; bge 7f; fadds f1,f1,f13; blr; 7:; lis 9,-32702; lfs f0,-1336(9); fcmpu 0,f1,f0; blelr; fsubs f1,f1,f13"
extern "C" float f_80306C30() {}
