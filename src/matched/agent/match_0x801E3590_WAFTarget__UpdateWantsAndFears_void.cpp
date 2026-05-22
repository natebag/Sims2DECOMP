// 0x801E3590 WAFTarget::UpdateWantsAndFears(void) (872 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stfd f29,0x30(1); stfd f30,0x38(1); stfd f31,0x40(1); stmw 24,0x10(1); stw 0,0x4c(1); lwz 11,-21496(13); mr 31,3; cmpwi 11,0; beq 13f; lwz 9,0x0(11); lha 3,0x60(9); lwz 0,0x64(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 13f; lwz 0,0x88(31); lis 9,-32705; lfs f30,0x643c(9); cmpwi 0,0; beq 4f; lis 9,-32697; lwz 0,0x94(31); addi 9,9,24012; lwz 10,0x284(31); rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 8,9,0; lis 11,-32705; lfs f1,0x6440(11); li 30,0; cmpw 10,8; beq 0f; li 30,1; 0:; stw 8,0x284(31); cmpwi 8,0; beq 1f; lwz 9,0x4(8); lha 3,0x88(9); lwz 0,0x8c(9); add 3,8,3; mtspr 8,0; blrl; 1:; cmpwi 30,1; bne 2f; lwz 0,0x284(31); cmpwi 0,0; beq 2f; mr 3,31; bl _s801E3590_0; b 3f; 2:; mr 3,31; bl _s801E3590_1; fctiwz f0,f1; mr 3,31; stfd f0,0x8(1); lwz 4,0xc(1); bl _s801E3590_2; 3:; lfs f13,0x278(31); lfs f0,0x274(31); fcmpu 0,f13,f0; beq 4f; lwz 0,0x264(31); cmpwi 0,0; bne 4f; lwz 0,0x270(31); cmpwi 0,0; bne 4f; mr 3,31; bl _s801E3590_3; 4:; lwz 0,0x84(31); cmpwi 0,0; beq 13f; lis 9,-32705; lis 11,-32705; lfs f31,0x6440(9); li 25,0; lfs f29,0x6444(11); addi 24,31,184; addi 29,31,592; addi 30,31,180; li 28,0; 5:; lfsx f0,28,24; fcmpu 0,f0,f31; ble 8f; fsubs f0,f0,f30; fcmpu 0,f0,f31; stfsx f0,28,24; cror 3,2,0; bns 12f; stfs f29,0x8(30); mr 3,29; addi 27,31,200; addi 26,31,204; bl _s801E3590_4; addi 9,31,196; lwz 5,0x94(31); lwzx 4,9,28; mr 3,29; bl _s801E3590_5; lis 4,-32705; mr 3,29; addi 4,4,25624; bl _s801E3590_6; lwz 5,0x94(31); mr 3,29; lwzx 4,27,28; bl _s801E3590_7; mr 3,29; li 4,0; bl _s801E3590_8; lwz 5,0x94(31); mr 3,29; lwz 4,0x18(30); bl _s801E3590_9; mr 3,29; li 4,0; bl _s801E3590_10; mr 3,29; bl _s801E3590_11; lwz 0,-31536(13); cmpwi 0,0; bne 6f; li 3,120; bl _s801E3590_12; bl _s801E3590_13; stw 3,-31536(13); 6:; lwz 3,-31536(13); lis 4,14989; ori 4,4,58004; bl _s801E3590_14; lwz 0,0x0(31); lwzx 4,27,28; lwz 5,-4(30); cmpwi 0,0; beq 7f; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 6,0x7c(31); li 7,0; bl _s801E3590_15; 7:; lwz 0,0x0(31); lwzx 4,26,28; cmpwi 0,0; lwz 5,0x0(30); beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lwz 6,0x7c(31); li 7,0; bl _s801E3590_16; b 12f; 8:; addi 9,31,188; lfsx f0,9,28; fcmpu 0,f0,f31; ble 9f; fsubs f0,f0,f30; stfsx f0,9,28; fcmpu 0,f0,f31; cror 3,2,0; bns 12f; mr 3,31; mr 4,25; bl _s801E3590_17; b 12f; 9:; addi 9,31,192; lfsx f0,9,28; fcmpu 0,f0,f31; ble 12f; fsubs f0,f0,f30; stfsx f0,9,28; fcmpu 0,f0,f31; cror 3,2,0; bns 12f; lwz 0,0x0(31); addi 9,31,200; lwzx 4,9,28; cmpwi 0,0; lwz 5,-4(30); beq 10f; lwz 3,0x1c(31); cmpwi 3,0; beq 10f; lwz 6,0x7c(31); li 7,0; bl _s801E3590_18; 10:; lwz 0,0x0(31); lwz 4,0x18(30); cmpwi 0,0; lwz 5,0x0(30); beq 11f; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 6,0x7c(31); li 7,0; bl _s801E3590_19; 11:; mr 3,31; mr 4,25; bl _s801E3590_20; 12:; addi 25,25,1; addi 30,30,60; addi 28,28,60; cmpwi 25,6; ble 5b; 13:; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x10(1); lfd f29,0x30(1); lfd f30,0x38(1); lfd f31,0x40(1); addi 1,1,72"
extern "C" void _s801E3590_0();
extern "C" void _s801E3590_1();
extern "C" void _s801E3590_2();
extern "C" void _s801E3590_3();
extern "C" void _s801E3590_4();
extern "C" void _s801E3590_5();
extern "C" void _s801E3590_6();
extern "C" void _s801E3590_7();
extern "C" void _s801E3590_8();
extern "C" void _s801E3590_9();
extern "C" void _s801E3590_10();
extern "C" void _s801E3590_11();
extern "C" void _s801E3590_12();
extern "C" void _s801E3590_13();
extern "C" void _s801E3590_14();
extern "C" void _s801E3590_15();
extern "C" void _s801E3590_16();
extern "C" void _s801E3590_17();
extern "C" void _s801E3590_18();
extern "C" void _s801E3590_19();
extern "C" void _s801E3590_20();
extern "C" void f_801E3590() {}
