// 0x801E3278 WAFTarget::Update(void) (764 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 27,0x24(1); stw 0,0x44(1); mr 31,3; lwz 0,0x84(31); cmpwi 0,0; beq 10f; lwz 0,0x24c(31); cmpwi 0,0; bne 0f; lwz 0,0x94(31); lis 9,-32697; addi 9,9,24012; rlwinm 11,0,2,0,29; addi 9,9,188; lwzx 0,9,11; cmpwi 0,0; beq 0f; li 0,1; stw 0,0x24c(31); lwzx 11,9,11; lwz 9,0x4(11); lha 3,0x3b0(9); lwz 0,0x3b4(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x280(31); cmpwi 0,0; beq 1f; li 0,0; mr 3,31; stw 0,0x280(31); bl _s801E3278_0; 1:; lfs f0,0x248(31); lis 30,-32697; lfs f13,-26800(13); lwz 0,0x8c(31); fadds f0,f0,f13; stfs f0,0x248(31); cmpwi 0,0; bne 7f; lwz 0,0x90(31); cmpwi 0,0; beq 6f; lwz 0,0x88(31); cmpwi 0,0; bne 7f; addi 3,1,8; lis 29,-32705; bl _s801E3278_1; addi 3,1,8; bl _s801E3278_2; lwz 5,0x94(31); addi 3,1,8; addi 4,29,25580; bl _s801E3278_3; addi 3,1,8; li 4,1; bl _s801E3278_4; lwz 0,0x94(31); cmpwi 0,0; beq 2f; addi 3,1,8; li 4,320; bl _s801E3278_5; 2:; addi 9,30,23428; lwz 0,0xec(9); cmpwi 0,0; beq 3f; lwz 4,-28816(13); addi 3,1,8; lwz 5,0x94(31); bl _s801E3278_6; addi 3,1,8; li 4,0; bl _s801E3278_7; 3:; addi 3,1,8; addi 30,31,592; bl _s801E3278_8; li 27,0; lwz 7,-29232(13); addi 4,29,25580; lwz 8,0x94(31); li 5,250; li 6,0; mr 3,30; bl _s801E3278_9; addi 28,31,192; mr 3,30; li 4,255; bl _s801E3278_10; li 29,0; mr 3,30; bl _s801E3278_11; lis 9,-32705; lfs f31,0x6414(9); 4:; lfsx f0,29,28; fcmpu 0,f0,f31; ble 5f; stfsx f31,29,28; mr 3,31; mr 4,27; bl _s801E3278_12; 5:; addi 27,27,1; addi 29,29,60; cmpwi 27,6; ble 4b; li 0,1; addi 3,1,8; stw 0,0x88(31); li 4,2; stw 0,0x8c(31); bl _s801E3278_13; b 7f; 6:; lwz 0,0x88(31); cmpwi 0,0; beq 7f; addi 30,31,592; lwz 7,-29220(13); lwz 8,0x94(31); lis 4,-32705; li 5,250; li 6,0; addi 4,4,25580; mr 3,30; bl _s801E3278_14; mr 3,30; li 4,0; bl _s801E3278_15; mr 3,30; bl _s801E3278_16; li 0,1; stw 0,0x8c(31); 7:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; bne 10f; lwz 9,0x9c(31); lwz 0,0xa0(31); cmpw 9,0; beq 10f; lwz 0,0x98(31); cmpwi 0,0; bne 10f; cmpwi 9,0; beq 8f; addi 30,31,592; lis 29,-32705; lwz 6,0x94(31); mr 3,30; addi 4,29,25552; li 5,1; bl _s801E3278_17; lwz 7,-29256(13); addi 4,29,25552; lwz 8,0x94(31); mr 3,30; li 5,250; li 6,0; bl _s801E3278_18; mr 3,30; li 4,255; bl _s801E3278_19; mr 3,30; bl _s801E3278_20; b 9f; 8:; addi 30,31,592; lwz 7,-29244(13); lwz 8,0x94(31); lis 4,-32705; addi 4,4,25552; mr 3,30; li 5,250; li 6,0; bl _s801E3278_21; mr 3,30; li 4,0; bl _s801E3278_22; mr 3,30; bl _s801E3278_23; 9:; li 0,1; stw 0,0x98(31); 10:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x24(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s801E3278_0();
extern "C" void _s801E3278_1();
extern "C" void _s801E3278_2();
extern "C" void _s801E3278_3();
extern "C" void _s801E3278_4();
extern "C" void _s801E3278_5();
extern "C" void _s801E3278_6();
extern "C" void _s801E3278_7();
extern "C" void _s801E3278_8();
extern "C" void _s801E3278_9();
extern "C" void _s801E3278_10();
extern "C" void _s801E3278_11();
extern "C" void _s801E3278_12();
extern "C" void _s801E3278_13();
extern "C" void _s801E3278_14();
extern "C" void _s801E3278_15();
extern "C" void _s801E3278_16();
extern "C" void _s801E3278_17();
extern "C" void _s801E3278_18();
extern "C" void _s801E3278_19();
extern "C" void _s801E3278_20();
extern "C" void _s801E3278_21();
extern "C" void _s801E3278_22();
extern "C" void _s801E3278_23();
extern "C" void f_801E3278() {}
