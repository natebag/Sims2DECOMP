// 0x80218E84 __static_initialization_and_destruction_0 (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; lis 9,-32704; lis 11,-32704; lfs f0,-10340(9); lis 8,-32704; lfs f13,-10336(11); lis 9,-32696; stfs f0,0x7e1c(9); lis 10,-32704; lfs f12,-10332(8); addi 7,9,32284; stfs f13,0x8(7); lis 11,-32696; lfs f11,-10328(10); addi 6,11,32296; stfs f12,0x7e28(11); lis 5,-32696; stfs f11,0x8(6); addi 10,5,32260; stfs f0,0x7e04(5); lis 4,-32696; stfs f0,0x8(10); addi 8,4,32272; stfs f13,0x7e10(4); stfs f13,0x8(8); stfs f0,0x4(10); stfs f0,0x4(8); stfs f13,0x4(7); stfs f11,0x4(6)"
extern "C" void f_80218E84() {}
