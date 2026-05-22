// 0x80231040 ELightGrid::EvaluateLampsOn(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 8,0x18(3); lwz 0,0x1c(3); cmpw 8,0; bge 4f; lis 9,-32704; lis 10,-32704; lfs f10,-3436(9); rlwinm 11,8,5,0,26; addi 11,11,32; lfs f12,-3432(10); fmr f11,f10; add 11,11,3; 0:; lwz 9,0x1c(11); lfs f0,0x90(9); addi 9,9,144; fcmpu 0,f0,f10; fmr f13,f10; blt 1f; fmr f13,f0; fcmpu 0,f0,f12; ble 1f; fmr f13,f12; 1:; stfs f13,0x10(11); lfs f0,0x4(9); fcmpu 0,f0,f11; fmr f13,f11; blt 2f; fmr f13,f0; fcmpu 0,f0,f12; ble 2f; fmr f13,f12; 2:; stfs f13,0x14(11); lfs f0,0x8(9); fcmpu 0,f0,f11; fmr f13,f11; blt 3f; fmr f13,f0; fcmpu 0,f0,f12; ble 3f; fmr f13,f12; 3:; stfs f13,0x18(11); addi 8,8,1; addi 11,11,32; lwz 0,0x1c(3); cmpw 8,0; blt 0b; 4:; lwz 4,0x10(3); lwz 5,0x14(3); bl _s80231040_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80231040_0();
extern "C" void f_80231040() {}
