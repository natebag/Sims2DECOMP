// 0x802439D0 strncasecmp (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 5,5; bne 1f; li 3,0; blr; 0:; cmpwi 5,0; beq 4f; cmpwi 7,0; beq 4f; cmpwi 8,0; beq 4f; addi 3,3,1; addi 4,4,1; 1:; cmpwi 5,0; lbz 6,0x0(3); addi 5,5,-1; lbz 12,0x0(4); beq 4f; lis 9,-32704; extsb 10,6; addi 9,9,-935; mr 7,10; lbzx 0,10,9; andi. 11,0,1; beq 2f; addi 10,10,32; 2:; extsb 11,12; lbzx 0,11,9; mr 8,11; andi. 9,0,1; beq 3f; addi 11,11,32; 3:; cmpw 10,11; beq 0b; 4:; lis 9,-32704; rlwinm 3,6,0,24,31; addi 9,9,-935; lbzx 0,3,9; andi. 11,0,1; beq 5f; addi 3,3,32; 5:; rlwinm 11,12,0,24,31; lbzx 0,11,9; andi. 9,0,1; beq 6f; addi 11,11,32; 6:; subf 3,11,3"
extern "C" int f_802439D0() {}
