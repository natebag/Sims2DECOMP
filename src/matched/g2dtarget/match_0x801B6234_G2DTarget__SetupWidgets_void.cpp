// 0x801B6234 G2DTarget::SetupWidgets(void) (1752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); mr 30,3; addi 31,30,312; mr 3,31; bl _s801B6234_0; lis 4,-32705; li 5,0; addi 4,4,3552; mr 3,31; bl _s801B6234_1; li 4,144; mr 3,31; bl _s801B6234_2; lwz 4,0xd4(30); mr 3,31; addi 4,4,32; rlwinm 4,4,31,1,31; subfic 4,4,224; bl _s801B6234_3; lis 4,-32705; mr 3,31; addi 4,4,3572; li 5,0; bl _s801B6234_4; lwz 0,0xa4(30); cmpwi 0,0; ble 0f; mr 3,31; li 4,1; bl _s801B6234_5; b 1f; 0:; mr 3,31; li 4,0; bl _s801B6234_6; 1:; addi 3,30,312; lis 4,-32705; mr 31,3; addi 4,4,3584; li 5,0; bl _s801B6234_7; lwz 0,0xa4(30); cmpwi 0,1; ble 2f; mr 3,31; li 4,1; bl _s801B6234_8; b 3f; 2:; mr 3,31; li 4,0; bl _s801B6234_9; 3:; lis 4,-32705; mr 3,31; addi 4,4,3596; li 5,0; bl _s801B6234_10; lwz 0,0xa4(30); cmpwi 0,2; ble 4f; mr 3,31; li 4,1; bl _s801B6234_11; b 5f; 4:; mr 3,31; li 4,0; bl _s801B6234_12; 5:; lwz 0,0xd4(30); lis 10,17200; lis 9,-32705; rlwinm 0,0,31,1,31; lfd f13,0xe48(9); subfic 0,0,224; lis 9,-32705; stw 0,0xc(1); lis 4,-32705; lfs f12,0xe50(9); addi 4,4,3608; stw 10,0x8(1); mr 3,31; li 5,0; lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fadds f31,f0,f12; bl _s801B6234_13; lfs f0,0xf4(30); lis 9,-32705; lfd f12,0xe58(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 6f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 7f; 6:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 7:; mr 3,31; bl _s801B6234_14; lis 9,-32705; fmr f13,f31; lfd f0,0xe58(9); fcmpu 0,f13,f0; cror 3,2,1; bso 8f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 9f; 8:; fsub f0,f13,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 9:; mr 3,31; bl _s801B6234_15; mr 3,31; li 4,288; bl _s801B6234_16; addi 3,30,256; bl _s801B6234_17; cmpwi 3,0; beq 10f; lis 9,-32705; lfs f0,0xe60(9); fadds f0,f31,f0; stfs f0,0xf8(30); b 11f; 10:; stfs f31,0xf8(30); 11:; lis 4,-32705; mr 3,31; addi 4,4,3620; li 5,0; bl _s801B6234_18; lis 9,-32705; lfs f13,0xf4(30); lfs f0,0xec(30); lis 11,-32705; lfs f12,0xe64(9); lfd f11,0xe58(11); fmadds f0,f0,f12,f13; fmr f13,f0; fcmpu 0,f13,f11; cror 3,2,1; bso 12f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 13f; 12:; fsub f0,f13,f11; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 13:; mr 3,31; bl _s801B6234_19; lis 9,-32705; lfs f13,0xf8(30); lfs f0,0xf0(30); lis 11,-32705; lfs f12,0xe64(9); lfd f11,0xe58(11); fmadds f0,f0,f12,f13; fmr f13,f0; fcmpu 0,f13,f11; cror 3,2,1; bso 14f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 15f; 14:; fsub f0,f13,f11; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 15:; mr 3,31; bl _s801B6234_20; lfs f0,0xec(30); lis 9,-32705; lfd f12,0xe58(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 16f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 17f; 16:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 17:; mr 3,31; bl _s801B6234_21; lfs f0,0xf0(30); lis 9,-32705; lfd f12,0xe58(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 18f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 19f; 18:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 19:; mr 3,31; bl _s801B6234_22; lis 4,-32705; mr 3,31; addi 4,4,3632; li 5,0; bl _s801B6234_23; lis 9,-32705; lfs f12,0xec(30); lfs f0,0xe68(9); fcmpu 0,f12,f0; ble 22f; lfs f0,0xf4(30); lis 9,-32705; lfs f13,0xe6c(9); lis 11,-32705; fadds f0,f0,f12; lfd f12,0xe58(11); fadds f0,f0,f13; fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 20f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 21f; 20:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 21:; mr 3,31; bl _s801B6234_24; b 25f; 22:; lfs f0,0xf4(30); lis 9,-32705; lfd f12,0xe58(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 23f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 24f; 23:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 24:; mr 3,31; bl _s801B6234_25; 25:; lfs f0,0xf8(30); lis 9,-32705; lfd f12,0xe58(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 26f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 27f; 26:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 27:; mr 3,31; bl _s801B6234_26; lfs f0,0xe4(30); lis 9,-32705; lfd f12,0xe58(9); fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 28f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 29f; 28:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 29:; mr 3,31; bl _s801B6234_27; lwz 0,0xa4(30); cmpwi 0,0; ble 41f; lfs f11,0xf0(30); lfs f12,0xe8(30); fcmpu 0,f11,f12; ble 30f; lfs f0,0xf8(30); lis 9,-32705; lfs f13,0xe70(9); fadds f0,f0,f11; b 31f; 30:; lfs f0,0xf8(30); lis 9,-32705; lfs f13,0xe70(9); fadds f0,f0,f12; 31:; fadds f31,f0,f13; lis 4,-32705; mr 3,31; addi 4,4,3644; li 5,0; bl _s801B6234_28; lis 11,-32705; lis 9,-32705; lfs f13,0xe74(11); lfs f0,0xdc(30); lis 11,-32705; lfs f12,0xe78(9); fsubs f0,f0,f13; lfs f11,0xe7c(11); fsubs f0,f0,f12; lis 9,-32705; lfd f12,0xe58(9); fadds f0,f0,f11; fmr f13,f0; fcmpu 0,f13,f12; cror 3,2,1; bso 32f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 33f; 32:; fsub f0,f13,f12; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 33:; mr 3,31; bl _s801B6234_29; lis 9,-32705; fmr f13,f31; lfd f0,0xe58(9); fcmpu 0,f13,f0; cror 3,2,1; bso 34f; fctiwz f0,f13; stfd f0,0x8(1); lwz 4,0xc(1); b 35f; 34:; fsub f0,f13,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 4,0xc(1); xoris 4,4,32768; 35:; mr 3,31; bl _s801B6234_30; lis 4,-32705; mr 3,31; addi 4,4,3256; li 5,0; bl _s801B6234_31; lwz 0,0xb0(30); cmpwi 0,0; bne 36f; mr 3,31; li 4,-1; bl _s801B6234_32; b 37f; 36:; lis 4,1286; mr 3,31; ori 4,4,29183; bl _s801B6234_33; 37:; lwz 0,0xa4(30); cmpwi 0,1; ble 39f; lis 4,-32705; mr 3,31; addi 4,4,3268; li 5,0; bl _s801B6234_34; lwz 0,0xb0(30); cmpwi 0,1; bne 38f; mr 3,31; li 4,-1; bl _s801B6234_35; b 39f; 38:; lis 4,1286; mr 3,31; ori 4,4,29183; bl _s801B6234_36; 39:; lwz 0,0xa4(30); cmpwi 0,2; ble 41f; lis 4,-32705; mr 3,31; addi 4,4,3280; li 5,0; bl _s801B6234_37; lwz 0,0xb0(30); cmpwi 0,2; bne 40f; mr 3,31; li 4,-1; bl _s801B6234_38; b 41f; 40:; lis 4,1286; mr 3,31; ori 4,4,29183; bl _s801B6234_39; 41:; mr 3,31; bl _s801B6234_40; mr 3,30; bl _s801B6234_41; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"

