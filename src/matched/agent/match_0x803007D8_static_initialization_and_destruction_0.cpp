// 0x803007D8 __static_initialization_and_destruction_0 (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; lis 9,-32702; lis 11,-32702; lfs f13,-2192(9); lis 8,-32693; lfs f0,-2188(11); lis 9,-32693; addi 11,8,2292; addi 10,9,2304; stfs f13,0x8(11); stfs f0,0x8(10); stfs f13,0x8f4(8); stfs f0,0x900(9); stfs f13,0x4(11); stfs f0,0x4(10)"
extern "C" void f_803007D8() {}
