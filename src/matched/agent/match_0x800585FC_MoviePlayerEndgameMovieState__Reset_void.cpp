// 0x800585FC MoviePlayerEndgameMovieState::Reset(void) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s800585FC_0; lis 3,-32697; addi 3,3,23428; bl _s800585FC_1; lwz 11,-22652(13); mr 30,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22652(13); lwz 9,0x0(11); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,-21492(13); bl _s800585FC_2; bl _s800585FC_3; bl _s800585FC_4; bl _s800585FC_5; bl _s800585FC_6; bl _s800585FC_7; bl _s800585FC_8; bl _s800585FC_9; bl _s800585FC_10; bl _s800585FC_11; bl _s800585FC_12; bl _s800585FC_13; bl _s800585FC_14; bl _s800585FC_15; bl _s800585FC_16; bl _s800585FC_17; bl _s800585FC_18; bl _s800585FC_19; bl _s800585FC_20; bl _s800585FC_21; bl _s800585FC_22; bl _s800585FC_23; bl _s800585FC_24; bl _s800585FC_25; bl _s800585FC_26; bl _s800585FC_27; bl _s800585FC_28; bl _s800585FC_29; lwz 10,-26564(13); lis 9,-32707; lwz 11,0x0(10); lfs f1,0x3dcc(9); lha 3,0x60(11); lwz 0,0x64(11); add 3,10,3; mtspr 8,0; blrl; lis 3,-32697; mr 4,30; addi 3,3,-7672; li 5,-1; li 6,-1; bl _s800585FC_30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800585FC_0();
extern "C" void _s800585FC_1();
extern "C" void _s800585FC_2();
extern "C" void _s800585FC_3();
extern "C" void _s800585FC_4();
extern "C" void _s800585FC_5();
extern "C" void _s800585FC_6();
extern "C" void _s800585FC_7();
extern "C" void _s800585FC_8();
extern "C" void _s800585FC_9();
extern "C" void _s800585FC_10();
extern "C" void _s800585FC_11();
extern "C" void _s800585FC_12();
extern "C" void _s800585FC_13();
extern "C" void _s800585FC_14();
extern "C" void _s800585FC_15();
extern "C" void _s800585FC_16();
extern "C" void _s800585FC_17();
extern "C" void _s800585FC_18();
extern "C" void _s800585FC_19();
extern "C" void _s800585FC_20();
extern "C" void _s800585FC_21();
extern "C" void _s800585FC_22();
extern "C" void _s800585FC_23();
extern "C" void _s800585FC_24();
extern "C" void _s800585FC_25();
extern "C" void _s800585FC_26();
extern "C" void _s800585FC_27();
extern "C" void _s800585FC_28();
extern "C" void _s800585FC_29();
extern "C" void _s800585FC_30();
extern "C" void f_800585FC() {}
