// 0x80055C8C EIObjTileBoundRect::Set(CTilePt (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f30,0x20(1); stfd f31,0x28(1); stmw 28,0x10(1); stw 0,0x34(1); mr 29,3; mr 30,4; mr 3,30; lis 28,17200; bl _s80055C8C_0; xoris 3,3,32768; stw 3,0xc(1); lis 9,-32707; lfd f30,0x35a8(9); mr 3,30; stw 28,0x8(1); lfd f31,0x8(1); fsub f31,f31,f30; frsp f31,f31; bl _s80055C8C_1; xoris 3,3,32768; stw 3,0xc(1); lis 9,-32707; lfs f13,0x35b0(9); stw 28,0x8(1); fadds f12,f31,f13; lfd f0,0x8(1); fsubs f31,f31,f13; stfs f12,0x4(29); fsub f0,f0,f30; stfs f31,0x0(29); frsp f0,f0; fadds f12,f0,f13; fsubs f0,f0,f13; stfs f12,0xc(29); stfs f0,0x8(29); lwz 0,0x34(1); mtspr 8,0; lmw 28,0x10(1); lfd f30,0x20(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s80055C8C_0();
extern "C" void _s80055C8C_1();
extern "C" void f_80055C8C() {}
