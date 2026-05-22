// 0x8014CC0C cFixedWorldImpl::Load(iResFile (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 27,5; mr 30,4; lwz 3,0x2c(31); lis 5,16754; ori 5,5,29305; li 6,11; li 7,0; bl _s8014CC0C_0; mr. 3,3; bne 5f; lwz 3,0x38(31); lis 5,16754; mr 4,30; ori 5,5,29305; li 6,12; li 7,0; bl _s8014CC0C_1; mr. 3,3; bne 5f; lwz 3,0x34(31); lis 5,16754; mr 4,30; ori 5,5,29305; li 6,8; li 7,0; bl _s8014CC0C_2; mr. 3,3; bne 5f; lwz 9,0x2c(31); lwz 28,0x4(9); lwz 29,0x8(9); lwz 0,0x14(31); cmpw 29,0; bne 0f; lwz 0,0x18(31); cmpw 28,0; beq 4f; 0:; lwz 3,0x30(31); cmpwi 3,0; beq 1f; li 4,3; bl _s8014CC0C_3; 1:; li 3,24; bl _s8014CC0C_4; mr 30,3; lis 4,-32706; addi 3,1,8; addi 4,4,-8660; bl _s8014CC0C_5; li 4,2; mr 5,29; mr 6,28; addi 7,1,8; mr 3,30; bl _s8014CC0C_6; addi 3,1,8; li 4,2; bl _s8014CC0C_7; lwz 3,0x3c(31); stw 30,0x30(31); cmpwi 3,0; beq 2f; li 4,3; bl _s8014CC0C_8; 2:; li 3,12; bl _s8014CC0C_9; mr 4,29; mr 5,28; bl _s8014CC0C_10; lwz 0,0x40(31); stw 3,0x3c(31); cmpwi 0,0; beq 3f; mr 3,0; li 4,3; bl _s8014CC0C_11; 3:; li 3,12; bl _s8014CC0C_12; mr 4,29; mr 5,28; bl _s8014CC0C_13; stw 3,0x40(31); cmpwi 27,80; stw 29,0x14(31); stw 28,0x18(31); bgt 4f; cmpwi 29,64; bne 4f; cmpwi 28,64; bne 4f; lwz 9,0x0(31); li 4,39; li 5,39; li 6,1; lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; 4:; li 3,0; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8014CC0C_0();
extern "C" void _s8014CC0C_1();
extern "C" void _s8014CC0C_2();
extern "C" void _s8014CC0C_3();
extern "C" void _s8014CC0C_4();
extern "C" void _s8014CC0C_5();
extern "C" void _s8014CC0C_6();
extern "C" void _s8014CC0C_7();
extern "C" void _s8014CC0C_8();
extern "C" void _s8014CC0C_9();
extern "C" void _s8014CC0C_10();
extern "C" void _s8014CC0C_11();
extern "C" void _s8014CC0C_12();
extern "C" void _s8014CC0C_13();
extern "C" void f_8014CC0C() {}
