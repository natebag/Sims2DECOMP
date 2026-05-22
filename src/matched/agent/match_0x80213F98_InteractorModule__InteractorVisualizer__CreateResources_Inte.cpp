// 0x80213F98 InteractorModule::InteractorVisualizer::CreateResources(InteractorModule::FloorPainter (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 30,0x40(1); stw 0,0x4c(1); mr 30,4; bl _s80213F98_0; mr. 31,3; li 3,0; beq 1f; lis 4,-4065; mr 3,31; ori 4,4,44476; bl _s80213F98_1; lis 4,405; mr 3,31; ori 4,4,2706; bl _s80213F98_2; lis 4,25452; mr 3,31; ori 4,4,38080; bl _s80213F98_3; lis 9,-32704; li 0,0; lfs f0,-10552(9); addi 4,1,8; stw 0,0x8(1); lis 11,-32735; stw 0,0x4(4); addi 11,11,29436; stw 0,0x8(4); li 8,2048; stw 0,0xc(4); lis 7,-32696; stw 0,0x10(4); stw 0,0x14(4); stw 0,0x18(4); stw 0,0x1c(4); stw 0,0x20(4); stw 0,0x24(4); stw 0,0x34(4); stfs f0,0x30(4); stw 0,0x28(4); stfs f0,0x2c(4); lwz 9,-23844(13); lwz 10,0x0(30); stw 0,0x8(1); cmpwi 9,0; stw 0,0x34(4); stw 0,0x4(4); stw 0,0x8(4); stw 0,0xc(4); stw 0,0x10(4); stw 0,0x14(4); stw 0,0x18(4); stw 0,0x1c(4); stw 0,0x20(4); stw 0,0x24(4); stw 8,0x8(1); stw 11,0x1c(1); stw 10,0x20(1); bne 0f; lis 9,-32704; li 0,1; lfs f0,-10548(9); addi 11,7,32236; stw 0,-23844(13); stfs f0,0x7dec(7); stfs f0,0x4(11); stfs f0,0x8(11); 0:; lis 9,-32696; li 0,1; addi 9,9,32236; mr 3,31; stw 9,0x10(1); stw 0,0x24(1); bl _s80213F98_4; li 3,1; 1:; lwz 0,0x4c(1); mtspr 8,0; lmw 30,0x40(1); addi 1,1,72"
extern "C" void _s80213F98_0();
extern "C" void _s80213F98_1();
extern "C" void _s80213F98_2();
extern "C" void _s80213F98_3();
extern "C" void _s80213F98_4();
extern "C" void f_80213F98() {}
