// 0x8008D91C LiveModeChangeHouseStateMachine::Startup(void) (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; bl _s8008D91C_0; bl _s8008D91C_1; bl _s8008D91C_2; bl _s8008D91C_3; bl _s8008D91C_4; bl _s8008D91C_5; bl _s8008D91C_6; bl _s8008D91C_7; bl _s8008D91C_8; bl _s8008D91C_9; bl _s8008D91C_10; bl _s8008D91C_11; bl _s8008D91C_12; bl _s8008D91C_13; bl _s8008D91C_14; bl _s8008D91C_15; bl _s8008D91C_16; bl _s8008D91C_17; bl _s8008D91C_18; bl _s8008D91C_19; bl _s8008D91C_20; bl _s8008D91C_21; bl _s8008D91C_22; bl _s8008D91C_23; bl _s8008D91C_24; bl _s8008D91C_25; bl _s8008D91C_26; li 3,28; bl _s8008D91C_27; li 30,0; lis 11,-32698; mr 9,3; li 29,-1; li 28,1; addi 11,11,-10248; mr 4,9; stw 11,0x18(9); mr 3,27; stw 30,0x0(9); stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 28,0x14(9); bl _s8008D91C_28; li 3,28; bl _s8008D91C_29; lis 11,-32698; mr 9,3; addi 11,11,-10320; mr 4,9; stw 11,0x18(9); mr 3,27; stw 28,0x0(9); stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 28,0x14(9); bl _s8008D91C_30; li 3,28; bl _s8008D91C_31; lis 11,-32698; mr 9,3; addi 11,11,-10392; li 0,2; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,27; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 28,0x14(9); bl _s8008D91C_32; li 3,32; bl _s8008D91C_33; lis 11,-32698; mr 9,3; addi 11,11,-10464; li 0,3; stw 0,0x0(9); mr 3,27; stw 29,0xc(9); mr 4,9; stw 28,0x14(9); stw 11,0x18(9); stw 30,0x1c(9); stw 29,0x4(9); stw 30,0x8(9); stw 30,0x10(9); bl _s8008D91C_34; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8008D91C_0();
extern "C" void _s8008D91C_1();
extern "C" void _s8008D91C_2();
extern "C" void _s8008D91C_3();
extern "C" void _s8008D91C_4();
extern "C" void _s8008D91C_5();
extern "C" void _s8008D91C_6();
extern "C" void _s8008D91C_7();
extern "C" void _s8008D91C_8();
extern "C" void _s8008D91C_9();
extern "C" void _s8008D91C_10();
extern "C" void _s8008D91C_11();
extern "C" void _s8008D91C_12();
extern "C" void _s8008D91C_13();
extern "C" void _s8008D91C_14();
extern "C" void _s8008D91C_15();
extern "C" void _s8008D91C_16();
extern "C" void _s8008D91C_17();
extern "C" void _s8008D91C_18();
extern "C" void _s8008D91C_19();
extern "C" void _s8008D91C_20();
extern "C" void _s8008D91C_21();
extern "C" void _s8008D91C_22();
extern "C" void _s8008D91C_23();
extern "C" void _s8008D91C_24();
extern "C" void _s8008D91C_25();
extern "C" void _s8008D91C_26();
extern "C" void _s8008D91C_27();
extern "C" void _s8008D91C_28();
extern "C" void _s8008D91C_29();
extern "C" void _s8008D91C_30();
extern "C" void _s8008D91C_31();
extern "C" void _s8008D91C_32();
extern "C" void _s8008D91C_33();
extern "C" void _s8008D91C_34();
extern "C" void f_8008D91C() {}
