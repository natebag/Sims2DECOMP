// 0x8019E77C CASPersonalTarget::ParseSignText(short, (632 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stw 31,0x3c(1); stw 0,0x44(1); mr 31,5; cmpwi 4,5; beq 8f; bgt 1f; cmpwi 4,2; beq 5f; bgt 0f; cmpwi 4,0; beq 3f; cmpwi 4,1; beq 4f; b 17f; 0:; cmpwi 4,3; beq 6f; cmpwi 4,4; beq 7f; b 17f; 1:; cmpwi 4,8; beq 11f; bgt 2f; cmpwi 4,6; beq 9f; cmpwi 4,7; beq 10f; b 17f; 2:; cmpwi 4,10; beq 13f; blt 12f; cmpwi 4,11; beq 14f; b 17f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12312; addi 3,1,8; crxor 6,6,6; bl _s8019E77C_0; lwz 9,0x8(1); b 15f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12296; addi 3,1,12; crxor 6,6,6; bl _s8019E77C_1; lwz 9,0xc(1); b 15f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12280; addi 3,1,16; crxor 6,6,6; bl _s8019E77C_2; lwz 9,0x10(1); b 15f; 6:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12264; addi 3,1,20; crxor 6,6,6; bl _s8019E77C_3; lwz 9,0x14(1); b 15f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12248; addi 3,1,24; crxor 6,6,6; bl _s8019E77C_4; lwz 9,0x18(1); b 15f; 8:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12236; addi 3,1,28; crxor 6,6,6; bl _s8019E77C_5; lwz 9,0x1c(1); b 15f; 9:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12220; addi 3,1,32; crxor 6,6,6; bl _s8019E77C_6; lwz 9,0x20(1); b 15f; 10:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12204; addi 3,1,36; crxor 6,6,6; bl _s8019E77C_7; lwz 9,0x24(1); b 15f; 11:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12188; addi 3,1,40; crxor 6,6,6; bl _s8019E77C_8; lwz 9,0x28(1); b 15f; 12:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12168; addi 3,1,44; crxor 6,6,6; bl _s8019E77C_9; lwz 9,0x2c(1); b 15f; 13:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12148; addi 3,1,48; crxor 6,6,6; bl _s8019E77C_10; lwz 9,0x30(1); b 15f; 14:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-12132; addi 3,1,52; crxor 6,6,6; bl _s8019E77C_11; lwz 9,0x34(1); 15:; li 4,0; cmpwi 9,0; beq 16f; lwz 4,0x0(9); 16:; mr 3,31; bl _s8019E77C_12; b 18f; 17:; lis 4,-32705; mr 3,31; addi 4,4,-17308; bl _s8019E77C_13; 18:; lwz 0,0x44(1); mtspr 8,0; lwz 31,0x3c(1); addi 1,1,64"
extern "C" void _s8019E77C_0();
extern "C" void _s8019E77C_1();
extern "C" void _s8019E77C_2();
extern "C" void _s8019E77C_3();
extern "C" void _s8019E77C_4();
extern "C" void _s8019E77C_5();
extern "C" void _s8019E77C_6();
extern "C" void _s8019E77C_7();
extern "C" void _s8019E77C_8();
extern "C" void _s8019E77C_9();
extern "C" void _s8019E77C_10();
extern "C" void _s8019E77C_11();
extern "C" void _s8019E77C_12();
extern "C" void _s8019E77C_13();
extern "C" void f_8019E77C() {}
