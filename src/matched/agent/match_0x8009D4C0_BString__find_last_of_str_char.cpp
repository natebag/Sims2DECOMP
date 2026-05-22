// 0x8009D4C0 BString::find_last_of_str(char (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 31,5; mr 27,4; mr 28,6; li 29,0; bl _s8009D4C0_0; cmplw 31,3; bge 0f; addi 31,31,1; b 1f; 0:; mr 3,30; bl _s8009D4C0_1; mr 31,3; 1:; mr 3,30; bl _s8009D4C0_2; cmpwi 3,0; beq 6f; 2:; cmpwi 31,0; beq 6f; li 29,0; addi 31,31,-1; b 4f; 3:; addi 29,29,1; 4:; cmpw 29,28; beq 2b; mr 3,30; bl _s8009D4C0_3; lbzx 9,3,31; li 11,1; lbzx 0,27,29; cmpw 9,0; bne 5f; li 11,0; 5:; cmpwi 11,0; bne 3b; b 7f; 6:; cmpw 29,28; beq 8f; 7:; mr 3,30; bl _s8009D4C0_4; cmpwi 3,0; mr 3,31; bne 9f; 8:; li 3,-1; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009D4C0_0();
extern "C" void _s8009D4C0_1();
extern "C" void _s8009D4C0_2();
extern "C" void _s8009D4C0_3();
extern "C" void _s8009D4C0_4();
extern "C" void f_8009D4C0() {}
