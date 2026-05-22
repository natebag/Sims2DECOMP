// 0x802D2880 EString::EString(char (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,3; mr 28,5; mr. 26,4; beq 0f; mr 3,26; bl _s802D2880_0; mr 29,3; b 1f; 0:; li 29,0; 1:; cmpwi 28,0; beq 2f; mr 3,28; bl _s802D2880_1; mr 30,3; b 3f; 2:; li 30,0; 3:; add. 4,29,30; beq 4f; addi 4,4,1; mr 3,27; bl _s802D2880_2; mr. 31,3; beq 4f; mr 4,26; mr 5,29; mr 3,31; crxor 6,6,6; bl _s802D2880_3; add 3,31,29; mr 4,28; addi 5,30,1; crxor 6,6,6; bl _s802D2880_4; stw 31,0x0(27); b 5f; 4:; mr 3,27; bl _s802D2880_5; 5:; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802D2880_0();
extern "C" void _s802D2880_1();
extern "C" void _s802D2880_2();
extern "C" void _s802D2880_3();
extern "C" void _s802D2880_4();
extern "C" void _s802D2880_5();
extern "C" void f_802D2880() {}
