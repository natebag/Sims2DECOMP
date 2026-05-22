// 0x8018AFC4 LoadGameTarget::SpawnWrongDeviceDialog(void) (552 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; addi 3,31,132; bl _s8018AFC4_0; lwz 3,0x118(31); bl _s8018AFC4_1; lis 4,-32697; cmpwi 3,7; bgt 1f; cmpwi 3,0; blt 1f; lis 5,-32705; addi 4,4,24012; addi 5,5,-19052; addi 3,1,8; crxor 6,6,6; bl _s8018AFC4_2; addi 30,31,172; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s8018AFC4_3; 1:; lwz 0,0x138(31); andi. 9,0,1; beq 4f; lis 29,-32697; lis 5,-32705; addi 4,29,24012; addi 5,5,-19028; addi 3,1,12; addi 30,31,180; crxor 6,6,6; bl _s8018AFC4_4; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s8018AFC4_5; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 5,5,-19020; addi 3,1,16; crxor 6,6,6; bl _s8018AFC4_6; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,30; bl _s8018AFC4_7; lis 4,-32705; addi 3,31,188; addi 4,4,-19228; bl _s8018AFC4_8; li 0,2; b 8f; 4:; lis 29,-32697; lis 5,-32705; addi 4,29,24012; addi 5,5,-19028; addi 3,1,20; addi 30,31,180; crxor 6,6,6; bl _s8018AFC4_9; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,30; bl _s8018AFC4_10; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 3,1,24; addi 5,5,-19012; crxor 6,6,6; bl _s8018AFC4_11; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,30; bl _s8018AFC4_12; addi 30,31,188; lis 5,-32705; addi 4,29,24012; addi 5,5,-19020; addi 3,1,28; crxor 6,6,6; bl _s8018AFC4_13; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,30; bl _s8018AFC4_14; li 0,3; 8:; stw 0,0x84(31); li 9,3; li 0,0; stw 9,0x8c(31); li 11,1; sth 0,0xce(31); stw 0,0x98(31); stw 11,0xa0(31); stw 0,0x88(31); stw 0,0x94(31); stw 0,0x90(31); stw 0,0xc0(31); sth 0,0xcc(31); lwz 9,0x118(31); lwz 0,0x190(9); cmpwi 0,1; bne 9f; li 0,2; stw 0,0xd0(31); b 10f; 9:; stw 11,0xd0(31); 10:; addi 3,31,132; bl _s8018AFC4_15; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s8018AFC4_0();
extern "C" void _s8018AFC4_1();
extern "C" void _s8018AFC4_2();
extern "C" void _s8018AFC4_3();
extern "C" void _s8018AFC4_4();
extern "C" void _s8018AFC4_5();
extern "C" void _s8018AFC4_6();
extern "C" void _s8018AFC4_7();
extern "C" void _s8018AFC4_8();
extern "C" void _s8018AFC4_9();
extern "C" void _s8018AFC4_10();
extern "C" void _s8018AFC4_11();
extern "C" void _s8018AFC4_12();
extern "C" void _s8018AFC4_13();
extern "C" void _s8018AFC4_14();
extern "C" void _s8018AFC4_15();
extern "C" void f_8018AFC4() {}
