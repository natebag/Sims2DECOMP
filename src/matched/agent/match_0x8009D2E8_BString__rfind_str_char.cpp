// 0x8009D2E8 BString::rfind_str(char (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 27,3; mr 31,5; mr 29,6; mr 30,4; bl _s8009D2E8_0; subf 3,29,3; cmplw 31,3; bge 0f; addi 28,31,1; b 1f; 0:; mr 3,27; bl _s8009D2E8_1; subf 28,29,3; 1:; mr 3,27; bl _s8009D2E8_2; cmplw 3,29; blt 9f; cmpwi 29,0; bne 3f; b 9f; 2:; addi 3,28,-1; b 10f; 3:; cmpwi 28,0; beq 9f; add 26,30,29; 4:; li 30,0; b 6f; 5:; mr 30,31; 6:; cmplw 30,29; bge 8f; mr 3,27; addi 31,30,1; bl _s8009D2E8_3; subf 0,30,29; add 3,3,28; subf 11,31,26; add 3,3,0; lbz 9,0x0(11); lbz 0,-2(3); li 11,1; cmpw 9,0; bne 7f; li 11,0; 7:; cmpwi 11,0; beq 5b; 8:; cmpw 30,29; beq 2b; addi 9,30,1; subf 5,30,29; subf 9,9,26; add 5,28,5; lbz 4,0x0(9); addi 5,5,-3; mr 3,27; extsb 4,4; bl _s8009D2E8_4; cmpwi 3,-1; beq 9f; add 0,3,30; subf 0,29,0; addic. 28,0,2; bne 4b; 9:; li 3,-1; 10:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8009D2E8_0();
extern "C" void _s8009D2E8_1();
extern "C" void _s8009D2E8_2();
extern "C" void _s8009D2E8_3();
extern "C" void _s8009D2E8_4();
extern "C" void f_8009D2E8() {}
