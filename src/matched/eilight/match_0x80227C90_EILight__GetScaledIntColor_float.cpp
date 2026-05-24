// 0x80227C90 EILight::GetScaledIntColor(float, (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); lis 9,-32704; lfs f11,0x8c(3); lfs f0,-6540(9); addi 11,3,144; lfs f13,0x8(11); lis 9,-32704; fmuls f1,f1,f0; lfs f12,0x90(3); fmuls f1,f1,f11; lfs f0,0x4(11); lfs f11,-6536(9); fmuls f12,f12,f1; fmuls f13,f13,f1; stfs f12,0x8(1); fmuls f0,f0,f1; stfs f13,0x10(1); stfs f0,0xc(1); fcmpu 0,f12,f11; ble 0f; li 0,255; b 1f; 0:; fmr f0,f12; fctiwz f13,f0; stfd f13,0x18(1); lwz 0,0x1c(1); 1:; lis 9,-32704; lfs f13,0xc(1); lfs f0,-6536(9); stw 0,0x0(4); fcmpu 0,f13,f0; ble 2f; li 0,255; b 3f; 2:; fmr f0,f13; fctiwz f13,f0; stfd f13,0x18(1); lwz 0,0x1c(1); 3:; lis 9,-32704; lfs f13,0x10(1); lfs f0,-6536(9); stw 0,0x4(4); fcmpu 0,f13,f0; ble 4f; li 0,255; b 5f; 4:; fmr f0,f13; fctiwz f13,f0; stfd f13,0x18(1); lwz 0,0x1c(1); 5:; stw 0,0x8(4); addi 1,1,32"

struct EILight {
    void GetScaledIntColor();
};

void EILight::GetScaledIntColor() {
}
