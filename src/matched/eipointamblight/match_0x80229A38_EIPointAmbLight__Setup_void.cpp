// 0x80229A38 EIPointAmbLight::Setup(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stw 31,0x34(1); stw 0,0x3c(1); lis 9,-32704; mr 31,3; lfs f0,-5776(9); addi 8,1,20; lwz 0,0xc0(31); addi 3,1,8; stfs f0,0x20(1); addi 10,1,32; stfs f0,0x28(1); cmpwi 0,0; stfs f0,0x24(1); lwz 0,0x20(1); lwz 9,0x24(1); lwz 11,0x28(1); stw 0,0x14(1); stw 9,0x4(8); stw 11,0x8(8); lwz 0,0x14(1); stw 0,0x8(1); stw 9,0x4(3); stw 11,0x8(3); beq 0f; lfs f1,0xbc(31); addi 4,31,172; bl _s80229A38_0; b 1f; 0:; lis 9,-32704; lis 11,-32704; lfs f0,-5772(9); lfs f13,-5768(11); stfs f0,0x8(10); stfs f0,0x4(10); stfs f0,0x20(1); lwz 9,0x20(1); lwz 11,0x4(10); lwz 0,0x8(10); stw 9,0x8(1); stw 0,0x8(3); stw 11,0x4(3); stfs f13,0x8(10); stfs f13,0x4(10); stfs f13,0x20(1); lwz 0,0x20(1); lwz 9,0x8(10); lwz 11,0x4(10); stw 0,0x14(1); stw 9,0x8(8); stw 11,0x4(8); 1:; mr 3,31; addi 4,1,8; bl _s80229A38_1; lwz 0,0x3c(1); mtspr 8,0; lwz 31,0x34(1); addi 1,1,56"

extern "C" void _s80229A38_0();
extern "C" void _s80229A38_1();

struct EIPointAmbLight {
    void Setup();
};

void EIPointAmbLight::Setup() {
}
