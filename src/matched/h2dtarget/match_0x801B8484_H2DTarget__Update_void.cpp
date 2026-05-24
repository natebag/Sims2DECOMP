// 0x801B8484 H2DTarget::Update(void) (1460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 15,0xc(1); stw 0,0x54(1); stw 12,0x8(1); lis 9,-32697; mr 28,3; lwz 0,0x5c70(9); li 17,0; cmpwi 0,0; beq 0f; li 17,1; 0:; lwz 11,-30264(13); lis 9,10922; ori 9,9,43691; li 25,0; addi 11,11,1; cmpw 25,17; mulhw 9,11,9; srawi 10,11,31; stw 11,-30264(13); subf 22,10,9; mulli 0,22,6; subf 22,0,11; bgt 23f; lis 9,-32697; addi 20,28,180; addi 16,9,24012; addi 21,28,136; addi 15,16,188; addi 19,28,252; mr 23,20; li 24,0; addi 18,28,236; 1:; cmpwi 22,2; beq 5f; bgt 2f; cmpwi 22,0; beq 3f; cmpwi 22,1; beq 4f; rlwinm 31,25,2,0,29; b 9f; 2:; cmpwi 22,4; beq 7f; blt 6f; cmpwi 22,5; beq 8f; rlwinm 31,25,2,0,29; b 9f; 3:; lwz 3,-44(23); rlwinm 31,25,2,0,29; bl _s801B8484_0; b 9f; 4:; addi 9,28,172; rlwinm 31,25,2,0,29; lwzx 3,9,24; bl _s801B8484_1; b 9f; 5:; addi 9,28,164; rlwinm 31,25,2,0,29; lwzx 3,9,24; bl _s801B8484_2; b 9f; 6:; lwz 3,-24(23); rlwinm 31,25,2,0,29; bl _s801B8484_3; lwz 3,-24(23); bl _s801B8484_4; b 9f; 7:; addi 9,28,188; rlwinm 31,25,2,0,29; lwzx 3,9,24; bl _s801B8484_5; b 9f; 8:; lwz 3,0x0(23); rlwinm 31,25,2,0,29; bl _s801B8484_6; 9:; lwz 3,-26524(13); mr 4,25; bl _s801B8484_7; addi 9,28,276; mr 27,3; lwzx 0,9,24; mr 26,9; cmpwi 0,1; beq 10f; cmpwi 0,3; beq 10f; cmpwi 0,2; cmpwi 4,27,0; bne 16f; 10:; cmpwi 4,27,0; beq cr4,11f; lwzx 30,18,24; mr 3,27; mr 4,30; bl _s801B8484_8; mr 29,3; mr 4,30; mr 3,27; bl _s801B8484_9; mr 6,3; li 4,9; mr 5,29; mr 3,27; li 7,0; bl _s801B8484_10; cmpwi 3,0; li 4,1; bne 12f; 11:; li 4,0; 12:; lwzx 9,26,24; cmpwi 9,1; bne 13f; addi 30,28,228; lwzx 0,30,31; cmpw 0,4; beq 16f; addic. 9,28,172; beq 16f; stwx 4,30,31; lwzx 3,9,31; bl _s801B8484_11; b 14f; 13:; cmpwi 9,3; bne 15f; addi 30,28,228; lwzx 0,30,31; cmpw 0,4; beq 16f; addic. 9,28,164; beq 16f; stwx 4,30,31; lwzx 3,9,31; bl _s801B8484_12; 14:; lwzx 4,30,31; lwzx 3,21,31; bl _s801B8484_13; b 16f; 15:; cmpwi 9,2; bne 16f; addi 30,28,228; lwzx 0,30,31; cmpw 0,4; beq 16f; addic. 9,28,156; beq 16f; stwx 4,30,31; lwzx 3,9,31; bl _s801B8484_14; lwzx 4,30,31; lwzx 3,21,31; bl _s801B8484_15; 16:; addi 26,28,244; beq cr4,17f; lwzx 30,18,24; mr 3,27; mr 4,30; bl _s801B8484_16; mr 29,3; mr 4,30; mr 3,27; bl _s801B8484_17; mr 6,3; mr 5,29; mr 3,27; li 4,6; li 7,0; bl _s801B8484_18; cmpwi 3,0; beq 17f; lwzx 0,26,31; li 29,1; cmpwi 0,0; bne 18f; 17:; li 29,0; 18:; lwzx 0,26,24; cmpw 29,0; beq 21f; cmpwi 29,0; bne 20f; addi 30,28,260; lwzx 0,30,31; cmpwi 0,0; beq 19f; lwzx 0,19,31; cmpwi 0,0; bne 20f; lwzx 3,20,31; li 4,0; bl _s801B8484_19; stwx 3,30,31; b 20f; 19:; lwzx 11,15,31; cmpwi 11,0; beq 20f; lwz 9,0x4(11); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 20f; lwzx 3,20,31; bl _s801B8484_20; 20:; stwx 29,26,24; b 22f; 21:; addi 30,28,260; lwzx 0,30,31; cmpwi 0,0; bne 22f; cmpwi 29,0; beq 22f; lwzx 9,19,31; addi 9,9,1; cmpwi 9,29; stwx 9,19,31; ble 22f; lwzx 3,20,31; li 4,1; bl _s801B8484_21; stwx 3,30,31; cmpwi 3,0; beq 22f; addi 30,28,268; lwzx 0,30,31; cmpwi 0,0; bne 22f; lwzx 3,21,31; li 4,1; bl _s801B8484_22; lwz 3,0xb4(16); lis 5,-32705; addi 5,5,5128; mr 4,25; bl _s801B8484_23; mr 5,3; mr 4,25; stwx 5,30,31; li 6,5; lwz 3,0xb4(16); bl _s801B8484_24; 22:; addi 25,25,1; addi 23,23,4; addi 24,24,4; cmpw 25,17; ble 1b; 23:; lwz 3,0xc4(28); cmpwi 3,0; beq 24f; bl _s801B8484_25; 24:; lwz 0,0xe0(28); cmpwi 0,0; beq 26f; lwz 11,0xcc(28); cmpwi 11,0; beq 25f; lwz 9,0x80(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0xcc(28); 25:; li 0,0; li 3,0; stw 0,0xe0(28); bl _s801B8484_26; 26:; lwz 0,0xdc(28); cmpwi 0,0; beq 27f; lis 9,-32697; lwz 3,0x5f08(9); bl _s801B8484_27; mr. 31,3; bne 27f; li 3,176; bl _s801B8484_28; lwz 4,0xd4(28); lwz 5,0xd8(28); bl _s801B8484_29; stw 3,0xcc(28); stw 31,0xdc(28); 27:; li 25,0; cmpw 25,17; bgt 34f; lis 29,-32705; addi 24,28,156; addi 26,28,172; addi 27,28,164; li 30,0; 28:; mr 3,28; mr 4,25; bl _s801B8484_30; cmpwi 3,0; beq 29f; addi 31,28,136; lwzx 3,31,30; bl _s801B8484_31; cmpwi 3,0; bne 33f; lwzx 3,31,30; bl _s801B8484_32; addi 3,29,2780; li 4,1; bl _s801B8484_33; b 33f; 29:; addi 31,28,136; lwzx 3,31,30; bl _s801B8484_34; cmpwi 3,0; beq 30f; lwzx 3,31,30; bl _s801B8484_35; addi 3,29,2780; li 4,0; bl _s801B8484_36; 30:; lwzx 3,24,30; cmpwi 3,0; beq 31f; bl _s801B8484_37; 31:; lwzx 3,26,30; cmpwi 3,0; beq 32f; bl _s801B8484_38; 32:; lwzx 3,27,30; cmpwi 3,0; beq 33f; bl _s801B8484_39; 33:; addi 25,25,1; addi 30,30,4; cmpw 25,17; ble 28b; 34:; lwz 3,0xc4(28); cmpwi 3,0; beq 36f; bl _s801B8484_40; lis 9,-32705; lfs f0,0x1420(9); fcmpu 0,f1,f0; bge 36f; lwz 11,0xc4(28); cmpwi 11,0; beq 35f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 35:; li 0,0; stw 0,0xc4(28); 36:; lwz 0,0x54(1); lwz 12,0x8(1); mtspr 8,0; lmw 15,0xc(1); mtcrf 8,12; addi 1,1,80"

