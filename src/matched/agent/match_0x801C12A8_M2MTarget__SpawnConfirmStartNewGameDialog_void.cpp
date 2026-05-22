// 0x801C12A8 M2MTarget::SpawnConfirmStartNewGameDialog(void) (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; lis 29,-32697; lis 5,-32705; addi 4,29,24012; addi 5,5,8780; addi 3,1,8; crxor 6,6,6; bl _s801C12A8_0; addi 30,31,172; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s801C12A8_1; addi 30,31,180; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,-1344; addi 3,1,12; crxor 6,6,6; bl _s801C12A8_2; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s801C12A8_3; addi 30,31,184; lis 5,-32705; addi 4,29,24012; addi 5,5,-1340; addi 3,1,16; crxor 6,6,6; bl _s801C12A8_4; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s801C12A8_5; lis 4,-32705; addi 3,31,188; addi 4,4,-8284; bl _s801C12A8_6; lwz 11,0x190(31); li 0,0; li 10,1; li 8,2; li 9,3; sth 0,0xce(31); stw 9,0x8c(31); cmpwi 11,1; stw 8,0x84(31); stw 0,0x98(31); stw 10,0xa0(31); stw 10,0xa4(31); stw 10,0x88(31); stw 0,0x94(31); stw 0,0x90(31); stw 0,0xc0(31); sth 0,0xcc(31); bne 3f; stw 8,0xd0(31); b 4f; 3:; stw 10,0xd0(31); 4:; addi 3,31,132; bl _s801C12A8_7; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801C12A8_0();
extern "C" void _s801C12A8_1();
extern "C" void _s801C12A8_2();
extern "C" void _s801C12A8_3();
extern "C" void _s801C12A8_4();
extern "C" void _s801C12A8_5();
extern "C" void _s801C12A8_6();
extern "C" void _s801C12A8_7();
extern "C" void f_801C12A8() {}
