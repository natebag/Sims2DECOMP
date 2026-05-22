// 0x802060C8 __static_initialization_and_destruction_0 (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; lis 9,-32704; lis 11,-32704; lfs f12,-13468(11); lis 10,-32704; lfs f13,-13472(9); lfs f0,-13464(10); lis 9,-32696; fmuls f13,f13,f12; addi 11,9,32224; stfs f0,0x7de0(9); stfs f13,-23848(13); stfs f0,0x4(11); stfs f0,0x8(11)"
extern "C" void f_802060C8() {}
