// 0x80243678 strcasecmp (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="b 1f; 0:; addi 3,3,1; addi 4,4,1; 1:; lbz 0,0x0(3); lbz 8,0x0(4); mr 7,0; extsb 0,0; cmpwi 0,0; beq 4f; lis 9,-32704; mr 10,0; addi 9,9,-935; lbzx 0,10,9; andi. 11,0,1; beq 2f; addi 10,10,32; 2:; extsb 11,8; lbzx 0,11,9; andi. 9,0,1; beq 3f; addi 11,11,32; 3:; cmpw 10,11; beq 0b; 4:; lis 9,-32704; rlwinm 3,7,0,24,31; addi 9,9,-935; lbzx 0,3,9; andi. 11,0,1; beq 5f; addi 3,3,32; 5:; rlwinm 11,8,0,24,31; lbzx 0,11,9; andi. 9,0,1; beq 6f; addi 11,11,32; 6:; subf 3,11,3"
extern "C" int f_80243678() {}
