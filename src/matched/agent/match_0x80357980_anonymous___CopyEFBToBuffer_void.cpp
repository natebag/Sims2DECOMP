// 0x80357980 {anonymous}::CopyEFBToBuffer(void (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); xoris 4,4,32768; stw 4,0xc(1); lis 0,17200; mr 10,11; xoris 5,5,32768; stw 0,0x8(1); lis 9,-32702; lfd f10,0x2be8(9); mr 4,11; lfd f11,0x8(1); mr 9,11; stw 5,0xc(1); mr 29,11; lfs f5,0x0(6); fsub f11,f11,f10; stw 0,0x8(1); frsp f11,f11; lfs f0,0x0(7); mr 30,11; lfd f12,0x8(1); mr 28,3; fmadds f0,f11,f5,f0; lfs f6,0x4(6); lfs f13,0x4(7); fsub f12,f12,f10; lfs f10,0x8(6); fctiwz f8,f0; lfs f9,0xc(6); frsp f12,f12; stfd f8,0x8(1); fmadds f13,f12,f6,f13; lwz 9,0xc(1); fctiwz f7,f13; fsubs f10,f10,f5; stfd f7,0x8(1); fmuls f11,f11,f10; rlwinm 3,9,0,16,31; fmr f0,f11; lwz 4,0xc(1); fctiwz f8,f0; fsubs f9,f9,f6; stfd f8,0x8(1); fmuls f12,f12,f9; rlwinm 4,4,0,16,31; fmr f0,f12; lwz 29,0xc(1); fctiwz f13,f0; stfd f13,0x8(1); rlwinm 29,29,0,16,31; mr 5,29; lwz 30,0xc(1); rlwinm 30,30,0,16,31; mr 6,30; bl _s80357980_0; mr 3,29; mr 4,30; li 5,4; li 6,0; bl _s80357980_1; mr 3,28; li 4,0; bl _s80357980_2; bl _s80357980_3; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s80357980_0();
extern "C" void _s80357980_1();
extern "C" void _s80357980_2();
extern "C" void _s80357980_3();
extern "C" void f_80357980() {}
