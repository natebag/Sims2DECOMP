// 0x80024790 GetIndex(int, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x0(4); li 10,0; cmpwi 6,4,0; mr 11,4; mcrf cr7,cr6; b 5f; 0:; mulli 9,10,184; lhzx 0,11,9; cmpw 3,0; bne 1f; mr 3,10; blr; 1:; bge 4f; li 3,0; beq cr7,2f; lwz 3,-4(11); 2:; li 0,0; beq cr7,3f; lwz 0,-4(11); 3:; add 9,10,3; addi 9,9,-1; divw 3,9,0; mullw 3,3,0; subf 3,3,9; blr; 4:; addi 10,10,1; 5:; li 0,0; beq cr6,6f; lwz 0,-4(4); 6:; cmpw 10,0; blt 0b; cmpwi 11,0; li 3,0; beq 7f; lwz 3,-4(11); 7:; addi 3,3,-1"
extern "C" int f_80024790() {}
