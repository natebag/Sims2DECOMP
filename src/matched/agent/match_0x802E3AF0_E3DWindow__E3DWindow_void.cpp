// 0x802E3AF0 E3DWindow::E3DWindow(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; bl _s802E3AF0_0; lis 9,-32697; li 0,5; addi 9,9,-22592; mtspr 9,0; stw 9,0x9c(31); 0:; bdnz 0b; li 0,4; addi 3,31,352; mtspr 9,0; addi 26,31,160; addi 25,31,288; addi 29,31,544; addi 30,31,64; addi 27,31,560; addi 28,31,80; 1:; bdnz 1b; bl _s802E3AF0_1; mr 3,26; bl _s802E3AF0_2; mr 3,25; bl _s802E3AF0_3; lfs f0,0x40(31); li 0,1; stw 0,0x31c(31); lis 9,-32702; stfs f0,0x220(31); lis 11,-32702; lfs f11,-5116(9); mr 3,31; lfs f13,0x4(30); lfs f12,-5112(11); stfs f13,0x4(29); lfs f0,0x8(30); stfs f0,0x8(29); lfs f13,0xc(30); stfs f13,0xc(29); lfs f0,0x50(31); stfs f0,0x230(31); lfs f13,0x4(28); stfs f13,0x4(27); lfs f0,0x8(28); stfs f0,0x8(27); lfs f13,0xc(28); stfs f13,0xc(27); stfs f11,0x28c(31); stfs f12,0x29c(31); lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s802E3AF0_0();
extern "C" void _s802E3AF0_1();
extern "C" void _s802E3AF0_2();
extern "C" void _s802E3AF0_3();
extern "C" void f_802E3AF0() {}
