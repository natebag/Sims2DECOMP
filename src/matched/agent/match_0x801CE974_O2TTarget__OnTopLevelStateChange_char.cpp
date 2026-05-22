// 0x801CE974 O2TTarget::OnTopLevelStateChange(char (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 31,0x24(1); stw 0,0x2c(1); mr 31,3; addi 3,1,8; bl _s801CE974_0; addi 3,1,8; bl _s801CE974_1; lwz 0,0x88(31); cmpwi 0,0; bne 0f; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,15928; bl _s801CE974_2; addi 3,1,8; li 4,1; bl _s801CE974_3; lis 4,-32705; addi 3,1,8; addi 4,4,15948; li 5,0; bl _s801CE974_4; addi 3,1,8; li 4,0; bl _s801CE974_5; b 1f; 0:; cmpwi 0,2; bne 1f; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,15928; bl _s801CE974_6; addi 3,1,8; li 4,0; bl _s801CE974_7; lis 4,-32705; addi 3,1,8; addi 4,4,15948; li 5,0; bl _s801CE974_8; addi 3,1,8; li 4,1; bl _s801CE974_9; 1:; addi 3,1,8; bl _s801CE974_10; mr 3,31; bl _s801CE974_11; addi 3,1,8; li 4,2; bl _s801CE974_12; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x24(1); addi 1,1,40"
extern "C" void _s801CE974_0();
extern "C" void _s801CE974_1();
extern "C" void _s801CE974_2();
extern "C" void _s801CE974_3();
extern "C" void _s801CE974_4();
extern "C" void _s801CE974_5();
extern "C" void _s801CE974_6();
extern "C" void _s801CE974_7();
extern "C" void _s801CE974_8();
extern "C" void _s801CE974_9();
extern "C" void _s801CE974_10();
extern "C" void _s801CE974_11();
extern "C" void _s801CE974_12();
extern "C" void f_801CE974() {}
