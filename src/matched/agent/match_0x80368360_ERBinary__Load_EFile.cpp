// 0x80368360 ERBinary::Load(EFile (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; mr 30,4; bl _s80368360_0; addi 3,1,8; bl _s80368360_1; lis 5,16969; addi 3,1,8; mr 4,30; ori 5,5,20050; li 6,6; li 7,6; bl _s80368360_2; cmpwi 3,0; bne 0f; addi 3,1,8; li 4,2; bl _s80368360_3; b 1f; 0:; addi 3,1,8; bl _s80368360_4; lwz 9,0x18(1); lis 3,-32693; lwz 0,0x10(31); li 5,8; mr 4,9; addi 3,3,17784; rlwimi 0,9,8,0,23; stw 0,0x10(31); bl _s80368360_5; lwz 5,0x18(1); mr 4,3; stw 4,0x14(31); stw 5,0x18(31); lwz 9,0x28(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s80368360_6; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s80368360_0();
extern "C" void _s80368360_1();
extern "C" void _s80368360_2();
extern "C" void _s80368360_3();
extern "C" void _s80368360_4();
extern "C" void _s80368360_5();
extern "C" void _s80368360_6();
extern "C" void f_80368360() {}
