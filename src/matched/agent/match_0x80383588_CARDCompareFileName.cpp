// 0x80383588 __CARDCompareFileName (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 5,3,8; li 7,32; b 2f; 0:; lbz 0,0x0(5); addi 5,5,1; lbz 6,0x0(4); addi 4,4,1; extsb 3,0; extsb 0,6; cmpw 3,0; beq 1f; li 3,0; blr; 1:; extsb. 0,6; bne 2f; li 3,1; blr; 2:; addic. 7,7,-1; bge 0b; lbz 0,0x0(4); extsb. 0,0; bne 3f; li 3,1; blr; 3:; li 3,0"
extern "C" int f_80383588() {}
