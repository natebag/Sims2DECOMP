// 0x801BD3C8 ITBTarget::GetLocalizable(char (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801BD3C8_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801BD3C8_1; mr 31,3; li 0,0; lis 3,-32705; sth 0,0x0(31); addi 3,3,6968; mr 4,30; bl _s801BD3C8_2; cmpwi 3,0; bne 1f; lwz 3,0x8c(29); bl _s801BD3C8_3; mr 4,3; mr 3,31; bl _s801BD3C8_4; 1:; mr 3,31; bl _s801BD3C8_5; mr 3,31; bl _s801BD3C8_6; mr 3,31; bl _s801BD3C8_7; mr 3,31; bl _s801BD3C8_8; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801BD3C8_9; mr 30,3; mr 4,31; bl _s801BD3C8_10; mr 3,31; bl _s801BD3C8_11; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801BD3C8_0();
extern "C" void _s801BD3C8_1();
extern "C" void _s801BD3C8_2();
extern "C" void _s801BD3C8_3();
extern "C" void _s801BD3C8_4();
extern "C" void _s801BD3C8_5();
extern "C" void _s801BD3C8_6();
extern "C" void _s801BD3C8_7();
extern "C" void _s801BD3C8_8();
extern "C" void _s801BD3C8_9();
extern "C" void _s801BD3C8_10();
extern "C" void _s801BD3C8_11();
extern "C" void f_801BD3C8() {}
