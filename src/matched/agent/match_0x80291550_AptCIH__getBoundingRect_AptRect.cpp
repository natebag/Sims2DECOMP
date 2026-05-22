// 0x80291550 AptCIH::getBoundingRect(AptRect (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f30,0x20(1); stfd f31,0x28(1); stw 31,0x1c(1); stw 0,0x34(1); lis 9,-32704; lis 11,-32704; lfs f30,0x5ae4(9); mr 31,4; lfs f31,0x5ae8(11); mr 5,31; stfs f30,0x0(31); stfs f31,0x8(31); stfs f31,0xc(31); stfs f30,0x4(31); lwz 4,-22920(13); bl _s80291550_0; lfs f0,0x0(31); fcmpu 0,f0,f30; bne 0f; lfs f0,0x8(31); fcmpu 0,f0,f31; bne 0f; lfs f0,0xc(31); fcmpu 0,f0,f31; bne 0f; lfs f0,0x4(31); fcmpu 0,f0,f30; bne 0f; lis 9,-32704; lfs f0,0x5aec(9); stfs f0,0x4(31); stfs f0,0x0(31); stfs f0,0x8(31); stfs f0,0xc(31); 0:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x1c(1); lfd f30,0x20(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s80291550_0();
extern "C" void f_80291550() {}
