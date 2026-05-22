// 0x80175934 __static_initialization_and_destruction_0 (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; lis 9,-32706; lis 11,-32706; lfs f10,0x21f4(9); lis 10,-32706; lfs f9,0x21f8(11); lis 9,-32696; stfs f10,0x79e4(9); lis 11,-32706; lfs f11,0x21fc(10); addi 9,9,31204; lfs f12,0x2200(11); lis 10,-32706; stfs f9,0x4(9); lis 11,-32706; stfs f11,0x8(9); stfsu f12,0xc(9); lfs f0,0x2204(10); stfs f11,0x8(9); stfs f0,0x4(9); stfsu f12,0xc(9); lfs f13,0x2208(11); stfs f0,0x4(9); stfs f13,0x8(9); stfsu f10,0xc(9); stfs f13,0x8(9); stfs f9,0x4(9)"
extern "C" void f_80175934() {}
