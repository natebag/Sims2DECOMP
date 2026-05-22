// 0x802D2AA0 EString::GetLine(__sFILE (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1064(1); mfspr 0,8; stmw 26,0x410(1); stw 0,0x42c(1); mr 29,3; mr 27,4; li 31,0; addi 28,1,1032; addi 30,1,8; li 26,0; 0:; mr 3,28; li 4,1; li 5,1; mr 6,27; bl _s802D2AA0_0; mr. 3,3; beq 1f; lbz 0,0x408(1); cmpwi 0,10; bne 2f; 1:; stbx 26,30,31; addi 31,31,1; b 3f; 2:; stbx 0,30,31; cmpwi 3,1; addi 31,31,1; beq 0b; 3:; cmpwi 31,1; ble 4f; addi 9,31,-2; lbzx 0,30,9; cmpwi 0,13; bne 4f; li 0,0; addi 31,31,-1; stbx 0,30,9; 4:; lwz 4,0x0(29); mr 3,29; bl _s802D2AA0_1; mr 3,29; addi 4,1,8; bl _s802D2AA0_2; addi 3,31,-1; lwz 0,0x42c(1); mtspr 8,0; lmw 26,0x410(1); addi 1,1,1064"
extern "C" void _s802D2AA0_0();
extern "C" void _s802D2AA0_1();
extern "C" void _s802D2AA0_2();
extern "C" void f_802D2AA0() {}
