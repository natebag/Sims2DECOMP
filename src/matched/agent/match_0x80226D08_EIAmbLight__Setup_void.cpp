// 0x80226D08 EIAmbLight::Setup(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 0,0x34(1); lis 11,-32704; addi 7,1,20; lfs f0,-7084(11); lis 9,-32704; lfs f13,-7080(9); addi 8,1,8; stfs f0,0x20(1); addi 9,1,32; stfs f0,0x28(1); lis 6,-32704; stfs f0,0x24(1); mr 4,8; lwz 0,0x20(1); lwz 11,0x24(1); lwz 10,0x28(1); stw 0,0x14(1); stw 11,0x4(7); stw 10,0x8(7); lfs f0,-7076(6); lwz 0,0x14(1); stw 0,0x8(1); stw 11,0x4(8); stw 10,0x8(8); stfs f13,0x8(9); stfs f13,0x4(9); stfs f13,0x20(1); lwz 0,0x20(1); lwz 11,0x4(9); lwz 10,0x8(9); stw 0,0x8(1); stw 11,0x4(8); stw 10,0x8(8); stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x20(1); lwz 11,0x20(1); lwz 10,0x8(9); lwz 0,0x4(9); stw 11,0x14(1); stw 0,0x4(7); stw 10,0x8(7); bl _s80226D08_0; lwz 0,0x34(1); mtspr 8,0; addi 1,1,48"
extern "C" void _s80226D08_0();
extern "C" void f_80226D08() {}
