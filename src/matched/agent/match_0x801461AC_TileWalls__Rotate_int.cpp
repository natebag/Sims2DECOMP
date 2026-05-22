// 0x801461AC TileWalls::Rotate(int) (648 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 27,0x44(1); stw 0,0x5c(1); mr 31,3; mr 28,4; mr 4,31; addi 3,1,8; bl _s801461AC_0; lwz 0,0x2c(1); addi 3,1,8; add 0,0,28; rlwinm 0,0,0,30,31; stw 0,0x2c(1); bl _s801461AC_1; mr 3,31; bl _s801461AC_2; mr. 27,3; beq 5f; 0:; mr 4,28; mr 3,27; bl _s801461AC_3; mr 29,3; addi 3,1,8; mr 4,29; bl _s801461AC_4; mr 4,27; mr 3,31; bl _s801461AC_5; mr 4,3; mr 5,29; addi 3,1,8; bl _s801461AC_6; cmpwi 27,32; bne 1f; li 5,1; li 4,32; mr 3,31; bl _s801461AC_7; mr 30,3; mr 4,28; li 3,1; bl _s801461AC_8; mr 6,3; mr 4,30; addi 3,1,8; mr 5,29; bl _s801461AC_9; li 5,3; li 4,32; mr 3,31; bl _s801461AC_10; mr 30,3; mr 4,28; li 3,3; bl _s801461AC_11; mr 6,3; mr 5,29; addi 3,1,8; mr 4,30; bl _s801461AC_12; li 4,3; mr 3,31; bl _s801461AC_13; mr 30,3; mr 4,28; li 3,3; bl _s801461AC_14; mr 5,3; mr 4,30; addi 3,1,8; bl _s801461AC_15; li 4,1; mr 3,31; bl _s801461AC_16; mr 30,3; mr 4,28; li 3,1; b 2f; 1:; cmpwi 27,16; bne 3f; li 5,2; li 4,16; mr 3,31; bl _s801461AC_17; mr 30,3; mr 4,28; li 3,2; bl _s801461AC_18; mr 6,3; mr 4,30; addi 3,1,8; mr 5,29; bl _s801461AC_19; li 5,4; li 4,16; mr 3,31; bl _s801461AC_20; mr 30,3; mr 4,28; li 3,4; bl _s801461AC_21; mr 6,3; mr 5,29; addi 3,1,8; mr 4,30; bl _s801461AC_22; li 4,2; mr 3,31; bl _s801461AC_23; mr 30,3; mr 4,28; li 3,2; bl _s801461AC_24; mr 5,3; mr 4,30; addi 3,1,8; bl _s801461AC_25; li 4,4; mr 3,31; bl _s801461AC_26; mr 30,3; mr 4,28; li 3,4; 2:; bl _s801461AC_27; mr 5,3; mr 4,30; addi 3,1,8; bl _s801461AC_28; b 4f; 3:; mr 4,27; li 5,0; mr 3,31; bl _s801461AC_29; mr 4,3; mr 5,29; addi 3,1,8; li 6,0; bl _s801461AC_30; 4:; mr 4,27; mr 3,31; bl _s801461AC_31; mr 4,3; mr 5,29; addi 3,1,8; bl _s801461AC_32; mr 4,27; mr 3,31; bl _s801461AC_33; mr. 27,3; bne 0b; 5:; addi 4,1,8; mr 3,31; bl _s801461AC_34; addi 3,1,8; li 4,2; bl _s801461AC_35; lwz 0,0x5c(1); mtspr 8,0; lmw 27,0x44(1); addi 1,1,88"
extern "C" void _s801461AC_0();
extern "C" void _s801461AC_1();
extern "C" void _s801461AC_2();
extern "C" void _s801461AC_3();
extern "C" void _s801461AC_4();
extern "C" void _s801461AC_5();
extern "C" void _s801461AC_6();
extern "C" void _s801461AC_7();
extern "C" void _s801461AC_8();
extern "C" void _s801461AC_9();
extern "C" void _s801461AC_10();
extern "C" void _s801461AC_11();
extern "C" void _s801461AC_12();
extern "C" void _s801461AC_13();
extern "C" void _s801461AC_14();
extern "C" void _s801461AC_15();
extern "C" void _s801461AC_16();
extern "C" void _s801461AC_17();
extern "C" void _s801461AC_18();
extern "C" void _s801461AC_19();
extern "C" void _s801461AC_20();
extern "C" void _s801461AC_21();
extern "C" void _s801461AC_22();
extern "C" void _s801461AC_23();
extern "C" void _s801461AC_24();
extern "C" void _s801461AC_25();
extern "C" void _s801461AC_26();
extern "C" void _s801461AC_27();
extern "C" void _s801461AC_28();
extern "C" void _s801461AC_29();
extern "C" void _s801461AC_30();
extern "C" void _s801461AC_31();
extern "C" void _s801461AC_32();
extern "C" void _s801461AC_33();
extern "C" void _s801461AC_34();
extern "C" void _s801461AC_35();
extern "C" void f_801461AC() {}
