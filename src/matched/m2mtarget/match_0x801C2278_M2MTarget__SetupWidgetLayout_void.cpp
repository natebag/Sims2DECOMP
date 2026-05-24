// 0x801C2278 M2MTarget::SetupWidgetLayout(void) (1748 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stfd f30,0x98(1); stfd f31,0xa0(1); stmw 24,0x78(1); stw 0,0xac(1); li 0,320; xoris 0,0,32768; lis 31,17200; stw 0,0x74(1); li 11,224; mr 8,10; xoris 11,11,32768; stw 31,0x70(1); lis 9,-32705; lfd f30,0x2398(9); lis 7,-32705; lfd f13,0x70(1); lis 9,-32705; stw 11,0x74(1); addi 27,1,16; lfs f12,0x23a0(7); fsub f13,f13,f30; stw 31,0x70(1); frsp f13,f13; lfs f11,0x23a4(9); lis 11,-32705; lfd f0,0x70(1); mr 25,3; stfs f13,0x8(1); lis 4,-32705; fsub f0,f0,f30; stfs f12,0x10(1); frsp f0,f0; lfs f31,0x23a8(11); stfs f0,0xc(1); addi 4,4,8524; stfs f11,0x4(27); addi 30,1,96; addi 29,1,32; addi 28,1,88; lfs f11,0x10(1); lfs f13,0x14(1); lfs f12,0x8(1); fmuls f11,f11,f31; lfs f0,0xc(1); fmuls f13,f13,f31; fsubs f12,f12,f11; lwz 9,0x80(25); fsubs f0,f0,f13; stfs f12,0x18(1); stfs f0,0x1c(1); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,25,3; blrl; bl _s801C2278_0; stfs f31,0x5c(1); lis 11,-32705; stfs f31,0x58(1); lis 9,-32698; lfs f31,0x23ac(11); li 10,0; lwz 7,0x58(1); addi 9,9,-21552; lwz 8,0x5c(1); stfs f31,0x58(1); stfs f31,0x5c(1); lwz 0,0x58(1); lwz 11,0x5c(1); stw 9,0x54(1); stw 7,0x24(1); stw 8,0x28(1); stw 0,0x4c(1); stw 10,0x20(1); stw 11,0x50(1); bl _s801C2278_1; li 4,16; li 5,16; li 6,0; li 7,0; bl _s801C2278_2; lis 9,-32705; stw 3,0x2c(1); lfs f0,0x23b0(9); addi 3,25,308; stfs f31,0x44(1); stfs f0,0x60(1); stfs f0,0xc(30); stfs f0,0x4(30); stfs f0,0x8(30); stfs f31,0x58(1); stfs f31,0x4(28); bl _s801C2278_3; lis 9,-32705; mr 8,3; lfs f1,0x23b4(9); mr 4,28; mr 5,27; mr 6,30; li 7,0; mr 3,29; bl _s801C2278_4; mr 3,29; bl _s801C2278_5; fmr f31,f1; mr 3,29; bl _s801C2278_6; lwz 0,0x188(25); stfs f1,0x14(1); cmpwi 0,0; ble 0f; xoris 0,0,32768; stw 0,0x74(1); lis 10,-32705; lis 9,-32705; lfs f13,0x23bc(10); stw 31,0x70(1); lfs f12,0x23b8(9); lfd f0,0x70(1); fsub f0,f0,f30; frsp f0,f0; fmadds f0,f0,f12,f13; fadds f31,f31,f0; 0:; lis 9,-32705; lis 11,-32705; lfs f0,0x23c0(9); lfd f12,0x23c8(11); fadds f0,f31,f0; fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 1f; fctiwz f0,f13; stfd f0,0x70(1); lwz 7,0x74(1); b 2f; 1:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x70(1); lwz 7,0x74(1); xoris 7,7,32768; 2:; lwz 0,0x188(25); lis 8,17200; lis 9,-32705; xoris 0,0,32768; lfd f13,0x2398(9); stw 0,0x74(1); lis 9,-32705; lfs f12,0x23b8(9); lis 11,-32705; stw 8,0x70(1); lfd f11,0x23c8(11); lfd f0,0x70(1); stw 7,0x160(25); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; fsubs f0,f31,f0; fmr f1,f0; fcmpu 0,f1,f11; cror 3,2,1; bso 3f; mr 9,10; fctiwz f0,f1; stfd f0,0x70(1); lwz 0,0x74(1); b 4f; 3:; fsub f0,f1,f11; fctiwz f13,f0; stfd f13,0x70(1); lwz 0,0x74(1); xoris 0,0,32768; 4:; addi 30,25,288; stw 0,0x164(25); mr 3,30; mr 31,30; bl _s801C2278_7; lis 4,-32705; mr 3,30; addi 4,4,9092; li 5,0; bl _s801C2278_8; mr 3,30; li 4,104; bl _s801C2278_9; lwz 0,0x160(25); lis 8,17200; lis 11,-32705; stw 0,0x74(1); lis 10,-32705; lfd f12,0x23d0(11); lis 7,-32705; stw 8,0x70(1); lis 11,-32705; lfs f10,0x23d8(10); lis 8,-32705; lfd f0,0x70(1); lfs f11,0x23a8(7); fsub f0,f0,f12; lfs f13,0x23dc(11); frsp f0,f0; lfd f12,0x23c8(8); fadds f0,f0,f10; fmuls f0,f0,f11; fsubs f13,f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 5f; fctiwz f0,f13; stfd f0,0x70(1); lwz 4,0x74(1); b 6f; 5:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x70(1); lwz 4,0x74(1); xoris 4,4,32768; 6:; mr 3,30; bl _s801C2278_10; lwz 0,0x160(25); lis 10,17200; lis 9,-32705; rlwinm 0,0,31,1,31; lfd f13,0x23d0(9); subfic 0,0,224; lis 9,-32705; stw 0,0x74(1); lis 4,-32705; lfs f12,0x23b4(9); addi 4,4,9072; stw 10,0x70(1); mr 3,31; li 5,0; lfd f0,0x70(1); fsub f0,f0,f13; frsp f0,f0; fadds f0,f0,f12; stfs f0,0x1c(1); bl _s801C2278_11; lfs f0,0x18(1); lis 9,-32705; lfd f12,0x23c8(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 7f; fctiwz f0,f13; stfd f0,0x70(1); lwz 4,0x74(1); b 8f; 7:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x70(1); lwz 4,0x74(1); xoris 4,4,32768; 8:; mr 3,31; bl _s801C2278_12; lfs f0,0x1c(1); lis 9,-32705; lfd f12,0x23c8(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 9f; fctiwz f0,f13; stfd f0,0x70(1); lwz 4,0x74(1); b 10f; 9:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x70(1); lwz 4,0x74(1); xoris 4,4,32768; 10:; mr 3,31; bl _s801C2278_13; lfs f0,0x10(1); lis 9,-32705; lfd f12,0x23c8(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 11f; fctiwz f0,f13; stfd f0,0x70(1); lwz 4,0x74(1); b 12f; 11:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x70(1); lwz 4,0x74(1); xoris 4,4,32768; 12:; mr 3,31; bl _s801C2278_14; lwz 0,0x188(25); cmpwi 0,0; ble 17f; lis 9,-32705; lfs f13,0x14(1); lfs f0,0x1c(1); lis 4,-32705; lfs f12,0x23e0(9); addi 4,4,9060; fadds f0,f0,f13; mr 3,31; fadds f31,f0,f12; li 5,0; bl _s801C2278_15; lis 11,-32705; lis 9,-32705; lfs f13,0x23a4(11); lfs f0,0x8(1); lis 11,-32705; lfs f12,0x23d8(9); fsubs f0,f0,f13; lfs f11,0x23e4(11); fsubs f0,f0,f12; lis 9,-32705; lfd f12,0x23c8(9); fadds f0,f0,f11; fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 13f; fctiwz f0,f13; stfd f0,0x70(1); lwz 4,0x74(1); b 14f; 13:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x70(1); lwz 4,0x74(1); xoris 4,4,32768; 14:; mr 3,31; bl _s801C2278_16; lis 9,-32705; fmr f13,f31; lfd f0,0x23c8(9); fcmpu 0,f13,f0; cror 3,2,1; bso 15f; fctiwz f0,f13; stfd f0,0x70(1); lwz 4,0x74(1); b 16f; 15:; fsub f0,f13,f0; fctiwz f13,f0; stfd f13,0x70(1); lwz 4,0x74(1); xoris 4,4,32768; 16:; mr 3,31; bl _s801C2278_17; 17:; lwz 0,0x188(25); li 28,0; cmpw 28,0; bge 19f; lis 9,-32700; lis 11,-32700; addi 24,9,-26104; addi 26,11,-26072; lis 9,-32700; mr 29,31; addi 27,9,-26088; 18:; addi 30,28,48; li 5,0; mr 3,29; mr 4,24; stb 30,0xc(24); addi 28,28,1; bl _s801C2278_18; mr 3,29; li 4,-4; bl _s801C2278_19; mr 3,29; li 4,2; bl _s801C2278_20; li 5,0; mr 3,29; mr 4,26; stb 30,0xa(26); bl _s801C2278_21; mr 3,29; li 4,44; bl _s801C2278_22; mr 3,29; li 4,0; bl _s801C2278_23; li 5,0; mr 3,29; mr 4,27; stb 30,0xd(27); bl _s801C2278_24; mr 3,29; li 4,0; bl _s801C2278_25; mr 3,29; li 4,7; bl _s801C2278_26; mr 3,29; li 4,400; bl _s801C2278_27; lwz 0,0x188(25); cmpw 28,0; blt 18b; 19:; mr 3,31; bl _s801C2278_28; lwz 3,0x20(1); lis 9,-32698; addi 9,9,-21552; stw 9,0x54(1); cmpwi 3,0; beq 22f; mr 11,3; 20:; lwz 30,0x0(11); cmpwi 11,0; beq 21f; lwz 9,0xc(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 21:; mr. 11,30; bne 20b; 22:; lwz 30,0x2c(1); bl _s801C2278_29; mr 4,30; bl _s801C2278_30; lwz 0,0xac(1); mtspr 8,0; lmw 24,0x78(1); lfd f30,0x98(1); lfd f31,0xa0(1); addi 1,1,168"

