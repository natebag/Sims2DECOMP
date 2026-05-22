// 0x80206364 InteractorModule::FloorPainter::OnCreate(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80206364_0; mr 4,31; bl _s80206364_1; lis 9,-32704; lis 11,-32704; lfs f13,-13052(9); lis 10,-32697; lfs f0,-13048(11); li 3,0; stfs f13,0x50(31); stfs f0,0x54(31); lwz 9,0x5ea0(10); lwz 9,0x0(9); cmpwi 9,0; beq 0f; lwz 3,-4(9); 0:; rlwinm 3,3,2,0,29; bl _s80206364_2; stw 3,0xb8(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80206364_0();
extern "C" void _s80206364_1();
extern "C" void _s80206364_2();
extern "C" void f_80206364() {}
