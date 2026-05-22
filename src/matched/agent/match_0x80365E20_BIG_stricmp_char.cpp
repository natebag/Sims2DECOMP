// 0x80365E20 BIG_stricmp(char (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 6,3; lis 9,-32704; lbz 11,0x0(6); addi 7,9,-935; extsb 11,11; lbzx 0,11,7; mr 8,11; andi. 9,0,1; beq 0f; addi 8,11,32; 0:; lbz 0,0x0(4); extsb 10,0; lbzx 9,10,7; andi. 0,9,1; beq 1f; addi 10,10,32; 1:; subf. 3,10,8; bnelr; cmpwi 11,0; beqlr; 2:; lbzu 0,0x1(6); addi 4,4,1; extsb 8,0; lbzx 9,8,7; mr 10,8; andi. 0,9,1; beq 3f; addi 10,8,32; 3:; lbz 0,0x0(4); extsb 11,0; lbzx 9,11,7; andi. 0,9,1; beq 4f; addi 11,11,32; 4:; subf. 3,11,10; bnelr; cmpwi 8,0; bne 2b"
extern "C" int f_80365E20() {}