extern "C" void _s801B6234_0();
extern "C" void _s801B6234_1();
extern "C" void _s801B6234_2();
extern "C" void _s801B6234_3();
extern "C" void _s801B6234_4();
extern "C" void _s801B6234_5();
extern "C" void _s801B6234_6();
extern "C" void _s801B6234_7();
extern "C" void _s801B6234_8();
extern "C" void _s801B6234_9();
extern "C" void _s801B6234_10();
extern "C" void _s801B6234_11();
extern "C" void _s801B6234_12();
extern "C" void _s801B6234_13();
extern "C" void _s801B6234_14();
extern "C" void _s801B6234_15();
extern "C" void _s801B6234_16();
extern "C" void _s801B6234_17();
extern "C" void _s801B6234_18();
extern "C" void _s801B6234_19();
extern "C" void _s801B6234_20();
extern "C" void _s801B6234_21();
extern "C" void _s801B6234_22();
extern "C" void _s801B6234_23();
extern "C" void _s801B6234_24();
extern "C" void _s801B6234_25();
extern "C" void _s801B6234_26();
extern "C" void _s801B6234_27();
extern "C" void _s801B6234_28();
extern "C" void _s801B6234_29();
extern "C" void _s801B6234_30();
extern "C" void _s801B6234_31();
extern "C" void _s801B6234_32();
extern "C" void _s801B6234_33();
extern "C" void _s801B6234_34();
extern "C" void _s801B6234_35();
extern "C" void _s801B6234_36();
extern "C" void _s801B6234_37();
extern "C" void _s801B6234_38();
extern "C" void _s801B6234_39();
extern "C" void _s801B6234_40();
extern "C" void _s801B6234_41();

struct G2DTarget {
    void SetupWidgets();
};

void G2DTarget::SetupWidgets() {
}
