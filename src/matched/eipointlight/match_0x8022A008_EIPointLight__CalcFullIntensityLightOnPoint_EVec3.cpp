// 0x8022A008 EIPointLight::CalcFullIntensityLightOnPoint(EVec3 (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 30,0x18(1); stw 0,0x2c(1); mr 31,3; lfs f12,0x4(4); lfs f13,0xac(31); lis 9,-32704; lfs f11,0xb0(31); mr 30,5; lfs f0,0x0(4); addi 3,1,8; lfs f31,-5460(9); fsubs f12,f12,f11; fsubs f0,f0,f13; stfs f12,0xc(1); stfs f0,0x8(1); stfs f31,0x10(1); bl _s8022A008_0; lfs f0,0x8c(31); fmr f12,f1; fcmpu 0,f0,f31; stfs f0,0x0(30); bne 0f; lis 9,-32704; lfs f0,-5456(9); stfs f0,0x0(30); 0:; fcmpu 0,f12,f31; beq 2f; lwz 0,0xcc(31); lis 11,-32704; lfs f1,-5452(11); cmpwi 0,0; beq 1f; lis 9,-32704; lfs f13,0xc8(31); lfs f0,-5448(9); fmuls f0,f12,f0; fdivs f1,f13,f0; fmuls f1,f1,f1; 1:; lfs f0,0x0(30); lfs f13,-5452(11); fmuls f0,f1,f0; fcmpu 0,f0,f13; stfs f0,0x0(30); ble 2f; stfs f13,0x0(30); 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x18(1); lfd f31,0x20(1); addi 1,1,40"

extern "C" void _s8022A008_0();

struct EIPointLight {
    void CalcFullIntensityLightOnPoint_EVec3();
};

void EIPointLight::CalcFullIntensityLightOnPoint_EVec3() {
}
