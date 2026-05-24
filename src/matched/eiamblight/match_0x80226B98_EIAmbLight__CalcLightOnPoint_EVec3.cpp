// 0x80226B98 EIAmbLight::CalcLightOnPoint(EVec3 (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lis 9,-32704; addi 30,1,8; lfs f0,-7092(9); mr 29,5; mr 31,3; stfs f0,0x8(30); stfs f0,0x4(30); stfs f0,0x8(1); lwz 0,0x8(1); lwz 9,0x4(30); lwz 11,0x8(30); stw 0,0x0(29); stw 9,0x4(29); stw 11,0x8(29); lwz 9,0x0(31); lha 3,0x178(9); lwz 0,0x17c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; addi 9,31,144; lfs f13,0x8c(31); lfs f0,0x8(9); lfs f12,0x4(9); lfs f11,0x90(31); fmuls f0,f0,f13; fmuls f12,f12,f13; stfs f0,0x10(1); fmuls f11,f11,f13; stfs f12,0xc(1); stfs f11,0x8(1); lwz 11,0x8(1); lwz 0,0x8(30); lwz 9,0x4(30); stw 0,0x8(29); stw 11,0x0(29); stw 9,0x4(29); 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"

struct EIAmbLight {
    void CalcLightOnPoint_EVec3();
};

void EIAmbLight::CalcLightOnPoint_EVec3() {
}
