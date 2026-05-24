// 0x8001D644 CameraDirector::Update(void) (1360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-232(1); mfspr 0,8; stfd f31,0xe0(1); stmw 22,0xb8(1); stw 0,0xec(1); mr 22,3; li 9,0; lwz 0,0x160(22); cmpwi 0,0; beq 0f; cmpwi 0,8; beq 0f; li 9,1; 0:; cmpwi 9,0; beq 1f; mr 3,22; bl _s8001D644_0; cmpwi 3,0; beq 1f; lwz 0,0x160(22); cmpwi 0,7; beq 1f; lis 9,-32707; li 0,2; lfs f1,-6748(9); mr 3,22; stw 0,0x238(22); li 4,0; li 5,0; bl _s8001D644_1; 1:; lwz 0,0x160(22); cmpwi 0,4; beq 7f; bgt 2f; cmpwi 0,2; beq 15f; bgt 3f; cmpwi 0,1; beq 13f; b 17f; 2:; cmpwi 0,6; beq 11f; blt 8f; cmpwi 0,7; beq 5f; b 17f; 3:; lwz 0,0x170(22); cmpwi 0,0; beq 17f; addi 30,1,8; addi 31,22,128; mr 4,31; mr 3,30; bl _s8001D644_2; addi 29,1,72; addi 28,1,88; addi 27,1,104; mr 3,30; mr 4,29; mr 5,28; mr 6,27; bl _s8001D644_3; lwz 3,0x170(22); mr 4,29; mr 5,28; mr 6,27; bl _s8001D644_4; lfs f1,0x1a0(22); mr 3,22; bl _s8001D644_5; lwz 9,0x230(22); li 0,1; stw 0,0x160(22); cmpwi 9,0; beq 17f; mr 3,31; bl _s8001D644_6; lwz 5,0x118(22); cmpwi 5,0; beq 4f; addi 3,1,120; mr 4,31; bl _s8001D644_7; lwz 9,0x78(1); lwz 10,0x7c(1); lwz 11,0x80(1); lwz 12,0x84(1); stw 9,0x80(22); stw 10,0x84(22); stw 11,0x8(31); stw 12,0xc(31); lwz 9,0x88(1); lwz 10,0x8c(1); stw 9,0x10(31); stw 10,0x14(31); lwz 11,0x90(1); lwz 12,0x94(1); stw 11,0x18(31); stw 12,0x1c(31); lwz 9,0x98(1); lwz 10,0x9c(1); stw 9,0x20(31); stw 10,0x24(31); lwz 11,0xa0(1); lwz 12,0xa4(1); stw 11,0x28(31); stw 12,0x2c(31); lwz 9,0xa8(1); lwz 10,0xac(1); stw 9,0x30(31); stw 10,0x34(31); lwz 11,0xb0(1); lwz 12,0xb4(1); stw 11,0x38(31); stw 12,0x3c(31); 4:; lwz 5,0x11c(22); cmpwi 5,0; beq 17f; addi 3,1,120; mr 4,31; bl _s8001D644_8; lwz 9,0x78(1); lwz 10,0x7c(1); lwz 11,0x80(1); lwz 12,0x84(1); stw 9,0x80(22); stw 10,0x84(22); stw 11,0x8(31); stw 12,0xc(31); lwz 9,0x88(1); lwz 10,0x8c(1); stw 9,0x10(31); stw 10,0x14(31); lwz 11,0x90(1); lwz 12,0x94(1); stw 11,0x18(31); stw 12,0x1c(31); lwz 9,0x98(1); lwz 10,0x9c(1); stw 9,0x20(31); stw 10,0x24(31); lwz 11,0xa0(1); lwz 12,0xa4(1); stw 11,0x28(31); stw 12,0x2c(31); lwz 9,0xa8(1); lwz 10,0xac(1); stw 9,0x30(31); stw 10,0x34(31); lwz 11,0xb0(1); lwz 12,0xb4(1); stw 11,0x38(31); stw 12,0x3c(31); b 17f; 5:; lwz 3,0x170(22); cmpwi 3,0; beq 6f; li 4,0; bl _s8001D644_9; 6:; lwz 0,0x23c(22); cmpwi 0,0; beq 7f; mr 3,22; bl _s8001D644_10; 7:; lwz 0,0x198(22); cmpwi 0,0; bne 10f; mr 3,22; bl _s8001D644_11; b 17f; 8:; lwz 0,0x198(22); cmpwi 0,0; bne 10f; lwz 9,0x230(22); li 0,1; stw 0,0x160(22); cmpwi 9,0; beq 17f; addi 31,22,128; mr 3,31; bl _s8001D644_12; lwz 5,0x118(22); cmpwi 5,0; beq 9f; addi 3,1,8; mr 4,31; bl _s8001D644_13; lwz 25,0x8(1); lwz 26,0xc(1); addi 9,1,8; lwz 23,0x38(9); lwz 24,0x3c(9); lwz 11,0x8(9); lwz 12,0xc(9); lwz 7,0x10(9); lwz 8,0x14(9); lwz 5,0x18(9); lwz 6,0x1c(9); lwz 3,0x20(9); lwz 4,0x24(9); lwz 29,0x28(9); lwz 30,0x2c(9); lwz 27,0x30(9); lwz 28,0x34(9); stw 25,0x80(22); stw 26,0x84(22); stw 11,0x8(31); stw 12,0xc(31); stw 7,0x10(31); stw 8,0x14(31); stw 5,0x18(31); stw 6,0x1c(31); stw 3,0x20(31); stw 4,0x24(31); stw 29,0x28(31); stw 30,0x2c(31); stw 27,0x30(31); stw 28,0x34(31); stw 23,0x38(31); stw 24,0x3c(31); 9:; lwz 5,0x11c(22); cmpwi 5,0; beq 17f; addi 3,1,8; mr 4,31; bl _s8001D644_14; lwz 11,0x8(1); lwz 12,0xc(1); addi 9,1,8; lwz 7,0x38(9); lwz 8,0x3c(9); lwz 5,0x8(9); lwz 6,0xc(9); lwz 3,0x10(9); lwz 4,0x14(9); lwz 29,0x18(9); lwz 30,0x1c(9); lwz 27,0x20(9); lwz 28,0x24(9); lwz 25,0x28(9); lwz 26,0x2c(9); lwz 23,0x30(9); lwz 24,0x34(9); stw 11,0x80(22); stw 12,0x84(22); stw 7,0x38(31); stw 8,0x3c(31); stw 5,0x8(31); stw 6,0xc(31); stw 3,0x10(31); stw 4,0x14(31); stw 29,0x18(31); stw 30,0x1c(31); stw 27,0x20(31); stw 28,0x24(31); stw 25,0x28(31); stw 26,0x2c(31); stw 23,0x30(31); stw 24,0x34(31); b 17f; 10:; mr 3,22; bl _s8001D644_15; stw 3,0x198(22); b 17f; 11:; mr 3,22; addi 31,22,424; bl _s8001D644_16; mr 3,31; lis 4,1; bl _s8001D644_17; cmpwi 3,0; beq 17f; li 0,1; stw 0,0x160(22); lwz 9,0x8(31); lwz 11,0x44(31); mulli 9,9,176; add 9,9,11; lbz 0,0xd(9); cmpwi 0,0; beq 12f; mr 3,31; bl _s8001D644_18; 12:; lis 9,-32707; li 0,0; lfs f0,-6744(9); stw 0,0x220(22); stfs f0,0x22c(22); b 17f; 13:; addi 3,22,424; lis 4,1; bl _s8001D644_19; cmpwi 3,0; beq 14f; mr 3,22; bl _s8001D644_20; 14:; lwz 9,0x164(22); cmpwi 9,0; beq 17f; li 0,0; stw 9,0x160(22); stw 0,0x164(22); b 17f; 15:; lis 9,-32707; lfs f0,0x168(22); lfs f31,-6744(9); fcmpu 0,f0,f31; ble 17f; lwz 11,-21496(13); cmpwi 11,0; beq 16f; lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 17f; 16:; lfs f0,0x168(22); lfs f13,-22732(13); fsubs f0,f0,f13; fcmpu 0,f0,f31; stfs f0,0x168(22); bge 17f; mr 3,22; bl _s8001D644_21; li 0,0; stw 0,0x160(22); 17:; lwz 0,0x160(22); cmpwi 0,0; beq 18f; mr 3,22; bl _s8001D644_22; 18:; lwz 0,0xec(1); mtspr 8,0; lmw 22,0xb8(1); lfd f31,0xe0(1); addi 1,1,232"

extern "C" void _s8001D644_0();
extern "C" void _s8001D644_1();
extern "C" void _s8001D644_2();
extern "C" void _s8001D644_3();
extern "C" void _s8001D644_4();
extern "C" void _s8001D644_5();
extern "C" void _s8001D644_6();
extern "C" void _s8001D644_7();
extern "C" void _s8001D644_8();
extern "C" void _s8001D644_9();
extern "C" void _s8001D644_10();
extern "C" void _s8001D644_11();
extern "C" void _s8001D644_12();
extern "C" void _s8001D644_13();
extern "C" void _s8001D644_14();
extern "C" void _s8001D644_15();
extern "C" void _s8001D644_16();
extern "C" void _s8001D644_17();
extern "C" void _s8001D644_18();
extern "C" void _s8001D644_19();
extern "C" void _s8001D644_20();
extern "C" void _s8001D644_21();
extern "C" void _s8001D644_22();

struct CameraDirector {
    void Update();
};

void CameraDirector::Update() {
}
