// 0x802D5000 EString2::Replace(unsigned (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 26,0x20(1); stw 0,0x3c(1); mr 28,3; mr 27,4; mr 26,5; bl _s802D5000_0; mr 31,3; cmpwi 31,-1; beq 0f; addi 29,1,24; mr 4,28; mr 3,29; mr 5,31; bl _s802D5000_1; lwz 4,0x18(1); addi 30,1,8; addi 3,1,16; mr 5,26; bl _s802D5000_2; mr 3,27; bl _s802D5000_3; add 3,31,3; lwz 5,0x0(28); add 3,3,3; lwz 4,0x10(1); add 5,3,5; addi 3,1,8; bl _s802D5000_4; lwz 4,0x8(1); mr 3,28; bl _s802D5000_5; lwz 4,0x8(1); mr 3,30; bl _s802D5000_6; lwz 4,0x10(1); addi 3,1,16; bl _s802D5000_7; lwz 4,0x18(1); mr 3,29; bl _s802D5000_8; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x3c(1); mtspr 8,0; lmw 26,0x20(1); addi 1,1,56"
extern "C" void _s802D5000_0();
extern "C" void _s802D5000_1();
extern "C" void _s802D5000_2();
extern "C" void _s802D5000_3();
extern "C" void _s802D5000_4();
extern "C" void _s802D5000_5();
extern "C" void _s802D5000_6();
extern "C" void _s802D5000_7();
extern "C" void _s802D5000_8();
extern "C" void f_802D5000() {}
