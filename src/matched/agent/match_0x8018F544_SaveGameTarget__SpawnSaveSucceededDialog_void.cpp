// 0x8018F544 SaveGameTarget::SpawnSaveSucceededDialog(void) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; lis 29,-32697; addi 3,31,132; addi 30,31,172; bl _s8018F544_0; lis 5,-32705; addi 4,29,24012; addi 3,1,8; addi 5,5,-17748; crxor 6,6,6; bl _s8018F544_1; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s8018F544_2; addi 30,31,180; lis 5,-32705; addi 4,29,24012; addi 5,5,-17924; addi 3,1,12; crxor 6,6,6; bl _s8018F544_3; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s8018F544_4; lis 30,-32705; addi 4,30,-18356; addi 3,31,184; bl _s8018F544_5; addi 4,30,-18356; addi 3,31,188; bl _s8018F544_6; li 9,3; li 0,0; li 11,1; stw 9,0x8c(31); sth 0,0xce(31); stw 0,0x98(31); stw 11,0xa0(31); stw 11,0x84(31); stw 0,0x88(31); stw 0,0x94(31); stw 0,0x90(31); stw 0,0xc0(31); sth 0,0xcc(31); lwz 9,0x118(31); lwz 0,0x190(9); cmpwi 0,1; bne 2f; li 0,2; stw 0,0xd0(31); b 3f; 2:; stw 11,0xd0(31); 3:; addi 3,31,132; bl _s8018F544_7; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8018F544_0();
extern "C" void _s8018F544_1();
extern "C" void _s8018F544_2();
extern "C" void _s8018F544_3();
extern "C" void _s8018F544_4();
extern "C" void _s8018F544_5();
extern "C" void _s8018F544_6();
extern "C" void _s8018F544_7();
extern "C" void f_8018F544() {}
