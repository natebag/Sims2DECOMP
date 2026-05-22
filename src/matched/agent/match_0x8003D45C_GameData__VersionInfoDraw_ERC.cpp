// 0x8003D45C GameData::VersionInfoDraw(ERC (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f29,0x48(1); stfd f30,0x50(1); stfd f31,0x58(1); stmw 27,0x34(1); stw 0,0x64(1); lis 9,-32697; mr 27,4; lwz 31,0x5ed0(9); cmpwi 31,0; beq 0f; lis 9,-32707; lis 30,-32707; lfs f1,0x1e7c(9); mr 3,31; lfs f2,0x1e80(30); li 4,1; lis 29,-32707; lis 28,17200; bl _s8003D45C_0; lfs f30,0x1e80(30); addi 9,1,16; addi 11,31,88; mr 4,27; stfs f30,0x10(1); mr 3,31; stfs f30,0xc(9); stfs f30,0x4(9); stfs f30,0x8(9); lfs f0,0x10(1); stfs f0,0x58(31); lfs f13,0x14(1); stfs f13,0x4(11); lfs f0,0x18(1); stfs f0,0x8(11); lfs f13,0x1c(1); stfs f13,0xc(11); bl _s8003D45C_1; lis 11,-32707; lis 9,-32707; lfs f0,0x1e84(9); lfs f13,0x1e88(11); stfs f0,0x8(1); stfs f13,0xc(1); bl _s8003D45C_2; mr 5,3; lfs f1,0x1e8c(29); addi 6,1,8; li 8,0; li 9,0; li 10,1; mr 4,27; li 7,0; fmr f2,f30; mr 3,31; bl _s8003D45C_3; lwz 10,-26392(13); lis 11,-32707; lis 8,-32707; lwz 0,0x1c(10); lfd f29,0x1e90(11); xoris 0,0,32768; lfs f31,0x1e98(8); stw 0,0x2c(1); lfs f13,0xc(1); stw 28,0x28(1); lfd f0,0x28(1); fsub f0,f0,f29; frsp f0,f0; fdivs f0,f31,f0; fadds f13,f13,f0; stfs f13,0xc(1); bl _s8003D45C_4; mr 5,3; lfs f1,0x1e8c(29); li 9,0; mr 4,27; addi 6,1,8; li 7,0; li 8,0; fmr f2,f30; li 10,1; mr 3,31; bl _s8003D45C_5; lwz 11,-26392(13); lfs f13,0xc(1); lwz 0,0x1c(11); xoris 0,0,32768; stw 0,0x2c(1); stw 28,0x28(1); lfd f0,0x28(1); fsub f0,f0,f29; frsp f0,f0; fdivs f31,f31,f0; fadds f13,f13,f31; stfs f13,0xc(1); bl _s8003D45C_6; mr 5,3; lfs f1,0x1e8c(29); mr 3,31; mr 4,27; fmr f2,f30; addi 6,1,8; li 7,0; li 8,0; li 9,0; li 10,1; bl _s8003D45C_7; 0:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x34(1); lfd f29,0x48(1); lfd f30,0x50(1); lfd f31,0x58(1); addi 1,1,96"
extern "C" void _s8003D45C_0();
extern "C" void _s8003D45C_1();
extern "C" void _s8003D45C_2();
extern "C" void _s8003D45C_3();
extern "C" void _s8003D45C_4();
extern "C" void _s8003D45C_5();
extern "C" void _s8003D45C_6();
extern "C" void _s8003D45C_7();
extern "C" void f_8003D45C() {}
