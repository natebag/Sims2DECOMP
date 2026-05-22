// 0x80012034 AwarenessManager::Reset(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); mr 30,3; bl _s80012034_0; mr 3,30; bl _s80012034_1; lis 9,-32707; lfs f31,-9112(9); stfs f31,0xc(30); bl _s80012034_2; xoris 3,3,32768; stw 3,0xc(1); lis 0,17200; lis 11,-32707; lis 8,-32707; stw 0,0x8(1); lis 7,-32707; lfd f13,-9104(11); li 10,0; lfd f0,0x8(1); li 11,-1; lfs f12,-9096(8); fsub f0,f0,f13; lwz 0,0x0(30); lfs f11,-9092(7); frsp f0,f0; fmuls f0,f0,f12; rlwinm 0,0,0,31,31; fmuls f0,f0,f11; stw 11,0x14(30); stw 0,0x0(30); stfs f0,0x10(30); stw 10,0x40(30); stfs f31,0x3c(30); stw 10,0x18(30); stw 10,0x1c(30); stfs f31,0x20(30); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s80012034_0();
extern "C" void _s80012034_1();
extern "C" void _s80012034_2();
extern "C" void f_80012034() {}
