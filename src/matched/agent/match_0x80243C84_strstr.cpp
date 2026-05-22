// 0x80243C84 strstr (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 10,3; lbz 0,0x0(10); cmpwi 0,0; bne 1f; lbz 0,0x0(4); li 3,0; cmpwi 0,0; bnelr; 0:; mr 3,10; blr; 1:; li 11,0; b 3f; 2:; addi 11,11,1; 3:; lbzx 0,4,11; extsb 9,0; cmpwi 9,0; beq 0b; lbzx 0,10,11; extsb 0,0; cmpw 9,0; beq 2b; lbzu 0,0x1(10); cmpwi 0,0; bne 1b; li 3,0"
extern "C" int f_80243C84() {}
