// 0x8018E508 SaveGameTarget::SpawnCardDamagedDialog(void) (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; addi 3,31,132; bl _s8018E508_0; lwz 3,0x118(31); bl _s8018E508_1; cmpwi 3,-1; beq 3f; lis 4,-32697; blt 5f; cmpwi 3,7; bgt 5f; lwz 0,0x138(31); andi. 9,0,256; beq 0f; lis 5,-32705; addi 4,4,24012; addi 5,5,-18136; addi 3,1,8; crxor 6,6,6; bl _s8018E508_2; addi 30,31,172; lwz 9,0x8(1); b 1f; 0:; lis 5,-32705; addi 4,4,24012; addi 5,5,-18108; addi 3,1,12; crxor 6,6,6; bl _s8018E508_3; addi 30,31,172; lwz 9,0xc(1); 1:; li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s8018E508_4; b 5f; 3:; lis 4,-32697; addi 3,1,16; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s8018E508_5; addi 30,31,172; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; bl _s8018E508_6; 5:; lis 29,-32697; lis 5,-32705; addi 4,29,24012; addi 5,5,-18196; addi 3,1,20; addi 30,31,180; crxor 6,6,6; bl _s8018E508_7; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,30; bl _s8018E508_8; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 5,5,-18188; addi 3,1,24; crxor 6,6,6; bl _s8018E508_9; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,30; bl _s8018E508_10; lis 4,-32705; addi 3,31,188; addi 4,4,-18356; bl _s8018E508_11; li 9,3; li 0,0; stw 9,0x8c(31); li 10,2; li 11,1; sth 0,0xce(31); stw 10,0x84(31); stw 0,0x98(31); stw 11,0xa0(31); stw 0,0x88(31); stw 0,0x94(31); stw 0,0x90(31); stw 0,0xc0(31); sth 0,0xcc(31); lwz 9,0x118(31); lwz 0,0x190(9); cmpwi 0,1; bne 8f; stw 10,0xd0(31); b 9f; 8:; stw 11,0xd0(31); 9:; addi 3,31,132; bl _s8018E508_12; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s8018E508_0();
extern "C" void _s8018E508_1();
extern "C" void _s8018E508_2();
extern "C" void _s8018E508_3();
extern "C" void _s8018E508_4();
extern "C" void _s8018E508_5();
extern "C" void _s8018E508_6();
extern "C" void _s8018E508_7();
extern "C" void _s8018E508_8();
extern "C" void _s8018E508_9();
extern "C" void _s8018E508_10();
extern "C" void _s8018E508_11();
extern "C" void _s8018E508_12();
extern "C" void f_8018E508() {}
