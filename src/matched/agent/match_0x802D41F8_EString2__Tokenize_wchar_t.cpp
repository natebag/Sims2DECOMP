// 0x802D41F8 EString2::Tokenize(wchar_t, (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 23,0x24(1); stw 0,0x4c(1); mr 29,3; mr 24,4; lwz 3,0x0(29); mr 25,5; lhz 0,0x0(3); cmpwi 0,0; bne 0f; li 3,0; b 2f; 0:; li 0,0; addi 30,1,8; stw 0,0x18(1); mr 23,30; bl _s802D41F8_0; mr 28,23; mr 26,3; mr 3,30; li 31,0; bl _s802D41F8_1; addi 27,1,24; addi 30,1,16; 1:; mr 5,27; mr 6,26; mr 7,24; mr 3,30; mr 4,29; addi 31,31,1; bl _s802D41F8_2; lwz 4,0x10(1); mr 3,28; bl _s802D41F8_3; lwz 4,0x10(1); mr 3,30; bl _s802D41F8_4; mr 3,25; mr 4,28; bl _s802D41F8_5; lwz 0,0x8(1); cmpwi 0,0; bne 1b; mr 3,23; li 4,0; bl _s802D41F8_6; addi 3,31,-1; 2:; lwz 0,0x4c(1); mtspr 8,0; lmw 23,0x24(1); addi 1,1,72"
extern "C" void _s802D41F8_0();
extern "C" void _s802D41F8_1();
extern "C" void _s802D41F8_2();
extern "C" void _s802D41F8_3();
extern "C" void _s802D41F8_4();
extern "C" void _s802D41F8_5();
extern "C" void _s802D41F8_6();
extern "C" void f_802D41F8() {}
