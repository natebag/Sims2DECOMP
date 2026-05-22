// 0x8018C564 LoadGameTarget::SpawnFormattingDialog(void) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-18632; addi 3,1,8; crxor 6,6,6; bl _s8018C564_0; addi 30,31,172; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s8018C564_1; lis 30,-32705; addi 4,30,-19228; addi 3,31,180; bl _s8018C564_2; addi 4,30,-19228; addi 3,31,184; bl _s8018C564_3; addi 4,30,-19228; addi 3,31,188; bl _s8018C564_4; lwz 10,-26512(13); li 0,0; li 9,3; li 11,1; stw 9,0x8c(31); addi 3,31,132; stw 11,0x90(31); stw 0,0x98(31); stw 0,0xa0(31); stw 0,0x84(31); stw 0,0x88(31); stw 0,0x94(31); stw 0,0xc0(31); sth 0,0xcc(31); sth 0,0xce(31); stw 0,0xc(10); bl _s8018C564_5; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8018C564_0();
extern "C" void _s8018C564_1();
extern "C" void _s8018C564_2();
extern "C" void _s8018C564_3();
extern "C" void _s8018C564_4();
extern "C" void _s8018C564_5();
extern "C" void f_8018C564() {}
