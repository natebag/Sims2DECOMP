// 0x800B55D0 EdithDialogPrimitive::ResetDialogParameters(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; addi 3,1,8; addi 30,31,40; bl _s800B55D0_0; addi 29,31,44; addi 4,1,8; mr 3,30; bl _s800B55D0_1; addi 30,31,48; addi 3,1,8; li 4,2; bl _s800B55D0_2; addi 28,31,52; addi 3,1,8; addi 27,31,56; bl _s800B55D0_3; addi 4,1,8; mr 3,29; bl _s800B55D0_4; addi 3,1,8; li 4,2; bl _s800B55D0_5; addi 3,1,8; bl _s800B55D0_6; addi 4,1,8; mr 3,30; bl _s800B55D0_7; addi 3,1,8; li 4,2; bl _s800B55D0_8; addi 3,1,8; bl _s800B55D0_9; addi 4,1,8; mr 3,28; bl _s800B55D0_10; addi 3,1,8; li 4,2; bl _s800B55D0_11; addi 3,1,8; bl _s800B55D0_12; addi 4,1,8; mr 3,27; bl _s800B55D0_13; addi 3,1,8; li 4,2; bl _s800B55D0_14; lwz 3,0x3c(31); cmpwi 3,0; beq 0f; bl _s800B55D0_15; li 0,0; stw 0,0x3c(31); 0:; li 9,0; li 0,-1; stw 0,0x18(31); sth 9,0x4a(31); stw 9,0x44(31); sth 9,0x48(31); lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800B55D0_0();
extern "C" void _s800B55D0_1();
extern "C" void _s800B55D0_2();
extern "C" void _s800B55D0_3();
extern "C" void _s800B55D0_4();
extern "C" void _s800B55D0_5();
extern "C" void _s800B55D0_6();
extern "C" void _s800B55D0_7();
extern "C" void _s800B55D0_8();
extern "C" void _s800B55D0_9();
extern "C" void _s800B55D0_10();
extern "C" void _s800B55D0_11();
extern "C" void _s800B55D0_12();
extern "C" void _s800B55D0_13();
extern "C" void _s800B55D0_14();
extern "C" void _s800B55D0_15();
extern "C" void f_800B55D0() {}
