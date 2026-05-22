// 0x8018F660 SaveGameTarget::SpawnSaveFailedDialog(void) (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; addi 3,31,132; bl _s8018F660_0; lwz 3,0x118(31); bl _s8018F660_1; cmpwi 3,-1; beq 1f; lis 4,-32697; blt 3f; cmpwi 3,7; bgt 3f; lis 5,-32705; addi 4,4,24012; addi 5,5,-17724; addi 3,1,8; crxor 6,6,6; bl _s8018F660_2; addi 30,31,172; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s8018F660_3; b 3f; 1:; lis 4,-32697; addi 3,1,12; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s8018F660_4; addi 30,31,172; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s8018F660_5; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-17924; addi 3,1,16; addi 30,31,180; crxor 6,6,6; bl _s8018F660_6; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; li 29,1; bl _s8018F660_7; lis 30,-32705; addi 4,30,-18356; addi 3,31,184; bl _s8018F660_8; stw 29,0x84(31); addi 4,30,-18356; addi 3,31,188; bl _s8018F660_9; li 9,3; li 0,0; stw 9,0x8c(31); sth 0,0xce(31); stw 0,0x98(31); stw 29,0xa0(31); stw 0,0x88(31); stw 0,0x94(31); stw 0,0x90(31); stw 0,0xc0(31); sth 0,0xcc(31); lwz 9,0x118(31); lwz 0,0x190(9); cmpwi 0,1; bne 5f; li 0,2; stw 0,0xd0(31); b 6f; 5:; stw 29,0xd0(31); 6:; addi 3,31,132; bl _s8018F660_10; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8018F660_0();
extern "C" void _s8018F660_1();
extern "C" void _s8018F660_2();
extern "C" void _s8018F660_3();
extern "C" void _s8018F660_4();
extern "C" void _s8018F660_5();
extern "C" void _s8018F660_6();
extern "C" void _s8018F660_7();
extern "C" void _s8018F660_8();
extern "C" void _s8018F660_9();
extern "C" void _s8018F660_10();
extern "C" void f_8018F660() {}
