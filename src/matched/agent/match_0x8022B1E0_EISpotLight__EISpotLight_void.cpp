// 0x8022B1E0 EISpotLight::EISpotLight(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; bl _s8022B1E0_0; lis 11,-32704; lis 10,-32704; lfs f0,-5000(11); lis 9,-32697; lfs f13,-4996(10); addi 9,9,-27176; stw 9,0x0(30); addi 11,30,184; stfs f0,0xb8(30); addi 9,1,8; stfs f13,0x8(11); lis 10,-32704; stfs f0,0x4(11); lis 5,-32704; stfs f0,0x8(9); addi 8,30,172; stfs f0,0x4(9); lis 4,-32704; stfs f0,0x8(1); lis 7,-32704; lfs f13,-4992(10); lis 29,-32704; lwz 11,0x8(1); li 6,1; lwz 10,0x8(9); mr 3,30; lwz 0,0x4(9); stw 11,0xac(30); lfs f0,-4988(5); stw 10,0x8(8); stw 0,0x4(8); stfs f13,0xc4(30); stfs f0,0xc8(30); lfs f13,-4984(29); lfs f12,-4980(4); lfs f0,-4976(7); fmuls f13,f13,f12; stw 6,0xd4(30); fmuls f0,f0,f12; stfs f13,0xcc(30); stfs f0,0xd0(30); bl _s8022B1E0_1; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8022B1E0_0();
extern "C" void _s8022B1E0_1();
extern "C" void f_8022B1E0() {}