extern "C" void _s801C2278_0();
extern "C" void _s801C2278_1();
extern "C" void _s801C2278_2();
extern "C" void _s801C2278_3();
extern "C" void _s801C2278_4();
extern "C" void _s801C2278_5();
extern "C" void _s801C2278_6();
extern "C" void _s801C2278_7();
extern "C" void _s801C2278_8();
extern "C" void _s801C2278_9();
extern "C" void _s801C2278_10();
extern "C" void _s801C2278_11();
extern "C" void _s801C2278_12();
extern "C" void _s801C2278_13();
extern "C" void _s801C2278_14();
extern "C" void _s801C2278_15();
extern "C" void _s801C2278_16();
extern "C" void _s801C2278_17();
extern "C" void _s801C2278_18();
extern "C" void _s801C2278_19();
extern "C" void _s801C2278_20();
extern "C" void _s801C2278_21();
extern "C" void _s801C2278_22();
extern "C" void _s801C2278_23();
extern "C" void _s801C2278_24();
extern "C" void _s801C2278_25();
extern "C" void _s801C2278_26();
extern "C" void _s801C2278_27();
extern "C" void _s801C2278_28();
extern "C" void _s801C2278_29();
extern "C" void _s801C2278_30();

struct M2MTarget {
    void SetupWidgetLayout();
};

void M2MTarget::SetupWidgetLayout() {
}
