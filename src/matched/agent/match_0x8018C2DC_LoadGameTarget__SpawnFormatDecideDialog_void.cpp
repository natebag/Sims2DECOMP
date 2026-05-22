// 0x8018C2DC LoadGameTarget::SpawnFormatDecideDialog(void) (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; lis 29,-32697; lis 5,-32705; addi 4,29,24012; addi 5,5,-18684; addi 3,1,8; crxor 6,6,6; bl _s8018C2DC_0; addi 30,31,172; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s8018C2DC_1; addi 30,31,180; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,-18832; addi 3,1,12; crxor 6,6,6; bl _s8018C2DC_2; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s8018C2DC_3; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 5,5,-18828; addi 3,1,16; crxor 6,6,6; bl _s8018C2DC_4; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s8018C2DC_5; lis 4,-32705; addi 3,31,188; addi 4,4,-19228; bl _s8018C2DC_6; li 11,0; li 10,1; li 0,3; li 8,2; stw 0,0x8c(31); sth 11,0xce(31); stw 11,0x98(31); stw 10,0xa0(31); stw 8,0x84(31); stw 10,0x88(31); stw 11,0x94(31); stw 11,0x90(31); stw 11,0xc0(31); sth 11,0xcc(31); lwz 9,0x118(31); lwz 0,0x190(9); cmpwi 0,1; bne 3f; stw 8,0xd0(31); b 4f; 3:; stw 10,0xd0(31); 4:; addi 3,31,132; bl _s8018C2DC_7; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8018C2DC_0();
extern "C" void _s8018C2DC_1();
extern "C" void _s8018C2DC_2();
extern "C" void _s8018C2DC_3();
extern "C" void _s8018C2DC_4();
extern "C" void _s8018C2DC_5();
extern "C" void _s8018C2DC_6();
extern "C" void _s8018C2DC_7();
extern "C" void f_8018C2DC() {}
