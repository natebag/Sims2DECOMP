// 0x801D1544 PZ1Target::PZ1Target(int) (1104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 29,0x44(1); stw 0,0x54(1); stw 12,0x40(1); mr 31,3; mr 30,4; bl _s801D1544_0; lis 9,-32705; lis 11,-32698; addi 9,9,16528; addi 11,11,29160; lwz 7,0x0(9); lwz 8,0x4(9); li 0,1; stw 11,0x80(31); lis 9,-32708; stw 30,0xbc(31); addi 4,1,24; stw 0,0x94(31); addi 29,9,-27820; cmpwi 31,0; stw 7,0x18(1); stw 8,0x1c(1); stw 31,0x10(1); beq 0f; addi 3,1,8; li 5,8; bl _s801D1544_1; b 1f; 0:; stw 31,0x8(1); 1:; stw 29,0x14(1); lis 9,-32705; addi 11,1,8; lwz 5,0x8(1); addi 9,9,16536; lwz 4,0x4(11); lwz 6,0x8(11); addi 10,31,40; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 4,31,0; stw 5,0x28(31); lis 9,-32708; stw 0,0xc(10); addi 29,9,-27700; stw 4,0x4(10); addi 9,1,32; stw 6,0x8(10); stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,2f; mr 4,9; mr 3,30; li 5,8; bl _s801D1544_2; b 3f; 2:; stw 31,0x8(1); 3:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,16544; lwz 5,0x8(30); addi 11,31,56; lwz 10,0x4(30); addi 4,1,40; lwz 0,0xc(30); stw 6,0x38(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 29,9,-27580; stw 5,0x8(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,4f; mr 3,30; li 5,8; bl _s801D1544_3; b 5f; 4:; stw 31,0x8(1); 5:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,16552; lwz 5,0x8(30); addi 11,31,72; lwz 10,0x4(30); addi 4,1,48; lwz 0,0xc(30); stw 6,0x48(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 29,9,-27460; stw 5,0x8(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,6f; mr 3,30; li 5,8; bl _s801D1544_4; b 7f; 6:; stw 31,0x8(1); 7:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-8840; lwz 5,0x8(30); addi 11,31,88; lwz 10,0x4(30); addi 4,1,56; lwz 0,0xc(30); stw 6,0x58(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 29,9,-27340; stw 5,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,8f; mr 3,30; li 5,8; bl _s801D1544_5; b 9f; 8:; stw 31,0x8(1); 9:; stw 29,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32705; lwz 7,0xc(30); addi 9,9,16648; lwz 10,0x4(30); lwz 6,0x8(30); lwz 0,-31532(13); stw 8,0x68(31); stw 7,0xc(11); cmpwi 0,0; stw 10,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s801D1544_6; bl _s801D1544_7; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s801D1544_8; bl _s801D1544_9; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s801D1544_10; bl _s801D1544_11; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s801D1544_12; bl _s801D1544_13; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s801D1544_14; bl _s801D1544_15; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s801D1544_16; bl _s801D1544_17; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s801D1544_18; bl _s801D1544_19; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s801D1544_20; bl _s801D1544_21; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s801D1544_22; bl _s801D1544_23; stw 3,-31536(13); 18:; lwz 0,-31536(13); li 9,1; lwz 11,0xbc(31); li 6,0; stw 0,0x24(31); li 7,0; cmpwi 11,30; stw 9,0x0(31); beq 21f; bgt 19f; cmpwi 11,26; beq 20f; b 24f; 19:; cmpwi 11,39; beq 22f; b 24f; 20:; lwz 0,-29712(13); lis 9,-32705; addi 6,9,29260; li 7,2; b 23f; 21:; lwz 0,-29708(13); lis 9,-32705; addi 6,9,29352; li 7,4; b 23f; 22:; lwz 0,-29704(13); lis 9,-32705; addi 6,9,29488; li 7,3; 23:; stw 0,0x8c(31); 24:; lis 5,-32705; mr 3,31; addi 5,5,28780; li 4,45; bl _s801D1544_24; mr 3,31; lwz 0,0x54(1); lwz 12,0x40(1); mtspr 8,0; lmw 29,0x44(1); mtcrf 8,12; addi 1,1,80"
extern "C" void _s801D1544_0();
extern "C" void _s801D1544_1();
extern "C" void _s801D1544_2();
extern "C" void _s801D1544_3();
extern "C" void _s801D1544_4();
extern "C" void _s801D1544_5();
extern "C" void _s801D1544_6();
extern "C" void _s801D1544_7();
extern "C" void _s801D1544_8();
extern "C" void _s801D1544_9();
extern "C" void _s801D1544_10();
extern "C" void _s801D1544_11();
extern "C" void _s801D1544_12();
extern "C" void _s801D1544_13();
extern "C" void _s801D1544_14();
extern "C" void _s801D1544_15();
extern "C" void _s801D1544_16();
extern "C" void _s801D1544_17();
extern "C" void _s801D1544_18();
extern "C" void _s801D1544_19();
extern "C" void _s801D1544_20();
extern "C" void _s801D1544_21();
extern "C" void _s801D1544_22();
extern "C" void _s801D1544_23();
extern "C" void _s801D1544_24();
extern "C" void f_801D1544() {}
