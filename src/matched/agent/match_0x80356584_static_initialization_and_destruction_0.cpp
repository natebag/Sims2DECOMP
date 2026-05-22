// 0x80356584 __static_initialization_and_destruction_0 (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmpwi 3,0; beqlr; li 0,256; mtspr 9,0; 0:; bdnz 0b; li 0,256; mtspr 9,0; 1:; bdnz 1b; lis 11,-32702; lis 10,-32690; lfs f0,0x2a34(11); addi 9,10,-7088; stfs f0,-7088(10); stfs f0,0x4(9); stfs f0,0xc(9); stfs f0,0x8(9)"
extern "C" void f_80356584() {}
