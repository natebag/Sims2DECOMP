// 0x8009F6B8 BString::find_last_not_of(char, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; mr 31,5; stb 4,0x8(1); bl _s8009F6B8_0; cmplw 31,3; bge 0f; addi 31,31,1; b 1f; 0:; mr 3,30; bl _s8009F6B8_1; mr 31,3; 1:; mr 3,30; bl _s8009F6B8_2; cmpwi 3,0; bne 3f; li 3,-1; b 6f; 2:; addi 31,31,-1; 3:; mr 3,30; bl _s8009F6B8_3; add 3,3,31; lbz 9,0x8(1); lbz 0,-1(3); cmpw 0,9; bne 4f; cmplwi 31,1; bgt 2b; 4:; cmpwi 31,1; bne 5f; mr 3,30; bl _s8009F6B8_4; lbz 9,0x0(3); lbz 0,0x8(1); cmpw 9,0; li 3,-1; beq 6f; 5:; addi 3,31,-1; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8009F6B8_0();
extern "C" void _s8009F6B8_1();
extern "C" void _s8009F6B8_2();
extern "C" void _s8009F6B8_3();
extern "C" void _s8009F6B8_4();
extern "C" void f_8009F6B8() {}
