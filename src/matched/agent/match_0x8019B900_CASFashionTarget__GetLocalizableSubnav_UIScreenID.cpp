// 0x8019B900 CASFashionTarget::GetLocalizableSubnav(UIScreenID, (796 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stw 31,0x4c(1); stw 0,0x54(1); mr 31,6; cmpwi 4,10; beq 0f; cmpwi 4,17; beq 10f; b 23f; 0:; cmpwi 5,2; beq 4f; bgt 1f; cmpwi 5,0; beq 2f; cmpwi 5,1; beq 3f; b 23f; 1:; cmpwi 5,3; beq 5f; cmpwi 5,4; beq 6f; b 23f; 2:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14096; addi 3,1,8; crxor 6,6,6; bl _s8019B900_0; lwz 9,0x8(1); b 19f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14080; addi 3,1,12; crxor 6,6,6; bl _s8019B900_1; lwz 9,0xc(1); b 19f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15808; addi 3,1,16; crxor 6,6,6; bl _s8019B900_2; lwz 9,0x10(1); b 19f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15788; addi 3,1,20; crxor 6,6,6; bl _s8019B900_3; lwz 9,0x14(1); b 19f; 6:; lwz 9,0x84(3); lwz 3,0x2c(9); cmpwi 3,1; beq 7f; ble 9f; cmpwi 3,5; beq 8f; b 9f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14064; addi 3,1,24; crxor 6,6,6; bl _s8019B900_4; lwz 9,0x18(1); b 19f; 8:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14044; addi 3,1,28; crxor 6,6,6; bl _s8019B900_5; lwz 9,0x1c(1); b 19f; 9:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15608; addi 3,1,32; crxor 6,6,6; bl _s8019B900_6; lwz 9,0x20(1); b 19f; 10:; cmpwi 5,3; beq 15f; bgt 11f; cmpwi 5,1; beq 13f; bgt 14f; cmpwi 5,0; beq 12f; b 23f; 11:; cmpwi 5,5; beq 17f; blt 16f; cmpwi 5,6; beq 18f; cmpwi 5,7; beq 21f; b 23f; 12:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14024; addi 3,1,36; crxor 6,6,6; bl _s8019B900_7; lwz 9,0x24(1); b 19f; 13:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14008; addi 3,1,40; crxor 6,6,6; bl _s8019B900_8; lwz 9,0x28(1); b 19f; 14:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13988; addi 3,1,44; crxor 6,6,6; bl _s8019B900_9; lwz 9,0x2c(1); b 19f; 15:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13968; addi 3,1,48; crxor 6,6,6; bl _s8019B900_10; lwz 9,0x30(1); b 19f; 16:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13952; addi 3,1,52; crxor 6,6,6; bl _s8019B900_11; lwz 9,0x34(1); b 19f; 17:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13936; addi 3,1,56; crxor 6,6,6; bl _s8019B900_12; lwz 9,0x38(1); b 19f; 18:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13916; addi 3,1,60; crxor 6,6,6; bl _s8019B900_13; lwz 9,0x3c(1); 19:; li 4,0; cmpwi 9,0; beq 20f; lwz 4,0x0(9); 20:; mr 3,31; bl _s8019B900_14; b 23f; 21:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13900; addi 3,1,64; crxor 6,6,6; bl _s8019B900_15; lwz 9,0x40(1); li 4,0; cmpwi 9,0; beq 22f; lwz 4,0x0(9); 22:; mr 3,31; bl _s8019B900_16; 23:; lwz 0,0x54(1); mtspr 8,0; lwz 31,0x4c(1); addi 1,1,80"
extern "C" void _s8019B900_0();
extern "C" void _s8019B900_1();
extern "C" void _s8019B900_2();
extern "C" void _s8019B900_3();
extern "C" void _s8019B900_4();
extern "C" void _s8019B900_5();
extern "C" void _s8019B900_6();
extern "C" void _s8019B900_7();
extern "C" void _s8019B900_8();
extern "C" void _s8019B900_9();
extern "C" void _s8019B900_10();
extern "C" void _s8019B900_11();
extern "C" void _s8019B900_12();
extern "C" void _s8019B900_13();
extern "C" void _s8019B900_14();
extern "C" void _s8019B900_15();
extern "C" void _s8019B900_16();
extern "C" void f_8019B900() {}
