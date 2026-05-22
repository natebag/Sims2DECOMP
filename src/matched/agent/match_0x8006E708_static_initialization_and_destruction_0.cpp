// 0x8006E708 __static_initialization_and_destruction_0 (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; lis 11,-32707; lis 9,-32707; lfs f13,0x5184(11); lis 10,-32707; lfs f0,0x5180(9); addi 11,13,-24932; stfs f13,0x4(11); addi 9,13,-24924; stfs f0,0x4(9); addi 8,13,-24940; lfs f12,0x5188(10); stfs f0,0x0(8); stfs f12,0x0(9); stfs f0,0x4(8); stfs f0,0x0(11)"
extern "C" void f_8006E708() {}
