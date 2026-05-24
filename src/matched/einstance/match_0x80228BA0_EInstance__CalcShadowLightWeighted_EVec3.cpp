// 0x80228BA0 EInstance::CalcShadowLightWeighted(EVec3 (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 31,0x2c(1); stw 0,0x34(1); mr 7,3; mr 31,4; mr. 5,5; blt 2f; mulli 0,5,84; lwz 9,0x4(7); add 9,9,0; addi 11,9,24636; lwz 10,0x3c(11); cmpwi 10,0; beq 0f; addi 9,11,32; lfs f11,0x8c(10); lfs f0,0x20(11); addi 10,1,8; lfs f13,0x8(9); lfs f12,0x4(9); fmuls f0,f0,f11; fmuls f13,f13,f11; stfs f0,0x8(1); fmuls f12,f12,f11; stfs f13,0x10(1); stfs f12,0xc(1); lwz 9,0x8(1); lwz 11,0x8(10); lwz 0,0x4(10); stw 9,0x0(31); stw 0,0x4(31); stw 11,0x8(31); b 1f; 0:; addi 9,7,60; addi 11,7,72; lfs f0,0x4(11); lis 10,-32704; lfs f10,0x4(9); lis 8,-32704; lfs f12,0x48(7); mr 6,5; lfs f11,0x3c(7); fadds f10,f10,f0; lfs f0,-6148(10); mr 3,7; lfs f13,0x8(9); fadds f11,f11,f12; lfs f9,0x8(11); fmuls f12,f10,f0; lfs f8,-6144(8); fmuls f0,f11,f0; fadds f13,f13,f9; addi 4,1,8; stfs f13,0x20(1); mr 5,31; stfs f12,0xc(1); stfs f0,0x8(1); stfs f8,0x10(1); stfs f11,0x18(1); stfs f10,0x1c(1); bl _s80228BA0_0; 1:; mr 3,31; bl _s80228BA0_1; 2:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x2c(1); addi 1,1,48"

extern "C" void _s80228BA0_0();
extern "C" void _s80228BA0_1();

struct EInstance {
    void CalcShadowLightWeighted_EVec3();
};

void EInstance::CalcShadowLightWeighted_EVec3() {
}
