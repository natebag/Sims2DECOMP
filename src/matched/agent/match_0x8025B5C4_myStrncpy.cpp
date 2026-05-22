// 0x8025B5C4 myStrncpy (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 6,5; b 1f; 0:; lbz 0,0x0(4); addi 4,4,1; addi 6,6,-1; stb 0,0x0(3); addi 3,3,1; 1:; cmplwi 6,0; beq 2f; lbz 0,0x0(4); extsb. 0,0; bne 0b; 2:; subf 3,6,5"
extern "C" void f_8025B5C4() {}
