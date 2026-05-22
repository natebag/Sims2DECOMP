// 0x802FFB98 EWindow::EWindow(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lis 9,-32702; lis 11,-32702; lfs f13,-2236(9); addi 10,1,8; lfs f0,-2232(11); lis 9,-32697; stfs f13,0x8(1); mr 30,3; stfs f0,0xc(10); addi 9,9,-21072; stfs f0,0x8(10); addi 11,30,96; stfs f13,0x4(10); addi 8,30,64; stw 9,0x9c(30); addi 7,30,80; li 0,1; lfs f0,0x8(1); stfs f0,0x60(30); stfs f13,0x4(11); lfs f0,0x8(10); stfs f0,0x8(11); lfs f13,0xc(10); stfs f13,0xc(11); lfs f0,0x60(30); stfs f0,0x40(30); lfs f13,0x4(11); stfs f13,0x4(8); lfs f0,0x8(11); stfs f0,0x8(8); lfs f13,0xc(11); stfs f13,0xc(8); lfs f0,0x40(30); stfs f0,0x50(30); lfs f13,0x4(8); stfs f13,0x4(7); lfs f0,0x8(8); stfs f0,0x8(7); lfs f13,0xc(8); stfs f13,0xc(7); stw 0,0x98(30); bl _s802FFB98_0; mr 3,30; bl _s802FFB98_1; li 0,0; li 9,5; stw 0,0x90(30); mr 3,30; stw 9,0x94(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s802FFB98_0();
extern "C" void _s802FFB98_1();
extern "C" void f_802FFB98() {}
