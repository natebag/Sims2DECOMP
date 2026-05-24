// 0x80226C58 EIAmbLight::LightingParameters(EVec3 (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); stmw 30,0x18(1); lis 9,-32704; addi 11,1,8; lfs f0,-7088(9); addi 30,3,144; stfs f0,0x8(11); stfs f0,0x4(11); stfs f0,0x8(1); lwz 0,0x8(11); lwz 8,0x4(11); lwz 9,0x8(1); stfs f0,0x8(11); stfs f0,0x4(11); stfs f0,0x8(1); stw 0,0x8(4); stw 8,0x4(4); stw 9,0x0(4); lwz 9,0x8(1); lwz 10,0x4(11); lwz 0,0x8(11); stfs f0,0x0(5); stw 0,0x8(6); stw 10,0x4(6); stw 9,0x0(6); lfs f13,0x8c(3); lfs f11,0x90(3); lfs f0,0x8(30); lfs f12,0x4(30); fmuls f11,f11,f13; fmuls f0,f0,f13; stfs f11,0x8(1); fmuls f12,f12,f13; stfs f0,0x10(1); stfs f12,0xc(1); lwz 10,0x8(1); lwz 0,0x8(11); lwz 9,0x4(11); stw 0,0x8(7); stw 10,0x0(7); stw 9,0x4(7); lmw 30,0x18(1); addi 1,1,32"

struct EIAmbLight {
    void LightingParameters_EVec3();
};

void EIAmbLight::LightingParameters_EVec3() {
}
