// 0x80229810 EIPointAmbLight::EIPointAmbLight(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; bl _s80229810_0; lis 9,-32704; addi 10,1,8; lfs f0,-5788(9); lis 11,-32697; addi 11,11,-28384; lis 6,-32704; stfs f0,0x8(10); lis 7,-32704; stfs f0,0x4(10); addi 8,30,172; stfs f0,0x8(1); li 5,1; stw 11,0x0(30); mr 3,30; lwz 11,0x4(10); lwz 0,0x8(1); lwz 9,0x8(10); stw 0,0xac(30); lfs f0,-5784(6); lfs f13,-5780(7); stw 9,0x8(8); stw 11,0x4(8); stfs f0,0xb8(30); stfs f13,0xbc(30); stw 5,0xc0(30); bl _s80229810_1; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80229810_0();
extern "C" void _s80229810_1();
extern "C" void f_80229810() {}
