// 0x801C3734 MDITarget::SetVariable(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801C3734_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lis 3,-32705; mr 4,31; addi 3,3,9528; bl _s801C3734_1; mr. 3,3; bne 1f; stw 3,0x98(30); b 2f; 1:; lis 3,-32705; mr 4,31; addi 3,3,9548; bl _s801C3734_2; mr. 31,3; bne 2f; stw 31,0x98(30); addi 3,1,8; bl _s801C3734_3; lis 4,-32705; addi 3,1,8; addi 4,4,9568; li 5,0; li 6,0; bl _s801C3734_4; stw 31,0x94(30); addi 3,1,8; li 4,2; bl _s801C3734_5; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801C3734_0();
extern "C" void _s801C3734_1();
extern "C" void _s801C3734_2();
extern "C" void _s801C3734_3();
extern "C" void _s801C3734_4();
extern "C" void _s801C3734_5();
extern "C" void f_801C3734() {}
