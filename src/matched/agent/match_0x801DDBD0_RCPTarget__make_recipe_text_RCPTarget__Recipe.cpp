// 0x801DDBD0 RCPTarget::make_recipe_text(RCPTarget::Recipe (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-568(1); mfspr 0,8; stmw 25,0x21c(1); stw 0,0x23c(1); mr 29,4; mr 31,5; mr 3,31; li 4,0; li 5,-1; bl _s801DDBD0_0; cmpwi 29,0; beq 0f; lwz 0,0x10(29); cmpwi 0,0; bne 1f; 0:; li 3,0; b 5f; 1:; mr 4,29; li 3,0; bl _s801DDBD0_1; lis 25,-32697; lis 9,-32705; mr 30,3; addi 28,9,16952; addi 4,25,24012; lwz 5,0x0(28); addi 3,1,520; crxor 6,6,6; bl _s801DDBD0_2; lwz 9,0x208(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,31; lis 26,-32705; bl _s801DDBD0_3; lis 27,-32705; addi 4,26,21076; mr 3,31; bl _s801DDBD0_4; addi 4,1,8; mr 3,30; bl _s801DDBD0_5; addi 4,1,8; mr 3,31; bl _s801DDBD0_6; addi 4,27,21084; mr 3,31; bl _s801DDBD0_7; mr 4,29; li 3,3; bl _s801DDBD0_8; mr 30,3; lwz 5,0xc(28); lis 4,-32697; addi 3,1,524; addi 4,4,24012; crxor 6,6,6; bl _s801DDBD0_9; lwz 9,0x20c(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,31; bl _s801DDBD0_10; lis 4,-32705; mr 3,31; addi 4,4,21076; bl _s801DDBD0_11; addi 4,1,8; mr 3,30; bl _s801DDBD0_12; addi 4,1,8; mr 3,31; bl _s801DDBD0_13; addi 4,27,21084; mr 3,31; bl _s801DDBD0_14; mr 4,29; li 3,1; bl _s801DDBD0_15; mr 30,3; lwz 5,0x10(28); addi 4,25,24012; addi 3,1,528; crxor 6,6,6; bl _s801DDBD0_16; lwz 9,0x210(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,31; bl _s801DDBD0_17; addi 4,26,21076; mr 3,31; bl _s801DDBD0_18; addi 4,1,8; mr 3,30; bl _s801DDBD0_19; mr 3,31; addi 4,1,8; bl _s801DDBD0_20; li 3,1; 5:; lwz 0,0x23c(1); mtspr 8,0; lmw 25,0x21c(1); addi 1,1,568"
extern "C" void _s801DDBD0_0();
extern "C" void _s801DDBD0_1();
extern "C" void _s801DDBD0_2();
extern "C" void _s801DDBD0_3();
extern "C" void _s801DDBD0_4();
extern "C" void _s801DDBD0_5();
extern "C" void _s801DDBD0_6();
extern "C" void _s801DDBD0_7();
extern "C" void _s801DDBD0_8();
extern "C" void _s801DDBD0_9();
extern "C" void _s801DDBD0_10();
extern "C" void _s801DDBD0_11();
extern "C" void _s801DDBD0_12();
extern "C" void _s801DDBD0_13();
extern "C" void _s801DDBD0_14();
extern "C" void _s801DDBD0_15();
extern "C" void _s801DDBD0_16();
extern "C" void _s801DDBD0_17();
extern "C" void _s801DDBD0_18();
extern "C" void _s801DDBD0_19();
extern "C" void _s801DDBD0_20();
extern "C" void f_801DDBD0() {}
