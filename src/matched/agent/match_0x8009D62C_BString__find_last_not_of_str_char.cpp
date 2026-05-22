// 0x8009D62C BString::find_last_not_of_str(char (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 31,5; mr 26,4; mr 27,6; li 28,0; bl _s8009D62C_0; cmplw 31,3; bge 0f; addi 31,31,1; b 1f; 0:; mr 3,29; bl _s8009D62C_1; mr 31,3; 1:; mr 3,29; bl _s8009D62C_2; cmpwi 3,0; beq 5f; cmpwi 31,0; beq 5f; 2:; li 28,0; addi 30,31,-1; b 4f; 3:; addi 28,28,1; 4:; cmpw 28,27; beq 6f; mr 3,29; bl _s8009D62C_3; add 3,3,31; lbzx 9,26,28; lbz 0,-1(3); cmpw 0,9; bne 3b; mr. 31,30; bne 2b; 5:; cmpw 28,27; bne 7f; 6:; mr 3,29; bl _s8009D62C_4; cmpwi 3,0; addi 3,31,-1; bne 8f; 7:; li 3,-1; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8009D62C_0();
extern "C" void _s8009D62C_1();
extern "C" void _s8009D62C_2();
extern "C" void _s8009D62C_3();
extern "C" void _s8009D62C_4();
extern "C" void f_8009D62C() {}
