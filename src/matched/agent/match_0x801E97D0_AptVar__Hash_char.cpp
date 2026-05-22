// 0x801E97D0 AptVar::Hash(char (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 10,0; li 11,0; lbzx 0,3,10; cmpwi 0,0; beq 1f; 0:; lbzx 0,3,11; addi 11,11,1; lbzx 9,3,11; extsb 0,0; add 10,10,0; cmpwi 9,0; bne 0b; 1:; mr 3,10"
extern "C" int f_801E97D0() {}
