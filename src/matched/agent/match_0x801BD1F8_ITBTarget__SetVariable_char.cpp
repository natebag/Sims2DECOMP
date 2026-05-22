// 0x801BD1F8 ITBTarget::SetVariable(char (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801BD1F8_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lis 3,-32705; mr 4,31; addi 3,3,6916; bl _s801BD1F8_1; mr. 3,3; beq 4f; lis 3,-32705; mr 4,31; addi 3,3,6944; bl _s801BD1F8_2; cmpwi 3,0; bne 1f; li 0,4; addi 3,1,8; stw 0,0x90(30); bl _s801BD1F8_3; lis 4,-32705; lis 7,-32705; addi 3,1,8; li 5,125; li 6,0; li 8,0; addi 7,7,-8764; addi 4,4,6968; bl _s801BD1F8_4; li 4,255; addi 3,1,8; bl _s801BD1F8_5; addi 3,1,8; bl _s801BD1F8_6; addi 3,1,8; li 4,2; bl _s801BD1F8_7; b 5f; 1:; lis 3,-32705; mr 4,31; addi 3,3,6980; bl _s801BD1F8_8; cmpwi 3,0; bne 2f; li 0,2; stw 0,0x90(30); b 5f; 2:; lis 3,-32705; mr 4,31; addi 3,3,7008; bl _s801BD1F8_9; cmpwi 3,0; bne 3f; li 0,3; stw 0,0x90(30); b 5f; 3:; lis 3,-32705; mr 4,31; addi 3,3,7040; bl _s801BD1F8_10; mr. 3,3; bne 5f; stw 3,0x88(30); 4:; stw 3,0x94(30); 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801BD1F8_0();
extern "C" void _s801BD1F8_1();
extern "C" void _s801BD1F8_2();
extern "C" void _s801BD1F8_3();
extern "C" void _s801BD1F8_4();
extern "C" void _s801BD1F8_5();
extern "C" void _s801BD1F8_6();
extern "C" void _s801BD1F8_7();
extern "C" void _s801BD1F8_8();
extern "C" void _s801BD1F8_9();
extern "C" void _s801BD1F8_10();
extern "C" void f_801BD1F8() {}
