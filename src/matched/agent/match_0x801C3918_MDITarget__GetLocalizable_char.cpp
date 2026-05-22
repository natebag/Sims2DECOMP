// 0x801C3918 MDITarget::GetLocalizable(char (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801C3918_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801C3918_1; mr 31,3; li 0,0; lis 3,-32705; sth 0,0x0(31); addi 3,3,9644; mr 4,30; bl _s801C3918_2; cmpwi 3,0; bne 1f; lwz 3,0x84(29); cmpwi 3,0; beq 2f; bl _s801C3918_3; mr 4,3; mr 3,31; bl _s801C3918_4; b 2f; 1:; lis 3,-32705; mr 4,30; addi 3,3,9656; bl _s801C3918_5; cmpwi 3,0; bne 2f; lwz 3,0x84(29); cmpwi 3,0; beq 2f; addi 3,3,4; bl _s801C3918_6; mr 4,3; mr 3,31; bl _s801C3918_7; 2:; mr 3,31; bl _s801C3918_8; mr 3,31; bl _s801C3918_9; mr 3,31; bl _s801C3918_10; mr 3,31; bl _s801C3918_11; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801C3918_12; mr 30,3; mr 4,31; bl _s801C3918_13; mr 3,31; bl _s801C3918_14; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C3918_0();
extern "C" void _s801C3918_1();
extern "C" void _s801C3918_2();
extern "C" void _s801C3918_3();
extern "C" void _s801C3918_4();
extern "C" void _s801C3918_5();
extern "C" void _s801C3918_6();
extern "C" void _s801C3918_7();
extern "C" void _s801C3918_8();
extern "C" void _s801C3918_9();
extern "C" void _s801C3918_10();
extern "C" void _s801C3918_11();
extern "C" void _s801C3918_12();
extern "C" void _s801C3918_13();
extern "C" void _s801C3918_14();
extern "C" void f_801C3918() {}
