// 0x802F9A10 __static_initialization_and_destruction_0 (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; lis 11,-32702; lis 10,-32693; lfs f0,-3204(11); addi 9,10,2208; addi 8,9,12; li 0,0; stfs f0,0x28(9); addi 11,9,40; stfs f0,0x8a0(10); stfs f0,0x4(8); stw 0,0x24(9); stfs f0,0x4(11); stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x8(8); stfs f0,0xc(9); stfs f0,0x18(9); stfs f0,0x1c(9); stfs f0,0x20(9); stfs f0,0xc(11); stfs f0,0x8(11)"
extern "C" void f_802F9A10() {}
