// 0x80084FEC IShrubObject::IShrubObject(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="beq 2f; mr 10,0; 0:; lwz 9,0x0(11); lwz 0,0x0(9); cmpw 0,4; bne 1f; lwz 0,0x4(9); andi. 8,0,1; beq 1f; lwz 0,0x8(9); cmpw 0,5; beqlr; addi 3,3,1; 1:; addi 11,11,4; cmpw 11,10; bne 0b; 2:; li 3,-1"
extern "C" int f_80084FEC() {}
