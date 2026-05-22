// 0x80306CE0 AngleRange90(float, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; lfs f0,-1328(9); fcmpu 0,f1,f0; ble 1f; lis 9,-32702; fmr f13,f0; lfs f0,-1324(9); 0:; fsubs f1,f1,f0; fcmpu 0,f1,f13; bgt 0b; 1:; lis 9,-32702; lfs f0,-1320(9); fcmpu 0,f1,f0; bge 3f; lis 9,-32702; fmr f13,f0; lfs f0,-1324(9); 2:; fadds f1,f1,f0; fcmpu 0,f1,f13; blt 2b; 3:; lis 9,-32702; lfs f0,-1316(9); fcmpu 0,f1,f0; bge 4f; lwz 0,0x0(3); lis 9,-32702; lfs f0,-1328(9); xori 0,0,1; stw 0,0x0(3); fadds f1,f1,f0; blr; 4:; lis 9,-32702; lfs f0,-1312(9); fcmpu 0,f1,f0; blelr; lwz 0,0x0(3); lis 9,-32702; lfs f0,-1328(9); xori 0,0,1; stw 0,0x0(3); fsubs f1,f1,f0"
extern "C" void f_80306CE0() {}
