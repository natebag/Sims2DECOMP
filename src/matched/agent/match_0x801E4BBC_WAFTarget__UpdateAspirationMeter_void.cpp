// 0x801E4BBC WAFTarget::UpdateAspirationMeter(void) (872 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f30,0x20(1); stfd f31,0x28(1); stmw 28,0x10(1); stw 0,0x34(1); mr 29,3; lis 9,-32697; lwz 0,0x94(29); lis 11,-32705; addi 9,9,24012; lfs f1,0x6514(11); addi 9,9,188; rlwinm 0,0,2,0,29; lwzx 11,9,0; cmpwi 11,0; beq 0f; lwz 9,0x4(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; 0:; mr 3,29; bl _s801E4BBC_0; fctiwz f0,f1; mr 11,9; stfd f0,0x8(1); lis 0,17200; lis 10,-32705; lis 8,-32705; lwz 9,0xc(1); lis 7,-32705; lfd f13,0x6518(10); xoris 9,9,32768; lfs f12,0x6520(8); stw 9,0xc(1); stw 0,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f13,f0; fcmpu 0,f13,f12; beq 1f; lis 9,-32705; lfs f0,0x6524(9); fcmpu 0,f13,f0; beq 1f; lfs f0,0x6528(7); fcmpu 0,f13,f0; bne 2f; 1:; lis 9,-32705; lfs f0,0x652c(9); fadds f13,f13,f0; 2:; lis 9,-32705; lis 10,-32705; lis 11,-32705; lfs f11,0x6530(9); lfs f30,0x6520(11); fmr f0,f13; lfs f12,0x6534(10); stfs f13,0x274(29); fcmpu 0,f0,f30; fsubs f12,f12,f11; stfs f13,0x278(29); ble 3f; fmr f0,f30; 3:; fmr f31,f30; fdivs f0,f0,f31; addi 30,29,592; mr 3,30; mr 31,30; fmadds f0,f0,f12,f11; fctiwz f13,f0; stfd f13,0x8(1); lwz 28,0xc(1); bl _s801E4BBC_1; lwz 5,0x94(29); lis 4,-32705; addi 4,4,25412; mr 3,30; bl _s801E4BBC_2; mr 4,28; mr 3,30; bl _s801E4BBC_3; lwz 5,0x94(29); lis 4,-32705; addi 4,4,25436; mr 3,30; bl _s801E4BBC_4; mr 4,28; mr 3,30; bl _s801E4BBC_5; mr 3,30; bl _s801E4BBC_6; lis 9,-32705; lis 11,-32705; lfs f0,0x278(29); lfs f11,0x6538(9); lfs f12,0x653c(11); fcmpu 0,f0,f31; fsubs f12,f12,f11; bge 4f; mr 3,31; bl _s801E4BBC_7; lwz 5,0x94(29); lis 4,-32705; addi 4,4,25460; mr 3,31; bl _s801E4BBC_8; li 4,240; mr 3,31; bl _s801E4BBC_9; lwz 5,0x94(29); lis 4,-32705; addi 4,4,25480; mr 3,31; bl _s801E4BBC_10; mr 3,31; li 4,240; bl _s801E4BBC_11; mr 3,31; bl _s801E4BBC_12; b 5f; 4:; fsubs f0,f0,f30; fdivs f0,f0,f30; mr 3,31; fmadds f0,f0,f12,f11; fctiwz f13,f0; stfd f13,0x8(1); lwz 28,0xc(1); bl _s801E4BBC_13; lwz 5,0x94(29); lis 4,-32705; addi 4,4,25460; mr 3,31; bl _s801E4BBC_14; mr 4,28; mr 3,31; bl _s801E4BBC_15; lwz 5,0x94(29); lis 4,-32705; addi 4,4,25480; mr 3,31; bl _s801E4BBC_16; mr 3,31; mr 4,28; bl _s801E4BBC_17; mr 3,31; bl _s801E4BBC_18; 5:; lis 9,-32705; lfs f13,0x278(29); lfs f0,0x6524(9); li 30,0; ori 30,30,65280; fcmpu 0,f13,f0; blt 6f; lis 9,-32705; lis 30,255; lfs f0,0x6528(9); ori 30,30,65535; fcmpu 0,f13,f0; bge 6f; li 30,0; ori 30,30,65280; 6:; lwz 8,0x94(29); lis 4,-32705; lis 28,-32705; li 5,1; li 6,0; addi 7,28,-8764; addi 4,4,25584; mr 3,31; bl _s801E4BBC_19; mr 4,30; mr 3,31; bl _s801E4BBC_20; mr 3,31; bl _s801E4BBC_21; lis 9,-32705; lfs f13,0x278(29); lfs f0,0x6528(9); fcmpu 0,f13,f0; cror 3,2,1; bns 7f; lwz 8,0x94(29); lis 4,-32705; addi 4,4,25520; addi 7,28,-8764; mr 3,31; li 5,1; li 6,0; bl _s801E4BBC_22; mr 3,31; li 4,255; bl _s801E4BBC_23; mr 3,31; bl _s801E4BBC_24; b 8f; 7:; lwz 8,0x94(29); lis 4,-32705; addi 4,4,25520; addi 7,28,-8764; mr 3,31; li 5,1; li 6,0; bl _s801E4BBC_25; mr 3,31; li 4,0; bl _s801E4BBC_26; mr 3,31; bl _s801E4BBC_27; 8:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x10(1); lfd f30,0x20(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s801E4BBC_0();
extern "C" void _s801E4BBC_1();
extern "C" void _s801E4BBC_2();
extern "C" void _s801E4BBC_3();
extern "C" void _s801E4BBC_4();
extern "C" void _s801E4BBC_5();
extern "C" void _s801E4BBC_6();
extern "C" void _s801E4BBC_7();
extern "C" void _s801E4BBC_8();
extern "C" void _s801E4BBC_9();
extern "C" void _s801E4BBC_10();
extern "C" void _s801E4BBC_11();
extern "C" void _s801E4BBC_12();
extern "C" void _s801E4BBC_13();
extern "C" void _s801E4BBC_14();
extern "C" void _s801E4BBC_15();
extern "C" void _s801E4BBC_16();
extern "C" void _s801E4BBC_17();
extern "C" void _s801E4BBC_18();
extern "C" void _s801E4BBC_19();
extern "C" void _s801E4BBC_20();
extern "C" void _s801E4BBC_21();
extern "C" void _s801E4BBC_22();
extern "C" void _s801E4BBC_23();
extern "C" void _s801E4BBC_24();
extern "C" void _s801E4BBC_25();
extern "C" void _s801E4BBC_26();
extern "C" void _s801E4BBC_27();
extern "C" void f_801E4BBC() {}
