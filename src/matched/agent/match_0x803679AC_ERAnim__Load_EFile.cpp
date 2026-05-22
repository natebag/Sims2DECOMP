// 0x803679AC ERAnim::Load(EFile (752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 26,0x30(1); stw 0,0x4c(1); mr 31,3; mr 27,4; addi 3,1,8; bl _s803679AC_0; lis 5,16718; addi 3,1,8; mr 4,27; ori 5,5,18765; li 6,17; li 7,18; bl _s803679AC_1; cmpwi 3,0; beq 1f; addi 3,1,8; addi 29,31,80; bl _s803679AC_2; addi 28,31,136; lwz 9,0x18(1); lwz 0,0x10(31); rlwimi 0,9,8,0,23; stw 0,0x10(31); bl _s803679AC_3; lwz 4,0x18(1); li 5,0; bl _s803679AC_4; lwz 9,0x28(27); mr 26,3; lwz 5,0x18(1); mr 4,26; lwz 0,0x1c(9); addi 30,26,28; lha 3,0x18(9); mtspr 8,0; add 3,27,3; blrl; mr 4,26; li 5,4; addi 3,31,24; bl _s803679AC_5; addi 4,26,4; li 5,12; addi 3,31,28; bl _s803679AC_6; li 5,12; addi 4,26,16; addi 3,31,40; bl _s803679AC_7; mr 4,30; addi 3,31,52; bl _s803679AC_8; add 30,30,3; li 5,4; mr 4,30; addi 3,31,64; bl _s803679AC_9; addi 30,30,4; mr 4,30; addi 3,31,68; bl _s803679AC_10; add 30,30,3; li 5,4; addi 3,1,32; mr 4,30; bl _s803679AC_11; addi 30,30,4; mr 3,29; li 4,0; li 5,0; bl _s803679AC_12; lwz 4,0x20(1); li 5,0; mr 3,29; bl _s803679AC_13; mr 3,29; bl _s803679AC_14; rlwinm 0,3,2,0,29; mr 4,30; lwz 3,0x50(31); add 30,30,0; mr 5,0; bl _s803679AC_15; mr 4,30; li 5,4; addi 3,31,100; addi 30,30,4; bl _s803679AC_16; mr 4,30; li 5,4; addi 3,31,104; addi 30,30,4; bl _s803679AC_17; mr 4,30; li 5,4; addi 3,31,108; addi 30,30,4; bl _s803679AC_18; mr 4,30; li 5,1; addi 3,31,114; addi 30,30,1; bl _s803679AC_19; mr 4,30; li 5,4; addi 3,31,116; addi 30,30,4; bl _s803679AC_20; mr 4,30; li 5,4; addi 3,31,120; addi 30,30,4; bl _s803679AC_21; mr 4,30; li 5,4; addi 3,31,124; addi 30,30,4; bl _s803679AC_22; mr 4,30; li 5,4; addi 3,31,128; addi 30,30,4; bl _s803679AC_23; mr 4,30; li 5,1; addi 3,31,112; addi 30,30,1; bl _s803679AC_24; mr 4,30; li 5,1; addi 3,31,113; addi 30,30,1; bl _s803679AC_25; mr 4,30; mr 3,28; bl _s803679AC_26; add 30,30,3; mr 4,30; addi 3,31,148; bl _s803679AC_27; lwz 0,0x18(31); lis 8,17200; lis 9,-32702; xoris 0,0,32768; lfd f13,0x3280(9); stw 0,0x2c(1); lis 9,-32702; lfs f10,0x64(31); mr 10,11; stw 8,0x28(1); lfs f11,0x3288(9); lfd f0,0x28(1); fsub f0,f0,f13; frsp f0,f0; fdivs f0,f0,f10; fmuls f0,f0,f11; fmr f13,f0; fctiwz f12,f13; stfd f12,0x28(1); lwz 0,0x2c(1); stw 0,0x14(31); lwz 9,0x4(28); cmpwi 9,0; beq 0f; addi 9,9,-1; lwz 11,0x88(31); mulli 9,9,12; lwzx 9,11,9; cmpw 9,0; ble 0f; stw 9,0x14(31); 0:; bl _s803679AC_28; mr 4,26; bl _s803679AC_29; b 2f; 1:; mr 3,31; mr 4,27; bl _s803679AC_30; 2:; addi 3,1,8; li 4,2; bl _s803679AC_31; lwz 0,0x4c(1); mtspr 8,0; lmw 26,0x30(1); addi 1,1,72"
extern "C" void _s803679AC_0();
extern "C" void _s803679AC_1();
extern "C" void _s803679AC_2();
extern "C" void _s803679AC_3();
extern "C" void _s803679AC_4();
extern "C" void _s803679AC_5();
extern "C" void _s803679AC_6();
extern "C" void _s803679AC_7();
extern "C" void _s803679AC_8();
extern "C" void _s803679AC_9();
extern "C" void _s803679AC_10();
extern "C" void _s803679AC_11();
extern "C" void _s803679AC_12();
extern "C" void _s803679AC_13();
extern "C" void _s803679AC_14();
extern "C" void _s803679AC_15();
extern "C" void _s803679AC_16();
extern "C" void _s803679AC_17();
extern "C" void _s803679AC_18();
extern "C" void _s803679AC_19();
extern "C" void _s803679AC_20();
extern "C" void _s803679AC_21();
extern "C" void _s803679AC_22();
extern "C" void _s803679AC_23();
extern "C" void _s803679AC_24();
extern "C" void _s803679AC_25();
extern "C" void _s803679AC_26();
extern "C" void _s803679AC_27();
extern "C" void _s803679AC_28();
extern "C" void _s803679AC_29();
extern "C" void _s803679AC_30();
extern "C" void _s803679AC_31();
extern "C" void f_803679AC() {}
