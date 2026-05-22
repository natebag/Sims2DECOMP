// 0x80306554 __static_initialization_and_destruction_0 (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 3,-32693; addi 3,3,3368; bl _s80306554_0; lis 8,-32702; lis 7,-32702; lfs f11,-1408(8); lis 9,-32702; lis 11,-32693; lis 6,-32702; lfs f12,-1400(7); lis 10,-32693; lfs f0,-1404(9); addi 8,11,3396; stfs f11,0xd44(11); addi 9,10,3408; lfs f13,-1396(6); stfs f12,0x8(8); stfs f13,0x8(9); stfs f0,0xd50(10); stfs f0,0x4(9); stfs f0,0x4(8); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80306554_0();
extern "C" void f_80306554() {}
