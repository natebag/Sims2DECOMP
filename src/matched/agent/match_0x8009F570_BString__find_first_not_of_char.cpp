// 0x8009F570 BString::find_first_not_of(char, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; stb 4,0x8(1); mr 31,5; b 1f; 0:; addi 31,31,1; 1:; mr 3,30; bl _s8009F570_0; cmplw 31,3; bge 2f; mr 3,30; bl _s8009F570_1; lbzx 9,3,31; lbz 0,0x8(1); cmpw 9,0; beq 0b; 2:; mr 3,30; bl _s8009F570_2; cmplw 31,3; li 3,-1; bge 3f; mr 3,31; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8009F570_0();
extern "C" void _s8009F570_1();
extern "C" void _s8009F570_2();
extern "C" void f_8009F570() {}
