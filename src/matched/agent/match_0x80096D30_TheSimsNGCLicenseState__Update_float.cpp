// 0x80096D30 TheSimsNGCLicenseState::Update(float) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x8(31); bl _s80096D30_0; lis 9,-32706; lfs f0,-29860(9); fcmpu 0,f1,f0; bge 0f; lis 9,-32706; lfs f13,0x4c(31); lfs f0,-29856(9); fcmpu 0,f13,f0; bge 2f; lwz 9,0x8(31); lfs f0,0x28(9); fadds f0,f0,f0; fadds f0,f13,f0; stfs f0,0x4c(31); b 2f; 0:; lis 9,-32706; lfs f13,0x4c(31); lfs f31,-29852(9); fcmpu 0,f13,f31; ble 1f; lwz 9,0x8(31); lfs f0,0x28(9); fadds f0,f0,f0; fsubs f0,f13,f0; stfs f0,0x4c(31); b 2f; 1:; stfs f31,0x4c(31); lwz 3,0x8(31); bl _s80096D30_1; lis 9,-32706; lfs f0,-29848(9); fcmpu 0,f1,f0; ble 2f; mr 3,31; fmr f1,f31; li 4,1; bl _s80096D30_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s80096D30_0();
extern "C" void _s80096D30_1();
extern "C" void _s80096D30_2();
extern "C" void f_80096D30() {}
