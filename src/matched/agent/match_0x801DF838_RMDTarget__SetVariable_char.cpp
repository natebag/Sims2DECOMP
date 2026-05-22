// 0x801DF838 RMDTarget::SetVariable(char (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801DF838_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lwz 3,-29680(13); mr 4,31; bl _s801DF838_1; cmpwi 3,0; bne 1f; lwz 0,0x88(30); cmpwi 0,2; bne 3f; mr 3,30; bl _s801DF838_2; b 3f; 1:; lwz 3,-29672(13); mr 4,31; bl _s801DF838_3; cmpwi 3,0; bne 2f; li 0,2; addi 3,1,8; stw 0,0x88(30); bl _s801DF838_4; addi 3,1,8; bl _s801DF838_5; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,21520; bl _s801DF838_6; addi 3,1,8; li 4,1; bl _s801DF838_7; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,21532; bl _s801DF838_8; addi 3,1,8; li 4,1; bl _s801DF838_9; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,21552; bl _s801DF838_10; li 4,1; addi 3,1,8; bl _s801DF838_11; addi 3,1,8; bl _s801DF838_12; addi 3,1,8; li 4,2; bl _s801DF838_13; b 3f; 2:; lwz 3,-29664(13); mr 4,31; bl _s801DF838_14; cmpwi 3,0; bne 3f; addi 3,1,8; bl _s801DF838_15; lis 4,-32705; addi 3,1,8; addi 4,4,21572; li 6,0; li 5,0; bl _s801DF838_16; mr 3,30; bl _s801DF838_17; addi 3,1,8; li 4,2; bl _s801DF838_18; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801DF838_0();
extern "C" void _s801DF838_1();
extern "C" void _s801DF838_2();
extern "C" void _s801DF838_3();
extern "C" void _s801DF838_4();
extern "C" void _s801DF838_5();
extern "C" void _s801DF838_6();
extern "C" void _s801DF838_7();
extern "C" void _s801DF838_8();
extern "C" void _s801DF838_9();
extern "C" void _s801DF838_10();
extern "C" void _s801DF838_11();
extern "C" void _s801DF838_12();
extern "C" void _s801DF838_13();
extern "C" void _s801DF838_14();
extern "C" void _s801DF838_15();
extern "C" void _s801DF838_16();
extern "C" void _s801DF838_17();
extern "C" void _s801DF838_18();
extern "C" void f_801DF838() {}
