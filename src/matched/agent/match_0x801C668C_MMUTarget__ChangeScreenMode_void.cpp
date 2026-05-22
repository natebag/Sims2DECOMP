// 0x801C668C MMUTarget::ChangeScreenMode(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; lwz 30,0x8c(31); cmpwi 30,0; bne 0f; addi 3,1,8; bl _s801C668C_0; addi 3,1,8; bl _s801C668C_1; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,11008; bl _s801C668C_2; li 4,0; addi 3,1,8; bl _s801C668C_3; addi 3,1,8; bl _s801C668C_4; li 0,1; stw 30,0x90(31); mr 3,31; stw 0,0x8c(31); bl _s801C668C_5; addi 3,1,8; li 4,2; bl _s801C668C_6; b 1f; 0:; cmpwi 30,1; bne 1f; lwz 0,0x9c(31); lis 4,-32700; addi 4,4,-25964; lis 3,-32697; rlwinm 0,0,4,0,27; addi 3,3,-7672; add 4,0,4; bl _s801C668C_7; li 0,2; stw 30,0x90(31); stw 0,0x8c(31); mr 3,31; bl _s801C668C_8; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801C668C_0();
extern "C" void _s801C668C_1();
extern "C" void _s801C668C_2();
extern "C" void _s801C668C_3();
extern "C" void _s801C668C_4();
extern "C" void _s801C668C_5();
extern "C" void _s801C668C_6();
extern "C" void _s801C668C_7();
extern "C" void _s801C668C_8();
extern "C" void f_801C668C() {}
