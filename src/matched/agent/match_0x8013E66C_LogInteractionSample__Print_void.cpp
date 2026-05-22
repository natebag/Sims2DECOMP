// 0x8013E66C LogInteractionSample::Print(void) (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lis 30,-32706; lwz 4,0x34(31); addi 3,13,-24588; bl _s8013E66C_0; addi 4,30,-11160; bl _s8013E66C_1; lwz 4,0x28(31); addi 3,13,-24588; bl _s8013E66C_2; addi 4,30,-11160; bl _s8013E66C_3; lwz 4,0x2c(31); addi 3,13,-24588; bl _s8013E66C_4; addi 4,30,-11160; bl _s8013E66C_5; lwz 4,0x30(31); addi 3,13,-24588; bl _s8013E66C_6; addi 4,30,-11160; bl _s8013E66C_7; lwz 0,0x38(31); cmpwi 0,0; beq 0f; lis 9,-32706; addi 4,9,-11156; b 1f; 0:; lis 9,-32706; addi 4,9,-11152; 1:; addi 3,13,-24588; lis 30,-32706; bl _s8013E66C_8; addi 4,30,-11160; bl _s8013E66C_9; lfs f0,0x4(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_10; addi 4,30,-11160; bl _s8013E66C_11; lfs f0,0x8(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_12; addi 4,30,-11160; bl _s8013E66C_13; lfs f0,0xc(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_14; addi 4,30,-11160; bl _s8013E66C_15; lfs f0,0x10(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_16; addi 4,30,-11160; bl _s8013E66C_17; lfs f0,0x14(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_18; addi 4,30,-11160; bl _s8013E66C_19; lfs f0,0x18(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_20; addi 4,30,-11160; bl _s8013E66C_21; lfs f0,0x1c(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_22; addi 4,30,-11160; bl _s8013E66C_23; lfs f0,0x20(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_24; addi 4,30,-11160; bl _s8013E66C_25; lfs f0,0x24(31); addi 4,1,8; addi 3,13,-24588; stfd f0,0x8(1); bl _s8013E66C_26; addi 4,30,-11160; bl _s8013E66C_27; lwz 11,-21508(13); lwz 4,0x0(31); lwz 9,0x0(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 2f; lwz 4,0x14(3); addi 3,13,-24588; bl _s8013E66C_28; lis 4,-32706; addi 4,4,-11160; bl _s8013E66C_29; b 3f; 2:; lwz 4,0x0(31); addi 3,13,-24588; bl _s8013E66C_30; 3:; lis 4,-32706; addi 3,13,-24588; addi 4,4,-11144; bl _s8013E66C_31; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8013E66C_0();
extern "C" void _s8013E66C_1();
extern "C" void _s8013E66C_2();
extern "C" void _s8013E66C_3();
extern "C" void _s8013E66C_4();
extern "C" void _s8013E66C_5();
extern "C" void _s8013E66C_6();
extern "C" void _s8013E66C_7();
extern "C" void _s8013E66C_8();
extern "C" void _s8013E66C_9();
extern "C" void _s8013E66C_10();
extern "C" void _s8013E66C_11();
extern "C" void _s8013E66C_12();
extern "C" void _s8013E66C_13();
extern "C" void _s8013E66C_14();
extern "C" void _s8013E66C_15();
extern "C" void _s8013E66C_16();
extern "C" void _s8013E66C_17();
extern "C" void _s8013E66C_18();
extern "C" void _s8013E66C_19();
extern "C" void _s8013E66C_20();
extern "C" void _s8013E66C_21();
extern "C" void _s8013E66C_22();
extern "C" void _s8013E66C_23();
extern "C" void _s8013E66C_24();
extern "C" void _s8013E66C_25();
extern "C" void _s8013E66C_26();
extern "C" void _s8013E66C_27();
extern "C" void _s8013E66C_28();
extern "C" void _s8013E66C_29();
extern "C" void _s8013E66C_30();
extern "C" void _s8013E66C_31();
extern "C" void f_8013E66C() {}
