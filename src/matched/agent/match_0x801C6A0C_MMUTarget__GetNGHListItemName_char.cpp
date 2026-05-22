// 0x801C6A0C MMUTarget::GetNGHListItemName(char (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-280(1); mfspr 0,8; stmw 29,0x10c(1); stw 0,0x11c(1); mr 30,4; li 29,0; lis 4,-32705; mr 3,30; addi 4,4,10716; bl _s801C6A0C_0; cmpwi 3,0; beq 4f; lis 4,-32705; mr 3,30; addi 4,4,10728; bl _s801C6A0C_1; cmpwi 3,0; bne 0f; li 29,1; b 4f; 0:; lis 4,-32705; mr 3,30; addi 4,4,10740; bl _s801C6A0C_2; cmpwi 3,0; bne 1f; li 29,2; b 4f; 1:; lis 4,-32705; mr 3,30; addi 4,4,10752; bl _s801C6A0C_3; cmpwi 3,0; bne 2f; li 29,3; b 4f; 2:; lis 4,-32705; mr 3,30; addi 4,4,10764; bl _s801C6A0C_4; cmpwi 3,0; bne 3f; li 29,4; b 4f; 3:; lis 4,-32705; mr 3,30; addi 4,4,10776; bl _s801C6A0C_5; cmpwi 3,0; bne 4f; li 29,5; 4:; lis 4,-32700; rlwinm 0,29,4,0,27; addi 4,4,-26060; addi 3,1,8; add 4,0,4; bl _s801C6A0C_6; li 3,8192; bl _s801C6A0C_7; mr 30,3; addi 3,1,8; bl _s801C6A0C_8; addi 4,3,1; mr 5,30; addi 3,1,8; bl _s801C6A0C_9; mr 3,30; bl _s801C6A0C_10; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801C6A0C_11; mr 29,3; mr 4,30; bl _s801C6A0C_12; mr 3,30; bl _s801C6A0C_13; mr 3,29; lwz 0,0x11c(1); mtspr 8,0; lmw 29,0x10c(1); addi 1,1,280"
extern "C" void _s801C6A0C_0();
extern "C" void _s801C6A0C_1();
extern "C" void _s801C6A0C_2();
extern "C" void _s801C6A0C_3();
extern "C" void _s801C6A0C_4();
extern "C" void _s801C6A0C_5();
extern "C" void _s801C6A0C_6();
extern "C" void _s801C6A0C_7();
extern "C" void _s801C6A0C_8();
extern "C" void _s801C6A0C_9();
extern "C" void _s801C6A0C_10();
extern "C" void _s801C6A0C_11();
extern "C" void _s801C6A0C_12();
extern "C" void _s801C6A0C_13();
extern "C" void f_801C6A0C() {}
