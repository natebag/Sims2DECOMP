// 0x8009D594 BString::find_first_not_of_str(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; mr 28,6; mr 30,5; b 4f; 0:; li 31,0; b 2f; 1:; addi 31,31,1; 2:; cmplw 31,28; bge 3f; mr 3,29; bl _s8009D594_0; lbzx 9,3,30; lbzx 0,27,31; cmpw 9,0; bne 1b; 3:; cmpw 31,28; beq 5f; addi 30,30,1; 4:; mr 3,29; bl _s8009D594_1; cmplw 30,3; blt 0b; 5:; mr 3,29; bl _s8009D594_2; cmplw 30,3; li 3,-1; bge 6f; mr 3,30; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009D594_0();
extern "C" void _s8009D594_1();
extern "C" void _s8009D594_2();
extern "C" void f_8009D594() {}
