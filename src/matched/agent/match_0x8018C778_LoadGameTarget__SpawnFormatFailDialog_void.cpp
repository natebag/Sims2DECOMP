// 0x8018C778 LoadGameTarget::SpawnFormatFailDialog(void) (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); mr 31,3; lis 28,-32697; lis 5,-32705; addi 4,28,24012; addi 5,5,-18576; addi 3,1,8; crxor 6,6,6; bl _s8018C778_0; addi 30,31,172; lwz 9,0x8(1); lis 29,-32697; li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s8018C778_1; lwz 0,0x138(31); andi. 9,0,1; beq 3f; lis 5,-32705; addi 4,29,24012; addi 3,1,12; addi 5,5,-19028; crxor 6,6,6; bl _s8018C778_2; addi 30,31,180; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s8018C778_3; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 5,5,-19020; addi 3,1,16; crxor 6,6,6; bl _s8018C778_4; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s8018C778_5; lis 4,-32705; addi 3,31,188; addi 4,4,-19228; bl _s8018C778_6; li 0,2; b 7f; 3:; lis 5,-32705; addi 4,29,24012; addi 3,1,20; addi 5,5,-19028; crxor 6,6,6; bl _s8018C778_7; addi 30,31,180; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; bl _s8018C778_8; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 5,5,-19012; addi 3,1,24; crxor 6,6,6; bl _s8018C778_9; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,30; bl _s8018C778_10; addi 30,31,188; lis 5,-32705; addi 4,28,24012; addi 5,5,-19020; addi 3,1,28; crxor 6,6,6; bl _s8018C778_11; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,30; bl _s8018C778_12; li 0,3; 7:; stw 0,0x84(31); li 9,3; li 0,0; stw 9,0x8c(31); li 11,1; sth 0,0xce(31); stw 0,0x98(31); stw 11,0xa0(31); stw 0,0x88(31); stw 0,0x94(31); stw 0,0x90(31); stw 0,0xc0(31); sth 0,0xcc(31); lwz 9,0x118(31); lwz 0,0x190(9); cmpwi 0,1; bne 8f; li 0,2; stw 0,0xd0(31); b 9f; 8:; stw 11,0xd0(31); 9:; addi 3,31,132; bl _s8018C778_13; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s8018C778_0();
extern "C" void _s8018C778_1();
extern "C" void _s8018C778_2();
extern "C" void _s8018C778_3();
extern "C" void _s8018C778_4();
extern "C" void _s8018C778_5();
extern "C" void _s8018C778_6();
extern "C" void _s8018C778_7();
extern "C" void _s8018C778_8();
extern "C" void _s8018C778_9();
extern "C" void _s8018C778_10();
extern "C" void _s8018C778_11();
extern "C" void _s8018C778_12();
extern "C" void _s8018C778_13();
extern "C" void f_8018C778() {}
