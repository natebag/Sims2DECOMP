// 0x8018EE6C SaveGameTarget::SpawnNoSpaceDialog(SaveGameTarget::NoSpaceType) (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 31,3; mr 30,4; addi 3,31,132; bl _s8018EE6C_0; lwz 3,0x118(31); bl _s8018EE6C_1; cmpwi 3,-1; beq 0f; lis 4,-32697; blt 8f; cmpwi 3,7; bgt 8f; lis 5,-32705; addi 4,4,24012; addi 5,5,-17920; addi 3,1,8; crxor 6,6,6; bl _s8018EE6C_2; addi 30,31,172; lwz 9,0x8(1); b 4f; 0:; cmpwi 30,1; beq 3f; bgt 1f; cmpwi 30,0; beq 2f; b 8f; 1:; cmpwi 30,2; beq 6f; b 8f; 2:; lis 4,-32697; addi 3,1,12; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s8018EE6C_3; addi 30,31,172; lwz 9,0xc(1); b 4f; 3:; lis 4,-32697; addi 3,1,16; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s8018EE6C_4; addi 30,31,172; lwz 9,0x10(1); 4:; li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,30; bl _s8018EE6C_5; b 8f; 6:; lis 4,-32697; addi 3,1,20; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s8018EE6C_6; addi 30,31,172; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,30; bl _s8018EE6C_7; 8:; lis 29,-32697; lis 5,-32705; addi 4,29,24012; addi 5,5,-18196; addi 3,1,24; addi 30,31,180; crxor 6,6,6; bl _s8018EE6C_8; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; mr 3,30; bl _s8018EE6C_9; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 3,1,28; addi 5,5,-18188; crxor 6,6,6; bl _s8018EE6C_10; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 10f; lwz 4,0x0(9); 10:; mr 3,30; bl _s8018EE6C_11; lwz 0,0x138(31); andi. 9,0,4; beq 12f; lis 5,-32705; addi 4,29,24012; addi 5,5,-17900; addi 3,1,32; crxor 6,6,6; bl _s8018EE6C_12; addi 30,31,188; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; mr 3,30; bl _s8018EE6C_13; li 0,3; b 13f; 12:; lis 4,-32705; addi 3,31,188; addi 4,4,-18356; bl _s8018EE6C_14; li 0,2; 13:; stw 0,0x84(31); li 9,3; li 0,0; stw 9,0x8c(31); li 11,1; sth 0,0xce(31); stw 0,0x88(31); stw 0,0x98(31); stw 11,0xa0(31); stw 0,0x94(31); stw 0,0x90(31); stw 0,0xc0(31); sth 0,0xcc(31); lwz 9,0x118(31); lwz 0,0x190(9); cmpwi 0,1; bne 14f; li 0,2; stw 0,0xd0(31); b 15f; 14:; stw 11,0xd0(31); 15:; addi 3,31,132; bl _s8018EE6C_15; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s8018EE6C_0();
extern "C" void _s8018EE6C_1();
extern "C" void _s8018EE6C_2();
extern "C" void _s8018EE6C_3();
extern "C" void _s8018EE6C_4();
extern "C" void _s8018EE6C_5();
extern "C" void _s8018EE6C_6();
extern "C" void _s8018EE6C_7();
extern "C" void _s8018EE6C_8();
extern "C" void _s8018EE6C_9();
extern "C" void _s8018EE6C_10();
extern "C" void _s8018EE6C_11();
extern "C" void _s8018EE6C_12();
extern "C" void _s8018EE6C_13();
extern "C" void _s8018EE6C_14();
extern "C" void _s8018EE6C_15();
extern "C" void f_8018EE6C() {}
