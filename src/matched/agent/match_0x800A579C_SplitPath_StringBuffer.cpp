// 0x800A579C SplitPath(StringBuffer (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 30,3; mr 26,4; mr 25,5; mr 24,6; li 28,-1; bl _s800A579C_0; addi 31,3,-1; b 1f; 0:; addi 31,31,-1; 1:; cmpwi 31,0; blt 3f; mr 3,30; mr 4,31; bl _s800A579C_1; cmpwi 3,92; beq 2f; mr 3,30; mr 4,31; bl _s800A579C_2; cmpwi 3,47; bne 0b; 2:; mr 28,31; 3:; mr 3,30; bl _s800A579C_3; mr 29,3; addi 31,29,-1; addi 27,28,1; b 5f; 4:; addi 31,31,-1; 5:; cmpw 31,28; ble 6f; mr 3,30; mr 4,31; bl _s800A579C_4; cmpwi 3,46; bne 4b; mr 29,31; 6:; mr 3,26; bl _s800A579C_5; mr 5,27; mr 4,30; mr 3,26; bl _s800A579C_6; mr 3,25; bl _s800A579C_7; mr 3,30; bl _s800A579C_8; add 4,3,28; subf 5,28,29; addi 4,4,1; addi 5,5,-1; mr 3,25; bl _s800A579C_9; mr 3,24; bl _s800A579C_10; mr 3,30; bl _s800A579C_11; add 4,3,29; li 5,-1; mr 3,24; bl _s800A579C_12; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s800A579C_0();
extern "C" void _s800A579C_1();
extern "C" void _s800A579C_2();
extern "C" void _s800A579C_3();
extern "C" void _s800A579C_4();
extern "C" void _s800A579C_5();
extern "C" void _s800A579C_6();
extern "C" void _s800A579C_7();
extern "C" void _s800A579C_8();
extern "C" void _s800A579C_9();
extern "C" void _s800A579C_10();
extern "C" void _s800A579C_11();
extern "C" void _s800A579C_12();
extern "C" void f_800A579C() {}
