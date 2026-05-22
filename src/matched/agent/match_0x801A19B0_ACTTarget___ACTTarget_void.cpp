// 0x801A19B0 ACTTarget::~ACTTarget(void) (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); lis 9,-32698; mr 29,3; addi 9,9,31072; addi 25,29,1616; stw 9,0x80(29); mr 28,25; addi 26,29,236; mr 24,4; addi 27,1,32; 0:; lwz 9,0x4(28); li 10,0; lwz 0,0x0(9); stw 9,0x20(1); b 2f; 1:; lwz 0,0x0(9); addi 10,10,1; 2:; stw 0,0x24(1); lwz 9,0x24(1); li 11,1; lwz 0,0x0(27); cmpw 9,0; bne 3f; li 11,0; 3:; cmpwi 11,0; bne 1b; cmpwi 10,0; beq 5f; lwz 9,0x4(28); lwz 3,0x0(9); stw 3,0x8(1); cmpwi 3,0; lwz 30,0x8(3); stw 3,0x18(1); lwz 31,0x0(3); lwz 9,0x4(3); stw 31,0x0(9); stw 9,0x4(31); beq 4f; li 4,12; bl _s801A19B0_0; 4:; stw 31,0x10(1); cmpwi 30,0; beq 0b; lwz 9,0x1c(30); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; b 0b; 5:; lwz 0,0xdc(29); lis 9,-32697; lwz 3,0x5f10(9); cmpwi 0,0; bne 6f; li 4,60; bl _s801A19B0_1; b 7f; 6:; li 4,61; bl _s801A19B0_2; 7:; lwz 0,0x0(29); cmpwi 0,0; beq 17f; lwz 3,0x4(29); addi 4,29,40; bl _s801A19B0_3; lwz 3,0x8(29); addi 4,29,56; bl _s801A19B0_4; lwz 3,0xc(29); addi 4,29,72; bl _s801A19B0_5; addi 9,29,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 8f; lwz 0,0x58(29); cmpwi 0,0; beq 9f; 8:; li 11,1; 9:; cmpwi 11,0; beq 10f; lwz 3,0x10(29); bl _s801A19B0_6; 10:; addi 9,29,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 11f; lwz 0,0x68(29); cmpwi 0,0; beq 12f; 11:; li 11,1; 12:; cmpwi 11,0; beq 13f; lwz 3,0x14(29); bl _s801A19B0_7; 13:; lwz 3,0x18(29); cmpwi 3,0; beq 14f; lwz 4,0x7c(29); bl _s801A19B0_8; 14:; lwz 3,0x1c(29); cmpwi 3,0; beq 15f; lwz 4,0x7c(29); bl _s801A19B0_9; 15:; lwz 3,0x20(29); cmpwi 3,0; beq 16f; lwz 4,0x7c(29); bl _s801A19B0_10; 16:; lwz 3,0x24(29); cmpwi 3,0; beq 17f; lwz 4,0x7c(29); bl _s801A19B0_11; 17:; mr 3,25; bl _s801A19B0_12; lwz 3,0x4(25); cmpwi 3,0; beq 18f; li 4,12; bl _s801A19B0_13; 18:; cmpwi 26,0; beq 20f; addi 31,29,1604; cmpw 26,31; beq 20f; 19:; addi 31,31,-76; li 4,2; addi 3,31,52; bl _s801A19B0_14; cmpw 26,31; bne 19b; 20:; lis 9,-32698; andi. 0,24,1; addi 9,9,-12328; stw 9,0x80(29); beq 21f; mr 3,29; bl _s801A19B0_15; 21:; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s801A19B0_0();
extern "C" void _s801A19B0_1();
extern "C" void _s801A19B0_2();
extern "C" void _s801A19B0_3();
extern "C" void _s801A19B0_4();
extern "C" void _s801A19B0_5();
extern "C" void _s801A19B0_6();
extern "C" void _s801A19B0_7();
extern "C" void _s801A19B0_8();
extern "C" void _s801A19B0_9();
extern "C" void _s801A19B0_10();
extern "C" void _s801A19B0_11();
extern "C" void _s801A19B0_12();
extern "C" void _s801A19B0_13();
extern "C" void _s801A19B0_14();
extern "C" void _s801A19B0_15();
extern "C" void f_801A19B0() {}
