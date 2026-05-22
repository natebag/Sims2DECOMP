// 0x802E2B4C EEngine::Init(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; bl _s802E2B4C_0; bl _s802E2B4C_1; bl _s802E2B4C_2; bl _s802E2B4C_3; bl _s802E2B4C_4; bl _s802E2B4C_5; bl _s802E2B4C_6; bl _s802E2B4C_7; bl _s802E2B4C_8; bl _s802E2B4C_9; bl _s802E2B4C_10; bl _s802E2B4C_11; bl _s802E2B4C_12; bl _s802E2B4C_13; bl _s802E2B4C_14; bl _s802E2B4C_15; bl _s802E2B4C_16; bl _s802E2B4C_17; bl _s802E2B4C_18; bl _s802E2B4C_19; bl _s802E2B4C_20; bl _s802E2B4C_21; bl _s802E2B4C_22; bl _s802E2B4C_23; bl _s802E2B4C_24; bl _s802E2B4C_25; bl _s802E2B4C_26; mr 3,31; bl _s802E2B4C_27; mr 3,31; bl _s802E2B4C_28; mr 3,31; bl _s802E2B4C_29; mr 3,31; bl _s802E2B4C_30; mr 3,31; bl _s802E2B4C_31; lwz 9,0x0(31); lha 3,0x88(9); lwz 0,0x8c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; li 3,0; beq 0f; mr 3,31; addi 30,31,52; bl _s802E2B4C_32; li 29,1; bl _s802E2B4C_33; mr 3,31; bl _s802E2B4C_34; lwz 11,-26532(13); lis 4,-32693; addi 4,4,-11760; lwz 9,0x0(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); addi 4,31,16; lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; bl _s802E2B4C_35; mr 3,30; bl _s802E2B4C_36; stw 29,0x4(31); bl _s802E2B4C_37; stw 29,-22772(13); li 3,1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E2B4C_0();
extern "C" void _s802E2B4C_1();
extern "C" void _s802E2B4C_2();
extern "C" void _s802E2B4C_3();
extern "C" void _s802E2B4C_4();
extern "C" void _s802E2B4C_5();
extern "C" void _s802E2B4C_6();
extern "C" void _s802E2B4C_7();
extern "C" void _s802E2B4C_8();
extern "C" void _s802E2B4C_9();
extern "C" void _s802E2B4C_10();
extern "C" void _s802E2B4C_11();
extern "C" void _s802E2B4C_12();
extern "C" void _s802E2B4C_13();
extern "C" void _s802E2B4C_14();
extern "C" void _s802E2B4C_15();
extern "C" void _s802E2B4C_16();
extern "C" void _s802E2B4C_17();
extern "C" void _s802E2B4C_18();
extern "C" void _s802E2B4C_19();
extern "C" void _s802E2B4C_20();
extern "C" void _s802E2B4C_21();
extern "C" void _s802E2B4C_22();
extern "C" void _s802E2B4C_23();
extern "C" void _s802E2B4C_24();
extern "C" void _s802E2B4C_25();
extern "C" void _s802E2B4C_26();
extern "C" void _s802E2B4C_27();
extern "C" void _s802E2B4C_28();
extern "C" void _s802E2B4C_29();
extern "C" void _s802E2B4C_30();
extern "C" void _s802E2B4C_31();
extern "C" void _s802E2B4C_32();
extern "C" void _s802E2B4C_33();
extern "C" void _s802E2B4C_34();
extern "C" void _s802E2B4C_35();
extern "C" void _s802E2B4C_36();
extern "C" void _s802E2B4C_37();
extern "C" void f_802E2B4C() {}
