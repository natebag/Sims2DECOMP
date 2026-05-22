// 0x800693E0 SAnimator2::SetDesiredFacing(float) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32707; lfs f13,0xb4(3); lfs f0,0x4c10(9); fcmpu 0,f13,f0; beq 4f; lis 9,-32707; fsubs f13,f1,f13; lfs f0,0x4c18(9); fcmpu 0,f13,f0; ble 1f; lis 9,-32707; fmr f12,f0; lfs f0,0x4c14(9); 0:; fsubs f13,f13,f0; fcmpu 0,f13,f12; bgt 0b; 1:; lis 9,-32707; lfs f0,0x4c1c(9); fcmpu 0,f13,f0; bge 3f; lis 9,-32707; fmr f12,f0; lfs f0,0x4c14(9); 2:; fadds f13,f13,f0; fcmpu 0,f13,f12; blt 2b; 3:; lis 9,-32707; fabs f13,f13; lfs f0,0x4c20(9); fcmpu 0,f13,f0; ble 4f; lis 9,-32707; lfs f0,0x4c10(9); stfs f0,0x608(3); 4:; stfs f1,0xb4(3)"
extern "C" void f_800693E0() {}
