// 0x80224BB8 InteractorModule::WallPainter::ValidateWallSegment(void) (1164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-248(1); mfspr 0,8; stmw 21,0xcc(1); stw 0,0xfc(1); mr 31,3; li 25,0; lwz 11,0x9c(31); addi 10,31,156; lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; stw 11,0x4(10); li 0,0; stw 0,0x98(31); lwz 9,0x88(31); andi. 0,9,16; beq 3f; mr 3,31; bl _s80224BB8_0; lwz 9,0x98(31); cmpwi 9,0; beq 25f; lwz 0,0x88(31); andi. 11,0,8; bne 2f; lwz 0,0x94(31); cmpw 9,0; ble 2f; cmpwi 0,-1; bne 25f; 2:; li 25,1; b 25f; 3:; lfs f0,0x60(31); addi 9,31,96; lfs f12,0x20(31); addi 11,31,32; stfs f0,0x18(1); addi 4,1,24; addi 5,1,40; addi 30,1,8; lfs f0,0x4(9); mr 27,4; lwz 3,0x4(31); mr 28,5; stfs f0,0x1c(1); li 6,0; mr 29,30; lfs f13,0x8(9); stfs f12,0x28(1); stfs f13,0x20(1); lfs f0,0x4(11); stfs f0,0x2c(1); lfs f13,0x8(11); stfs f13,0x30(1); bl _s80224BB8_1; lfs f11,0x18(1); addi 9,1,56; lfs f12,0x28(1); subfic 0,3,0; adde 23,0,3; lfs f13,0x2c(1); lis 8,-32704; fsubs f12,f12,f11; lfs f10,0x1c(1); lfs f0,0x30(1); mr 26,9; lfs f11,0x20(1); fsubs f13,f13,f10; stfs f12,0x38(1); fsubs f0,f0,f11; stfs f13,0x3c(1); stfs f0,0x40(1); lwz 11,0x38(1); lwz 10,0x4(9); lwz 0,0x8(9); stw 11,0x8(1); lfs f13,-7292(8); stw 0,0x8(30); stw 10,0x4(30); stfs f13,0x8(30); lfs f0,0x8(1); fcmpu 0,f0,f13; bne 4f; lfs f0,0x4(30); fcmpu 0,f0,f13; beq 5f; 4:; mr 3,30; mr 4,30; bl _s80224BB8_2; 5:; lwz 0,0x0(30); lis 9,-32704; lwz 11,0x8(30); lwz 10,0x4(30); stw 0,0x8(1); lfs f12,-7292(9); lfs f13,0x8(1); stw 11,0x8(29); stw 10,0x4(29); fcmpu 0,f13,f12; cror 3,2,1; bso 6f; fneg f13,f13; 6:; lfs f0,0xc(1); fmr f11,f0; fcmpu 0,f0,f12; cror 3,2,1; bns 8f; fsubs f0,f13,f11; b 9f; 7:; li 25,0; b 21f; 8:; fadds f0,f13,f11; 9:; lis 9,-32704; fmr f13,f0; lfs f12,-7292(9); fcmpu 0,f13,f12; cror 3,2,1; bso 10f; fneg f13,f13; 10:; lfs f0,0x8(1); fcmpu 0,f0,f12; beq 11f; fcmpu 0,f11,f12; beq 11f; lis 9,-32704; lfs f0,-7288(9); fcmpu 0,f13,f0; bge 12f; 11:; li 25,1; 12:; cmpwi 25,1; bne 26f; addi 3,1,72; mr 22,3; bl _s80224BB8_3; lfs f13,0x28(1); li 0,0; lfs f0,0x18(1); lwz 29,-21488(13); fcmpu 0,f13,f0; bne 13f; lfs f13,0x2c(1); lfs f0,0x1c(1); fcmpu 0,f13,f0; bne 13f; lfs f13,0x30(1); lfs f0,0x20(1); fcmpu 0,f13,f0; beq 14f; 13:; li 0,1; 14:; cmpwi 0,0; beq 23f; addi 30,1,128; mr 3,26; bl _s80224BB8_4; mr 24,30; mr 3,30; bl _s80224BB8_5; mr 6,30; mr 5,26; mr 3,27; mr 4,28; bl _s80224BB8_6; mr 4,30; mr 3,26; bl _s80224BB8_7; mr 4,30; mr 3,26; bl _s80224BB8_8; mr 30,3; cmpwi 30,8; beq 22f; mr 27,22; bl _s80224BB8_9; li 0,0; stw 3,0xc0(1); stw 0,0xc4(1); mr 4,23; addi 28,1,136; addi 3,1,192; addi 5,1,196; mr 6,26; mr 7,24; bl _s80224BB8_10; rlwinm 0,30,1,0,30; lis 9,-32696; add 23,0,30; addi 21,9,24096; b 20f; 15:; lwz 9,0x0(29); mr 5,26; mr 3,28; lha 4,0xa8(9); lwz 0,0xac(9); add 4,29,4; mtspr 8,0; blrl; mr 4,28; mr 3,27; bl _s80224BB8_11; mr 3,28; li 4,2; bl _s80224BB8_12; lwz 4,0xc0(1); mr 3,27; bl _s80224BB8_13; cmpwi 3,0; beq 18f; lwz 4,0x90(31); lis 3,-32697; addi 3,3,24012; bl _s80224BB8_14; mr 30,3; lwz 4,0xc0(1); lwz 5,0xc4(1); mr 3,22; bl _s80224BB8_15; lwz 0,0x88(31); andi. 9,0,4; beq 16f; cmpw 3,30; beq 18f; b 17f; 16:; andi. 11,0,8; beq 18f; cmpwi 3,0; beq 18f; addi 4,31,156; bl _s80224BB8_16; 17:; lwz 9,0x98(31); addi 9,9,1; stw 9,0x98(31); 18:; lwz 0,0x88(31); andi. 9,0,4; beq 19f; lwz 9,0x94(31); cmpwi 9,-1; beq 19f; lwz 0,0x98(31); cmpw 0,9; bgt 7b; 19:; mr 3,26; add 4,23,21; bl _s80224BB8_17; li 0,1; stb 0,0x3a(1); 20:; lwz 9,0x0(29); mr 4,26; lha 3,0x58(9); lwz 0,0x5c(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 3,0; bne 21f; mr 3,26; mr 4,24; bl _s80224BB8_18; cmpwi 3,0; beq 15b; 21:; lwz 0,0x98(31); cmpwi 0,0; bne 22f; li 25,0; 22:; mr 3,24; li 4,2; bl _s80224BB8_19; mr 3,26; li 4,2; bl _s80224BB8_20; b 24f; 23:; li 25,0; 24:; mr 3,22; li 4,2; bl _s80224BB8_21; 25:; cmpwi 25,1; bne 26f; lwz 0,0x88(31); ori 0,0,128; b 27f; 26:; lwz 0,0x88(31); rlwinm 0,0,0,25,23; 27:; stw 0,0x88(31); lwz 0,0xfc(1); mtspr 8,0; lmw 21,0xcc(1); addi 1,1,248"
extern "C" void _s80224BB8_0();
extern "C" void _s80224BB8_1();
extern "C" void _s80224BB8_2();
extern "C" void _s80224BB8_3();
extern "C" void _s80224BB8_4();
extern "C" void _s80224BB8_5();
extern "C" void _s80224BB8_6();
extern "C" void _s80224BB8_7();
extern "C" void _s80224BB8_8();
extern "C" void _s80224BB8_9();
extern "C" void _s80224BB8_10();
extern "C" void _s80224BB8_11();
extern "C" void _s80224BB8_12();
extern "C" void _s80224BB8_13();
extern "C" void _s80224BB8_14();
extern "C" void _s80224BB8_15();
extern "C" void _s80224BB8_16();
extern "C" void _s80224BB8_17();
extern "C" void _s80224BB8_18();
extern "C" void _s80224BB8_19();
extern "C" void _s80224BB8_20();
extern "C" void _s80224BB8_21();
extern "C" void f_80224BB8() {}
