// 0x801C16AC M2MTarget::SpawnSaveBeforeQuitGameDialog(void) (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 31,3; lis 28,-32697; lis 5,-32705; addi 4,28,24012; addi 5,5,8904; addi 3,1,8; crxor 6,6,6; bl _s801C16AC_0; addi 30,31,172; lwz 9,0x8(1); lis 29,-32697; li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s801C16AC_1; addi 30,31,180; lis 5,-32705; addi 4,29,24012; addi 3,1,12; addi 5,5,-1344; crxor 6,6,6; bl _s801C16AC_2; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s801C16AC_3; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 5,5,-1340; addi 3,1,16; crxor 6,6,6; bl _s801C16AC_4; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s801C16AC_5; addi 30,31,188; lis 5,-32705; addi 4,28,24012; addi 5,5,1784; addi 3,1,20; crxor 6,6,6; bl _s801C16AC_6; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,30; bl _s801C16AC_7; lwz 0,0x190(31); li 9,0; li 11,3; li 10,1; stw 11,0x8c(31); cmpwi 0,1; sth 9,0xce(31); stw 9,0x98(31); stw 10,0xa0(31); stw 9,0xa4(31); stw 11,0x84(31); stw 9,0x88(31); stw 9,0x94(31); stw 9,0x90(31); stw 9,0xc0(31); sth 9,0xcc(31); bne 4f; li 0,2; stw 0,0xd0(31); b 5f; 4:; stw 10,0xd0(31); 5:; addi 3,31,132; bl _s801C16AC_8; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s801C16AC_0();
extern "C" void _s801C16AC_1();
extern "C" void _s801C16AC_2();
extern "C" void _s801C16AC_3();
extern "C" void _s801C16AC_4();
extern "C" void _s801C16AC_5();
extern "C" void _s801C16AC_6();
extern "C" void _s801C16AC_7();
extern "C" void _s801C16AC_8();
extern "C" void f_801C16AC() {}
