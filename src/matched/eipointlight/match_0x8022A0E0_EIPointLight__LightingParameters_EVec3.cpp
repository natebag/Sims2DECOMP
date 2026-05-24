// 0x8022A0E0 EIPointLight::LightingParameters(EVec3 (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 30,3; lis 9,-32704; lfs f13,-5444(9); mr 29,4; lfs f0,0xc8(30); mr 4,6; mr 31,7; fmuls f0,f0,f13; stfs f0,0x0(5); lwz 9,0x0(30); lwz 0,0x174(9); lha 3,0x170(9); mtspr 8,0; add 3,30,3; blrl; addi 9,30,144; lfs f12,0x8c(30); lfs f0,0x8(9); addi 11,1,8; lfs f13,0x90(30); lis 8,-32704; lfs f11,0x4(9); fmuls f0,f12,f0; fmuls f13,f12,f13; stfs f0,0x10(1); fmuls f12,f12,f11; stfs f13,0x8(1); stfs f12,0xc(1); addi 7,30,156; lwz 10,0x8(1); mr 6,11; lwz 0,0x4(11); lwz 9,0x8(11); stw 10,0x0(31); stw 0,0x4(31); stw 9,0x8(31); lfs f12,-5440(8); lfs f0,0x9c(30); stfs f0,0x8(1); fcmpu 0,f0,f12; lfs f0,0x4(7); stfs f0,0xc(1); lfs f13,0x8(7); stfs f13,0x10(1); bne 0f; fcmpu 0,f0,f12; bne 0f; fcmpu 0,f13,f12; addi 8,1,24; beq 2f; 0:; lis 9,-32704; lfs f0,0x8(1); lfs f13,-5436(9); fmr f11,f0; fcmpu 0,f0,f13; bne 1f; lfs f0,0xc(1); fcmpu 0,f0,f13; bne 1f; lfs f0,0x10(1); addi 8,1,24; fcmpu 0,f0,f13; beq 2f; 1:; lfs f13,0x0(31); addi 11,1,24; lfs f10,0x8(6); mr 8,11; fmuls f13,f13,f11; lfs f12,0x4(31); lfs f11,0x4(6); lfs f0,0x8(31); fmuls f12,f12,f11; stfs f13,0x18(1); fmuls f0,f0,f10; stfs f12,0x1c(1); stfs f0,0x20(1); lwz 9,0x18(1); lwz 10,0x4(11); lwz 0,0x8(11); stw 9,0x0(31); stw 0,0x8(31); stw 10,0x4(31); 2:; lis 9,-32704; lfs f0,-5440(9); stfs f0,0x8(8); stfs f0,0x4(8); stfs f0,0x18(1); lwz 9,0x8(8); lwz 11,0x4(8); lwz 0,0x18(1); stw 9,0x8(29); stw 0,0x0(29); stw 11,0x4(29); lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"

struct EIPointLight {
    void LightingParameters_EVec3();
};

void EIPointLight::LightingParameters_EVec3() {
}
