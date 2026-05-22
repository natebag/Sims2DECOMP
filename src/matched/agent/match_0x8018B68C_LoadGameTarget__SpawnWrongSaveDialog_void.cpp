// 0x8018B68C LoadGameTarget::SpawnWrongSaveDialog(void) (568 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 31,3; addi 3,31,132; bl _s8018B68C_0; lwz 3,0x118(31); bl _s8018B68C_1; cmpwi 3,-1; beq 1f; lis 4,-32697; blt 3f; cmpwi 3,7; bgt 3f; lis 5,-32705; addi 4,4,24012; addi 5,5,-18944; addi 3,1,8; crxor 6,6,6; bl _s8018B68C_2; addi 30,31,172; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s8018B68C_3; b 3f; 1:; lis 4,-32697; addi 3,1,12; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s8018B68C_4; addi 30,31,172; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s8018B68C_5; 3:; lis 29,-32697; lis 5,-32705; addi 4,29,24012; addi 5,5,-19028; addi 3,1,16; addi 30,31,180; crxor 6,6,6; bl _s8018B68C_6; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; bl _s8018B68C_7; lwz 0,0x138(31); andi. 9,0,1; beq 6f; lis 5,-32705; addi 4,29,24012; addi 3,1,20; addi 5,5,-18916; crxor 6,6,6; bl _s8018B68C_8; addi 30,31,184; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,30; bl _s8018B68C_9; addi 30,31,188; lis 5,-32705; addi 4,29,24012; addi 5,5,-19020; addi 3,1,24; crxor 6,6,6; bl _s8018B68C_10; lwz 9,0x18(1); b 8f; 6:; lis 5,-32705; addi 4,29,24012; addi 3,1,28; addi 5,5,-19012; crxor 6,6,6; bl _s8018B68C_11; addi 30,31,184; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,30; bl _s8018B68C_12; addi 30,31,188; lis 5,-32705; addi 4,29,24012; addi 5,5,-18916; addi 3,1,32; crxor 6,6,6; bl _s8018B68C_13; lwz 9,0x20(1); 8:; li 4,0; cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; mr 3,30; bl _s8018B68C_14; li 0,3; stw 0,0x84(31); li 9,3; li 0,0; stw 9,0x8c(31); li 11,1; sth 0,0xce(31); stw 0,0x98(31); stw 11,0xa0(31); stw 0,0x88(31); stw 0,0x94(31); stw 0,0x90(31); stw 0,0xc0(31); sth 0,0xcc(31); lwz 9,0x118(31); lwz 0,0x190(9); cmpwi 0,1; bne 10f; li 0,2; stw 0,0xd0(31); b 11f; 10:; stw 11,0xd0(31); 11:; addi 3,31,132; bl _s8018B68C_15; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s8018B68C_0();
extern "C" void _s8018B68C_1();
extern "C" void _s8018B68C_2();
extern "C" void _s8018B68C_3();
extern "C" void _s8018B68C_4();
extern "C" void _s8018B68C_5();
extern "C" void _s8018B68C_6();
extern "C" void _s8018B68C_7();
extern "C" void _s8018B68C_8();
extern "C" void _s8018B68C_9();
extern "C" void _s8018B68C_10();
extern "C" void _s8018B68C_11();
extern "C" void _s8018B68C_12();
extern "C" void _s8018B68C_13();
extern "C" void _s8018B68C_14();
extern "C" void _s8018B68C_15();
extern "C" void f_8018B68C() {}
