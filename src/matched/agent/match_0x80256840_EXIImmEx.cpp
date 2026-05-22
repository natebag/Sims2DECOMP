// 0x80256840 EXIImmEx (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 27,0x1c(1); addi 27,3,0; addi 28,4,0; addi 29,5,0; addi 30,6,0; b 5f; 0:; cmpwi 29,4; bge 1f; mr 31,29; b 2f; 1:; li 31,4; 2:; addi 5,31,0; addi 3,27,0; addi 4,28,0; addi 6,30,0; li 7,0; bl _s80256840_0; cmpwi 3,0; bne 3f; li 3,0; b 6f; 3:; mr 3,27; bl _s80256840_1; cmpwi 3,0; bne 4f; li 3,0; b 6f; 4:; add 28,28,31; subf 29,31,29; 5:; cmpwi 29,0; bne 0b; li 3,1; 6:; lwz 0,0x34(1); lmw 27,0x1c(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s80256840_0();
extern "C" void _s80256840_1();
extern "C" void f_80256840() {}
