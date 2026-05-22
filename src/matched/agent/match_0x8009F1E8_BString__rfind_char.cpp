// 0x8009F1E8 BString::rfind(char, (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; mr 31,5; stb 4,0x8(1); bl _s8009F1E8_0; cmplw 31,3; bge 0f; addi 31,31,1; b 1f; 0:; mr 3,30; bl _s8009F1E8_1; mr 31,3; 1:; mr 3,30; bl _s8009F1E8_2; cmpwi 3,0; bne 3f; li 3,-1; b 8f; 2:; addi 31,31,-1; 3:; mr 3,30; bl _s8009F1E8_3; add 3,3,31; lbz 9,0x8(1); lbz 0,-1(3); li 11,1; cmpw 0,9; bne 4f; li 11,0; 4:; cmpwi 11,0; beq 5f; cmplwi 31,1; bgt 2b; 5:; cmpwi 31,1; bne 7f; mr 3,30; bl _s8009F1E8_4; lbz 9,0x0(3); li 11,1; lbz 0,0x8(1); cmpw 9,0; bne 6f; li 11,0; 6:; cmpwi 11,0; li 3,-1; bne 8f; 7:; addi 3,31,-1; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8009F1E8_0();
extern "C" void _s8009F1E8_1();
extern "C" void _s8009F1E8_2();
extern "C" void _s8009F1E8_3();
extern "C" void _s8009F1E8_4();
extern "C" void f_8009F1E8() {}
