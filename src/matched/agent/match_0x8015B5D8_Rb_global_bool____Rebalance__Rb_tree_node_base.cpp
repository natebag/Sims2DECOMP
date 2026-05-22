// 0x8015B5D8 _Rb_global<bool>::_Rebalance(_Rb_tree_node_base (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8015B774" lines="addi 5,1,8; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,29,3; mtspr 8,0; blrl; lha 4,0x8(1); mr 3,28; bl _s8015B5D8_0; li 3,1; b 0f; li 3,0; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lwz 9,-21508(13); mr 29,3; mr 25,4; lwz 11,0x0(9); lwz 4,0x0(25); lha 3,0x38(11); lwz 0,0x3c(11); add 3,9,3; mtspr 8,0; blrl; mr 26,3; mr 3,29; bl _s8015B5D8_1; mulli 30,3,12; bl _s8015B5D8_2; li 4,12; li 5,0; bl _s8015B5D8_3; addi 30,30,12; mr 27,3; cmpwi 30,0; stw 30,0x0(27); beq 1f; bl _s8015B5D8_4; mr 4,30; li 5,0; bl _s8015B5D8_5; stw 3,0x4(27); b 2f; 1:; stw 30,0x4(27); 2:; li 0,1; lwz 31,0x4(27); stw 0,0x8(27); mr 3,29; bl _s8015B5D8_6; li 30,0; stb 3,0x6(31); li 28,0; mr 3,29; bl _s8015B5D8_7; sth 3,0x2(31); mr 3,29; bl _s8015B5D8_8; stb 3,0x5(31); mr 3,29; bl _s8015B5D8_9; sth 3,0x0(31); mr 3,29; bl _s8015B5D8_10; stw 3,0x8(31); mr 3,29; bl _s8015B5D8_11; stb 3,0x4(31); stb 30,0x7(31); addi 30,29,12"
extern "C" void _s8015B5D8_0();
extern "C" void _s8015B5D8_1();
extern "C" void _s8015B5D8_2();
extern "C" void _s8015B5D8_3();
extern "C" void _s8015B5D8_4();
extern "C" void _s8015B5D8_5();
extern "C" void _s8015B5D8_6();
extern "C" void _s8015B5D8_7();
extern "C" void _s8015B5D8_8();
extern "C" void _s8015B5D8_9();
extern "C" void _s8015B5D8_10();
extern "C" void _s8015B5D8_11();
extern "C" void f_8015B774();
extern "C" void f_8015B5D8() {}
