// 0x801A4DC0 CRDTarget::ShowCredits(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; li 30,1; li 0,0; stw 30,0x90(31); lis 3,-32697; stw 0,0x98(31); addi 3,3,24012; li 4,9; bl _s801A4DC0_0; mr. 3,3; beq 0f; stw 30,0xc0(31); b 1f; 0:; stw 3,0xc0(31); 1:; lwz 0,0x88(31); cmpwi 0,0; bne 2f; lwz 0,0x8c(31); cmpwi 0,0; bne 2f; lis 9,-32697; li 4,42; lwz 3,0x5f10(9); li 5,0; lis 30,-32705; bl _s801A4DC0_1; addi 3,1,8; bl _s801A4DC0_2; addi 3,1,8; bl _s801A4DC0_3; addi 3,1,8; li 5,0; addi 4,30,-7816; bl _s801A4DC0_4; addi 3,1,8; li 4,0; bl _s801A4DC0_5; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-7812; bl _s801A4DC0_6; addi 3,1,8; li 4,119; bl _s801A4DC0_7; addi 3,1,8; bl _s801A4DC0_8; lis 7,-32705; addi 3,1,8; li 6,0; li 8,0; addi 7,7,-7976; li 5,250; addi 4,30,-7816; bl _s801A4DC0_9; li 4,255; addi 3,1,8; bl _s801A4DC0_10; addi 3,1,8; bl _s801A4DC0_11; li 0,1; addi 3,1,8; stw 0,0x8c(31); li 4,2; stw 0,0x88(31); bl _s801A4DC0_12; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801A4DC0_0();
extern "C" void _s801A4DC0_1();
extern "C" void _s801A4DC0_2();
extern "C" void _s801A4DC0_3();
extern "C" void _s801A4DC0_4();
extern "C" void _s801A4DC0_5();
extern "C" void _s801A4DC0_6();
extern "C" void _s801A4DC0_7();
extern "C" void _s801A4DC0_8();
extern "C" void _s801A4DC0_9();
extern "C" void _s801A4DC0_10();
extern "C" void _s801A4DC0_11();
extern "C" void _s801A4DC0_12();
extern "C" void f_801A4DC0() {}
