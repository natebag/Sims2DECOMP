// 0x802D4070 EString2::EString2(unsigned (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 26,4; mr 27,3; mr 25,5; mr 3,26; bl _s802D4070_0; mr 31,3; mr 3,25; bl _s802D4070_1; mr 28,3; add. 30,31,28; beq 1f; addi 30,30,1; add 30,30,30; bl _s802D4070_2; mr 4,30; li 5,0; bl _s802D4070_3; mr. 29,3; beq 0f; add 30,31,31; mr 4,26; mr 5,30; mr 3,29; crxor 6,6,6; bl _s802D4070_4; addi 5,28,1; add 3,30,29; mr 4,25; rlwinm 5,5,1,0,30; crxor 6,6,6; bl _s802D4070_5; stw 29,0x0(27); b 2f; 0:; mr 3,27; bl _s802D4070_6; b 2f; 1:; mr 3,27; bl _s802D4070_7; 2:; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s802D4070_0();
extern "C" void _s802D4070_1();
extern "C" void _s802D4070_2();
extern "C" void _s802D4070_3();
extern "C" void _s802D4070_4();
extern "C" void _s802D4070_5();
extern "C" void _s802D4070_6();
extern "C" void _s802D4070_7();
extern "C" void f_802D4070() {}
