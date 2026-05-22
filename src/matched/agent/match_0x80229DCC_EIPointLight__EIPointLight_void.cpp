// 0x80229DCC EIPointLight::EIPointLight(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; bl _s80229DCC_0; lis 9,-32704; addi 10,1,8; lfs f0,-5472(9); lis 11,-32697; addi 11,11,-27984; lis 4,-32704; stfs f0,0x8(10); lis 29,-32704; stfs f0,0x4(10); addi 8,30,172; stfs f0,0x8(1); li 7,0; stw 11,0x0(30); li 6,-1; lwz 11,0x8(10); li 5,1; lwz 0,0x8(1); mr 3,30; lwz 9,0x4(10); stw 0,0xac(30); lfs f0,-5468(29); lfs f13,-5464(4); stw 11,0x8(8); stw 9,0x4(8); stw 7,0xb8(30); stw 6,0xc0(30); stfs f0,0xc4(30); stfs f13,0xc8(30); stw 5,0xcc(30); stw 7,0xbc(30); bl _s80229DCC_1; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80229DCC_0();
extern "C" void _s80229DCC_1();
extern "C" void f_80229DCC() {}
