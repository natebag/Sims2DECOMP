// 0x80167540 CasSimDescriptionS2C::CasSimDescriptionS2C(bool) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; li 4,0; bl _s80167540_0; cmpwi 30,0; stw 30,0x84(31); lis 9,-32706; lis 11,-32706; lfs f0,-168(9); lfs f13,-164(11); stfs f0,0x114(31); stfs f13,0x104(31); stfs f0,0xf8(31); stfs f0,0xfc(31); stfs f0,0x100(31); stfs f0,0x108(31); stfs f0,0x10c(31); stfs f0,0x110(31); mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80167540_0();
extern "C" void f_80167540() {}
