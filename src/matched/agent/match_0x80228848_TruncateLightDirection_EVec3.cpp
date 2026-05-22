// 0x80228848 TruncateLightDirection(EVec3 (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 9,-32704; lfs f13,-6184(9); lis 11,-32704; lfs f0,0x8(31); lfs f12,0x0(31); fsubs f11,f0,f13; stfs f11,0x8(31); lfs f13,-6180(11); fcmpu 0,f12,f13; bne 0f; lfs f0,0x4(31); fcmpu 0,f0,f13; bne 0f; fcmpu 0,f11,f13; beq 1f; 0:; mr 3,31; mr 4,31; bl _s80228848_0; 1:; lis 9,-32704; lfs f13,0x8(31); lfs f0,-6180(9); fcmpu 0,f13,f0; bne 2f; lis 9,-32704; lfs f0,-6176(9); stfs f0,0x8(31); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80228848_0();
extern "C" void f_80228848() {}
