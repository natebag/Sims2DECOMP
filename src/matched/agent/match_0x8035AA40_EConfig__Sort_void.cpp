// 0x8035AA40 EConfig::Sort(void) (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 25,0x34(1); stw 0,0x54(1); mr 26,3; lwz 0,0x14(26); cmpwi 0,0; beq 12f; addi 3,1,8; addi 27,26,8; mr 25,3; bl _s8035AA40_0; addi 3,1,24; bl _s8035AA40_1; lwz 31,0x14(26); cmpwi 31,0; beq 1f; 0:; lwz 30,0x10(31); mr 3,25; lwz 29,0x0(30); mr 4,30; bl _s8035AA40_2; stw 29,0x0(3); addi 3,1,24; lwz 4,0x0(29); bl _s8035AA40_3; stw 30,0x0(3); lwz 31,0x4(31); cmpwi 31,0; bne 0b; 1:; lwz 30,0x8(26); cmpwi 30,0; beq 4f; 2:; lwz 31,0x8(30); mr 3,25; mr 4,30; li 5,0; bl _s8035AA40_4; cmpwi 3,0; beq 3f; mr 4,30; mr 3,27; bl _s8035AA40_5; 3:; mr. 30,31; bne 2b; 4:; lwz 9,0x4(27); b 7f; 5:; lwz 0,0x8(27); lwz 30,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 6f; cmpwi 30,0; beq 6f; lwz 4,0x0(30); mr 3,30; bl _s8035AA40_6; mr 3,30; bl _s8035AA40_7; 6:; mr 9,31; 7:; li 0,1; cmpwi 9,0; bne 8f; li 0,0; 8:; cmpwi 0,0; bne 5b; mr 3,27; bl _s8035AA40_8; lwz 29,0x18(1); cmpwi 29,0; beq 11f; addi 28,1,40; 9:; lwz 4,0x18(29); mr 3,25; bl _s8035AA40_9; lwz 30,0x0(3); mr 3,27; mr 4,30; bl _s8035AA40_10; mr 31,3; li 4,61; mr 3,30; li 5,0; bl _s8035AA40_11; cmpwi 3,-1; beq 10f; mr 5,3; mr 4,30; mr 3,28; bl _s8035AA40_12; lwz 4,0x28(1); mr 5,31; addi 3,26,20; bl _s8035AA40_13; lwz 4,0x28(1); mr 3,28; bl _s8035AA40_14; 10:; lwz 29,0x10(29); cmpwi 29,0; bne 9b; 11:; li 0,1; addi 3,1,24; stw 0,0x0(26); bl _s8035AA40_15; mr 3,25; bl _s8035AA40_16; 12:; lwz 0,0x54(1); mtspr 8,0; lmw 25,0x34(1); addi 1,1,80"
extern "C" void _s8035AA40_0();
extern "C" void _s8035AA40_1();
extern "C" void _s8035AA40_2();
extern "C" void _s8035AA40_3();
extern "C" void _s8035AA40_4();
extern "C" void _s8035AA40_5();
extern "C" void _s8035AA40_6();
extern "C" void _s8035AA40_7();
extern "C" void _s8035AA40_8();
extern "C" void _s8035AA40_9();
extern "C" void _s8035AA40_10();
extern "C" void _s8035AA40_11();
extern "C" void _s8035AA40_12();
extern "C" void _s8035AA40_13();
extern "C" void _s8035AA40_14();
extern "C" void _s8035AA40_15();
extern "C" void _s8035AA40_16();
extern "C" void f_8035AA40() {}
