// 0x8019CFC4 CASMorphTarget::GetLocalizableSubnav(UIScreenID, (564 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stw 31,0x34(1); stw 0,0x3c(1); mr 31,6; cmpwi 4,6; beq 0f; cmpwi 4,8; beq 6f; b 17f; 0:; cmpwi 5,1; beq 3f; bgt 1f; cmpwi 5,0; beq 2f; b 17f; 1:; cmpwi 5,2; beq 4f; cmpwi 5,3; beq 5f; b 17f; 2:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13492; addi 3,1,8; crxor 6,6,6; bl _s8019CFC4_0; lwz 9,0x8(1); b 13f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13476; addi 3,1,12; crxor 6,6,6; bl _s8019CFC4_1; lwz 9,0xc(1); b 13f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13460; addi 3,1,16; crxor 6,6,6; bl _s8019CFC4_2; lwz 9,0x10(1); b 13f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15608; addi 3,1,20; crxor 6,6,6; bl _s8019CFC4_3; lwz 9,0x14(1); b 13f; 6:; cmpwi 5,2; beq 10f; bgt 7f; cmpwi 5,0; beq 8f; cmpwi 5,1; beq 9f; b 17f; 7:; cmpwi 5,4; beq 12f; blt 11f; cmpwi 5,5; beq 15f; b 17f; 8:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14096; addi 3,1,24; crxor 6,6,6; bl _s8019CFC4_4; lwz 9,0x18(1); b 13f; 9:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13444; addi 3,1,28; crxor 6,6,6; bl _s8019CFC4_5; lwz 9,0x1c(1); b 13f; 10:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13428; addi 3,1,32; crxor 6,6,6; bl _s8019CFC4_6; lwz 9,0x20(1); b 13f; 11:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13412; addi 3,1,36; crxor 6,6,6; bl _s8019CFC4_7; lwz 9,0x24(1); b 13f; 12:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13396; addi 3,1,40; crxor 6,6,6; bl _s8019CFC4_8; lwz 9,0x28(1); 13:; li 4,0; cmpwi 9,0; beq 14f; lwz 4,0x0(9); 14:; mr 3,31; bl _s8019CFC4_9; b 17f; 15:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15608; addi 3,1,44; crxor 6,6,6; bl _s8019CFC4_10; lwz 9,0x2c(1); li 4,0; cmpwi 9,0; beq 16f; lwz 4,0x0(9); 16:; mr 3,31; bl _s8019CFC4_11; 17:; lwz 0,0x3c(1); mtspr 8,0; lwz 31,0x34(1); addi 1,1,56"
extern "C" void _s8019CFC4_0();
extern "C" void _s8019CFC4_1();
extern "C" void _s8019CFC4_2();
extern "C" void _s8019CFC4_3();
extern "C" void _s8019CFC4_4();
extern "C" void _s8019CFC4_5();
extern "C" void _s8019CFC4_6();
extern "C" void _s8019CFC4_7();
extern "C" void _s8019CFC4_8();
extern "C" void _s8019CFC4_9();
extern "C" void _s8019CFC4_10();
extern "C" void _s8019CFC4_11();
extern "C" void f_8019CFC4() {}
