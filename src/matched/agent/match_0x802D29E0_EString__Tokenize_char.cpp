// 0x802D29E0 EString::Tokenize(char (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lwz 9,0x0(3); mr 31,4; mr 29,5; lbz 0,0x0(9); cmpwi 0,0; bne 0f; li 3,0; b 3f; 0:; addi 30,1,8; bl _s802D29E0_0; mr 28,30; mr 4,3; mr 3,30; bl _s802D29E0_1; lwz 3,0x8(1); mr 4,31; bl _s802D29E0_2; mr. 3,3; beq 2f; addi 30,1,16; 1:; mr 4,3; addi 3,1,16; bl _s802D29E0_3; mr 3,29; mr 4,30; bl _s802D29E0_4; lwz 4,0x10(1); mr 3,30; bl _s802D29E0_5; li 3,0; mr 4,31; bl _s802D29E0_6; mr. 3,3; bne 1b; 2:; lwz 4,0x8(1); mr 3,28; lwz 30,0x4(29); bl _s802D29E0_7; mr 3,30; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s802D29E0_0();
extern "C" void _s802D29E0_1();
extern "C" void _s802D29E0_2();
extern "C" void _s802D29E0_3();
extern "C" void _s802D29E0_4();
extern "C" void _s802D29E0_5();
extern "C" void _s802D29E0_6();
extern "C" void _s802D29E0_7();
extern "C" void f_802D29E0() {}
