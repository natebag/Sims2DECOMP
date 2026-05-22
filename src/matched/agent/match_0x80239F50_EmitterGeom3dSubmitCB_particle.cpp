// 0x80239F50 EmitterGeom3dSubmitCB(particle (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-272(1); mfspr 0,8; stfd f30,0x100(1); stfd f31,0x108(1); stmw 26,0xe8(1); stw 0,0x114(1); mr 28,6; mr 29,3; lwz 27,0x80(28); fmr f30,f1; fmr f31,f2; mr 26,5; lwz 30,0x88(28); mr 3,27; bl _s80239F50_0; addi 31,1,8; mr 4,3; mr 3,31; bl _s80239F50_1; addi 9,27,72; lwz 0,0x48(27); lwz 8,0x4(9); addi 7,29,16; lwz 10,0x8(9); addi 11,1,72; stw 0,0x48(1); mr 4,11; stw 8,0x4c(1); stw 10,0x50(1); lwz 10,0x8(7); lfs f0,0xc(9); lwz 8,0x10(29); lwz 0,0x4(7); stfs f0,0x54(1); stw 8,0x48(1); stw 0,0x4(11); stw 10,0x8(11); lwz 3,-26704(13); lfs f0,0x54(1); lfs f13,0x8(1); fmuls f0,f0,f13; stfs f0,0x54(1); bl _s80239F50_2; cmpwi 3,1; beq 1f; lfs f13,0x10c(30); addi 4,1,88; lfs f12,0x110(30); mr 3,31; lfs f0,0x114(30); fmuls f13,f31,f13; fmuls f12,f31,f12; stfs f13,0x58(1); fmuls f0,f31,f0; stfs f12,0x5c(1); stfs f0,0x60(1); bl _s80239F50_3; fmr f1,f30; mr 3,31; bl _s80239F50_4; fmr f1,f30; mr 3,31; bl _s80239F50_5; fmr f1,f30; mr 3,31; bl _s80239F50_6; lis 9,-32704; mr 3,31; lfs f1,-1844(9); bl _s80239F50_7; lwz 0,0x108(30); andi. 9,0,128; beq 0f; mr 4,28; addi 3,1,104; bl _s80239F50_8; lis 9,-32704; mr 4,31; lfs f0,-1840(9); addi 3,1,168; stfs f0,0xa0(1); stfs f0,0x98(1); stfs f0,0x9c(1); bl _s80239F50_9; mr 3,31; addi 4,1,104; addi 5,1,168; bl _s80239F50_10; 0:; lfs f12,0x18(29); lfs f0,0x10(29); lfs f13,0x14(29); stfs f0,0x38(1); stfs f13,0x3c(1); stfs f12,0x40(1); lwz 11,-28384(13); lfs f1,0xc(26); lwz 9,0x70(11); lwz 0,0x25c(9); lha 3,0x258(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-28384(13); mr 4,31; li 5,1; lwz 9,0x70(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; lwz 4,-28384(13); mr 3,27; bl _s80239F50_11; 1:; lwz 0,0x114(1); mtspr 8,0; lmw 26,0xe8(1); lfd f30,0x100(1); lfd f31,0x108(1); addi 1,1,272"
extern "C" void _s80239F50_0();
extern "C" void _s80239F50_1();
extern "C" void _s80239F50_2();
extern "C" void _s80239F50_3();
extern "C" void _s80239F50_4();
extern "C" void _s80239F50_5();
extern "C" void _s80239F50_6();
extern "C" void _s80239F50_7();
extern "C" void _s80239F50_8();
extern "C" void _s80239F50_9();
extern "C" void _s80239F50_10();
extern "C" void _s80239F50_11();
extern "C" void f_80239F50() {}
