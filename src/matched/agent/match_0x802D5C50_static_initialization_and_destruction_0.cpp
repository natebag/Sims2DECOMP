// 0x802D5C50 __static_initialization_and_destruction_0 (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; lis 11,-32702; lis 9,-32702; lfs f13,-6804(11); lis 10,-32694; lfs f0,-6800(9); lis 11,-32694; addi 9,11,7432; addi 7,10,7408; stfs f13,0x8(9); lis 8,-32694; stfs f13,0x1cf0(10); addi 6,8,7420; stfs f0,0x8(7); stfs f0,0x1cfc(8); stfs f0,0x8(6); stfs f0,0x1d08(11); stfs f0,0x4(9); stfs f0,0x4(7); stfs f13,0x4(6)"
extern "C" void f_802D5C50() {}
