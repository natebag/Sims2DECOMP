// 0x8009591C __static_initialization_and_destruction_0 (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; lis 9,-32706; lis 10,-32706; lfs f12,-30740(9); lis 8,-32706; lis 7,-32706; lis 11,-32696; lfs f11,-30736(10); addi 9,11,22820; lfs f13,-30732(8); lfs f0,-30728(7); stfs f12,0x5924(11); stfs f0,0xc(9); stfs f11,0x4(9); stfs f13,0x8(9)"
extern "C" void f_8009591C() {}
