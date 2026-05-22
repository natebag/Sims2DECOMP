// 0x8009F090 BString::find(char, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; stb 4,0x8(1); mr 31,5; b 1f; 0:; addi 31,31,1; 1:; mr 3,30; bl _s8009F090_0; cmplw 31,3; bge 3f; mr 3,30; bl _s8009F090_1; lbzx 9,3,31; li 11,1; lbz 0,0x8(1); cmpw 9,0; bne 2f; li 11,0; 2:; cmpwi 11,0; bne 0b; 3:; mr 3,30; bl _s8009F090_2; cmplw 31,3; li 3,-1; bge 4f; mr 3,31; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8009F090_0();
extern "C" void _s8009F090_1();
extern "C" void _s8009F090_2();
extern "C" void f_8009F090() {}
