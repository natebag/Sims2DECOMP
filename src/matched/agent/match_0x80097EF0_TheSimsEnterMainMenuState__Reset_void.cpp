// 0x80097EF0 TheSimsEnterMainMenuState::Reset(void) (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; bl _s80097EF0_0; bl _s80097EF0_1; bl _s80097EF0_2; bl _s80097EF0_3; bl _s80097EF0_4; bl _s80097EF0_5; bl _s80097EF0_6; bl _s80097EF0_7; bl _s80097EF0_8; bl _s80097EF0_9; bl _s80097EF0_10; bl _s80097EF0_11; bl _s80097EF0_12; bl _s80097EF0_13; bl _s80097EF0_14; bl _s80097EF0_15; bl _s80097EF0_16; bl _s80097EF0_17; bl _s80097EF0_18; bl _s80097EF0_19; bl _s80097EF0_20; bl _s80097EF0_21; bl _s80097EF0_22; bl _s80097EF0_23; bl _s80097EF0_24; bl _s80097EF0_25; bl _s80097EF0_26; lis 9,-32697; addi 31,9,24012; lwz 3,0x110(31); cmpwi 3,0; beq 0f; bl _s80097EF0_27; 0:; li 29,0; lis 30,-32697; stw 29,0xc(28); addi 3,30,23428; li 4,0; li 5,7; bl _s80097EF0_28; addi 30,30,23428; stw 29,0xe4(30); mr 3,30; stw 29,0xe8(30); li 4,0; bl _s80097EF0_29; stw 29,0x160(31); stw 29,0x84(30); stw 29,0xf0(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80097EF0_0();
extern "C" void _s80097EF0_1();
extern "C" void _s80097EF0_2();
extern "C" void _s80097EF0_3();
extern "C" void _s80097EF0_4();
extern "C" void _s80097EF0_5();
extern "C" void _s80097EF0_6();
extern "C" void _s80097EF0_7();
extern "C" void _s80097EF0_8();
extern "C" void _s80097EF0_9();
extern "C" void _s80097EF0_10();
extern "C" void _s80097EF0_11();
extern "C" void _s80097EF0_12();
extern "C" void _s80097EF0_13();
extern "C" void _s80097EF0_14();
extern "C" void _s80097EF0_15();
extern "C" void _s80097EF0_16();
extern "C" void _s80097EF0_17();
extern "C" void _s80097EF0_18();
extern "C" void _s80097EF0_19();
extern "C" void _s80097EF0_20();
extern "C" void _s80097EF0_21();
extern "C" void _s80097EF0_22();
extern "C" void _s80097EF0_23();
extern "C" void _s80097EF0_24();
extern "C" void _s80097EF0_25();
extern "C" void _s80097EF0_26();
extern "C" void _s80097EF0_27();
extern "C" void _s80097EF0_28();
extern "C" void _s80097EF0_29();
extern "C" void f_80097EF0() {}
