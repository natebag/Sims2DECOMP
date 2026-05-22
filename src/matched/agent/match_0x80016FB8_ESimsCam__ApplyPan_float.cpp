// 0x80016FB8 ESimsCam::ApplyPan(float) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,0x44c(3); lis 9,-32707; fadds f13,f0,f1; stfs f13,0x44c(3); lfs f12,-7376(9); fcmpu 0,f13,f12; ble 0f; fsubs f0,f13,f12; stfs f0,0x44c(3); blr; 0:; lis 9,-32707; lfs f0,-7372(9); fcmpu 0,f13,f0; bgelr; fadds f0,f13,f12; stfs f0,0x44c(3)"
extern "C" void f_80016FB8() {}
