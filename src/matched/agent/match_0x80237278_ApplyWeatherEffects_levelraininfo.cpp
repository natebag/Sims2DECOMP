// 0x80237278 ApplyWeatherEffects(levelraininfo (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); fmr f13,f1; mr. 3,3; beq 4f; lis 9,-32704; lis 10,-32704; lfs f9,-2688(9); lis 11,-32704; lfs f10,-2684(10); lfs f12,0x0(3); lfs f11,-2680(11); fmsubs f1,f12,f9,f10; fcmpu 0,f1,f11; bge 0f; lis 9,-32704; lfs f0,-2676(9); fadds f1,f1,f0; 0:; lfs f0,0x4(3); fsubs f1,f13,f1; fcmpu 0,f1,f11; fsubs f0,f0,f12; fmuls f0,f0,f9; ble 4f; fmr f13,f11; fcmpu 0,f1,f10; bge 1f; fadds f13,f1,f1; b 3f; 1:; fsubs f1,f1,f10; fcmpu 0,f1,f0; bge 2f; lis 9,-32704; lfs f13,-2672(9); b 3f; 2:; fsubs f1,f1,f0; fcmpu 0,f1,f10; bge 3f; lis 9,-32704; fadds f13,f1,f1; lfs f0,-2672(9); fsubs f13,f0,f13; 3:; lis 9,-32704; lfs f0,-2680(9); fcmpu 0,f13,f0; beq 4f; fmr f1,f13; mr 3,4; bl _s80237278_0; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80237278_0();
extern "C" void f_80237278() {}