extern "C" void _s801B8484_0();
extern "C" void _s801B8484_1();
extern "C" void _s801B8484_2();
extern "C" void _s801B8484_3();
extern "C" void _s801B8484_4();
extern "C" void _s801B8484_5();
extern "C" void _s801B8484_6();
extern "C" void _s801B8484_7();
extern "C" void _s801B8484_8();
extern "C" void _s801B8484_9();
extern "C" void _s801B8484_10();
extern "C" void _s801B8484_11();
extern "C" void _s801B8484_12();
extern "C" void _s801B8484_13();
extern "C" void _s801B8484_14();
extern "C" void _s801B8484_15();
extern "C" void _s801B8484_16();
extern "C" void _s801B8484_17();
extern "C" void _s801B8484_18();
extern "C" void _s801B8484_19();
extern "C" void _s801B8484_20();
extern "C" void _s801B8484_21();
extern "C" void _s801B8484_22();
extern "C" void _s801B8484_23();
extern "C" void _s801B8484_24();
extern "C" void _s801B8484_25();
extern "C" void _s801B8484_26();
extern "C" void _s801B8484_27();
extern "C" void _s801B8484_28();
extern "C" void _s801B8484_29();
extern "C" void _s801B8484_30();
extern "C" void _s801B8484_31();
extern "C" void _s801B8484_32();
extern "C" void _s801B8484_33();
extern "C" void _s801B8484_34();
extern "C" void _s801B8484_35();
extern "C" void _s801B8484_36();
extern "C" void _s801B8484_37();
extern "C" void _s801B8484_38();
extern "C" void _s801B8484_39();
extern "C" void _s801B8484_40();

struct H2DTarget {
    void Update();
};

void H2DTarget::Update() {
}
