// 0x8019C1E0 CASMiscTarget::GetLocalizableSubnav(UIScreenID, (1376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stw 31,0x74(1); stw 0,0x7c(1); cmpwi 4,12; mr 31,6; beq 18f; bgt 0f; cmpwi 4,4; beq 1f; cmpwi 4,11; beq 30f; b 40f; 0:; cmpwi 4,13; beq 10f; cmpwi 4,14; beq 24f; b 40f; 1:; cmpwi 5,2; beq 5f; bgt 2f; cmpwi 5,0; beq 3f; cmpwi 5,1; beq 4f; b 40f; 2:; cmpwi 5,4; beq 7f; blt 6f; cmpwi 5,5; beq 8f; b 40f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15940; addi 3,1,8; crxor 6,6,6; bl _s8019C1E0_0; lwz 9,0x8(1); b 36f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15864; addi 3,1,12; crxor 6,6,6; bl _s8019C1E0_1; lwz 9,0xc(1); b 36f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15712; addi 3,1,16; crxor 6,6,6; bl _s8019C1E0_2; lwz 9,0x10(1); b 36f; 6:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15688; addi 3,1,20; crxor 6,6,6; bl _s8019C1E0_3; lwz 9,0x14(1); b 36f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15664; addi 3,1,24; crxor 6,6,6; bl _s8019C1E0_4; lwz 9,0x18(1); b 36f; 8:; lwz 9,0x84(3); lwz 3,0x2c(9); cmpwi 3,0; beq 9f; cmpwi 3,4; bne 9f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14044; addi 3,1,28; crxor 6,6,6; bl _s8019C1E0_5; lwz 9,0x1c(1); b 36f; 9:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13852; addi 3,1,32; crxor 6,6,6; bl _s8019C1E0_6; lwz 9,0x20(1); b 36f; 10:; cmpwi 5,2; beq 14f; bgt 11f; cmpwi 5,0; beq 12f; cmpwi 5,1; beq 13f; b 40f; 11:; cmpwi 5,3; beq 15f; cmpwi 5,4; beq 17f; b 40f; 12:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15136; addi 3,1,36; crxor 6,6,6; bl _s8019C1E0_7; lwz 9,0x24(1); b 36f; 13:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13836; addi 3,1,40; crxor 6,6,6; bl _s8019C1E0_8; lwz 9,0x28(1); b 36f; 14:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13820; addi 3,1,44; crxor 6,6,6; bl _s8019C1E0_9; lwz 9,0x2c(1); b 36f; 15:; lis 3,-32705; addi 3,3,-16412; bl _s8019C1E0_10; cmpwi 3,1; bne 16f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15120; addi 3,1,48; crxor 6,6,6; bl _s8019C1E0_11; lwz 9,0x30(1); b 36f; 16:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15100; addi 3,1,52; crxor 6,6,6; bl _s8019C1E0_12; lwz 9,0x34(1); b 36f; 17:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15072; addi 3,1,56; crxor 6,6,6; bl _s8019C1E0_13; lwz 9,0x38(1); b 36f; 18:; cmpwi 5,1; beq 21f; bgt 19f; cmpwi 5,0; beq 20f; b 40f; 19:; cmpwi 5,2; beq 22f; cmpwi 5,3; beq 23f; b 40f; 20:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13800; addi 3,1,60; crxor 6,6,6; bl _s8019C1E0_14; lwz 9,0x3c(1); b 36f; 21:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13784; addi 3,1,64; crxor 6,6,6; bl _s8019C1E0_15; lwz 9,0x40(1); b 36f; 22:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13768; addi 3,1,68; crxor 6,6,6; bl _s8019C1E0_16; lwz 9,0x44(1); b 36f; 23:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15072; addi 3,1,72; crxor 6,6,6; bl _s8019C1E0_17; lwz 9,0x48(1); b 36f; 24:; cmpwi 5,1; beq 28f; bgt 25f; cmpwi 5,0; beq 26f; b 40f; 25:; cmpwi 5,2; beq 29f; b 40f; 26:; lis 3,-32705; addi 3,3,-16412; bl _s8019C1E0_18; cmpwi 3,1; bne 27f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13748; addi 3,1,76; crxor 6,6,6; bl _s8019C1E0_19; lwz 9,0x4c(1); b 36f; 27:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13732; addi 3,1,80; crxor 6,6,6; bl _s8019C1E0_20; lwz 9,0x50(1); b 36f; 28:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13708; addi 3,1,84; crxor 6,6,6; bl _s8019C1E0_21; lwz 9,0x54(1); b 36f; 29:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15072; addi 3,1,88; crxor 6,6,6; bl _s8019C1E0_22; lwz 9,0x58(1); b 36f; 30:; cmpwi 5,2; beq 34f; bgt 31f; cmpwi 5,0; beq 32f; cmpwi 5,1; beq 33f; b 40f; 31:; cmpwi 5,3; beq 35f; cmpwi 5,4; beq 38f; b 40f; 32:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13692; addi 3,1,92; crxor 6,6,6; bl _s8019C1E0_23; lwz 9,0x5c(1); b 36f; 33:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13680; addi 3,1,96; crxor 6,6,6; bl _s8019C1E0_24; lwz 9,0x60(1); b 36f; 34:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13664; addi 3,1,100; crxor 6,6,6; bl _s8019C1E0_25; lwz 9,0x64(1); b 36f; 35:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15084; addi 3,1,104; crxor 6,6,6; bl _s8019C1E0_26; lwz 9,0x68(1); 36:; li 4,0; cmpwi 9,0; beq 37f; lwz 4,0x0(9); 37:; mr 3,31; bl _s8019C1E0_27; b 40f; 38:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15072; addi 3,1,108; crxor 6,6,6; bl _s8019C1E0_28; lwz 9,0x6c(1); li 4,0; cmpwi 9,0; beq 39f; lwz 4,0x0(9); 39:; mr 3,31; bl _s8019C1E0_29; 40:; lwz 0,0x7c(1); mtspr 8,0; lwz 31,0x74(1); addi 1,1,120"
extern "C" void _s8019C1E0_0();
extern "C" void _s8019C1E0_1();
extern "C" void _s8019C1E0_2();
extern "C" void _s8019C1E0_3();
extern "C" void _s8019C1E0_4();
extern "C" void _s8019C1E0_5();
extern "C" void _s8019C1E0_6();
extern "C" void _s8019C1E0_7();
extern "C" void _s8019C1E0_8();
extern "C" void _s8019C1E0_9();
extern "C" void _s8019C1E0_10();
extern "C" void _s8019C1E0_11();
extern "C" void _s8019C1E0_12();
extern "C" void _s8019C1E0_13();
extern "C" void _s8019C1E0_14();
extern "C" void _s8019C1E0_15();
extern "C" void _s8019C1E0_16();
extern "C" void _s8019C1E0_17();
extern "C" void _s8019C1E0_18();
extern "C" void _s8019C1E0_19();
extern "C" void _s8019C1E0_20();
extern "C" void _s8019C1E0_21();
extern "C" void _s8019C1E0_22();
extern "C" void _s8019C1E0_23();
extern "C" void _s8019C1E0_24();
extern "C" void _s8019C1E0_25();
extern "C" void _s8019C1E0_26();
extern "C" void _s8019C1E0_27();
extern "C" void _s8019C1E0_28();
extern "C" void _s8019C1E0_29();
extern "C" void f_8019C1E0() {}
