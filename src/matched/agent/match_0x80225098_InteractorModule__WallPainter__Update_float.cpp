// 0x80225098 InteractorModule::WallPainter::Update(float) (948 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; lwz 11,0x9c(31); addi 10,31,156; lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; stw 11,0x4(10); mr 3,31; bl _s80225098_0; mr 3,31; bl _s80225098_1; lis 9,-32704; lwz 0,0x88(31); lfs f0,-7280(9); andi. 9,0,1024; stfs f0,0x84(31); beq 3f; addi 9,31,96; andi. 11,0,4096; bne 2f; lwz 0,0x8(9); addi 11,31,120; lwz 10,0x60(31); lwz 9,0x4(9); stw 10,0x78(31); stw 0,0x8(11); stw 9,0x4(11); lwz 0,0x88(31); ori 0,0,4096; stw 0,0x88(31); 2:; lwz 0,0x88(31); rlwinm 0,0,0,22,20; b 6f; 3:; andi. 9,0,2048; beq 7f; andi. 11,0,4096; addi 8,31,96; beq 4f; lwz 11,0x78(31); addi 9,31,120; lwz 0,0x4(9); lwz 10,0x8(9); stw 11,0x60(31); stw 0,0x4(8); stw 10,0x8(8); lwz 0,0x88(31); rlwinm 0,0,0,20,18; stw 0,0x88(31); b 5f; 4:; stfs f0,0x8(1); stfs f0,0x10(1); stfs f0,0xc(1); lwz 0,0x8(1); lwz 9,0xc(1); lwz 11,0x10(1); stw 0,0x60(31); stw 9,0x4(8); stw 11,0x8(8); 5:; lwz 10,0x60(31); addi 11,31,108; lwz 0,0x8(8); lwz 9,0x4(8); stw 10,0x6c(31); stw 0,0x8(11); stw 9,0x4(11); lwz 0,0x88(31); rlwinm 0,0,0,21,19; 6:; stw 0,0x88(31); 7:; lwz 29,0x4(31); cmpwi 29,0; beq 15f; lwz 0,0x88(31); andi. 9,0,16; beq 8f; addi 30,31,32; addi 3,31,8; mr 4,30; li 5,1; bl _s80225098_2; lwz 11,0x20(31); addi 9,31,96; lwz 0,0x8(30); addi 8,31,108; lwz 10,0x4(30); mr 3,31; stw 11,0x60(31); stw 0,0x8(9); stw 10,0x4(9); lwz 0,0x20(31); lwz 9,0x8(30); lwz 11,0x4(30); stw 0,0x6c(31); stw 9,0x8(8); stw 11,0x4(8); bl _s80225098_3; b 15f; 8:; andi. 9,0,2; beq 11f; addi 30,31,32; addi 0,31,8; mr 3,0; mr 29,0; mr 4,30; li 5,2; bl _s80225098_4; lwz 10,0x20(31); addi 11,31,96; lwz 0,0x8(30); lis 9,-32704; lwz 8,0x4(30); addi 7,31,108; stw 10,0x60(31); stw 0,0x8(11); stw 8,0x4(11); lfs f13,-7280(9); lwz 0,0x20(31); lwz 9,0x8(30); lwz 11,0x4(30); stw 0,0x6c(31); stw 9,0x8(7); stw 11,0x4(7); lfs f0,0x34(31); fcmpu 0,f0,f13; bne 9f; lfs f0,0x38(31); fcmpu 0,f0,f13; bne 9f; stfs f13,0x8(1); lis 9,-32704; lfs f0,-7276(9); addi 11,1,8; lwz 5,0x4(31); mr 4,11; stfs f0,0x4(11); mr 3,29; li 6,2; bl _s80225098_5; b 10f; 9:; lwz 5,0x4(31); mr 3,29; addi 4,31,52; li 6,2; bl _s80225098_6; 10:; lwz 0,0x88(31); rlwinm 0,0,0,31,29; stw 0,0x88(31); b 13f; 11:; andi. 9,0,512; beq 12f; addi 0,31,8; mr 5,29; mr 3,0; addi 4,31,52; li 6,2; mr 29,0; bl _s80225098_7; b 13f; 12:; mr 3,29; addi 30,31,8; bl _s80225098_8; mr 5,29; addi 4,31,52; mr 3,30; mr 29,30; bl _s80225098_9; 13:; mr 3,29; bl _s80225098_10; lwz 0,0x88(31); xori 0,0,1; andi. 9,0,1; beq 14f; addi 30,31,32; mr 3,29; mr 4,30; li 5,2; bl _s80225098_11; lwz 11,0x20(31); addi 9,31,96; lwz 0,0x8(30); addi 8,31,108; lwz 10,0x4(30); li 7,0; stw 11,0x60(31); stw 0,0x8(9); stw 10,0x4(9); lwz 0,0x20(31); lwz 9,0x8(30); lwz 11,0x4(30); stw 0,0x6c(31); stw 9,0x8(8); stw 11,0x4(8); stw 7,0x98(31); b 15f; 14:; mr 3,31; bl _s80225098_12; mr 3,31; bl _s80225098_13; 15:; lwz 0,0x88(31); andi. 9,0,32; beq 16f; mr 3,31; bl _s80225098_14; 16:; lwz 0,0x88(31); andi. 9,0,8192; beq 17f; mr 3,31; bl _s80225098_15; 17:; lwz 0,0x88(31); andi. 9,0,4; beq 18f; lwz 4,0x98(31); mr 3,31; bl _s80225098_16; b 19f; 18:; lwz 0,0x94(31); mr 3,31; lwz 4,0x98(31); add 4,0,4; bl _s80225098_17; 19:; lwz 0,0x88(31); andi. 9,0,64; beq 20f; mr 3,31; bl _s80225098_18; 20:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80225098_0();
extern "C" void _s80225098_1();
extern "C" void _s80225098_2();
extern "C" void _s80225098_3();
extern "C" void _s80225098_4();
extern "C" void _s80225098_5();
extern "C" void _s80225098_6();
extern "C" void _s80225098_7();
extern "C" void _s80225098_8();
extern "C" void _s80225098_9();
extern "C" void _s80225098_10();
extern "C" void _s80225098_11();
extern "C" void _s80225098_12();
extern "C" void _s80225098_13();
extern "C" void _s80225098_14();
extern "C" void _s80225098_15();
extern "C" void _s80225098_16();
extern "C" void _s80225098_17();
extern "C" void _s80225098_18();
extern "C" void f_80225098() {}
