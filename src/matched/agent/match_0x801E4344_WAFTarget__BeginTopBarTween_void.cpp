// 0x801E4344 WAFTarget::BeginTopBarTween(void) (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f30,0x20(1); stfd f31,0x28(1); stmw 28,0x10(1); stw 0,0x34(1); mr 31,3; addi 30,31,592; mr 3,30; bl _s801E4344_0; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25584; mr 3,30; bl _s801E4344_1; li 4,1; mr 3,30; bl _s801E4344_2; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25500; mr 3,30; bl _s801E4344_3; li 4,0; mr 3,30; bl _s801E4344_4; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25412; mr 3,30; bl _s801E4344_5; li 4,-40; mr 3,30; bl _s801E4344_6; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25436; mr 3,30; bl _s801E4344_7; li 4,-40; mr 3,30; bl _s801E4344_8; mr 3,30; bl _s801E4344_9; lis 9,-32705; lis 11,-32705; lfs f30,0x64a4(9); mr 3,31; lfs f31,0x64a8(11); fsubs f31,f31,f30; bl _s801E4344_10; lis 9,-32705; lfs f13,0x64ac(9); fmr f10,f1; mr 10,7; fctiwz f12,f10; fsubs f0,f1,f13; mr 8,7; fdivs f0,f0,f13; lis 0,17200; lis 11,-32705; lfs f8,0x278(31); lfd f13,0x64b0(11); lis 9,-32705; lfs f9,0x64b8(9); stfs f1,0x27c(31); fmadds f0,f0,f31,f30; fctiwz f11,f0; stfd f11,0x8(1); lwz 28,0xc(1); stfd f12,0x8(1); lwz 10,0xc(1); xoris 10,10,32768; stw 10,0xc(1); stw 0,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fsubs f0,f8,f0; fcmpu 0,f0,f9; cror 3,2,1; bns 0f; mr 9,7; b 1f; 0:; fneg f0,f0; 1:; fctiwz f13,f0; stfd f13,0x8(1); lwz 30,0xc(1); mulli 30,30,6; addi 29,31,592; lwz 7,-29184(13); lis 4,-32705; lwz 8,0x94(31); li 6,0; addi 4,4,25460; mr 3,29; addi 30,30,33; mr 5,30; bl _s801E4344_11; mr 4,28; mr 3,29; bl _s801E4344_12; mr 3,29; bl _s801E4344_13; lwz 8,0x94(31); lis 4,-32705; lis 7,-32705; mr 5,30; addi 7,7,-8764; li 6,0; addi 4,4,25480; mr 3,29; bl _s801E4344_14; mr 4,28; mr 3,29; bl _s801E4344_15; mr 3,29; bl _s801E4344_16; li 9,1; li 0,0; stw 0,0x268(31); stw 9,0x264(31); lwz 0,0x34(1); mtspr 8,0; lmw 28,0x10(1); lfd f30,0x20(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s801E4344_0();
extern "C" void _s801E4344_1();
extern "C" void _s801E4344_2();
extern "C" void _s801E4344_3();
extern "C" void _s801E4344_4();
extern "C" void _s801E4344_5();
extern "C" void _s801E4344_6();
extern "C" void _s801E4344_7();
extern "C" void _s801E4344_8();
extern "C" void _s801E4344_9();
extern "C" void _s801E4344_10();
extern "C" void _s801E4344_11();
extern "C" void _s801E4344_12();
extern "C" void _s801E4344_13();
extern "C" void _s801E4344_14();
extern "C" void _s801E4344_15();
extern "C" void _s801E4344_16();
extern "C" void f_801E4344() {}
