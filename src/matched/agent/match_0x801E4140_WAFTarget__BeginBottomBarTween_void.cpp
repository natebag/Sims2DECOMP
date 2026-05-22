// 0x801E4140 WAFTarget::BeginBottomBarTween(void) (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; lis 29,-32705; addi 30,31,592; lwz 8,0x94(31); lis 7,-32705; li 6,0; addi 7,7,-8764; li 5,1; mr 3,30; addi 4,29,25584; bl _s801E4140_0; li 4,0; mr 3,30; ori 4,4,65280; bl _s801E4140_1; mr 3,30; bl _s801E4140_2; mr 3,30; bl _s801E4140_3; lwz 5,0x94(31); addi 4,29,25584; mr 3,30; bl _s801E4140_4; li 4,0; mr 3,30; bl _s801E4140_5; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25500; mr 3,30; bl _s801E4140_6; li 4,1; mr 3,30; bl _s801E4140_7; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25460; mr 3,30; bl _s801E4140_8; li 4,240; mr 3,30; bl _s801E4140_9; lwz 5,0x94(31); lis 4,-32705; addi 4,4,25480; mr 3,30; bl _s801E4140_10; mr 3,30; li 4,240; bl _s801E4140_11; mr 3,30; bl _s801E4140_12; lis 11,-32705; lis 10,-32705; lis 9,-32705; lfs f9,0x6494(11); lfs f13,0x649c(9); lfs f0,0x6498(10); lfs f10,0x274(31); fsubs f8,f0,f9; fcmpu 0,f10,f13; ble 0f; fmr f10,f13; 0:; stfs f10,0x27c(31); lis 9,-32705; lfs f0,0x649c(9); lfs f12,0x278(31); lis 9,-32705; fdivs f0,f10,f0; lfs f11,0x64a0(9); fmadds f0,f8,f0,f9; fctiwz f13,f0; stfd f13,0x8(1); fsubs f12,f12,f10; fcmpu 0,f12,f11; lwz 28,0xc(1); cror 3,2,1; bns 1f; fmr f0,f12; mr 9,11; b 2f; 1:; fneg f0,f12; 2:; fctiwz f13,f0; stfd f13,0x8(1); lwz 30,0xc(1); mulli 30,30,6; addi 29,31,592; lwz 8,0x94(31); lis 4,-32705; lis 7,-32705; li 6,0; addi 7,7,23664; addi 4,4,25412; addi 30,30,33; mr 3,29; mr 5,30; bl _s801E4140_13; mr 4,28; mr 3,29; bl _s801E4140_14; mr 3,29; bl _s801E4140_15; lwz 8,0x94(31); lis 4,-32705; lis 7,-32705; mr 5,30; addi 7,7,-8764; li 6,0; addi 4,4,25436; mr 3,29; bl _s801E4140_16; mr 4,28; mr 3,29; bl _s801E4140_17; mr 3,29; bl _s801E4140_18; li 9,1; li 0,0; stw 0,0x268(31); stw 9,0x264(31); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801E4140_0();
extern "C" void _s801E4140_1();
extern "C" void _s801E4140_2();
extern "C" void _s801E4140_3();
extern "C" void _s801E4140_4();
extern "C" void _s801E4140_5();
extern "C" void _s801E4140_6();
extern "C" void _s801E4140_7();
extern "C" void _s801E4140_8();
extern "C" void _s801E4140_9();
extern "C" void _s801E4140_10();
extern "C" void _s801E4140_11();
extern "C" void _s801E4140_12();
extern "C" void _s801E4140_13();
extern "C" void _s801E4140_14();
extern "C" void _s801E4140_15();
extern "C" void _s801E4140_16();
extern "C" void _s801E4140_17();
extern "C" void _s801E4140_18();
extern "C" void f_801E4140() {}
