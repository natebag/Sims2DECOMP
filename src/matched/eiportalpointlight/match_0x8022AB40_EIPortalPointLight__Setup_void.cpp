// 0x8022AB40 EIPortalPointLight::Setup(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 29,0x34(1); stw 0,0x44(1); lis 9,-32704; mr 29,3; lfs f0,-5092(9); addi 10,1,20; lwz 0,0xcc(29); addi 30,1,8; stfs f0,0x20(1); addi 31,1,32; stfs f0,0x28(1); cmpwi 0,0; stfs f0,0x24(1); lwz 0,0x20(1); lwz 9,0x24(1); lwz 11,0x28(1); stw 0,0x14(1); stw 9,0x4(10); stw 11,0x8(10); lwz 0,0x14(1); stw 0,0x8(1); stw 9,0x4(30); stw 11,0x8(30); beq 0f; lwz 9,0x0(29); mr 4,31; lha 3,0x170(9); lwz 0,0x174(9); add 3,29,3; mtspr 8,0; blrl; lfs f1,0xc8(29); mr 3,30; mr 4,31; bl _s8022AB40_0; b 1f; 0:; lis 9,-32704; lis 11,-32704; lfs f0,-5088(9); lfs f13,-5084(11); stfs f0,0x8(31); stfs f0,0x4(31); stfs f0,0x20(1); lwz 9,0x20(1); lwz 11,0x4(31); lwz 0,0x8(31); stw 9,0x8(1); stw 0,0x8(30); stw 11,0x4(30); stfs f13,0x8(31); stfs f13,0x4(31); stfs f13,0x20(1); lwz 0,0x20(1); lwz 9,0x8(31); lwz 11,0x4(31); stw 0,0x14(1); stw 9,0x8(10); stw 11,0x4(10); 1:; mr 3,29; addi 4,1,8; bl _s8022AB40_1; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x34(1); addi 1,1,64"

extern "C" void _s8022AB40_0();
extern "C" void _s8022AB40_1();

struct EIPortalPointLight {
    void Setup();
};

void EIPortalPointLight::Setup() {
}
