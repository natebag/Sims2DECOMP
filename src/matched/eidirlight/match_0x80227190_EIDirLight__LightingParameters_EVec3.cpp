// 0x80227190 EIDirLight::LightingParameters(EVec3 (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); stmw 30,0x18(1); addi 9,3,172; lwz 10,0xac(3); lwz 0,0x8(9); addi 30,3,144; lwz 11,0x4(9); lis 8,-32704; stw 0,0x8(4); addi 9,1,8; stw 11,0x4(4); stw 10,0x0(4); lfs f10,-7000(8); lfs f13,0x8c(3); lfs f11,0x90(3); lfs f0,0x8(30); lfs f12,0x4(30); fmuls f11,f11,f13; fmuls f0,f0,f13; stfs f11,0x8(1); fmuls f12,f12,f13; stfs f0,0x10(1); stfs f12,0xc(1); lwz 11,0x8(1); lwz 10,0x4(9); lwz 0,0x8(9); stfs f10,0x8(9); stfs f10,0x4(9); stfs f10,0x8(1); stw 0,0x8(7); stw 11,0x0(7); stw 10,0x4(7); lwz 10,0x4(9); lwz 0,0x8(9); lwz 11,0x8(1); stfs f10,0x0(5); stw 0,0x8(6); stw 11,0x0(6); stw 10,0x4(6); lmw 30,0x18(1); addi 1,1,32"

struct EIDirLight {
    void LightingParameters_EVec3();
};

void EIDirLight::LightingParameters_EVec3() {
}
