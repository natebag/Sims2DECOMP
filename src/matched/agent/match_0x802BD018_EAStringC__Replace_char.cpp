// 0x802BD018 EAStringC::Replace(char, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0x0(3); mr 30,4; mr 31,5; addi 3,9,8; b 1f; 0:; stb 31,0x0(3); addi 3,3,1; 1:; mr 4,30; bl _s802BD018_0; mr. 3,3; bne 0b; li 3,0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802BD018_0();
extern "C" void f_802BD018() {}
