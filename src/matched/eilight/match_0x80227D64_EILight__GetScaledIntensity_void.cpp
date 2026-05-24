// 0x80227D64 EILight::GetScaledIntensity(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xa8(4); cmpwi 0,0; beq 1f; lis 9,-32704; lfs f0,0x9c(4); lfs f13,-6532(9); fmr f12,f0; fcmpu 0,f0,f13; bne 0f; lfs f0,0xa0(4); fcmpu 0,f0,f13; bne 0f; lfs f0,0xa4(4); fcmpu 0,f0,f13; beq 1f; 0:; addi 9,4,156; lfs f0,0x8c(4); lfs f13,0x8(9); lfs f11,0x4(9); fmuls f12,f0,f12; fmuls f13,f0,f13; stfs f12,0x0(3); fmuls f0,f0,f11; stfs f13,0x8(3); stfs f0,0x4(3); blr; 1:; lfs f0,0x8c(4); stfs f0,0x0(3); stfs f0,0x8(3); stfs f0,0x4(3)"

struct EILight {
    void GetScaledIntensity();
};

void EILight::GetScaledIntensity() {
}
