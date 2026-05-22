// 0x801DFA2C RMDTarget::GetLocalizable(char (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801DFA2C_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801DFA2C_1; mr 31,3; li 0,0; sth 0,0x0(31); mr 4,30; lwz 3,-29656(13); bl _s801DFA2C_2; cmpwi 3,0; bne 1f; addi 3,29,160; bl _s801DFA2C_3; mr 4,3; mr 3,31; bl _s801DFA2C_4; b 2f; 1:; lwz 3,-29648(13); mr 4,30; bl _s801DFA2C_5; cmpwi 3,0; bne 2f; addi 3,29,164; bl _s801DFA2C_6; mr 4,3; mr 3,31; bl _s801DFA2C_7; 2:; mr 3,31; bl _s801DFA2C_8; mr 3,31; bl _s801DFA2C_9; mr 3,31; bl _s801DFA2C_10; mr 3,31; bl _s801DFA2C_11; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801DFA2C_12; mr 30,3; mr 4,31; bl _s801DFA2C_13; mr 3,31; bl _s801DFA2C_14; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801DFA2C_0();
extern "C" void _s801DFA2C_1();
extern "C" void _s801DFA2C_2();
extern "C" void _s801DFA2C_3();
extern "C" void _s801DFA2C_4();
extern "C" void _s801DFA2C_5();
extern "C" void _s801DFA2C_6();
extern "C" void _s801DFA2C_7();
extern "C" void _s801DFA2C_8();
extern "C" void _s801DFA2C_9();
extern "C" void _s801DFA2C_10();
extern "C" void _s801DFA2C_11();
extern "C" void _s801DFA2C_12();
extern "C" void _s801DFA2C_13();
extern "C" void _s801DFA2C_14();
extern "C" void f_801DFA2C() {}
