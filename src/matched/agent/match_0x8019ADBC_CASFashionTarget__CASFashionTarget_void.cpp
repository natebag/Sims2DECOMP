// 0x8019ADBC CASFashionTarget::CASFashionTarget(void) (1176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 26,0x48(1); stw 0,0x64(1); stw 12,0x44(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12328; stw 9,0x80(31); addi 11,31,40; stw 0,0x0(31); addi 9,31,56; stw 0,0x4(31); addi 10,31,72; stw 0,0x8(31); addi 4,31,88; stw 0,0xc(31); lis 6,-32705; stw 0,0x10(31); addi 6,6,-14220; stw 0,0x14(31); addi 5,31,104; stw 0,0x18(31); lis 8,-32698; stw 0,0x8(11); addi 8,8,27656; stw 0,0x28(31); lis 11,-32698; stw 0,0x8(9); addi 11,11,27752; stw 0,0x38(31); lis 9,-32709; stw 0,0x8(10); addi 30,9,16472; stw 0,0x48(31); cmpwi 31,0; stw 0,0x8(4); stw 0,0x58(31); addi 4,1,24; stw 0,0x8(5); lwz 9,0x0(6); lwz 10,0x4(6); stw 8,0x88(31); stw 11,0x80(31); stw 0,0x8c(31); stw 9,0x18(1); stw 10,0x1c(1); stw 0,0x68(31); stw 0,0x78(31); stw 0,0x84(31); stw 31,0x10(1); beq 0f; addi 3,1,8; li 5,8; bl _s8019ADBC_0; b 1f; 0:; stw 31,0x8(1); 1:; stw 30,0x14(1); addi 11,1,8; lwz 4,0x8(1); lis 9,-32705; lwz 6,0x4(11); addi 9,9,-14212; lwz 5,0x8(11); addi 10,31,40; lwz 0,0xc(11); mr 30,11; stw 4,0x28(31); mr 26,10; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,32; stw 6,0x4(10); lis 9,-32709; stw 5,0x8(10); addi 29,9,16592; stw 0,0xc(10); cmpwi 4,31,0; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,2f; mr 3,30; li 5,8; bl _s8019ADBC_1; b 3f; 2:; stw 31,0x8(1); 3:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-14204; lwz 5,0x8(30); addi 11,31,56; lwz 0,0x4(30); mr 27,11; lwz 10,0xc(30); addi 4,1,40; stw 6,0x38(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32709; stw 5,0x8(11); addi 29,9,16712; stw 10,0xc(11); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,4f; mr 3,30; li 5,8; bl _s8019ADBC_2; b 5f; 4:; stw 31,0x8(1); 5:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-15236; lwz 5,0x8(30); addi 11,31,72; lwz 0,0x4(30); mr 28,11; lwz 10,0xc(30); addi 4,1,48; stw 6,0x48(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0x4(11); lis 9,-32709; stw 5,0x8(11); addi 29,9,16832; stw 10,0xc(11); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,6f; mr 3,30; li 5,8; bl _s8019ADBC_3; b 7f; 6:; stw 31,0x8(1); 7:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-15228; lwz 5,0x8(30); addi 11,31,88; lwz 10,0x4(30); addi 4,1,56; lwz 0,0xc(30); stw 6,0x58(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 29,9,16952; stw 5,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,8f; mr 3,30; li 5,8; bl _s8019ADBC_4; b 9f; 8:; stw 31,0x8(1); 9:; stw 29,0x14(1); addi 11,31,104; lwz 8,0x8(1); lis 9,-32705; lwz 7,0xc(30); addi 9,9,-14196; lwz 10,0x4(30); lwz 6,0x8(30); lwz 0,-31532(13); stw 8,0x68(31); stw 7,0xc(11); cmpwi 0,0; stw 10,0x4(11); stw 6,0x8(11); stw 9,0x7c(31); bne 10f; li 3,16; bl _s8019ADBC_5; bl _s8019ADBC_6; stw 3,-31532(13); 10:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x4(31); bne 11f; li 3,16; bl _s8019ADBC_7; bl _s8019ADBC_8; stw 3,-31528(13); 11:; lwz 9,-31524(13); lwz 0,-31528(13); cmpwi 9,0; stw 0,0x8(31); bne 12f; li 3,16; bl _s8019ADBC_9; bl _s8019ADBC_10; stw 3,-31524(13); 12:; lwz 9,-31488(13); lwz 0,-31524(13); cmpwi 9,0; stw 0,0xc(31); bne 13f; li 3,16; bl _s8019ADBC_11; bl _s8019ADBC_12; stw 3,-31488(13); 13:; lwz 9,-31516(13); lwz 0,-31488(13); cmpwi 9,0; stw 0,0x10(31); bne 14f; li 3,16; bl _s8019ADBC_13; bl _s8019ADBC_14; stw 3,-31516(13); 14:; lwz 9,-31484(13); lwz 0,-31516(13); cmpwi 9,0; stw 0,0x14(31); bne 15f; li 3,16; bl _s8019ADBC_15; bl _s8019ADBC_16; stw 3,-31484(13); 15:; lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 16f; li 3,16; bl _s8019ADBC_17; bl _s8019ADBC_18; stw 3,-31544(13); 16:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 17f; li 3,32; bl _s8019ADBC_19; bl _s8019ADBC_20; stw 3,-31540(13); 17:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 18f; li 3,120; bl _s8019ADBC_21; bl _s8019ADBC_22; stw 3,-31536(13); 18:; lwz 0,-31536(13); li 9,1; lis 4,-32705; lwz 3,0x4(31); stw 0,0x24(31); addi 4,4,-14176; stw 9,0x0(31); mr 5,26; bl _s8019ADBC_23; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-14156; cmpwi 0,0; beq 19f; lwz 3,0x8(31); mr 5,27; bl _s8019ADBC_24; 19:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-14136; cmpwi 0,0; beq 20f; lwz 3,0xc(31); mr 5,28; bl _s8019ADBC_25; 20:; mr 3,31; lwz 0,0x64(1); lwz 12,0x44(1); mtspr 8,0; lmw 26,0x48(1); mtcrf 8,12; addi 1,1,96"
extern "C" void _s8019ADBC_0();
extern "C" void _s8019ADBC_1();
extern "C" void _s8019ADBC_2();
extern "C" void _s8019ADBC_3();
extern "C" void _s8019ADBC_4();
extern "C" void _s8019ADBC_5();
extern "C" void _s8019ADBC_6();
extern "C" void _s8019ADBC_7();
extern "C" void _s8019ADBC_8();
extern "C" void _s8019ADBC_9();
extern "C" void _s8019ADBC_10();
extern "C" void _s8019ADBC_11();
extern "C" void _s8019ADBC_12();
extern "C" void _s8019ADBC_13();
extern "C" void _s8019ADBC_14();
extern "C" void _s8019ADBC_15();
extern "C" void _s8019ADBC_16();
extern "C" void _s8019ADBC_17();
extern "C" void _s8019ADBC_18();
extern "C" void _s8019ADBC_19();
extern "C" void _s8019ADBC_20();
extern "C" void _s8019ADBC_21();
extern "C" void _s8019ADBC_22();
extern "C" void _s8019ADBC_23();
extern "C" void _s8019ADBC_24();
extern "C" void _s8019ADBC_25();
extern "C" void f_8019ADBC() {}
